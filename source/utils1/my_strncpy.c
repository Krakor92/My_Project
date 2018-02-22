/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** 1 function
*/

#include "utils1.h"

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
char *my_strncpy(char *dest, char const *src, int n)
{
	int i = 0;
	int dest_len = my_strlen(dest);
	int src_len = my_strlen(src);

	if (dest_len < src_len && n > dest_len)
		return(dest);
	while ((i < n) && (src[i] != '\0')) {
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
