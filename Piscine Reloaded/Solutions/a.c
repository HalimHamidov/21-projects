#include <unistd.h>

void ft_putchar(char c);

void ft_alphabet_print()
{
	char c;

	c = 'a';
	while (c <= 'z')
	{
		ft_putchar(c);
		c++;
	}
}
