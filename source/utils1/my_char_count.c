/*
** EPITECH PROJECT, 2017
** [Minishell1]
** File description:
**
** my_char_count =
** Count the number of occurence of a char in a str
**
** @param	str	String to parse
** @param	c	Character to count
** @return	Number of {c} in {str}
**
**
** my_line_char_count =
** Count the number of occurence of a char in a str line
**
** @param	str	String to parse
** @param	c	Character to count
** @param	line	Line of the {str} where you count {c}
** @return	Number of {c} in a {line} of {str}
*/
int my_char_count(char *str, char c)
{
	int i = 0;

	for(; *str != 0; str++) {
		if (*str == c)
			++i;
	}
	return (i);
}

int my_line_char_count(char *str, char c, int line)
{
	int i = 0;
	int cur_line = 1;

	for(; *str != 0; str++) {
		if (*str == '\n')
			++cur_line;
		if (cur_line == line && *str == c)
			++i;
		if (cur_line > line)
			return (i);
	}
	return (i);
}
