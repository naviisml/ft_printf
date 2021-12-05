/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/30 13:18:33 by nismail       #+#    #+#                 */
/*   Updated: 2021/12/05 16:06:43 by navi          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int	ft_vprint(int fd, const char *format, va_list args);
int	ft_vfprintf(int fd, const char *format, va_list args);
int	ft_fprintf(int fd, const char *format, ...);
int	ft_vprintf(const char *format, va_list args);
int	ft_printf(const char *format, ...);

typedef struct s_print
{
	int		len;
	int		fd;
	va_list	args;
	char	arg;
	char	flag;
	char	*prefix;
}			t_print;

typedef struct s_flags
{
	char	flag;
	int		(*callback)(t_print *, char);
}		t_flags;

#endif