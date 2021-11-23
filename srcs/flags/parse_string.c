/* ************************************************************************** */
/*	                                                                        */
/*                                                        ::::::::            */
/*   parse_string.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: navi <navi@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 14:03:25 by navi          #+#    #+#                 */
/*   Updated: 2021/11/18 03:48:13 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
*
* The util_parse_str() function ...
*
*/

int	util_parse_str(t_print *arg, char c)
{
	char	*str;
	int		len;

	str = va_arg(arg->args, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	ft_putstr_fd(str, arg->fd);
	arg->len += len;
	arg->flag = c;
	return (1);
}

/*
*
* The util_parse_chr() function ...
*
*/

int	util_parse_chr(t_print *arg, char c)
{
	char	character;

	character = va_arg(arg->args, int);
	ft_putchar_fd(character, arg->fd);
	arg->len += 1;
	arg->flag = c;
	return (1);
}

/*
*
* The util_parse_percentage() function ...
*
*/

int	util_parse_percentage(t_print *arg, char c)
{
	return (util_parse_chr(arg, c));
}
