/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:27:10 by apearl            #+#    #+#             */
/*   Updated: 2019/09/18 20:30:17 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    *ft_memset(void *b, int c, size_t len)
{
    unsigned char *ptr;
    unsigned char sym;
    
    ptr = (unsigned char *)b;
    sym = (unsigned char)c;
    while (len--)
        *ptr++ = sym;
    return (b);
}

int main(void)
{
    printf("---------  test memset ---------\n");
    char array[27] = "avcnbvsbvsjvsn";
    int arrint[5] = {0,1,2,4,5};
    ft_memset(array, 'c',  8);
    printf("%s\n", array);
    unsigned char src[15]="1234567890";
    // Заполняем массив символом ‘1’
    printf ("src: %s\n",src);
    ft_memset(src, '1', 10);
    // Вывод массива src на консоль
    printf ("src: %s\n",src);
    
}
/*
 http://all-ht.ru/inf/prog/c/func/index.html
 SYNOPSIS
 #include <string.h>
 
 void *memset(void *s, int c, size_t n);
 
 DESCRIPTION
 The memset() function fills the first n bytes of the memory area pointed to by s with the constant byte c.
 RETURN VALUE
 The memset() function returns a pointer to the memory area s.
 
 -----
 memset – заполнения массива указанными символами.
 Синтаксис:
 
 #include < string.h >
 void *memset (void *destination, int c, size_t n);
 
 Аргументы:
 
 destination – указатель на заполняемый массив
 с – код символа для заполнения
 n – размер заполняемой части массива в байтах
 Возвращаемое значение:
 
 Функция возвращает указатель на заполняемый массив.
 
 Описание:
 
 Функция memset заполняет первые n байт области памяти, на которую указывает аргумент destination, символом, код которого указывается аргументом c.
 
 Пример:
 
 В примере создается массив src, содержащий строку «123456789», затем первые 10 байт этого массива заполняются символом ‘1’ и массив src выводится на консоль.
 
 
 #include < stdio.h >  //Для printf
 #include < string.h  >   //Для memset
 
 int main (void)
 {
 // Исходный массив
 unsigned char src[15]=”1234567890”;
 
 // Заполняем массив символом ‘1’
 memset (src, ‘1’, 10);
 
 // Вывод массива src на консоль
 printf (“src: %s\n”,src);
 
 return 0;
 }
 Результат:
 
 Вывод в консоль:
 src: 1111111111
 */
