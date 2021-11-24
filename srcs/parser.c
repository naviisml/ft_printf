/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: navi <navi@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 10:39:26 by navi          #+#    #+#                 */
/*   Updated: 2021/11/24 04:33:39 by navi          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	util_parse_percentage(t_print *arg, char c);
int	util_parse_str(t_print *arg, char c);
int	util_parse_chr(t_print *arg, char c);
int	util_parse_int(t_print *arg, char c);
int	util_parse_uint(t_print *arg, char c);
int	util_parse_example(t_print *arg, char c);
int	util_parse_hex_tolower(t_print *arg, char c);
int	util_parse_hex_toupper(t_print *arg, char c);
int	util_parse_pointer(t_print *arg, char c);

int	util_set_char_prefix(t_print *arg, char c);
int	util_set_fill(t_print *arg, char c);

/*
*
* The g_flag_types[] struct holds the flag 
* types and corresponding callback() function.
*
*/

t_flags	g_flag_types[] = {
{'u', util_parse_uint},
{'d', util_parse_int},
{'i', util_parse_int},
{'c', util_parse_chr},
{'s', util_parse_str},
{'p', util_parse_pointer},
{'x', util_parse_hex_tolower},
{'X', util_parse_hex_toupper},
{'%', util_parse_percentage}
};

/*
*
* The g_flags[] struct holds the flags with
* a corresponding callback() function.
*
*/

t_flags	g_flags[] = {
{'-', util_parse_example},
{'.', util_parse_example},
{'#', util_parse_example},
{'0', util_set_fill},
{'+', util_set_char_prefix},
{' ', util_set_char_prefix}
};

/*
*
* The ft_parse_flags() function iterates over the
* given t_flags *list parameter and executes the
* corresponding callback() if the flag is found.
*
* This function returns (1) if a flag is found, and
* (0) if a flag is not found.
*
*/

static int	ft_parse_flags(t_flags *list, t_print *arg, char c)
{
	int	i;
	int	res;

	i = 0;
	while (list[i].flag)
	{
		if (list[i].flag == c)
		{
			res = list[i].callback(arg, c);
			if (res == 0)
				return (0);
			return (1);
		}
		i++;
	}
	return (0);
}

/*
*
* The ft_parse_format() function iterates over
* every character after a '%', and check if the
* flag has ended.
*
* If this is not true, then the function checks if the
* character is a valid flag, if this true, the ft_parse_flags()
* function executes the corresponding callback() function.
*
* If this is not true, the loop will break and return the
* original index as it is not a valid flag.
*
*/

int	ft_parse_format(t_print *arg, const char *format, int index)
{
	int	i;

	i = index;
	while (format[i] != '\0')
	{
		if (ft_parse_flags(g_flags, arg, format[i]) == 1)
		{
			i++;
		}
		else if (ft_parse_flags(g_flag_types, arg, format[i]) == 1)
		{
			break ;
		}
		else
		{
			ft_putchar_fd('%', arg->fd);
			return (index - 1);
		}
	}
	return (i);
}
