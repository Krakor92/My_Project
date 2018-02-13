/*
** EPITECH PROJECT, 2017
** [N/A]
** File description:
**
** my_putstr_err =
** Write {str} on the stderr (fd = 2)
**
** @param	str	String to print on the stderr
** @return	The length of {str}
*/
#include "utils1.h"

int my_putstr_error(char const *str)
{
	int str_len = my_strlen(str);

	write(2, str, str_len);
	return (str_len);
}
