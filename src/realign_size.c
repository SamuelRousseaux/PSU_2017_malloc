/*
** EPITECH PROJECT, 2018
** Malloc
** File description:
** realign_size.c
*/

#include <unistd.h>

size_t realign_size(size_t size)
{
	if (size > 0 && size % 4 != 0)
		size += 4 - (size % 4);
	return (size);
}
