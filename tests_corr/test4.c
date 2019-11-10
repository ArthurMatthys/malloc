/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test4.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 16:16:19 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/10 13:04:48 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include <unistd.h>

void	print(char *s)
{
	write(1, s, strlen(s));
}

int main()
{
	char *addr;

	addr = malloc(16);
	free(NULL);
	ft_printf("1\n");
	free((void *)addr + 5);
	ft_printf("2\n");
	if (realloc((void*)addr +5, 10) == NULL)
		print("Bonjours\n");
	return (0);
}
