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
    WH,
    LE,
    NIL
};

char *sourcecode_start = NULL;
char *sourcecode = NULL;

static void interpreter_cleanup(void);

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
    int last_token = -1;
    int current_token = NIL;
    int i = 0;
    while ((ch = *sourcecode) != '\0')
    {
        switch (ch)
        {
        case '<':
            current_token = RIGHT;
            break;
        case '>':
            current_token = LEFT;
            break;
        case '+':
            current_token = ADD;
            break;
        case '-':
            current_token = SUB;
            break;
        case '.':
            current_token = OUT;
            break;
        case ',':
            current_token = IN;
            break;
        case '[':
            current_token = WH;
            break;
        case ']':
            current_token = LE;
            break;
        default:
            break;
        }
        i++;
        if (last_token != -1 && last_token != current_token)
        {
            switch (last_token)
            {
            case RIGHT:
                fprintf(f, "ptr += %d;\n", i - 1);
                break;
            case LEFT:
                fprintf(f, "*ptr -= %d;\n", i - 1);
                break;
            case ADD:
                fprintf(f, "*ptr += %d;\n", i - 1);
                break;
            case SUB:
                fprintf(f, "*ptr -= %d;\n", i - 1);
                break;
            case OUT:
                current_token = NIL;
                fprintf(f, "putchar(*ptr);\n");
                break;
            case IN:
                current_token = NIL;
                fprintf(f, "*ptr = (cell_t)getchar();\n");
                break;
            case WH:
                current_token = NIL;
                fprintf(f, "while (*ptr)\n{\n");
            case LE:
                current_token = NIL;
                fprintf(f, "}\n");
                break;
            }
            i = 0;
        }
        last_token = current_token;
        sourcecode++;
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