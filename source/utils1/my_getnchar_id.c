/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** 1 function
*/

#include "utils1.h"

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
int my_getnchar_id(char const *str, char c, int n)
{
	int i = 0;
	int j = 0;

	if (str == NULL || n <= 0)
		return -1;
	while (str[i] != '\0') {
		if (str[i] == c)
			j++;
		if (j == n)
			return i;
		i++;
	}
	return -1;
}
