/*
** EPITECH PROJECT, 2018
** Malloc
** File description:
** c file
*/

#include "malloc.h"

void *start_addr;
t_node *start_node;

void *init_btree(void)
{
	start_addr = sbrk(0);
	if (sbrk(getpagesize()) == ((void *)-1))
		return ((void *)-1);

	start_node = sbrk(sizeof(t_node));

	start_node->empty = EMPTY;
	start_node->size = getpagesize();
	start_node->ptr = start_addr;
	start_node->right = NULL;
	start_node->left = NULL;
	start_node->prev = NULL;
	return (start_node);
}

t_node *create_childs(t_node *father)
{
	t_node *right = sbrk(sizeof(t_node));
	t_node *left = sbrk(sizeof(t_node));

	if (right == (void *)-1 || left == (void *)-1)
		return ((void *)-1);
	right->empty = EMPTY;
	right->size = father->size / 2;
	right->ptr = father->ptr;
	right->right = NULL;
	right->left = NULL;
	right->prev = father;
	left->empty = EMPTY;
	left->size = father->size / 2;
	left->ptr = father->ptr + father->size / 2;
	left->right = NULL;
	left->left = NULL;
	left->prev = father;
	father->right = right;
	father->left = left;
	return (father);
}

void *find_right_node(size_t size, t_node *current_node)
{
	t_node *tmp_node = NULL;
	unsigned long tmp_size = current_node->size;

	if (size > tmp_size || current_node->empty == TAKEN
	    || current_node == (void *)-1)
		return (NULL);
	if (size <= tmp_size && size > tmp_size / 2) {
		if (current_node->right && current_node->left)
			return (NULL);
		current_node->empty = TAKEN;
		return (current_node);
	}
	else if (!current_node->right && !current_node->left)
		current_node = create_childs(current_node);
	tmp_node = find_right_node(size, current_node->right);
	if (tmp_node)
		return (tmp_node);
	tmp_node = find_right_node(size, current_node->left);
	return (tmp_node);
}

void *add_new_level(void)
{
	t_node *new_father = sbrk(sizeof(t_node));
	t_node *new_left = sbrk(sizeof(t_node));

	if (new_father == (void *)-1 || new_left == (void *)-1)
		return ((void *)-1);
	new_father->empty = EMPTY;
	new_father->size = start_node->size * 2;
	new_father->ptr = start_node->ptr;
	new_father->right = start_node;
	new_father->left = new_left;
	new_father->prev = NULL;
	new_left->empty = EMPTY;
	new_left->size = start_node->size;
	new_left->ptr = sbrk(start_node->size);
	if (new_left->ptr == ((void *)-1))
		return ((void *)-1);
	new_left->right = NULL;
	new_left->left = NULL;
	new_left->prev = new_father;
	return (new_father);
}

void *malloc(size_t size)
{
	t_node *right_node;


	size = realign_size(size + NODE_SIZE);
	if (!start_addr)
		if (init_btree() == (void *)-1)
			return (NULL);

	right_node = find_right_node(size, start_node);
	while (!right_node) {
		start_node = add_new_level();
		if (start_node == (void *)-1)
			return (NULL);
		right_node = find_right_node(size, start_node);
	}
	return (right_node->ptr);
}
