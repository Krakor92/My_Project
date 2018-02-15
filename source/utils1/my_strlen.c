/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** 1 function
*/

/*
** my_strlen =
** Count the number of character in the string given as parameter
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
