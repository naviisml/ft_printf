/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_number.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: navi <navi@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 14:03:25 by navi          #+#    #+#                 */
/*   Updated: 2021/12/07 02:41:26 by navi          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	util_print_prefix(t_print *arg, long long nbr);

/*
*
* The ft_putuint_fd() function writes the unsigned int *nbr
* to the output stream pointed by fd
*
*/

static int	ft_putuint_fd(unsigned int nbr, int fd)
{
	int	len;

	len = ft_floor((__int128)nbr);
	if (nbr > 9)
	{
		ft_putuint_fd((nbr / 10), fd);
		ft_putuint_fd((nbr % 10), fd);
	}
	else if (nbr < 10)
		ft_putchar_fd(nbr + '0', fd);
	return (len);
}

/*
*
* The util_parse_uint() function ...
*
*/

int	util_parse_uint(t_print *arg, char c)
{
	unsigned int	nbr;
	int				len;

	nbr = va_arg(arg->args, unsigned int);
	len = ft_floor((__int128)nbr);
	util_print_prefix(arg, (long long)nbr);
	ft_putuint_fd(nbr, arg->fd);
	arg->len += len;
	arg->flag = c;
	return (1);
}

/*
*
* The util_parse_int() function ...
*
*/

int	util_parse_int(t_print *arg, char c)
{
	int	nbr;
	int	len;

	nbr = va_arg(arg->args, int);
	len = ft_floor((__int128)nbr);
	util_print_prefix(arg, (long long)nbr);
	ft_putnbr_fd(nbr, arg->fd);
	arg->len += len;
	arg->flag = c;
	return (1);
}
