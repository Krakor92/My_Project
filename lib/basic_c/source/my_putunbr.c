/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** my_putunbr.c
*/

#include "basic_c.h"

/*
** my_putunbr =
** Print the unsigned number given as parameter on the stdout (fd = 1)
**
** @param	unbr	Unsigned number to print
** @return	The length of {unbr}
*/
unsigned int my_putunbr(unsigned int unbr)
{
	if (unbr > 9) {
		my_putnbr(unbr / 10);
		my_putchar('0' + unbr % 10);
	} else
		my_putchar('0' + unbr);
	return my_unbrlen(unbr);
}
