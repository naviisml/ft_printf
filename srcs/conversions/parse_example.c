/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_example.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: navi <navi@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 14:03:25 by navi          #+#    #+#                 */
/*   Updated: 2021/12/04 17:04:27 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
 * The util_parse_example() function is a example
 * function showing how future flags may be
 * compiled.
 */

int	util_parse_example(t_print *arg, char c)
{
	arg->len += 1;
	arg->flag = c;
	return (1);
}
