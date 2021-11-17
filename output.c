    #include<stdio.h>
    int arr[30000] = {0};
    typedef int cell_t;
    static cell_t cells[30000] = {0};
    static cell_t *ptr = cells;
    
int main(void)
{
    *ptr += 1;
*ptr = (cell_t)getchar();
*ptr -= 3;
return 0;
}