/*
** EPITECH PROJECT, 2018
** Malloc
** File description:
** include
*/

#ifndef MALLOC_H_
# define MALLOC_H_

# define GET_DATA 1
# define GET_NODE 0

# define TAKEN 0
# define EMPTY 1

#include <unistd.h>

typedef struct	node_s
{
	char		empty;
	unsigned long	size;
	void		*ptr;
	struct node_s	*right;
	struct node_s	*left;
	struct node_s	*prev;
}		t_node;

# define NODE_SIZE sizeof(t_node)

int my_strlen(char *str);
unsigned long my_putnbr(unsigned long n);
void my_putstr(char *str);
char *my_revstr(char *str);
void my_putadr(int *adress);
size_t realign_size(size_t);
void *malloc(size_t);
void *realloc(void *ptr, size_t size);
void free(void *ptr);
void *find_ptr_node(void *ptr, t_node *current_node);
void show_alloc_mem();

#endif
