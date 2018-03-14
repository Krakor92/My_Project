/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** 25 rows
*/

#include "utils2.h"

char *str_realloc(char* old_str, int old_size, int new_size)
{
	char *new_str;
	int i = 0;

	new_str = malloc(new_size * sizeof *new_str);
	if (!new_str)
		return my_ptr_error(INVALID_MALLOC);
	while (i < old_size) {
		new_str[i] = old_str[i];
		i++;
	}
	free(old_str);
	return new_str;
}
