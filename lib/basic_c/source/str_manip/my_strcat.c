/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** 25 rows
*/

#include "basic_c.h"

char *my_strcat(char *dest, const char *src)
{
	size_t dest_len = my_strlen(dest);
	size_t i = 0;

	for (i = 0; src[i]; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';
	return (dest);
}

char *my_heap_strcat(char *str, const char *cat)
{
	size_t str_len = my_strlen(str);
	size_t cat_len = my_strlen(cat);

	str = my_str_realloc(str, str_len, str_len + cat_len + 1);
	if (!str)
		return my_ptr_error(INVALID_MALLOC);
	str = my_strcat(str, cat);
	return str;
}
