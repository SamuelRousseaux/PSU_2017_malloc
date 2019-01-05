/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** realloc.c
*/

#include <string.h>
#include "malloc.h"

extern t_node *start_node;
extern void *start_addr;

void *realloc(void *ptr, size_t size)
{
	t_node *ret_node;
	void *l_ptr;

	if (ptr == NULL)
		return (malloc(size));
	if (start_addr == NULL || ptr < start_addr || ptr > sbrk(0))
		return (NULL);
	size = realign_size(size + NODE_SIZE);
	if (size == 0) {
		free(ptr);
		return (NULL);
	}
	ret_node = find_ptr_node(ptr, start_node);
	if (ret_node->size >= size)
		return (ret_node->ptr);
	l_ptr = malloc(size);
	l_ptr = memcpy(l_ptr, ptr, size);
	free(ptr);
	return (l_ptr);
}
