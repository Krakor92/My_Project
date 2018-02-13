/*
** EPITECH PROJECT, 2017
** emacs
** File description:
** my_put_nbr
*/
#include "utils1.h"

unsigned int	my_putunbr(unsigned int unbr)
{
	if (unbr > 9) {
		my_putnbr(unbr / 10);
		my_putchar('0' + unbr % 10);
	} else
		my_putchar('0' + unbr);
	return (my_unbrlen(unbr));
}
