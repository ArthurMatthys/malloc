/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/05 11:44:11 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/05 11:51:09 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

int		main()
{
	ft_printf("metadata : %lu\n", sizeof(t_metadata));
	ft_printf("metapage : %lu\n", sizeof(t_metapage));
	ft_printf("allocated : %lu\n", sizeof(t_allocated));
	return (1);
}
