/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:15:26 by apearl            #+#    #+#             */
/*   Updated: 2019/09/19 01:08:42 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 #include <stdio.h>
 #include <string.h>
 
 char    *ft_strcpy(char *dst, const char *src)
 {
 size_t i;
 
 i = 0;
 while (src[i] != '\0')
 {
 dst[i] = src[i];
 i++;
 }
 dst[i] = '\0';
 return (dst);
 }
 int main (void)
 {
 // Массив источник данных
 char src[1024]="first string\0 second string";
 // Массив приемник данных
 char dst[100]="";
 // Копируем строку из массива src в массив dst. Обратите внимание,
 //что скопируется только строка «первая строка\0».
 ft_strcpy(dst, src);
 //ft_strcpy(dst, "lorem");
 // Вывод массива src на консоль
 printf("src: %s %s\n",src, &src[14]);
 // Вывод массива dst на консоль
 printf("dst: %s %s\n",dst, &dst[14]);
 return 0;
 }
 
 strcpy – копирование строк.
 Синтаксис:
 
 #include < string.h >
 char *strcpy (char *destination, const char *source);
 
 Аргументы:
 
 destination – указатель на строку, в которую будут скопированы данные.
 source – указатель на строку источник копируемых данных.
 
 Возвращаемое значение:
 
 Функция возвращает указатель на строку, в которую скопированы данные.
 
 Описание:
 
 Функция strcpy копирует данные из строки, на которую указывает аргумент source, в строку, на которую указывает аргумент destination, пока не встретится символ конца строки (нулевой символ). Копирование производится вместе с символом конца строки.
 
 Если строки перекрываются, результат копирования будет не определен.
 
 Пример:
 
 В примере создается массив src, содержащий строку «первая строка» и строку «вторая строка», и пустой массив dst. Затем из массива src копируется одна строка в массив dst. Затем массивы src и dst выводятся на консоль.
 
 
 #include < stdio.h >  // Для printf
 #include < string.h > // Для strcpy
 int main (void)
 {
 // Массив источник данных
 char src[1024]=”первая строка\0вторая строка”;
 
 // Массив приемник данных
 char dst[1024]=””;
 
 // Копируем строку из массива src в массив dst. Обратите внимание,
 //что скопируется только строка «первая строка\0».
 strcpy (dst, src);
 
 // Вывод массива src на консоль
 printf (“src: %s %s\n”,src, &src[14]);
 
 // Вывод массива dst на консоль
 printf (“dst: %s %s\n”,dst, &dst[14]);
 
 return 0;
 }
 Результат:
 
 Вывод в консоль:
 src: первая строка вторая строка
 dst: первая строка
 */


#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void    ft_pc(char c)
{
    write(1, &c, 1);
}



void    ft_putstr(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    write(1, s, 15);
}

void ft_putendl(char *s)
{
    ft_putstr(s);
    ft_pc('\n');
}

char    *ft_strcpy(char *dst, const char *src)
{
    size_t i;
    
    i = 0;
    
    while (src[i] != '\0')
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}
int main (void)
{
    // Массив источник данных
    //char src[1024]="first string\0 second string";
    // Массив приемник данных
    char *dest;
    if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
        return (0);
    //memset(dest, 0, 15);
    memset(dest, 'f', 9); //"fffffffff000000" -> "lorem0fff000000" "skdjgbwgn24nogW"
    // Копируем строку из массива src в массив dst. Обратите внимание,
    //что скопируется только строка «первая строка\0».
    //strcpy(dst, src);
    ft_strcpy(dest, "lorem");
    ft_putendl(dest);
    
    
    char *dest2 = (char *)malloc(sizeof(char) * 15);
    memset(dest2, 'f', 9);
    ft_strcpy(dest2, "lorem ipsum");
    ft_putendl(dest2);
    
    
    char *dest3 = (char *)malloc(sizeof(char) * 15);
    memset(dest3, 'f', 9);
    ft_strcpy(dest3, "");
    ft_putendl(dest3);
    
    free(dest);
    free(dest2);
    free(dest3);
    // Вывод массива src на консоль
    //printf("src: %s %s\n",src, &src[14]);
    // Вывод массива dst на консоль
    //printf("dst: %s %s\n",dst, &dst[100]);
    return 0;
}
