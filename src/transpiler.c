#include "include/transpiler.h"
#include "include/terminal.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LOOP 50

enum token
{
    ADD,
    SUB,
    LEFT,
    RIGHT,
    IN,
    OUT,
    WHILE_START,
    WHILE_END,
    NIL
};

char *sourcecode_start = NULL;
char *sourcecode = NULL;

static void interpreter_cleanup(void);

static void print_token(int t, int i, FILE *f);

static int get_token(char ch);

char *transpiler_init(const char *source_str)
{
    char ch;
    int size = 0;
    atexit(interpreter_cleanup);
    FILE *source = fopen(source_str, "r");
    if (source == NULL)
    {
        return NULL;
    }
    while ((ch = getc(source)) != EOF)
    {
        switch (ch)
        {
        case '<':
        case '>':
        case '+':
        case '-':
        case '.':
        case ',':
        case '[':
        case ']':
            size++;
            break;
        default:
            continue;
            break;
        }
    }
    sourcecode_start = calloc(size + 1, sizeof(char));
    sourcecode = sourcecode_start;
    rewind(source);
    size = 0;
    while ((ch = getc(source)) != EOF)
    {
        switch (ch)
        {
        case '<':
        case '>':
        case '+':
        case '-':
        case '.':
        case ',':
        case '[':
        case ']':
            sourcecode[size++] = ch;
            break;
        default:
            continue;
            break;
        }
    }
    fclose(source);
    return sourcecode;
}

int transpiler_run(void)
{
    char ch;
    FILE *f = fopen("output.c", "w");
    fprintf(f, "\
    #include<stdio.h>\n\
    int arr[30000] = {0};\n\
    typedef int cell_t;\n\
    static cell_t cells[30000] = {0};\n\
    static cell_t *ptr = cells;\n\
    \nint main(void)\n{\n\
    ");
    int current_token = NIL;
    int i = 0;
    while ((ch = *sourcecode) != '\0')
    {
        current_token = get_token(ch);
        i = 1;
        while (*(sourcecode + i) != '\0' && get_token(*(sourcecode + i)) == current_token)
        {
            i++;
        }
        print_token(current_token, i, f);
        sourcecode = sourcecode + i;
    }
    fprintf(f, "return 0;\n}");
    fclose(f);
    return 0;
}

static void interpreter_cleanup(void)
{
    if (sourcecode_start != NULL)
    {
        free(sourcecode_start);
        sourcecode_start = NULL;
    }
}

static void print_token(int t, int i, FILE *f)
{
    switch (t)
    {
    case RIGHT:
        fprintf(f, "ptr += %d;\n", i);
        break;
    case LEFT:
        fprintf(f, "ptr -= %d;\n", i);
        break;
    case ADD:
        fprintf(f, "*ptr += %d;\n", i);
        break;
    case SUB:
        fprintf(f, "*ptr -= %d;\n", i);
        break;
    case OUT:
        while (i>0)
        {
            i--;
            fprintf(f, "putchar(*ptr);\n");
        }
        break;
    case IN:
        while (i>0)
        {
            i--;
            fprintf(f, "*ptr = (cell_t)getchar();\n");
        }
        break;
    case WHILE_START:
        while (i>0)
        {
            i--;
            fprintf(f, "while (*ptr)\n{\n");
        }
    case WHILE_END:
        while (i>0)
        {
            i--;
            fprintf(f, "}\n");
        }
        break;
    }
}

static int get_token(char ch)
{
    switch (ch)
    {
    case '<':
        return RIGHT;
        break;
    case '>':
        return LEFT;
        break;
    case '+':
        return ADD;
        break;
    case '-':
        return SUB;
        break;
    case '.':
        return OUT;
        break;
    case ',':
        return IN;
        break;
    case '[':
        return WHILE_START;
        break;
    case ']':
        return WHILE_END;
        break;
    default:
        return NIL;
        break;
    }
}