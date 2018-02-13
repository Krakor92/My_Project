/*
** EPITECH PROJECT, 2017
** [N/A]
** File description:
**
** my_int_error =
** Write {str} on the stderr (fd = 2) and return an int
**
** @param	str	String to print on the stderr
** @return	An int (usually -1)
*/
#include "utils1.h"

int my_int_error(char const *str)
{
	my_putstr_error(str);
	return (-1);
}
