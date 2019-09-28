/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:54:33 by apearl            #+#    #+#             */
/*   Updated: 2019/09/17 21:55:07 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ft_lstiter
// Prototype
// void ft_lstiter(t_list*lst,void(*f)(t_list *elem));
// Description
// Iterates the list lst and applies the function f to each link.
// Param. #1
// A pointer to the first link of a list.
// Param. #2
// The address of a function to apply to each link of a list.
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

void    ft_modify_list_with_d(t_list *elem)
{
    int        len;
    
    len = 0;
    while (((char *)elem->content)[len])
    {
        ((char *)elem->content)[len] = 'd';
        len++;
    }
}

void    ft_print_result(t_list *elem)
{
    int        len;
    
    while (elem)
    {
        len = 0;
        while (((char *)elem->content)[len])
            len++;
        write(1, elem->content, len);
        write(1, "\n", 1);
        elem = elem->next;
    }
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

void    ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
    if (f)
        while (lst)
        {
            f(lst);
            lst = lst->next;
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
    
    ft_lstiter(elem, &ft_modify_list_with_d);
    ft_print_result(elem);
    
    return (0);
}


/*
 http://www.pythontutor.com/visualize.html#mode=edit
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
 
 typedef struct        s_list
 {
 char            *content;
 size_t            content_size;
 struct s_list    *next;
 }                    t_list;
 
 void    ft_modify_list_with_d(t_list *elem)
 {
 int        len;
 
 len = 0;
 while (((char *)elem->content)[len])
 {
 ((char *)elem->content)[len] = 'd';
 len++;
 }
 }
 
 void    ft_print_result(t_list *elem)
 {
 int        len;
 
 while (elem)
 {
 len = 0;
 while (((char *)elem->content)[len])
 len++;
 write(1, elem->content, len);
 write(1, "\n", 1);
 elem = elem->next;
 }
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
 if (!(elem->content = (char*)malloc(sizeof(*(elem->content)) * content_size)))
 {
 free(elem);
 return (NULL);
 }
 elem->content = (char*)memcpy(elem->content, content, content_size);
 elem->content_size = content_size;
 }
 elem->next = NULL;
 return (elem);
 }
 
 void    ft_lstiter(t_list *lst, void (*f)(t_list *elem))
 {
 if (f)
 while (lst)
 {
 f(lst);
 lst = lst->next;
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
 
 ft_lstiter(elem, &ft_modify_list_with_d);
 ft_print_result(elem);
 
 return (0);
 }*/
