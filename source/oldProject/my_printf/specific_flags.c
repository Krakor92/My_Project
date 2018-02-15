/*
** EPITECH PROJECT, 2017
** [MY_PRINTF] {Vincent FAIVRE}
** File description:
** 2 functions
*/
#include "my_printf.h"

int	percent_flag(va_list ap)
{
	va_end(ap);
	my_putchar('%');
	return (1);
}

int	p_flag(va_list ap)
{
	void *p = va_arg(ap, void*);
	return (my_putstr(p));
}
