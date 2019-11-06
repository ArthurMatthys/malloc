/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr_def.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/06 14:29:59 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 16:58:04 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		useless_fun(t_tab *tab, char *str, int fd)
{
	int	i;

	i = 0;
	while (!(tab->side) && tab->acc -
			max(ft_strlen(str), (tab->width + is_inc(str[0], " +-"))) - i > 0)
		i += ft_putchar_fd((is_inc(str[0], " +-") || (!tab->fill) ||
					(is_inc(tab->type, "dDi") &&
					tab->width && tab->acc) ? ' ' : '0'), fd);
	return (i);
}

int		inner_print(char *str, int *t, t_tab *tab, int fd)
{
	if ((str[1] == 'x' || str[1] == 'X') && t[1] < 2)
	{
		ft_putchar_fd(str[t[1]++], fd);
		ft_putchar_fd(str[t[1]++], fd);
		return (2);
	}
	else if ((tab->width - t[2] - t[4] + t[3] * (str[1] == 'x') > 0))
	{
		ft_putchar_fd('0', fd);
		tab->width--;
		return (1);
	}
	else
	{
		ft_putchar_fd(str[t[1]++], 1);
		return (1);
	}
}

int		ft_intputstr_def(char *str, t_tab *tab, int fd)
{
	int	t[5];

	t[0] = 0;
	t[1] = 0;
	t[2] = 0;
	t[3] = 0;
	t[4] = ft_strlen(str);
	if ((is_inc(str[0], " +-") || str[1] == 'x')
			&& !(tab->width) && tab->acc && (tab->fill || tab->sign == 2))
	{
		tab->width = tab->acc;
		t[2]++;
		t[3] = 1;
	}
	else if ((str[1] == 'x' || str[1] == 'X'))
		tab->width += 2;
	t[0] += useless_fun(tab, str, fd);
	if (is_inc(str[t[1]], " +-"))
		t[2] -= ft_putchar_fd(str[t[1]++], fd);
	t[0] += -t[2];
	while (str[t[1]] && tab->w)
		t[0] += inner_print(str, t, tab, fd);
	while (tab->side && tab->acc - t[0] - t[3] > 0)
		t[0] += ft_putchar_fd(' ', fd);
	return (t[0] + t[3]);
}

int		ft_putstr_def(char *str, t_tab *tab, int fd)
{
	int i;
	int j;
	int k;
	int m;

	i = 0;
	k = 0;
	m = 0;
	j = ft_strlen(str);
	if (tab->w == 4 && is_inc(tab->type, "cCsS"))
		j = 0;
	while ((!(tab->side)) && (tab->acc -
				min(j, (tab->width + j * !tab->width)) - i > 0))
		i += ft_putchar_fd((tab->fill ? '0' : ' '), fd);
	while (str[k] && (k < tab->width ||
				(tab->w != 1 && tab->w != 4) || (!is_inc(tab->type, "sScC"))))
		i += ft_putchar_fd(str[k++], fd);
	while (tab->side && (tab->acc - i > 0))
		i += ft_putchar_fd((tab->fill ? '0' : ' '), fd);
	return (i);
}

int		print_string(const char *str, char c, int fd)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
	return (i);
}
