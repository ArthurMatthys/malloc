/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_s.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/05 17:20:26 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 16:57:55 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_s(va_list ap, t_tab *tab)
{
	char	*str;

	if (tab->len == 3)
		return (ft_printf_ss(ap, tab));
	str = va_arg(ap, char *);
	if (str == NULL)
		return (ft_putstr_def("(null)", tab, FIL));
	else
		return (ft_putstr_def(str, tab, FIL));
}

int		ft_printf_c(va_list ap, t_tab *tab)
{
	char	c;
	int		i;

	i = 0;
	if (tab->len != 3)
		c = (char)va_arg(ap, int);
	else
		return (ft_printf_cc(ap, tab));
	if (!tab->side)
		while (i < tab->acc - 1)
			i += ft_putchar_fd((tab->fill ? '0' : ' '), FIL);
	i += ft_putchar_fd(c, FIL);
	if (tab->side)
		while (i < tab->acc)
			i += ft_putchar_fd((tab->fill ? '0' : ' '), FIL);
	return (i);
}

int		ft_printf_ss(va_list ap, t_tab *tab)
{
	wchar_t	*str;

	str = va_arg(ap, wchar_t *);
	if (str == NULL)
		return (ft_putstr_def("(null)", tab, FIL));
	if (!(is_wstr_ok(str, tab)))
		return (-1);
	return (ft_putwstr_def(str, tab, FIL));
}

int		ft_printf_cc(va_list ap, t_tab *tab)
{
	wchar_t	c;
	int		i;
	int		t;

	i = 0;
	c = va_arg(ap, wchar_t);
	t = wchar_len(c);
	if (!is_ok(c) && tab->type == 'C')
		return (-1);
	if (!tab->side)
		while (i < tab->acc - t - tab->width)
			i += ft_putchar_fd(' ', FIL);
	i += ft_putwchar_fd(c, FIL);
	if (tab->side)
		while (i < tab->acc)
			i += ft_putchar_fd(' ', FIL);
	return (i);
}

int		ft_printf_other(t_tab *tab)
{
	char	str[2];

	if (tab->type != 25)
	{
		str[0] = tab->type;
		str[1] = '\0';
		if (tab->type != '%')
			tab->acc -= (tab->w == 1);
		return (ft_putstr_def(str, tab, FIL));
	}
	else
	{
		tab->acc--;
		str[0] = '\0';
		return (ft_putstr_def("", tab, FIL));
	}
}
