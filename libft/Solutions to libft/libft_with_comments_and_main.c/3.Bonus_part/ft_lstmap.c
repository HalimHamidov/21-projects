/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:56:31 by apearl            #+#    #+#             */
/*   Updated: 2019/09/17 21:56:36 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct        s_list
{
    void            *content;
    size_t            content_size;
    struct s_list    *next;
}                    t_list;
void    ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void    ft_bzero(void *s, size_t n);
t_list    *ft_lstnew(void const *content, size_t content_size);
void    *ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t            i;
    
    if (!src && !dst)
        return (dst);
    i = -1;
    while (++i < n)
        ((unsigned char *)dst)[i] = ((unsigned char*)src)[i];
    return (dst);
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

void    ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
    if (alst && *alst && del)
    {
        if ((*alst)->next)
            ft_lstdel(&(*alst)->next, del);
        ft_lstdelone(&(*alst), del);
    }
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
t_list    *ft_lstnew(void const *content, size_t content_size)
{
    t_list *res;
    
    if ((res = (t_list *)ft_memalloc(sizeof(t_list))))
    {
        if (!content)
        {
            res->content = NULL;
            res->content_size = 0;
        }
        else
        {
            if (!(res->content = ft_memalloc(content_size)))
            {
                free(res);
                return (NULL);
            }
            ft_memcpy(res->content, content, content_size);
            res->content_size = content_size;
        }
        res->next = NULL;
    }
    return (res);
}
static void    ft_del(void *content, size_t content_size)
{
    (void)content_size;
    free(content);
}

t_list        *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
    t_list *elem;
    t_list *prev;
    t_list *head;
    
    prev = NULL;
    head = NULL;
    if (f)
        while (lst)
        {
            if (!(elem = f(lst)))
            {
                if (head)
                    ft_lstdel(&head, &ft_del);
                return (NULL);
            }
            if (prev)
                prev->next = elem;
            else
                head = elem;
            lst = lst->next;
            prev = elem;
        }
    return (head);
}

void    ft_print_result(t_list *elem)
{
    int        len;
    
    len = 0;
    while (((char *)elem->content)[len])
        len++;
    write(1, elem->content, len);
    write(1, "\n", 1);
}

t_list    *ft_map(t_list *elem)
{
    int        i;
    t_list    *new_elem;
    
    new_elem = ft_lstnew(elem->content, elem->content_size);
    if (!new_elem)
        return (0);
    i = 0;
    while (((char *)new_elem->content)[i])
    {
        ((char *)new_elem->content)[i] = 'y';
        i++;
    }
    return (new_elem);
}
int main()
{
    t_list        *elem;
    t_list        *elem2;
    t_list        *elem3;
    t_list        *elem4;
    t_list        *list;
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
    
    if (!(list = ft_lstmap(elem, &ft_map)))
        return (0);
    if (list == elem)
        write(1, "A new list is not returned\n", 27);
    while (list)
    {
        ft_print_result(list);
        list = list->next;
    }
    ft_print_result(elem);
    ft_print_result(elem2);
    ft_print_result(elem3);
    ft_print_result(elem4);
    
    return (0);
}

/*
 ft_lstmap
 Prototype
 t_list * ft_lstmap(t_list *lst, t_list * (*f)(t_list *elem));
 Description
 Iterates a list lst and applies the function f to each link to create a “fresh” list (using malloc(3)) resulting from the suc- cessive applications of f. If the allocation fails, the function returns NULL.
 Param. #1
 A pointer’s to the first link of a list.
 Param. #2
 The address of a function to apply to each link of a list.
 Return value
 The new list.
 Libc functions
 malloc(3), free(3).
 */


// Recursively
// #include "libft.h"

// /*This function takes the list of lst passed in the parameter and applies to
//  * each link the function f (also passed in the parameter) and creates and
//  * returns a "fresh" list. This results in successive applications of the
//  * function recursively until the end of the list is reached and the newlist
//  * is returned.*/

