/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** my_str_realloc.c
*/

#include "basic_c.h"

char *my_str_realloc(char* old_str, size_t old_size, size_t new_size)
{
	char *new_str;
	size_t i = 0;

	new_str = malloc(new_size * sizeof(*new_str));
	if (!new_str)
		return my_ptr_error(INVALID_MALLOC);
	for (i = 0; i < old_size; i++)
		new_str[i] = old_str[i];
	free(old_str);
	return new_str;
}
