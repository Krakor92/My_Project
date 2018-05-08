/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** Functions that create 2 dimensions arrays (char**, int**, etc...)
*/

#include "basic_c.h"

void print_2d_char_arr(char **arr2d)
{
	size_t i = 0;

	if (!arr2d)
		return;
	for (i = 0; arr2d[i]; i++) {
		my_putstr(arr2d[i]);
		my_putchar('\n');
	}
}

void print_2d_int_arr(int **arr2d)
{
	size_t i = 0;
	size_t j = 0;

	if (!arr2d)
		return;
	for (i = 0; arr2d[i]; i++) {
		for (j = 0; arr2d[i][j]; j++) {
			my_putnbr(arr2d[i][j]);
			my_putstr(", ");
		}
		my_putchar('\n');
	}
}
