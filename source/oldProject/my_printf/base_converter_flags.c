/*
** EPITECH PROJECT, 2017
** [MY_PRINTF] {Vincent FAIVRE}
** File description:
** 4 functions
*/

#include "my_printf.h"

int	b_flag(va_list ap)
{
	unsigned int b = va_arg(ap, unsigned int);
	return (dec_to_binary_base(b));
}

int	o_flag(va_list ap)
{
	unsigned int o = va_arg(ap, unsigned int);
	return (dec_to_octal_base(o));
}

int	x_flag(va_list ap)
{
	unsigned int x = va_arg(ap, unsigned int);
	return (dec_to_hexa_base(x));
}

int	majx_flag(va_list ap)
{
	unsigned int majx = va_arg(ap, unsigned int);
	return (dec_to_majhexa_base(majx));
}
