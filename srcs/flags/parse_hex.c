/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_hex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: navi <navi@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 14:03:25 by navi          #+#    #+#                 */
/*   Updated: 2021/11/20 21:25:29 by navi          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
*
* The util_parse_hex_toupper() function ...
*
*/

int	util_parse_hex_toupper(t_print *arg, char c)
{
	unsigned int	hex;
	char			*value;

	hex = va_arg(arg->args, unsigned int);
	if (!hex)
	{
		ft_putchar_fd('0', arg->fd);
		arg->len += 1;
		arg->flag = c;
	}
	else
	{
		value = ft_inttohex((unsigned long long)hex);
		ft_putstr_fd(ft_strtoupper(value), arg->fd);
		arg->len += ft_strlen(value);
		arg->flag = c;
		free(value);
	}
	return (1);
}

/*
*
* The util_parse_hex_toupper() function ...
*
*/

int	util_parse_hex_tolower(t_print *arg, char c)
{
	unsigned int	hex;
	char			*value;

	hex = va_arg(arg->args, unsigned int);
	if (!hex)
	{
		ft_putchar_fd('0', arg->fd);
		arg->len += 1;
		arg->flag = c;
	}
	else
	{
		value = ft_inttohex((unsigned long long)hex);
		ft_putstr_fd(ft_strtolower(value), arg->fd);
		arg->len += ft_strlen(value);
		arg->flag = c;
		free(value);
	}
	return (1);
}

/*
*
* The util_parse_pointer() function ...
*
*/

int	util_parse_pointer(t_print *arg, char c)
{
	void	*hex;
	char	*value;

	hex = va_arg(arg->args, void *);
	arg->flag = c;
	if (!hex)
	{
		ft_putstr_fd("(nil)", arg->fd);
		arg->len += 5;
	}
	else
	{
		value = ft_inttohex((unsigned long long)hex);
		ft_putstr_fd("0x", arg->fd);
		ft_putstr_fd(ft_strtolower(value), arg->fd);
		arg->len += ft_strlen(value) + 2;
		free(value);
	}
	return (1);
}
