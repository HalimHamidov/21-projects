/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 03:18:18 by apearl            #+#    #+#             */
/*   Updated: 2019/09/15 03:20:17 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POINT_H
# define FT_POINT_H

typedef struct	
{
int x;
int y;
}				t_point;

#endif
/*
 #include <stdio.h>
 #include "ft_point.h"
 
 void    set_point(t_point *point)
 {
 point->x = 42;
 point->y = 21;
 }
 
 int    main(void)
 {
 int x, y;
 t_point    point;
 
 set_point(&point);
 printf("%d, %d", point.x, point.y);
 return (0);
 }
*/
