/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** 1 function
*/

#include "utils1.h"

/*
** my_ptr_error =
** Write the string given as parameter on the stderr (fd = 2) and return NULL
**
** @param	str	String to print on the stderr
** @return	NULL
*/
void *my_ptr_error(char const *str)
{
	my_putstr_error(str);
	return (NULL);
}
