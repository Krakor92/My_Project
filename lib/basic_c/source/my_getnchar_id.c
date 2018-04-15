/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** 1 function
*/

#include "basic_c.h"

/*
** my_getnchar_id =
** Give the id of the n-th character given in the string given as parameter
**
** @param	str	String to parse
** @param	c	The character to get the id
** @param	n	The n-th character
** @return	The id of the {n} {c} in {str} OR -1 if the func didn't find it
** 		or if there was an error
*/
int my_getnchar_id(char const *str, char c, size_t n)
{
	size_t i = 0;
	size_t j = 0;

	if (!str || n == 0)
		return -2;
	for (i = 0; str[i]; i++) {
		if (str[i] == c)
			j++;
		if (j == n)
			return i;
	}
	return -1;
}
