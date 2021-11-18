    #include<stdio.h>
    int arr[30000] = {0};
    typedef int cell_t;
    static cell_t cells[30000] = {0};
    static cell_t *ptr = cells;
    
int main(void)
{
    ptr -= 4;
*ptr += 2;
ptr -= 1;
*ptr += 1;
ptr -= 1;
*ptr += 2;
ptr -= 1;
*ptr += 1;
ptr -= 2;
*ptr += 2;
ptr += 1;
*ptr += 1;
while (*ptr)
{
while (*ptr)
{
ptr -= 1;
while (*ptr)
{
ptr -= 2;
while (*ptr)
{
ptr -= 4;
}
ptr += 4;
while (*ptr)
{
while (*ptr)
{
ptr -= 4;
*ptr += 1;
ptr += 4;
*ptr -= 1;
}
ptr += 4;
}
ptr -= 6;
}
*ptr += 1;
ptr += 1;
}
ptr -= 1;
*ptr -= 1;
ptr -= 2;
*ptr -= 2;
while (*ptr)
{
*ptr += 1;
while (*ptr)
{
*ptr += 3;
ptr += 4;
*ptr -= 2;
}
*ptr += 2;
ptr -= 4;
*ptr -= 2;
}
*ptr += 1;
while (*ptr)
{
ptr -= 4;
}
ptr += 4;
while (*ptr)
{
ptr += 2;
*ptr += 1;
ptr += 1;
*ptr += 1;
ptr += 1;
}
ptr += 2;
while (*ptr)
{
ptr -= 6;
while (*ptr)
{
while (*ptr)
{
ptr += 4;
*ptr += 1;
ptr -= 4;
*ptr -= 1;
}
ptr -= 4;
}
ptr += 8;
while (*ptr)
{
ptr += 4;
}
ptr -= 2;
*ptr -= 1;
while (*ptr)
{
ptr += 2;
*ptr += 1;
ptr -= 2;
*ptr -= 1;
}
*ptr += 1;
ptr += 2;
while (*ptr)
{
*ptr -= 1;
ptr -= 4;
while (*ptr)
{
*ptr -= 1;
while (*ptr)
{
*ptr += 1;
ptr -= 4;
*ptr -= 1;
}
*ptr -= 1;
ptr += 2;
*ptr -= 1;
while (*ptr)
{
ptr -= 4;
*ptr -= 1;
}
*ptr += 2;
ptr -= 2;
*ptr += 1;
while (*ptr)
{
*ptr -= 1;
ptr += 4;
*ptr += 1;
}
*ptr += 1;
ptr -= 4;
}
ptr += 4;
while (*ptr)
{
ptr += 4;
}
}
ptr -= 1;
while (*ptr)
{
*ptr -= 1;
while (*ptr)
{
ptr += 1;
*ptr += 1;
ptr -= 1;
*ptr -= 1;
}
}
*ptr += 1;
ptr += 1;
while (*ptr)
{
*ptr -= 1;
ptr -= 4;
while (*ptr)
{
*ptr -= 1;
while (*ptr)
{
*ptr += 1;
ptr -= 4;
*ptr -= 1;
}
*ptr -= 1;
ptr += 3;
*ptr -= 1;
while (*ptr)
{
ptr -= 4;
*ptr -= 1;
}
*ptr += 2;
ptr -= 3;
*ptr += 1;
while (*ptr)
{
*ptr -= 1;
ptr += 4;
*ptr += 1;
}
*ptr += 1;
ptr -= 4;
}
ptr += 4;
while (*ptr)
{
ptr += 4;
}
}
ptr += 2;
}
ptr -= 3;
*ptr += 1;
while (*ptr)
{
ptr -= 4;
}
*ptr -= 1;
while (*ptr)
{
*ptr += 1;
ptr += 4;
*ptr -= 2;
}
*ptr += 2;
while (*ptr)
{
ptr += 4;
}
ptr -= 3;
*ptr += 1;
while (*ptr)
{
ptr -= 1;
*ptr -= 1;
while (*ptr)
{
ptr -= 2;
while (*ptr)
{
*ptr -= 2;
while (*ptr)
{
*ptr += 2;
ptr -= 2;
*ptr += 1;
ptr -= 2;
*ptr -= 2;
}
*ptr -= 1;
ptr += 1;
while (*ptr)
{
*ptr -= 1;
while (*ptr)
{
*ptr -= 1;
while (*ptr)
{
*ptr += 3;
ptr += 4;
*ptr -= 1;
}
*ptr += 1;
ptr -= 4;
*ptr -= 1;
}
}
*ptr += 2;
ptr -= 1;
*ptr += 1;
while (*ptr)
{
*ptr -= 1;
ptr += 4;
*ptr += 1;
}
*ptr += 2;
ptr -= 2;
*ptr += 1;
ptr -= 2;
}
ptr += 2;
while (*ptr)
{
ptr -= 1;
while (*ptr)
{
ptr += 1;
*ptr -= 1;
ptr += 3;
}
*ptr += 1;
ptr += 1;
}
ptr -= 1;
*ptr -= 1;
ptr -= 3;
}
*ptr += 1;
ptr -= 1;
while (*ptr)
{
ptr -= 4;
}
*ptr -= 1;
while (*ptr)
{
*ptr += 1;
ptr += 4;
*ptr -= 2;
}
*ptr += 2;
ptr += 1;
while (*ptr)
{
while (*ptr)
{
ptr -= 4;
}
ptr += 4;
while (*ptr)
{
*ptr -= 1;
while (*ptr)
{
*ptr += 1;
ptr -= 1;
while (*ptr)
{
ptr += 1;
*ptr -= 1;
ptr -= 1;
*ptr -= 1;
}
*ptr += 2;
ptr += 1;
while (*ptr)
{
while (*ptr)
{
ptr -= 1;
*ptr -= 1;
ptr += 1;
*ptr -= 1;
}
*ptr += 2;
while (*ptr)
{
ptr += 4;
}
*ptr += 1;
ptr -= 2;
*ptr += 1;
ptr -= 2;
*ptr -= 1;
}
*ptr += 2;
ptr += 4;
*ptr -= 1;
}
ptr -= 1;
*ptr -= 1;
while (*ptr)
{
*ptr += 1;
while (*ptr)
{
ptr += 1;
*ptr += 1;
while (*ptr)
{
ptr += 4;
}
ptr -= 1;
}
ptr += 1;
*ptr += 1;
ptr -= 1;
}
*ptr += 1;
ptr += 1;
while (*ptr)
{
*ptr -= 1;
ptr -= 1;
*ptr -= 1;
ptr -= 3;
while (*ptr)
{
*ptr -= 1;
}
}
*ptr += 1;
ptr += 4;
}
}
ptr -= 1;
while (*ptr)
{
ptr += 4;
}
ptr -= 1;
while (*ptr)
{
*ptr -= 1;
while (*ptr)
{
*ptr -= 1;
while (*ptr)
{
*ptr += 5;
while (*ptr)
{
ptr -= 1;
*ptr += 8;
ptr += 1;
*ptr -= 1;
}
ptr -= 1;
*ptr -= 1;
putchar(*ptr);
ptr -= 3;
*ptr -= 1;
while (*ptr)
{
ptr += 3;
*ptr -= 4;
putchar(*ptr);
ptr += 1;
}
ptr += 1;
while (*ptr)
{
ptr += 2;
}
ptr -= 2;
while (*ptr)
{
*ptr -= 1;
}
ptr -= 1;
*ptr -= 1;
ptr -= 2;
*ptr += 1;
while (*ptr)
{
while (*ptr)
{
ptr -= 4;
}
*ptr += 1;
while (*ptr)
{
*ptr -= 1;
while (*ptr)
{
*ptr -= 1;
ptr -= 4;
*ptr += 1;
ptr -= 8;
*ptr -= 1;
while (*ptr)
{
*ptr -= 1;
while (*ptr)
{
*ptr += 3;
ptr += 4;
while (*ptr)
{
*ptr -= 1;
}
}
*ptr += 1;
ptr -= 4;
*ptr -= 1;
}
*ptr += 2;
while (*ptr)
{
ptr += 4;
}
}
*ptr += 1;
ptr += 4;
}
ptr -= 3;
}
*ptr += 1;
ptr += 1;
*ptr += 1;
ptr += 2;
}
ptr -= 1;
while (*ptr)
{
*ptr -= 1;
while (*ptr)
{
*ptr -= 1;
ptr -= 1;
while (*ptr)
{
*ptr -= 2;
while (*ptr)
{
*ptr += 2;
ptr -= 4;
*ptr -= 2;
}
*ptr -= 1;
ptr -= 1;
while (*ptr)
{
*ptr -= 1;
while (*ptr)
{
*ptr -= 1;
while (*ptr)
{
*ptr += 3;
ptr += 4;
*ptr -= 1;
}
*ptr += 1;
ptr -= 4;
*ptr -= 1;
}
}
*ptr += 2;
ptr += 1;
*ptr += 1;
while (*ptr)
{
*ptr -= 1;
ptr += 4;
*ptr += 1;
}
*ptr += 2;
ptr -= 4;
}
ptr += 4;
while (*ptr)
{
ptr -= 1;
while (*ptr)
{
ptr += 4;
}
*ptr += 1;
ptr += 1;
}
ptr -= 1;
*ptr -= 1;
ptr -= 2;
}
ptr += 1;
}
ptr -= 4;
while (*ptr)
{
*ptr -= 2;
while (*ptr)
{
*ptr += 2;
ptr -= 4;
*ptr -= 2;
}
*ptr -= 1;
ptr += 1;
*ptr -= 2;
while (*ptr)
{
*ptr += 3;
ptr -= 4;
*ptr -= 2;
}
*ptr += 1;
ptr -= 1;
*ptr += 1;
while (*ptr)
{
*ptr -= 1;
ptr += 4;
*ptr += 1;
}
*ptr += 2;
ptr -= 4;
}
ptr += 5;
while (*ptr)
{
ptr += 4;
}
ptr += 1;
}
ptr -= 1;
while (*ptr)
{
ptr -= 1;
*ptr += 1;
ptr += 2;
*ptr += 2;
ptr += 1;
}
ptr += 1;
}
ptr -= 1;
while (*ptr)
{
*ptr += 1;
ptr -= 1;
while (*ptr)
{
*ptr -= 2;
while (*ptr)
{
*ptr += 2;
ptr -= 4;
*ptr -= 2;
}
*ptr -= 1;
ptr -= 1;
*ptr -= 2;
while (*ptr)
{
*ptr += 3;
ptr -= 4;
*ptr -= 2;
}
*ptr += 1;
ptr += 1;
*ptr += 1;
while (*ptr)
{
*ptr -= 1;
ptr += 4;
*ptr += 1;
}
*ptr += 2;
ptr -= 4;
}
ptr += 3;
while (*ptr)
{
ptr += 4;
}
}
ptr -= 2;
}
ptr -= 1;
}
return 0;
}