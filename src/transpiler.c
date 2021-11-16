#include "include/transpiler.h"
#include "include/terminal.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LOOP 50

typedef int cell_t;

static cell_t cells[30000] = {0};

static const size_t cells_size = sizeof(cells);

static cell_t *ptr = cells;

static const cell_t *ptr_start = cells;

static const cell_t *ptr_end = cells + (cells_size / sizeof(cell_t));

static char *bracket_start[MAX_LOOP];

static int bracket_index = -1;

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
    FILE *f = fopen("output.c","w");
    char last_token = 0;
    while ((ch = *sourcecode) != '\0')
    {
        //printf("Line: %lli - ptr: %d - code: %c - Brackets: %d\n", sourcecode - sourcecode_start, *ptr, ch, bracket_index);
        switch (ch)
        {
        case '<':
                "ptr++";
            break;
        case '>':
                "ptr--";
            break;
        case '+':
            "(*ptr)++";
            break;
        case '-':
            "(*ptr)--";
            break;
        case '.':
            "putchar(*ptr)";
            break;
        case ',':
            "*ptr = (cell_t)getchar()";
            break;
        case '[':
            
        case ']':
            
            break;
        default:
            break;
        }
        sourcecode++;
    }
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