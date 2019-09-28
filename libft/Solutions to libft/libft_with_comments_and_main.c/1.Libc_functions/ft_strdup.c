/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:16:43 by apearl            #+#    #+#             */
/*   Updated: 2019/09/18 21:16:52 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char    *ft_strnew(size_t size);
void    *ft_memalloc(size_t size);
void    ft_bzero(void *s, size_t n);
size_t    ft_strlen(const char *s);

char    *ft_strdup(const char *s1)
{
    size_t    i;
    char    *result;
    
    if ((result = ft_strnew(ft_strlen(s1))))
    {
        i = 0;
        while (s1[i])
        {
            result[i] = s1[i];
            i++;
        }
        result[i] = '\0';
    }
    return (result);
}

char    *ft_strnew(size_t size)
{
    return ((char *)ft_memalloc(sizeof(char) * (size + 1)));
}

size_t    ft_strlen(const char *s)
{
    size_t i;
    
    i = 0;
    while (s[i])
        i++;
    return (i);
}

void    *ft_memalloc(size_t size)
{
    void *ptr;
    
    if ((ptr = malloc(size)))
        ft_bzero(ptr, size);
    return (ptr);
}
void    ft_bzero(void *s, size_t n)
{
    unsigned char *ptr;
    
    ptr = (unsigned char *)s;
    while (n--)
        *ptr++ = '\0';
}
int main (void)
{
    // Исходная строка
    char str [19]="0123456789аыв";
    // Переменная, в которую будет помещен указатель на дубликат строки
    char *istr;
    // Дублирование строки
    istr = ft_strdup (str);
    // Вывод дубликата на консоль
    printf ("Дубликат: %s\n", istr);
    // Очищаем память, выделенную под дубликат
    free (istr);
    return 0;
}
/*
 strdup – дублирование строк с выделением памяти под новую строку.
 Синтаксис:
 
 #include < string.h >
 char *strdup(const char *str);
 
 Аргументы:
 
 str – указатель на дублируемую строку.
 
 Возвращаемое значение:
 
 NULL – если не удалость выделить память под новую строку или скопировать строку на которую указывает аргумент str.
 Указатель на дублирующую строку.
 
 Описание:
 
 Функция strdup дублирует строку, на которую указывает аргумент str. Память под дубликат строки выделяется с помощью функции malloc, и по окончанию работы с дубликатом должна быть очищена с помощью функции free.
 
 Пример:
 
 В примере строка «0123456789» дублируется с помощью функции strdup и результат выводится на консоль. Перед завершением работы память, выделенная под дубликат строки, очищается.
 
 
 #include < stdio.h >  // Для printf
 #include < string.h > // Для strdup
 #include < stdlib.h > // Для free
 
 int main (void)
 {
 // Исходная строка
 char str [11]=”0123456789”;
 // Переменная, в которую будет помещен указатель на дубликат строки
 char *istr;
 
 // Дублирование строки
 istr = strdup (str);
 
 // Вывод дубликата на консоль
 printf (“Дубликат: %s\n“, istr);
 
 // Очищаем память, выделенную под дубликат
 free (istr);
 
 return 0;
 }
 Результат:
 
 Вывод в консоль:
 Дубликат: 0123456789*/

