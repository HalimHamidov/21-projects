/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:51:59 by apearl            #+#    #+#             */
/*   Updated: 2019/09/17 21:53:08 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ft_lstdel
// Prototype
// void ft_lstdel(t_list**alst,void(*del)(void*, size_t));
// Description
// Takes as a parameter the adress of a pointer to a link and frees the memory of this link and every successors of that link using the functions del and free(3). Finally the pointer to the link that was just freed must be set to NULL (quite similar to the function ft_memdel from the mandatory part).
// Param. #1
// The address of a pointer to the first link of a list that needs to be freed.
// Return value
// None.
// Libc functions
// free(3)
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct        s_list
{
    void            *content;
    size_t            content_size;
    struct s_list    *next;
}                    t_list;

void    ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
    if (alst && *alst && del)
    {
        del((*alst)->content, (*alst)->content_size);
        free(*alst);
        *alst = NULL;
    }
}

void    ft_print_result(t_list *elem)
{
    int        len;
    
    len = 0;
    while (((char *)elem->content)[len])
        len++;
    write(1, elem->content, len);
}

static int    nb_free_done;

void    ft_del(void *content, size_t size)
{
    (void)size;
    free(content);
    nb_free_done++;
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

void    ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
    if (alst && *alst && del)
    {
        if ((*alst)->next)
            ft_lstdel(&(*alst)->next, del);
        ft_lstdelone(&(*alst), del);
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
    nb_free_done = 0;
    
    ft_lstdel(&elem3, &ft_del);
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
    {
        write(1, "nb_free_done = ", 15);
        nb_free_done += '0';
        write(1, &nb_free_done, 1);
    }
    else
        write(1, "NULL", 4);
    
    return (0);
}
/* //for visualizor http://www.pythontutor.com/visualize.html#mode=edit
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
 
 typedef struct        s_list
 {
 char            *content;
 size_t            content_size;
 struct s_list    *next;
 }                    t_list;
 
 void    ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
 {
 if (alst && *alst && del)
 {
 del((*alst)->content, (*alst)->content_size);
 free(*alst);
 *alst = NULL;
 }
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
 
 void    ft_print_result(t_list *elem)
 {
 int        len;
 
 len = 0;
 while (((char *)elem->content)[len])
 len++;
 write(1, elem->content, len);
 }
 
 static int    nb_free_done;
 
 void    ft_del(void *content, size_t size)
 {
 (void)size;
 free(content);
 nb_free_done++;
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
 nb_free_done = 0;
 
 ft_lstdel(&elem3, &ft_del);
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
 {
 write(1, "nb_free_done = ", 15);
 nb_free_done += '0';
 write(1, &nb_free_done, 1);
 }
 else
 write(1, "NULL", 4);
 
 return (0);
 }
 */


// #include "libft.h"

// /*With this function we will be taking in as a parameter the address of a
//  * pointer on a link and freeing the memory of this link and all of the
//  * links following it one after another using the function 'del' that has been
//  * passed in as a parameter as well. We will also be using the function free.
//  * In order to terminate the link, the pointer on the first link, once freed,
//  * should be set to NULL.*/

// void        ft_lstdel(t_list **alst, void (*del)(void *, size_t))
// {
//     /*First we declare two link structures, one will be a temporary place
//      * holder and the other will hold the next link in the list.*/
//     t_list    *tmp;
//     t_list    *next;

//     /*We set our temporary link to hold the link pointed to in our parameter,
//      * alst. We the check to make sure that the function passsed in our
//      * parameter is not NULL.*/
//     tmp = *alst;
//     if (del != NULL)
//     {
//         /*If the del function is not NULL we begin our loop in the process of
//          * deleting our parameter passed link and all the others following it
//          * in the linked list. We do this by saying loop so long as tmp, which
//          * is holding the current link, is not equal to NULL, which would mean
//          * we have reached the end of our list.*/
//         while (tmp != NULL)
//         {
//             /*We take our current link's element next (the link following it)
//              * and place it into our link variable next. Separating it from
//              * the current link. We then run our del function that was passed
//              * in our parameters and give it as parameters our current link's
//              * content element and content_size element. Once those are deleted
//              * we the free the memory that is allocated in our tmp variable.
//              * We then set our next variable, which currently holds the link
//              * that should be following the one we just deleted, and put it
//              * into our tmp variable and start the loop again until we reach
//              * NULL. Thus ending the loop.*/
//             next = tmp->next;
//             del(tmp->content, tmp->content_size);
//             free(tmp);
//             tmp = next;
//         }
//         /*Once our loop is done and everything is deleted we then set the link
//          * alst to NULL. Effectively deleting the parameter passed link and
//          * all of those that were following it.*/
//         *alst = NULL;
//     }
// }


