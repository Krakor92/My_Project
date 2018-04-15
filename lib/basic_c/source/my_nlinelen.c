/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** 1 function
*/

#include "basic_c.h"

/*
** my_nlinelen =
** Count the number of character in a line of the string given as parameter
**
** @param	str		String to parse
** @param	nline		The n-th line where to count
** @param	count_newline	Count the \n or no ? 1 for yes, 0 for no
** @return	The length of the {line} lines in {str} OR -1
** 		if there was an error
*/
size_t my_nlinelen(char const *str, size_t nline, bool_t count_newline)
{
	size_t nb_lines = my_char_count(str, '\n') + 1;
	size_t i = 0;
	size_t j = 0;

	if (!str || nline == 0 || nline > nb_lines)
		return 0;
	if (nline == 1) {
		for (i = 0; str[i] && str[i] != '\n'; i++)
			j++;
	} else {
		i = my_getnchar_id(str, '\n', nline - 1) + 1;
		for (; str[i] && str[i] != '\n'; i++)
			j++;
	}
	if (count_newline == TRUE && str[i] == '\n')
		j++;
	return j;
}
