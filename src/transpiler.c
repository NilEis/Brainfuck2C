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
        i++;
        switch (ch)
        {
        case '<':
            current_token = RIGHT;
            printf("token: RIGHT\n");
            break;
        case '>':
            current_token = LEFT;
            printf("token: LEFT\n");
            break;
        case '+':
            current_token = ADD;
            printf("token: ADD\n");
            break;
        case '-':
            current_token = SUB;
            printf("token: SUB\n");
            break;
        case '.':
            current_token = OUT;
            printf("token: OUT\n");
            break;
        case ',':
            current_token = IN;
            printf("token: IN\n");
            break;
        case '[':
            current_token = WHILE_START;
            printf("token: WHILE_START\n");
            break;
        case ']':
            current_token = WHILE_END;
            printf("token: WHILE_END\n");
            break;
        default:
            break;
        }
        if ((last_token == NIL || current_token == last_token) && (current_token != IN || current_token != OUT || current_token != WHILE_START || current_token != WHILE_END))
        {
            i++;
            last_token = current_token;
        }
        else
        {
            switch (current_token)
            {
            case RIGHT:
                fprintf(f, "ptr += %d;\n", i);
                break;
            case LEFT:
                fprintf(f, "*ptr -= %d;\n", i);
                break;
            case ADD:
                fprintf(f, "*ptr += %d;\n", i);
                break;
            case SUB:
                fprintf(f, "*ptr -= %d;\n", i);
                break;
            case OUT:
                fprintf(f, "putchar(*ptr);\n");
                break;
            case IN:
                fprintf(f, "*ptr = (cell_t)getchar();\n");
                break;
            case WHILE_START:
                fprintf(f, "while (*ptr)\n{\n");
            case WHILE_END:
                fprintf(f, "}\n");
                break;
            }
            i = 0;
            last_token = NIL;
            current_token = NIL;
        }
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