/*
** EPITECH PROJECT, 2017
** [N/A] Vincent FAIVRE
** File description:
** 1 function
*/

#include "utils1.h"

/*
** my_checkstr =
** Check if a str is only composed of character in another str
**
** @param	str	String to parse
** @param	allow	String of allowed char
** @return	1 if {str} is only composed of char in {allow}, else 0
*/
int my_checkstr(char *str, char *allow)
{
	int nb_achar = my_strlen(allow);
	int not_achar = 0;
	int i = 0;
	int j = 0;

	for (i = 0; str[i] != 0; i++) {
		while (allow[j] != '\0') {
			if (str[i] != allow[j])
				not_achar++;
			j++;
		}
		if (not_achar == nb_achar)
			return 0;
		j = 0;
		not_achar = 0;
	}
	return 1;
}
