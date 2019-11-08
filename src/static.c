/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   static.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 16:15:53 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 17:56:58 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_metablock		*g_data[] = {NULL, NULL, NULL};

void	calledfirst(void)
{
	ft_printf("Yolo\n");
}

void	calledlast(void)
{
	ft_printf("Yolo\n");
}
