/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_hex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: navi <navi@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 14:03:25 by navi          #+#    #+#                 */
/*   Updated: 2021/12/05 16:18:20 by navi          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
 * The util_parse_hex_toupper() function ...
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
		value = ft_itoa_base((__int128) hex, 16);
		ft_putstr_fd(ft_strtoupper(value), arg->fd);
		arg->len += ft_strlen(value);
		arg->flag = c;
		free(value);
	}
	return (1);
}

/*
 * The util_parse_hex_toupper() function ...
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
		value = ft_itoa_base((__int128) hex, 16);
		ft_putstr_fd(ft_strtolower(value), arg->fd);
		arg->len += ft_strlen(value);
		arg->flag = c;
		free(value);
	}
	return (1);
}

/*
 * The util_parse_pointer() function ...
 */
int	util_parse_pointer(t_print *arg, char c)
{
	unsigned int	hex;
	char			*value;

	hex = va_arg(arg->args, unsigned int);
	arg->flag = c;
	arg->len += 2;
	ft_putstr_fd("0x", arg->fd);
	if (!hex)
	{
		ft_putstr_fd("0", arg->fd);
		arg->len += 1;
	}
	else
	{
		value = ft_itoa_base((__int128) hex, 16);
		ft_putstr_fd(ft_strtolower(value), arg->fd);
		arg->len += ft_strlen(value);
		free(value);
	}
	return (1);
}
