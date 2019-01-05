/*
** EPITECH PROJECT, 2018
** *
** File description:
** *
*/

#include "malloc.h"

extern t_node *start_node;

void print_mem_tree(t_node *current_node)
{
	void *tmp_ptr;
	size_t tmp_size;

	if (current_node->empty == TAKEN) {
		tmp_ptr = current_node->ptr;
		tmp_size = current_node->size;

		my_putadr(tmp_ptr);
		my_putstr(" - ");
		my_putadr((void *)((size_t)tmp_ptr + tmp_size));
		my_putstr(" : ");
		my_putnbr(tmp_size);
		my_putstr(" bytes\n");
	} else if (current_node->right && current_node->left) {
		print_mem_tree(current_node->right);
		print_mem_tree(current_node->left);
	}
}

void show_alloc_mem(void)
{
	my_putstr("break : ");
	my_putadr(sbrk(0));
	my_putstr("\n");
	print_mem_tree(start_node);
}
