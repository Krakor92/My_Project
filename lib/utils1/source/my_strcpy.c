/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** 1 function
*/

#include "utils1.h"

/*
** my_strcpy =
** Copy the content of a string in another one
** The string that get the content has to be bigger or equal in size
** with the other
**
** @param	dest	String that get the content
** @param	src	String which is copied
** @return	{dest} with {src}'s content OR the same {dest} if
** 		it's smaller than {src}
*/
char *my_strcpy(char *dest, char const *src)
{
	int i = 0;

	if (!dest || !src)
		return NULL;
	while (*src != '\0') {
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return dest;
}
