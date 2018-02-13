/*
** EPITECH PROJECT, 2017
** [N/A]
** File description:
**
** my_putstr =
** Write {str} on the stdout (fd = 1)
**
** @param	str	String to print on the stdout
** @return	The length of {str}
*/
#include "utils1.h"

int my_putstr(char const *str)
{
	int str_len = my_strlen(str);

	write(1, str, str_len);
	return (str_len);
}
