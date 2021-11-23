/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_example.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: navi <navi@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 14:03:25 by navi          #+#    #+#                 */
/*   Updated: 2021/11/19 16:26:31 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
*
* The util_parse_example() function is a example
* function showing how future flags may be
* compiled.
*
* We still need to move the va_arg, otherwise
* the program might segvault.
*
*/

int	util_parse_example(t_print *arg, char c)
{
	va_arg(arg->args, unsigned int);
	arg->len += 1;
	arg->flag = c;
	return (1);
}
