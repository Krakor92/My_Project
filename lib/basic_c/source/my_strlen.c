/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** 1 function
*/

#include <stddef.h>

/*
** my_strlen =
** Count the number of character in the string given as parameter
**
** @param	str	String to parse
** @return	The length of {str}
*/
size_t my_strlen(char const *str)
{
	size_t i = 0;

	if (!str)
		return 0;
	while (str[i])
		i++;
	return i;
}
