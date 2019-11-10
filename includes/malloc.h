/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   malloc.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 10:05:29 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/10 16:52:36 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdlib.h>
# include <sys/mman.h>
# include <sys/resource.h>
# include <unistd.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

# define TINY 0
# define SMALL 1
# define LARGE 2

# define CONSTRUCTOR void	__attribute__((constructor))
# define DESTRUCTOR void	__attribute__((destructor))

CONSTRUCTOR					calledfirst(void);
DESTRUCTOR					calledlast(void);

/*
** Metadata to put before an allocated memory
*/

typedef struct				s_metadata
{
	struct s_metadata		*previous;
	struct s_metadata		*next;
	char					freed;
	size_t					size;
}							t_metadata;

/*
** Metadata to put at the start of a page
*/

typedef struct				s_metablock
{
	struct s_metablock		*previous;
	struct s_metablock		*next;
	int						type;
	size_t					size;
}							t_metablock;

/*
** Global used to store which memory has been aloocated
*/

void *g_data[3];

# define TINY_SIZE (128 + sizeof(t_metadata))
# define TINY_BLOCK_SIZE ((sizeof(t_metablock) + TINY_SIZE) * getpagesize())

# define SMALL_SIZE (1024 + sizeof(t_metadata))
# define SMALL_BLOCK_SIZE ((sizeof(t_metablock) + SMALL_SIZE) * getpagesize())

/*
** Store a function regarding its index
*/

typedef void				*(*t_dispatcher)();

void						*malloc(size_t size);
void						*calloc(size_t count, size_t size);
void						*realloc(void *ptr, size_t size);
void						free(void *ptr);
void						show_alloc_mem(void);

/*
** Dispatch functions
*/

void						*handle_tiny(size_t size, int type);
void						*handle_small(size_t size, int type);
void						*handle_large(size_t size, int type);

/*
** Utils malloc
*/

size_t						round_up(size_t start, size_t to_round);
int							get_type(size_t size);
int							find_area(t_metablock *block, void *ptr);
void						*do_mmap(size_t size_alloc, size_t size, int type);
void						*find_block(t_metablock *block,
		size_t size, int type);
void						update_data(t_metadata *data,
		size_t size, int type);

#endif
