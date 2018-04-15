/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** 1 function
*/

#include "basic_c.h"

/*
** my_putstr_err =
** Write the string given as parameter on the stderr (fd = 2)
**
** @param	str	String to print on the stderr
** @return	The length of {str}
*/
size_t my_putstr_error(char const *str)
{
	int str_len = my_strlen(str);

	write(2, str, str_len);
	return str_len;
}
