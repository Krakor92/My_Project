/*
** EPITECH PROJECT, 2017
** [N/A]
** File description:
**
** my_strcpy =
** Copy the content of a str in another one
** The str that get the content has to be bigger or equal in size
** with the other
**
** @param	dest	String that get the content
** @param	src	String which is copied
** @return	Dest with src's content OR the same dest if
** 		it's smaller than src
*/
#include "utils1.h"

char *my_strcpy(char *dest, char const *src)
{
	int i = 0;

	if (my_strlen(dest) < my_strlen(src))
		return (dest);
	while (src[i] != '\0') {
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
