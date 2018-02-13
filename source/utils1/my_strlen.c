/*
** EPITECH PROJECT, 2017
** [N/A]
** File description:
**
** my_strlen =
** Count the number of character in the {str}
**
** @param	str	String to parse
** @return	The length of {str}
*/
int my_strlen(char const *str)
{
	int i = 0;

	while (str[i] != '\0')
		++i;
	return (i);
}
