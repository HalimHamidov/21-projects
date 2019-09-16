/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apearl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 02:41:21 by apearl            #+#    #+#             */
/*   Updated: 2019/09/15 02:50:28 by apearl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H
# define FT_ABS_H
# define ABS(value) ((value < 0) ? (-value) : (value)) //if (x<0) return -x(-*-=+); else return x;
#endif
/*

#ifndef FT_ABS_H
# define FT_ABS_H
#define ABS(x) ((x < 0) ? (-x) : (x))
#endif


#ifndef FT_ABS_H
# define FT_ABS_H
# define ABS(x) ((x<0)?(-x):(x))
#endif


#ifndef FT_ABS_H
# define FT_ABS_H
# define ABS(Value) ((Value < 0) ? (-Value) : (Value))
#endif

/*
 int abs(int x)
 {
 if (x>=0) return x;
 else return -x;
 }
 int main()
 {
 int x, y;
 
 printf("Type the coordinates of a point in 2-plane, say P = (x,y). First x=");
 scanf("%d", &x);
 printf("Second y=");
 scanf("%d", &y);
 
 printf("The distance of the P point to the x-axis is %d. \n Its distance to the y-axis is %d. \n", abs(y), abs(x));
 
 return 0;
 }
 */
