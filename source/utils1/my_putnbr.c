/*
** EPITECH PROJECT, 2017
** [N/A]
** File description:
**
** my_putnbr =
** Print a number on the stdout
**
** @param	nbr	Number to print
** @return	The length of the {nbr}
*/
#include "utils1.h"

int my_putnbr(int nbr)
{
	int minus = 0;

	if (nbr < 0) {
		my_putchar('-');
		nbr = -nbr;
		minus = 1;
	}
	if (nbr > 9) {
		my_putnbr(nbr / 10);
		my_putchar('0' + nbr % 10);
	} else
		my_putchar('0' + nbr);
	return (my_nbrlen(nbr) + minus);
}
