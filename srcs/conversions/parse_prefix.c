/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_prefix.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: navi <navi@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 14:03:25 by navi          #+#    #+#                 */
/*   Updated: 2021/11/19 22:25:26 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
*
* The util_print_prefix() function ...
*
*/

int	util_print_prefix(t_print *arg, int nbr)
{
	if (arg->prefix == 0)
		return (0);
	arg->len += 1;
	if (nbr >= 0)
		ft_putstr_fd(arg->prefix, arg->fd);
	return (1);
}

/*
*
* The util_set_prefix() function ...
*
*/

int	util_set_prefix(t_print *arg, char c)
{
	char	str[2];

	str[0] = c;
	str[1] = 0;
	arg->len += 1;
	arg->prefix = str;
	return (1);
}
