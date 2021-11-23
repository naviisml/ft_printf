/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/30 13:23:48 by nismail       #+#    #+#                 */
/*   Updated: 2021/11/19 16:52:20 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_parse_format(t_print *arg, const char *format, int index);

/*
*
* The ft_init_struct() function ...
*
*/

static void	ft_init_struct(t_print *arg, int fd, va_list args)
{
	va_copy(arg->args, args);
	arg->fd = fd;
	arg->len = 0;
	arg->prefix = 0;
}

/*
*
* The ft_vprint() function formats and prints its arguments, after the first, 
* under control of the format. The format is a character string which contains 
* three types of objects: plain characters, which are simply copied to standard 
* output, character escape sequences which are converted and copied to the 
* standard output, and format specifications, each of which causes printing of 
* the next successive argument.
*
* The arguments after the first are treated as strings if the corresponding 
* format is either c, b or s; otherwise it is evaluated as a C constant.
*
*/

int	ft_vprint(int fd, const char *format, va_list args)
{
	t_print	arg;
	int		i;

	ft_init_struct(&arg, fd, args);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i = ft_parse_format(&arg, format, i + 1);
		}
		else
		{
			ft_putchar_fd(format[i], fd);
			arg.len += 1;
		}
		i++;
	}
	va_end(arg.args);
	return (arg.len);
}
