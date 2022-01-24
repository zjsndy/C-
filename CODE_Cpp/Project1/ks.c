#include <stdio.h> 
#include <string.h>


int main()
{
    int ch = 0;
    while ((ch = getchar() != EOF))
    {
        if (ch < '0' || ch>'9')
            continue;
        else
            putchar(ch);
    }
    return 0;
}