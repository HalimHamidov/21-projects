/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:43:18 by apearl            #+#    #+#             */
/*   Updated: 2019/09/18 22:43:24 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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
int main (void)
{
    // Массив источник данных
    char src[10]="12345\0006789";
    
    // Массивы приемники данных
    char dst1[10]="1111111111";
    char dst2[10]="1111111111";
    
    // Счетчик
    int i;
    
    // Вывод массива src на консоль
    printf ("src:  ");
    for (i=0;i < 10;i++)
        printf (" %2d",(unsigned short) src[i]);
    printf ("\n ");
    
    // Копируем строку длиною не более трех символов из массива src в массив dst1.
    ft_strncpy (dst1, src,3);
    
    // Вывод массива dst1 на консоль
    printf ("dst1: ");
    for (i=0;i<10;i++)
        printf (" %2d",(unsigned short) dst1[i]);
    printf ("\n");
    
    // Копируем строку длиною не более семи символов из массива src в массив dst2.
    ft_strncpy (dst2, src,7);
    
    // Вывод массива dst2 на консоль
    printf ("dst2: ");
    for (i=0;i<10;i++)
        printf (" %2d",(unsigned short) dst2[i]);
    printf ("\n");
    
    return 0;
}
/*
 strncpy – копирование строк c ограничением длины.
 Синтаксис:
 
 #include < string.h >
 char *strncpy (char *destination, const char *source, size_t n);
 
 Аргументы:
 
 destination – указатель на строку в которую будут скопированы данные.
 source – указатель на строку источник копируемых данных.
 n – ограничение длинны копирования
 
 Возвращаемое значение:
 
 Функция возвращает указатель на строку, в которую скопированы данные.
 
 Описание:
 
 Функция strncpy копирует данные из строки, на которую указывает аргумент source, в строку на который указывает аргумент destination, пока не встретится символ конца строки (нулевой символ) или количество скопированных символов не достигнет величины указанной в аргументе n. При этом символ конца строки не копируется.
 
 Если в аргументе n указана величина большая, чем длинна строки, т.е. символ конца строки '\000' встретился раньше, чем было скопировано n символов, то в массив, на который указывает аргумент destination, дозаписывается столько нулевых символов, чтобы общая длина записанной строки достигла величины указанной в аргументе n.
 
 Если строки перекрываются, результат копирования будет не определен.
 
 Пример:
 
 В примере создается массив src, содержащий строку «12345» и «6789», и массивы dst1 и dst2, содержащие строки «1111111111». Затем в массив dst1 копируется с помощью функции strncpy строка из массива src, но длинной не более чем 3 символа. А в массив dst2 копируется строка из массива src, но длиной не более чем 7 символа.
 
 Коды символов содержащихся в массивах src, dst1 и dst2 выводятся на консоль.
 
 Обратите внимание, что при первом копировании не добавляется символ конца строки. А при втором копировании копируется пять символов из массива src, а шестой и седьмой символы массива dst2 обнуляются.
 
 
 #include < stdio.h >  // Для printf
 #include < string.h > // Для strncpy
 int main (void)
 {
 // Массив источник данных
 char src[10]=”12345\0006789”;
 
 // Массивы приемники данных
 char dst1[10]=”1111111111”;
 char dst2[10]=”1111111111”;
 
 // Счетчик
 int i;
 
 // Вывод массива src на консоль
 printf (“src:  ”);
 for (i=0;i < 10;i++)
 printf (“ %2d”,(unsigned short) src[i]);
 printf (“\n ”);
 
 // Копируем строку длиною не более трех символов из массива src в массив dst1.
 strncpy (dst1, src,3);
 
 // Вывод массива dst1 на консоль
 printf (“dst1: ”);
 for (i=0;i<10;i++)
 printf (“ %2d”,(unsigned short) dst1[i]);
 printf (“\n”);
 
 // Копируем строку длиною не более семи символов из массива src в массив dst2.
 strncpy (dst2, src,7);
 
 // Вывод массива dst2 на консоль
 printf (“dst2: ”);
 for (i=0;i<10;i++)
 printf (“ %2d”,(unsigned short) dst2[i]);
 printf (“\n”);
 
 return 0;
 }
 Результат:
 
 Вывод в консоль:
 src:  49 50 51 52 53 0  54 55 56 57
 dst1: 49 50 51 49 49 49 49 49 49 49
 dst2: 49 50 51 52 53 0  0  49 49 49
 */
//http://all-ht.ru/inf/prog/c/func/strncpy.html

// strcpy # copies s2 into s1 (including terminating '\0'). Returns s1.
// strncpy # copies n characters from s2 into s1. if s2 < s1, remainder of s1 is filled with '\0'. else s1 is not terminated. Returns s1.
