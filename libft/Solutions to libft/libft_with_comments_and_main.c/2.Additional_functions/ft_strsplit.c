/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:55:50 by apearl            #+#    #+#             */
/*   Updated: 2019/09/18 22:57:47 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char    *ft_strncpy(char *dst, const char *src, size_t len)
{
    size_t i;
    
    i = 0;
    while (src[i] && i < len)
    {
        dst[i] = src[i];
        i++;
    }
    while (i < len)
        dst[i++] = '\0';
    return (dst);
}
static int            ft_cntwrd(char const *s, char c)
{
    unsigned int    i;
    int                cntr;
    
    i = 0;
    cntr = 0;
    while (s[i])
    {
        while (s[i] == c)
            i++;
        if (s[i] != '\0')
            cntr++;
        while (s[i] && (s[i] != c))
            i++;
    }
    return (cntr);
}

static char            *ft_strndup(const char *s, size_t n)
{
    char            *str;
    
    str = (char *)malloc(sizeof(char) * n + 1);
    if (str == NULL)
        return (NULL);
    str = ft_strncpy(str, s, n);
    str[n] = '\0';
    return (str);
}

char                **ft_strsplit(char const *s, char c)
{
    int                i;
    int                j;
    int                k;
    char            **tab;
    
    i = 0;
    k = 0;
    if (!s || (!(tab = (char **)malloc(sizeof(char *) *
                                       (ft_cntwrd(s, c)) + 1))))
        return (NULL);
    while (s[i])
    {
        while (s[i] == c)
            i++;
        j = i;
        while (s[i] && s[i] != c)
            i++;
        if (i > j)
        {
            tab[k] = ft_strndup(s + j, i - j);
            k++;
        }
    }
    tab[k] = NULL; //tab[k] == '\0'; in pythontutor viSA
    return (tab);
}
int    main()
{
    char **str = ft_strsplit("*hello*fellow*students*", '*');
    for(int i = 0; i <  3; i++)
        printf("%s\n", str[i]);
    printf("\n");
    char **str1 = ft_strsplit("          ", ' ');
    for(int i = 0; i <  2; i++)
        printf("%s\n", str1[i]);
    printf("\n");
    char **str2 = ft_strsplit("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
    for(int i = 0; i <  12; i++)
        printf("%s\n", str2[i]);
    printf("\n");
    int i = 0;
    char **str3 = ft_strsplit("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');
    while(str3[i] != '\0')
    {
        printf("%s\n", str3[i]);
        i++;
    }
    printf("\n");
    int j = 0;
    char **str4 = ft_strsplit("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i');
    while(str4[j] != '\0')
    {
        printf("%s\n", str4[j]);
        j++;
    }
    printf("\n");
    int k = 0;
    char **str5 = ft_strsplit("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z');
    while(str5[k] != '\0')
    {
        printf("%s\n", str5[k]);
        k++;
    }
    return (0);
}

/*ft_strsplit # takes s divides according to c and returns list of arrays. if no c, list is composed of single array. Return new or NULL.
 
 ft_strsplit
 Prototype
 char ** ft_strsplit(char const *s, char c);
 Description
 Allocates (with malloc(3)) and returns an array of “fresh” strings (all ending with ’\0’, including the array itself) ob- tained by spliting s using the character c as a delimiter. If the allocation fails the function returns NULL. Example : ft_strsplit("*hello*fellow***students*", ’*’) re- turns the array ["hello", "fellow", "students"].
 Param. #1
 The string to split.
 Param. #2
 The delimiter character.
 Return value
 The array of “fresh” strings result of the split.
 Libc functions
 malloc(3), free(3)
 */
