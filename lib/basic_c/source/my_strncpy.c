/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** 1 function
*/

#include "basic_c.h"

/*
** my_strncpy =
** Copy all or a part of the content of a string in another one
** The string that get the content has to be bigger or equal in size
** with the other one
**
** @param	dest	String that get the content
** @param	src	String which is copied
** @param	n	Number of char that will get copied in {dest}
** @return	{dest} with all or a part of {src}'s content OR
** 		the same {dest} if it's smaller than {src} and {n}
*/
char *my_strncpy(char *dest, char const *src, size_t n)
{
	size_t i = 0;

	for (i = 0; (src[i] && i < n); i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return dest;
}

char *my_strcpy_from_a2b(char *dest, char const *src, size_t a, size_t b)
{
	size_t src_len = my_strlen(src);
	size_t i = 0;

	if (a > b || src_len <= b)
		return my_ptr_error("Invalid a or Invalid b!\n");
	while (src[a] && a <= b) {
		dest[i] = src[a];
		a++;
		i++;
	}
	dest[i] = '\0';
	return dest;
}

char *my_strcpy_till_char(char *dest, char const *src, char c, bool_t copy_it)
{
	size_t i = 0;

	if (!dest || !src)
		return NULL;
	while (src[i] && src[i] != c) {
		dest[i] = src[i];
		i++;
	}
	if (copy_it == TRUE && src[i] == c) {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}