// t_list        *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
// {
//     /*First we create a new t_list structure variable newlist*/
//     t_list *newlist;
//     /*We then make sure that both the list passed as well as the function f are
//      *not NULL. If they are we will return NULL. If not we will run the function
//      f on the link lst and set it into our newlist link variable. NOTE: We are
//      to assume that the function f allocates memory for our newlist variable
//      based on the data of lst. We then check if newlist is null as well as if
//      the link lst's element next is NULL. If neither are NULL we set our newlist
//      element next equal to the ft_lstmap function which has been passed lst's
//      element next (the link following it) as well as the function f. This allows
//      us to recursively apply the function f to all of the links and allows us to
//      allocate memory based on how many indiviual links we have in our list. Once
//      lst->next becomes equal to NULL this will break us out of the recursion and
//      have us return the newlist.*/
//     if (lst != NULL && f != NULL)
//     {
//         newlist = f(lst);
//         if (newlist != NULL && lst->next != NULL)
//             newlist->next = ft_lstmap(lst->next, f);
//         return (newlist);
//     }
//     return (NULL);
// }
//better to track it on https://www.onlinegdb.com/

// Visualize it on http://www.pythontutor.com/visualize.html#mode=edit
// #include <stdlib.h>
// #include <unistd.h>
// #include <string.h>

// typedef struct        s_list
// {
//     void            *content;
//     size_t            content_size;
//     struct s_list    *next;
// }                    t_list;

// void    ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
// {
//     if (alst && *alst && del)
//     {
//         del((*alst)->content, (*alst)->content_size);
//         free(*alst);
//         *alst = NULL;
//     }
// }

// void    ft_lstdel(t_list **alst, void (*del)(void *, size_t))
// {
//     if (alst && *alst && del)
//     {
//         if ((*alst)->next)
//             ft_lstdel(&(*alst)->next, del);
//         ft_lstdelone(&(*alst), del);
//     }
// }

// t_list    *ft_lstnew(void const *content, size_t content_size)
// {
//     t_list *res;

//     if ((res = (t_list *)malloc(sizeof(t_list))))
//     {
//         if (!content)
//         {
//             res->content = NULL;
//             res->content_size = 0;
//         }
//         else
//         {
//             if (!(res->content = malloc(content_size)))
//             {
//                 free(res);
//                 return (NULL);
//             }
//             memcpy(res->content, content, content_size);
//             res->content_size = content_size;
//         }
//         res->next = NULL;
//     }
//     return (res);
// }

// static void    ft_del(void *content, size_t content_size)
// {
//     (void)content_size;
//     free(content);
// }

// void    ft_print_result(t_list *elem)
// {
//     int        len;

//     len = 0;
//     while (((char *)elem->content)[len])
//         len++;
//     write(1, elem->content, len);
//     write(1, "\n", 1);
// }

// t_list    *ft_map(t_list *elem)
// {
//     int        i;
//     t_list    *new_elem;

//     new_elem = ft_lstnew(elem->content, elem->content_size);
//     if (!new_elem)
//         return (0);
//     i = 0;
//     while (((char *)new_elem->content)[i])
//     {
//         ((char *)new_elem->content)[i] = 'y';
//         i++;
//     }
//     return (new_elem);
// }

// t_list        *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
// {
//     t_list *elem;
//     t_list *prev;
//     t_list *head;

//     prev = NULL;
//     head = NULL;
//     if (f)
//         while (lst)
//         {
//             if (!(elem = f(lst)))
//             {
//                 if (head)
//                     ft_lstdel(&head, &ft_del);
//                 return (NULL);
//             }
//             if (prev)
//                 prev->next = elem;
//             else
//                 head = elem;
//             lst = lst->next;
//             prev = elem;
//         }
//     return (head);
// }

// int main()
// {
//     t_list        *elem;
//     t_list        *elem2;
//     t_list        *elem3;
//     t_list        *elem4;
//     t_list        *list;
//     char        str [] = "lorem";
//     char        str2 [] = "ips";
//     // char        str3 [] = "dolor";
//     // char        str4 [] = "sit";
//     elem = ft_lstnew(str, sizeof(str));
//     elem2 = ft_lstnew(str2, sizeof(str2));
//     // elem3 = ft_lstnew(str3, sizeof(str3));
//     // elem4 = ft_lstnew(str4, sizeof(str4));
//     elem->next = elem2;
//     elem2->next = NULL;
//  //   elem3->next = elem4;
//         if (!(list = ft_lstmap(elem, &ft_map)))
//             return (0);
//         if (list == elem)
//             write(1, "A new list is not returned\n", 27);
//         while (list)
//         {
//             ft_print_result(list);
//             list = list->next;
//         }
//             ft_print_result(elem);
//             ft_print_result(elem2);
//             // ft_print_result(elem3);
//             // ft_print_result(elem4);
//       return (0);
// }
