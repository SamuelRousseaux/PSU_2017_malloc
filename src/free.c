/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** free.c
*/

#include "malloc.h"

extern void *start_addr;
extern t_node *start_node;

void *find_ptr_node(void *ptr, t_node *current_node)
{
	t_node *tmp_node;

	if (current_node->ptr == ptr && current_node->empty == TAKEN) {
		return (current_node);
	} else if (current_node->right && current_node->left) {
		tmp_node = find_ptr_node(ptr, current_node->right);
		if (tmp_node)
			return (tmp_node);
		tmp_node = find_ptr_node(ptr, current_node->left);
		if (tmp_node)
			return (tmp_node);
		return (NULL);
	}
	return (NULL);
}

int check_childs(t_node *node)
{
	if (node->left->empty == TAKEN || node->right->empty == TAKEN)
		return (0);
	else if (node->left->left || node->left->right ||
		 node->right->left || node->right->right)
		return (0);
	else
		return (1);
}

void free_ptr(t_node *right_node)
{
	t_node *tmp_node = right_node;
	t_node *father_node;

	tmp_node->empty = EMPTY;
	while (tmp_node->prev) {
		father_node = tmp_node->prev;
		if (check_childs(father_node)) {
			father_node->left = NULL;
			father_node->right = NULL;
		} else
			return;
		tmp_node = father_node;
	}
}

void free(void *ptr)
{
	t_node *right_node;

	if (ptr < start_addr || ptr > sbrk(0))
		return;
	right_node = find_ptr_node(ptr, start_node);
	if (!right_node)
		return;
	free_ptr(right_node);
}
