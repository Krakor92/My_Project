/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** 1 function
*/

#include "utils1.h"

/*
** my_putstr =
** Write the string given as parameter on the stdout (fd = 1)
**
** @param	str	String to print on the stdout
** @return	The length of {str}
*/
int my_putstr(char const *str)
{
	int str_len = my_strlen(str);

	write(1, str, str_len);
	return str_len;
}
