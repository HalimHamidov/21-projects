/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:47:13 by apearl            #+#    #+#             */
/*   Updated: 2019/09/17 21:49:21 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ft_lstadd
// Prototype
// void ft_lstadd(t_list**alst,t_list*new);
// Description
// Adds the element new at the beginning of the list.
// Param. #1
// The address of a pointer to the first link of a list.
// Param. #2
// The link to add at the beginning of the list.
// Return value
// None.
// Libc functions
// None.

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct        s_list
{
    void            *content;
    size_t            content_size;
    struct s_list    *next;
}                    t_list;

void    ft_print_result(t_list *elem)
{
    int        len;
    
    len = 0;
    while (((char *)elem->content)[len])
        len++;
    write(1, elem->content, len);
    write(1, "\n", 1);
}

t_list    *ft_lstnew(void const *content, size_t content_size)
{
    t_list    *elem;
    
    elem = (t_list *)malloc(sizeof(t_list));
    if (!elem)
        return (NULL);
    if (!content)
    {
        elem->content = NULL;
        elem->content_size = 0;
    }
    else
    {
        if (!(elem->content = malloc(sizeof(*(elem->content)) * content_size)))
            return (NULL);
        elem->content = memcpy(elem->content, content, content_size);
        elem->content_size = content_size;
    }
    elem->next = NULL;
    return (elem);
}

void    ft_lstadd(t_list **alst, t_list *new)
{
    if (alst)
    {
        if (new)
            new->next = *alst;
        *alst = new;
    }
}

int main()
{
    t_list        *begin;
    t_list        *elem;
    t_list        *elem2;
    t_list        *elem3;
    t_list        *elem4;
    
    char        str [] = "lorem";
    char        str2 [] = "ipsum";
    char        str3 [] = "dolor";
    char        str4 [] = "sit";
    
    elem = ft_lstnew(str, sizeof(str));
    elem2 = ft_lstnew(str2, sizeof(str2));
    elem3 = ft_lstnew(str3, sizeof(str3));
    elem4 = ft_lstnew(str4, sizeof(str4));
    
    begin = NULL;
    ft_lstadd(&begin, elem4);
    ft_lstadd(&begin, elem3);
    ft_lstadd(&begin, elem2);
    ft_lstadd(&begin, elem);
    while (begin)
    {
        ft_print_result(begin);
        begin = begin->next;
    }
    
    return (0);
}

// //#include "libft.h"

// /*In this function we will be adding a new link, called 'new' that is passed
//  * in our parameters, to a list and placing this link at the head of our list.*/

// void        ft_lstadd(t_list **alst, t_list *new)
// {
//     /*First we check to make sure the link new that is passed to our parameters
//      * is NULL. If it is not, we set our link new's element next to the first
//      * link that is pointed to by alst in our parameters. We then set the
//      * pointer of alst to new, thus setting it to the head of our linked list.*/
//     if (new != NULL)
//     {
//         new->next = *alst;
//         *alst = new;
//     }
// }
