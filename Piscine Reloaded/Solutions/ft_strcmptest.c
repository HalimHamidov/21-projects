#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i]) //If any of the two operands is non-zero, then the condition becomes true.  
	{
		if (s1[i] != s2[i]) //If the values are not equal, then the condition becomes true. 
            return ((unsigned char)s1[i]-(unsigned char)s2[i]); /* man strcmp The strcmp() and strncmp() functions return an integer greater than,
        equal to, or less than 0, according as the string s1 is greater than,
        equal to, or less than the string s2.  The comparison is done using
        unsigned characters, so that `\200' is greater than `\0'.*/
		i++;
	}
	return (0);
}

/*
int    ft_strcmp(char *s1, char *s2)
{
    int    i;
    
    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        ++i;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
*/

/*
int        ft_strcmp(char *s1, char *s2)
{
    int i;
    
    i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}
*/

//https://www.tutorialspoint.com/cprogramming/c_operators.htm


 
int main(void)
{
printf("%lu", strlen("Halim"));
printf("\n");
printf("%d", strcmp("Halimjon", "Halimjon"));
printf("\n");
printf("%d", ft_strcmp("Halimon", "Halimi"));
return (0);
    printf("\n");
}
