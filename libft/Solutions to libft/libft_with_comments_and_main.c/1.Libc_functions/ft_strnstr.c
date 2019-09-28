/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 07:01:49 by apearl            #+#    #+#             */
/*   Updated: 2019/09/19 07:01:53 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t    ft_strlen(const char *s)
{
    size_t i;
    
    i = 0;
    while (s[i])
        i++;
    return (i);
}

char    *ft_strnstr(const char *hay, const char *need, size_t len)
{
    size_t    i;
    size_t    j;
    char    *s1;
    char    *s2;
    size_t    n;
    
    i = 0;
    j = 0;
    s1 = (char*)hay;
    s2 = (char*)need;
    n = ft_strlen(s2);
    if (s2[j] == 0)
        return (&s1[i]);
    while (s1[i] != 0 && n <= len--)
    {
        j = 0;
        while (s2[j] == s1[i + j])
        {
            if (s2[j + 1] == '\0')
                return (&s1[i]);
            j++;
        }
        i++;
    }
    return (NULL);
}

int main (void)
{
    // Массив со строкой для поиска
    char str1[]="lorem ipsum dolor sit amet";
    char str2[]="lorem";
    char *istr;
    istr = ft_strnstr(str1,str2,15);
    if (istr == NULL)
        printf ("Строка не найдена\n");
    else
        printf("Искомая строка начинается с символа %ld\n",istr-str1+1);
    printf("1-%s\n", istr);
    printf("2-%s\n", ft_strnstr("lorem ipsum dolor sit amet","ipsum",15));
    printf("3-%s\n", ft_strnstr("lorem ipsum dolor sit lorem ipsum dolor","ipsum",35));
    printf("4-%s\n", ft_strnstr("lorem ipsum dolor sit amet","",10));
    printf("5-%s\n", ft_strnstr("lorem ipsum dolor sit amet","ipsumm",30));
    printf("6-%s\n", ft_strnstr("lorem ipsum dolor sit amet","dol",30));
    printf("7-%s\n", ft_strnstr("lorem ipsum dolor sit amet","consectetur",30));
    printf("8-%s\n", ft_strnstr("lorem ipsum dolor sit amet","sit",10));
    printf("9-%s\n", ft_strnstr("lorem ipsum dolor sit amet","consectetur",15));
    printf("10-%s\n", ft_strnstr("lorem ipsum dolor sit amet","consectetur",0));
    return 0;
}
//strnstr # same as strstr where search is limited to n characters of s1.

/*strstr
 char        *ft_strstr(const char *haystack, const char *needle)
 {
 unsigned int    i;
 unsigned int    j;
 
 i = 0;
 if (haystack[0] == '\0' && needle[0] == '\0')
 return ((char *)haystack);
 while (haystack[i] != '\0')
 {
 j = 0;
 while (needle[j] != '\0' && haystack[i + j] == needle[j])
 j++;
 if (needle[j] == '\0')
 return ((char *)haystack + i);
 i++;
 }
 return (NULL);
 }
 */
