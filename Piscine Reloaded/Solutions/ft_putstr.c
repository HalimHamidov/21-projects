#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)// string pointer inside the condition of while the a set of characters in an array  reaches the end of the string/ str[] is an substiture here but we should include str[i] here
		ft_putchar(*str++); //we increment the strings characters one by one ,
/*
 {
 int i;
 
 i = 0;
 while (str[i] != '\0')
 {
 ft_putchar(str[i]);
 i++'
 }
 }
*/

}

int main(void)
{
	ft_putstr("Halim Hamidov is a hacker!");
	return (0);
}

