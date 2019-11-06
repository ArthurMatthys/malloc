/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putwstr_def.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/06 16:21:32 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 10:28:11 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		wchar_len(wchar_t c)
{
	if (c < 0xff)
		return (1);
	else if (c < 0x7FF)
		return (2);
	else if (c <= 0xfFFF)
		return (3);
	else
		return (4);
}

int		ft_putwstr_def(wchar_t *str, t_tab *tab, int fd)
{
	int i;
	int j;
	int	k;
	int m;

	k = 0;
	i = 0;
	j = 0;
	m = 0;
	while (str[k] && ((j < tab->width && (tab->width == 1 || tab->width == 4))
				|| tab->w == 10 || tab->w == 2))
		j += wchar_len(str[k++]);
	k = 0;
	while ((!(tab->side)) && (tab->acc - j - i > 0))
		i += ft_putchar_fd((tab->fill * '0' + !(tab->fill) * ' '), fd);
	while (str[k] && (m + wchar_len(str[k]) <= tab->width
				|| (tab->w != 1 && tab->w != 4)))
		m += ft_putwchar_fd(str[k++], fd);
	i += m;
	while (tab->side && (tab->acc - i > 0))
		i += ft_putchar_fd((tab->fill * '0' + !(tab->fill) * ' '), fd);
	return (i);
}
