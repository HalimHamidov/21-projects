#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_is_negative(int a)
{
	if (a < 0)
	{
	ft_putchar('N');
	}
	else
	{
	ft_putchar('P');
	}
}

int main()
{
	ft_is_negative(-9);
	return (0);
}
