/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** 1 function
*/

#include "utils1.h"

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
int my_nlinelen(char const *str, int nline, int count_newline)
{
	int nb_lines = my_char_count(str, '\n') + 1;
	int i = 0;
	int j = 0;

	if (str == NULL || nline <= 0 || nline > nb_lines)
		return (-1);
	if (nline == 1) {
		for (; str[i] != '\n' && str[i] != '\0'; i++)
			j++;
	}
	else {
		i = my_getnchar_id(str, '\n', nline - 1) + 1;
		for (; str[i] != '\n' && str[i] != '\0'; i++)
			j++;
	}
	if (count_newline == YES && str[i] == '\n')
		j++;
	return (j);
}
