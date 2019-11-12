/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test4.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 16:16:19 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 10:56:26 by amatthys    ###    #+. /#+    ###.fr     */
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
	free((void *)addr + 5);
	if (realloc((void*)addr +5, 10) == NULL)
		print("Bonjours\n");
	return (0);
}
