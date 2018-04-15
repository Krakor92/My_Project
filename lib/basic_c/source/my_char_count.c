/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** 2 functions
*/

#include <stdio.h>

/*
** my_char_count =
** Count the number of occurence of a char in a str
**
** @param	str	String to parse
** @param	c	Character to count
** @return	Number of {c} in {str}
*/
size_t my_char_count(const char *str, char c)
{
	size_t i = 0;
	size_t j = 0;

	if (!str)
		return 0;
	for (i = 0; str[i]; i++) {
		if (str[i] == c)
			j++;
	}
	return j;
}

/*
** my_line_char_count =
** Count the number of occurence of a char in a str line
**
** @param	str	String to parse
** @param	c	Character to count
** @param	line	Line of the {str} where you count {c}
** @return	Number of {c} in a {line} of {str}
*/
int my_line_char_count(const char *str, char c, int line)
{
	int i = 0;
	int j = 0;
	int cur_line = 1;

	for (i = 0; str[i]; i++) {
		if (str[i] == '\n')
			cur_line++;
		if (cur_line == line && str[i] == c)
			j++;
		if (cur_line > line)
			return j;
	}
	return j;
}
