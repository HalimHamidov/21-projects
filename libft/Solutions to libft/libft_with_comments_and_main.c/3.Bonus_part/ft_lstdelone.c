/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:53:21 by apearl            #+#    #+#             */
/*   Updated: 2019/09/17 21:53:55 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ft_lstdelone
// Prototype
// void ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
// Description
// Takes as a parameter a link’s pointer address and frees the memory of the link’s content using the function del given as a parameter, then frees the link’s memory using free(3). The memory of next must not be freed under any circumstance. Finally, the pointer to the link that was just freed must be set to NULL (quite similar to the function ft_memdel in the mandatory part).
// Param. #1
// The adress of a pointer to a link that needs to be freed.
// Return value
// None.
// Libc functions
// free(3)
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

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
}

void    ft_del(void *content, size_t size)
{
    (void)size;
    free(content);
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
        {
            free(elem);
            return (NULL);
        }
        elem->content = memcpy(elem->content, content, content_size);
        elem->content_size = content_size;
    }
    elem->next = NULL;
    return (elem);
}

void    ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
    if (alst && *alst && del)
    {
        del((*alst)->content, (*alst)->content_size);
        free(*alst);
        *alst = NULL;
    }
}

int main()
{
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
    
    elem->next = elem2;
    elem2->next = elem3;
    elem3->next = elem4;
    
    ft_lstdelone(&elem, &ft_del);
    if (elem)
        ft_print_result(elem);
    else
        write(1, "NULL", 4);
    write(1, "\n", 1);
    if (elem2)
        ft_print_result(elem2);
    else
        write(1, "NULL", 4);
    write(1, "\n", 1);
    if (elem3)
        ft_print_result(elem3);
    else
        write(1, "NULL", 4);
    write(1, "\n", 1);
    if (elem4)
        ft_print_result(elem4);
    else
        write(1, "NULL", 4);
    
    return (0);
}
// *In this function we are taking in, as a parameter, the address of a pointer on
//  * a link and freeing the memory content of the link with the function 'del'
//  * that has been passed as a parameter as well in order to free the memory of
//  * the link. The memory of the element next should never be freed. In order to
//  * terminate the link, the pointer on the current link should be put to NULL.*/

// #include "libft.h"

// void        ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
// {
//     /*First we check to make sure that the parameters that were passed into our
//      * function are not NULL. If they are not we then run our parameter passed
//      * function del by giving it's parameters our link alst's content and
//      * content_size. Once the function has deleted alst's content we the free
//      * the memory that was allocated to alst and then set it to NULL. Thus
//      * deleting on link in our list.*/
//     if (del != NULL && alst != NULL)
//     {
//         del((**alst).content, (**alst).content_size);
//         free(*alst);
//         *alst = NULL;
//     }
// }
