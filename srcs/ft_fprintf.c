/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fprintf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/30 13:23:48 by nismail       #+#    #+#                 */
/*   Updated: 2021/11/16 21:44:43 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
*
* The ft_fprintf() function is almost identical to the ft_printf() function.
* 
* The difference is that ft_fprintf() prints to a specific stream, while
* ft_printf() prints to the standard output(1).
*
*/

int	ft_vfprintf(int fd, const char *format, va_list args)
{
	int		res;

	res = ft_vprint(fd, format, args);
	return (res);
}

int	ft_fprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		res;

	va_start(args, format);
	res = ft_vprint(fd, format, args);
	va_end(args);
	return (res);
}
