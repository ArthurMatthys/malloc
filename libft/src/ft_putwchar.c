/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putwchar.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/10 13:50:44 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/13 09:28:00 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_next(const char *fmt, va_list ap, t_tab *tab)
{
	while (*fmt && *fmt != '%')
		fmt++;
	fmt++;
	parse_handler(fmt, tab);
	if (!*fmt)
		return (1);
	else if (tab->type == 'C' || (tab->type == 'c' && tab->len == 3))
	{
		return (is_ok(va_arg(ap, wchar_t)));
	}
	else if (tab->type == 'S' || (tab->type == 's' && tab->len == 3))
	{
		return (is_wstr_ok(va_arg(ap, wchar_t *), tab));
	}
	else
		return (1);
}

int		is_wstr_ok(wchar_t *str, t_tab *tab)
{
	int k;
	int i;

	i = 0;
	k = 0;
	if (str == NULL)
		return (1);
	while (*str && (k < tab->width || (tab->w == 2 || tab->w == 10)))
	{
		if (is_ok(*str))
		{
			str++;
			k += wchar_len(*str);
		}
		else
		{
			return (0);
		}
	}
	while (str[i++] && k <= tab->width)
		k += wchar_len(*str);
	if ((tab->w == 1 || tab->w == 4) && *str)
		return (k <= tab->width || (k - wchar_len(str[--i])) <= tab->width);
	else
		return (1);
}

int		is_ok(wchar_t c)
{
	int t;

	t = wchar_len(c);
	if (c > 255 && MB_CUR_MAX == 1)
		return (0);
	else if (c < 0)
		return (0);
	else if (c >= 0xd800 && c <= 0xdfff)
		return (0);
	else if (c > 0x10ffff)
		return (0);
	else
		return (1);
}

int		ft_putwchar_fd(wchar_t c, int fd)
{
	int		i;

	i = wchar_len(c);
	if (c <= 0xff)
		ft_putchar_fd(c, fd);
	else if (c <= 0x7FF)
	{
		ft_putchar_fd((c >> 6) + 0xC0, fd);
		ft_putchar_fd((c & 0x3F) + 0x80, fd);
	}
	else if (c <= 0xFFFF)
	{
		ft_putchar_fd((c >> 12) + 0xE0, fd);
		ft_putchar_fd(((c >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((c & 0x3F) + 0x80, fd);
	}
	else
	{
		ft_putchar_fd((c >> 18) + 0xF0, fd);
		ft_putchar_fd(((c >> 12) & 0x3F) + 0x80, fd);
		ft_putchar_fd(((c >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((c & 0x3F) + 0x80, fd);
	}
	return (i);
}
