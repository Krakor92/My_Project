/*
** EPITECH PROJECT, 2017
** [MY_PRINTF] {Vincent FAIVRE}
** File description:
** 2 functions
*/

#include "my_printf.h"

const converter_t converter_arr[] =
{
	{b_flag, 'b'},
	{c_flag, 'c'},
	{di_flag, 'd'},
	{di_flag, 'i'},
	{o_flag, 'o'},
	{p_flag, 'p'},
	{s_flag, 's'},
	{u_flag, 'u'},
	{x_flag, 'x'},
	{majx_flag, 'X'},
	{percent_flag, '%'},
	{NULL, 0}
};

static int exe_function(va_list ap, char flag)
{
	int i = 0;
	int len_ap = 0;

	while (converter_arr[i].keyword != 0) {
		if (converter_arr[i].keyword == flag) {
			len_ap = converter_arr[i].ptrfunction(ap);
			return (len_ap);
		}
		i += 1;
	}
	return (len_ap);
}


int my_printf(const char *fmt, ...)
{
	va_list ap;
	int i = 0;
	int len_tot = 0;

	va_start(ap, fmt);
	while (fmt[i] != '\0') {
		if (fmt[i] != '%') {
			my_putchar(fmt[i]);
			++len_tot;
			++i;
		} else {
			++i;
			len_tot += exe_function(ap, fmt[i]);
			++i;
		}
	}
	va_end(ap);
	return (len_tot);
}
