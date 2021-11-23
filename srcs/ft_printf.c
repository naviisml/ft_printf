/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/30 13:23:48 by nismail       #+#    #+#                 */
/*   Updated: 2021/11/17 14:34:40 by navi          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
*
* The ft_printf() function is almost identical to the ft_fprintf() function.
* 
* The difference is that ft_printf() prints to the standard output(1), while
* ft_fprintf() prints to a specific file descriptor.
*
*/

int	ft_vprintf(const char *format, va_list args)
{
	int		res;

	res = ft_vprint(1, format, args);
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		res;

	va_start(args, format);
	res = ft_vprint(1, format, args);
	va_end(args);
	return (res);
}
