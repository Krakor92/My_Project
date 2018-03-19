/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** 1 function
*/

#include "basic_c.h"

/*
** my_int_error =
** Write {str} on the stderr (fd = 2) and return an int
**
** @param	str	String to print on the stderr
** @return	An int (usually -1)
*/
int my_int_error(char const *str)
{
	my_putstr_error(str);
	return -1;
}
