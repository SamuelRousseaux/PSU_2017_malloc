/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** my_file.c
*/

#include "malloc.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}

void my_putstr(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		write(1, &str[i], 1);
}

unsigned long my_putnbr(unsigned long n)
{
	if (n >= 10) {
		my_putnbr(n / 10);
		my_putchar(n % 10 + '0');
	}
	if (n < 10)
		my_putchar(n % 10 + '0');
	return (n);
}

char *my_revstr(char *str)
{
	int i;
	int len;
	char c;

	len = my_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		c = *(str + i);
		*(str + i) = *(str + len - i - 1);
		*(str + len - i - 1) = c;
		++i;
	}
	return (str);
}

void my_putadr(int *adress)
{
	char  final[100];
	int   i;
	unsigned long nb;

	nb = (unsigned long)adress;
	i = 0;
	while (nb > 0)
	{
		if ((nb % 16) >= 10)
			final[i] = (nb % 16) + 87;
		else
			final[i] = (nb % 16) + 48;
		nb = nb / 16;
		i++;
	}
	final[i] = 'x';
	final[i + 1] = '0';
	final[i + 2] = '\0';
	my_putstr(my_revstr(final));
}
