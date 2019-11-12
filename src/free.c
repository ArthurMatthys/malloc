/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 08:35:39 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 17:04:10 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		free(void *ptr)
{
	t_metadata	*data;

	if (!ptr)
		return ;
	data = find_alloc(ptr);
	if (!data)
		return ;
	data->freed = 1;
}
