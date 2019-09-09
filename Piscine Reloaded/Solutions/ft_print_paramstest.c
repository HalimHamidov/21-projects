#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int main (int argcm char *argv[])
{
    int i;
    
    i = 1;
    while (argc > i) // when there are a lot of arguments we count them one by one till the end
    {
        while (*argv[i]) // while the string reaches the end of the sentence we continue
            ft_putchar(*argv[i]++); // write the characters of the first string one by one
        i++;
        ft_putchar('\n'); // new line
    }
    return (0);
}
