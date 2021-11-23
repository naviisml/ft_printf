/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_fill.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: navi <navi@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 14:03:25 by navi          #+#    #+#                 */
/*   Updated: 2021/11/19 22:23:43 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
*
* The util_set_fill() function ...
*
*/

int	util_set_fill(t_print *arg, char c)
{
	arg->len += 1;
	arg->flag = c;
	return (1);
}
