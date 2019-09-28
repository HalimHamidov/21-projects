/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 06:58:53 by apearl            #+#    #+#             */
/*   Updated: 2019/09/19 06:58:57 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

int main (void)
{
    // Массив со строкой для поиска
    char str1[]="lorem ipsum dolor sit amet";
    char str2[]="lorem";
    char *istr;
    istr = ft_strstr(str1,str2);
    if (istr == NULL)
        printf ("Строка не найдена\n");
    else
        printf("Искомая строка начинается с символа %ld\n",istr-str1+1);
    printf("1-%s\n", istr);
    printf("2-%s\n", ft_strstr("lorem ipsum dolor sit amet","ipsum"));
    printf("3-%s\n", ft_strstr("lorem ipsum dolor sit lorem ipsum dolor","ipsum"));
    printf("4-%s\n", ft_strstr("lorem ipsum dolor sit amet",""));
    printf("5-%s\n", ft_strstr("lorem ipsum dolor sit amet","ipsumm"));
    printf("6-%s\n", ft_strstr("lorem ipsum dolor sit amet","dol"));
    printf("7-%s\n", ft_strstr("lorem ipsum dolor sit amet","consectetur"));
    return 0;
}


/*
 strstr – поиск первого вхождения строки А в строку В.
 Синтаксис:
 
 #include < string.h >
 char *strstr(const char *strB, const char *strA);
 
 Аргументы:
 
 strB – указатель на строку, в которой ведется поиск.
 strA – указатель на искомую строку.
 
 Возвращаемое значение:
 
 NULL – если строка strA не входит в строку strB. Указатель на первое вхождение строки strA в строку strB.
 
 Описание:
 
 Функция strstr ищет первое вхождение строки (за исключением признак конца строки), на которую указывает аргумент strA, в строку , на которую указывает аргумент strB. Если строка strA имеет нулевую длину, то функция вернет указатель на начало строки strB.
 
 Пример:
 
 В примере, в строке «0123456789», с помощью функции strstr, ищется первое вхождение строки: «345». На консоль выводится номер первого элемента найденной строки.
 
 
 #include < stdio.h >  // Для printf
 #include < string.h > // Для strstr
 int main (void)
 {
 // Массив со строкой для поиска
 char str1 [11]=”0123456789”;
 // Набор символов, которые должны входить в искомый сегмент
 char str2 [10]=”345”;
 // Переменная, в которую будет занесен адрес первой найденной строки
 char *istr;
 
 //Поиск строки
 istr = strstr (str1,str2);
 
 //Вывод результата поиска на консоль
 if ( istr == NULL)
 printf (“Строка не найдена\n“);
 else
 printf (“Искомая строка начинается с символа %d\n“,istr-str1+1);
 
 return 0;
 }
 Результат:
 
 Вывод в консоль:
 Искомая строка начинается с символа 4
 
 */
//strstr # locates first occurence of s2 in s1. Returns s1 if s2 is empty, NULL if no match, else pointer to first occurence.
