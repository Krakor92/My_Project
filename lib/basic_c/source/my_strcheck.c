/*
** EPITECH PROJECT, 2017
** [N/A] Vincent FAIVRE
** File description:
** 1 function
*/

#include "basic_c.h"

/*
** my_checkstr =
** Check if a str is only composed of character in another str
**
** @param	str	String to parse
** @param	allow	String of allowed char
** @return	1 if {str} is only composed of char in {allow}, else 0
*/
bool_t my_strcheck(const char *str, const char *allow)
{
	size_t nb_allowed_char = my_strlen(allow);
	size_t not_an_allowed_char = 0;
	int i = 0;
	int j = 0;

	for (i = 0; str[i]; i++) {
		for (j = 0; allow[j]; j++) {
			if (str[i] != allow[j])
				not_an_allowed_char++;
		}
		if (not_an_allowed_char == nb_allowed_char)
			return FALSE;
		not_an_allowed_char = 0;
	}
	return TRUE;
}
