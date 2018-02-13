/*
** EPITECH PROJECT, 2017
** [N/A]
** File description:
**
** my_ptr_error =
** Write {str} on the stderr (fd = 2) and return NULL
**
** @param	str	String to print on the stderr
** @return	NULL
*/
#include "utils1.h"

void *my_ptr_error(char const *str)
{
	my_putstr_error(str);
	return (NULL);
}
