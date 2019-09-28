/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:56:54 by apearl            #+#    #+#             */
/*   Updated: 2019/09/17 21:58:16 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ft_lstnew
// Prototype
// t_list* ft_lstnew(voidconst*content,size_t content_size);
// Description
// Allocates (with malloc(3)) and returns a “fresh” link. The variables content and content_size of the new link are ini- tialized by copy of the parameters of the function. If the pa- rameter content is nul, the variable content is initialized to NULL and the variable content_size is initialized to 0 even if the parameter content_size isn’t. The variable next is initialized to NULL. If the allocation fails, the function returns NULL.
// Param. #1
// The content to put in the new link.
// Param. #2
// The size of the content of the new link.
// Return value
// The new link.
// Libc functions
// malloc(3), free(3)
// #include <stdlib.h>
// #include <unistd.h>
// #include <string.h>

// typedef struct        s_list
// {
//     void            *content;
//     size_t            content_size;
//     struct s_list    *next;
// }                    t_list;

// void    *ft_memcpy(void *dst, const void *src, size_t n)
// {
//     size_t            i;

//     if (!src && !dst)
//         return (dst);
//     i = -1;
//     while (++i < n)
//         ((unsigned char *)dst)[i] = ((unsigned char*)src)[i];
//     return (dst);
// }

// void    ft_bzero(void *s, size_t n)
// {
//     unsigned char *ptr;

//     ptr = (unsigned char *)s;
//     while (n--)
//         *ptr++ = '\0';
// }

// void    *ft_memalloc(size_t size)
// {
//     void *ptr;

//     if ((ptr = malloc(size)))
//         ft_bzero(ptr, size);
//     return (ptr);
// }



// t_list    *ft_lstnew(void const *content, size_t content_size)
// {
//     t_list *res;

//     if ((res = (t_list *)ft_memalloc(sizeof(t_list))))
//     {
//         if (!content)
//         {
//             res->content = NULL;
//             res->content_size = 0;
//         }
//         else
//         {
//             if (!(res->content = ft_memalloc(content_size)))
//             {
//                 free(res);
//                 return (NULL);
//             }
//             ft_memcpy(res->content, content, content_size);
//             res->content_size = content_size;
//         }
//         res->next = NULL;
//     }
//     return (res);
// }

// void    ft_print_result(char const *s)
// {
//     int        len;

//     len = 0;
//     while (s[len])
//         len++;
//     write(1, s, len);
// }

// void    ft_print_result2(int n)
// {
//     char c;

//     if (n >= 10)
//         ft_print_result2(n / 10);
//     c = n % 10 + '0';
//     write (1, &c, 1);
// }

// int main()
// {
//     t_list        *elem;


//         char    str [] = "lorem ipsum dolor sit";

//         if (!(elem = ft_lstnew(str, (sizeof(str)))))
//                 ft_print_result("NULL");
//         else
//         {
//             if (!(elem->content))
//                 ft_print_result("NULL");
//             else
//             {
//                 ft_print_result(elem->content);
//                 write(1, "\n", 1);
//             }
//                 ft_print_result2(elem->content_size);
//             if (!(elem->next))
//             {
//                 write(1, "\n", 1);
//                 ft_print_result("NULL");
//             }
//         }
// write(1, "\n", 1);
// write(1, "\n", 1);
//         int        i;

//         i = 42;
//         if (!(elem = ft_lstnew(&i, (sizeof(i)))))
//                 ft_print_result("NULL");
//         else
//         {
//             if (!(elem->content))
//                 ft_print_result("NULL");
//             else
//             {
//                 ft_print_result2(*(int *)(elem->content));
//                 write(1, "\n", 1);
//             }
//                 ft_print_result2(elem->content_size);
//             if (!(elem->next))
//             {
//                 write(1, "\n", 1);
//                 ft_print_result("NULL");
//             }
//         }
// write(1, "\n", 1);
// write(1, "\n", 1);
//         if (!(elem = ft_lstnew(NULL, 5)))
//                 ft_print_result("NULL");
//         else
//         {
//             if (!(elem->content))
//             {
//                 ft_print_result("NULL");
//                 write(1, "\n", 1);
//             }
//             else
//             {
//                 ft_print_result(elem->content);
//                 write(1, "\n", 1);
//             }
//                 ft_print_result2(elem->content_size);
//             if (!(elem->next))
//             {
//                 write(1, "\n", 1);
//                 ft_print_result("NULL");
//             }
//         }
//     return (0);
// }

// #include "libft.h"

// /*We will be allocating memory for, and returning, a "fresh" linked list. The
//  * elements content and content_size within our new link will be copied from the
//  * parameters of the function. If the parameter content is NULL the the element
//  * content_size is initialized to 0 regardless of the paramter of content_size.
//  * The element of next is initialized to NULL. If the memory allocation fails
//  * then we will return NULL*/

// t_list            *ft_lstnew(void const *content, size_t content_size)
// {
//     /*We first declare a new t_list structure called 'new'*/
//     t_list        *new;
//     /*We then proceed to allocate the memory required for the stucture to exist*/
//     new = (t_list *)malloc(sizeof(t_list) * 1);
//     /*In the event that the memory allocation failed we return NULL*/
//     if (new == NULL)
//         return (NULL);
//     /*If the parameter of content is NULL we set the content element to NULL
//      * and the content_size element to 0 regardless of the parameter given*/
//     if (content == NULL)
//     {
//         new->content = NULL;
//         new->content_size = 0;
//     }
//     /*If the above is not the case we move on. We allocate memory for our new
//      * linked list's element content by using our parameter of content_size.
//      * If the allocation fails for this we return NULL. If it works we use our
//      * ft_memmove function to move the data from our parameters into our linked
//      * new's content element. And last we set our link new's content_size to
//      * our parameter content_size*/
//     else
//     {
//         new->content = malloc(content_size);
//         if (new->content == NULL)
//             return (NULL);
//         ft_memmove(new->content, content, content_size);
//         new->content_size = content_size;
//     }
//     /*Last we set our new link list new's next element to NULL so that we know
//      * that we are at the end of the list. We then return our new link.*/
//     new->next = NULL;
//     return (new);
// }


//Paste it in and visualize the linked list structure there http://www.pythontutor.com/visualize.html#mode=display

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

void    ft_lstadd(t_list **alst, t_list *new)
{
    if (alst)
    {
        if (new)
            new->next = *alst;
        *alst = new;
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
