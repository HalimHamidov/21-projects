/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:54:07 by apearl            #+#    #+#             */
/*   Updated: 2019/09/18 22:54:11 by apearl           ###   ########.fr       */
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
char    *ft_strrchr(const char *s, int c)
{
    char    *ptr;
    char    sym;
    
    ptr = (char *)s + ft_strlen(s);
    sym = (char)c;
    while (ptr >= s)
    {
        if (*ptr == sym)
            return (ptr);
        ptr--;
    }
    return (NULL);
}

int main (void)
{
    char str [11]="0163456769";
    int ch = '6';
    char *ach;
    ach=ft_strrchr(str,ch);
    if (ach==NULL)
        printf ("Символ в строке не найден\n");
    else
        printf("Искомый символ в строке на позиции # %ld\n",ach-str+1);//тут ми имеем дело с адресом  пойнтеров и их   вычитинаием . и прибавляем 1 так как нам нужен порядковый номер
    return 0;
}
/*
 
 strrchr – поиск последнего вхождения символа в строку.
 Синтаксис:
 
 #include < string.h >
 char *strrchr (const char *str, int ch);
 
 Аргументы:
 
 str – указатель на строку, в которой будет осуществляться поиск.
 ch – код искомого символа.
 
 Возвращаемое значение:
 
 Указатель на искомый символ, если он найден в строке str, иначе NULL.
 
 Описание:
 
 Функция strchr ищет последнее вхождения символа, код которого указан в аргументе ch, в строке, на которую указывает аргумент str.
 
 Пример:
 
 В примере ищется последнее вхождение символа '6' в строке '0163456769’ и на экран выводится его порядковый номер в строке (отчет с единицы).
 
 
 #include < stdio.h >  // Для printf
 #include < string.h > // Для strrchr
 int main (void)
 {
 // Массив со строкой для поиска
 char str [11]=”0163456769”;
 // Код искомого символа
 int ch = '6';
 // Указатель на искомую переменную в строке,
 // по которой осуществляется поиск.
 char *ach;
 
 // Ищем символ ‘6’
 ach=strrchr (src,ch);
 
 // Выводим результат на консоль
 if (ach==NULL)
 printf (“Символ в строке не найден\n”);
 else
 printf (“Искомый символ в строке на позиции # %d\n”,ach-src+1);
 
 return 0;
 }
 Результат:
 
 Вывод в консоль:
 Искомый символ в строке на позиции # 9
 
 
 */
//strrchr # locates last occurence of c within s. null character is part of string. Return pointer to character or NULL.
