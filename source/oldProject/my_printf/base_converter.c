/*
** EPITECH PROJECT, 2017
** [MY_PRINTF] {Vincent FAIVRE}
** File description:
** 5 functions
*/
#include "my_printf.h"

int	dec_to_binary_base(unsigned int dec_int)
{
	char converted_arr[BINARY_BUFFER];
	int base = 2;
	char base_nb[] = "01";
	int i = 0;
	int nb_char_displayed = 0;

	if (dec_int == 0) {
		converted_arr[i] = '0';
		i += 1;
	}
	while (dec_int != 0) {
		converted_arr[i] = base_nb[dec_int % base];
		dec_int /= base;
		i += 1;

	}
	nb_char_displayed = print_converted_arr(i, converted_arr);
	return (nb_char_displayed);
}

int	dec_to_octal_base(unsigned int dec_int)
{
	char converted_arr[OCTAL_BUFFER];
	int base = 8;
	char base_nb[] = "01234567";
	int i = 0;
	int nb_char_displayed = 0;

	if (dec_int == 0) {
		converted_arr[i] = '0';
		i += 1;
	}
	while (dec_int != 0) {
		converted_arr[i] = base_nb[dec_int % base];
		dec_int /= base;
		i += 1;

	}
	nb_char_displayed = print_converted_arr(i, converted_arr);
	return (nb_char_displayed);
}

int	dec_to_hexa_base(unsigned int dec_int)
{
	char converted_arr[HEXA_BUFFER];
	int base = 16;
	char base_nb[] = "0123456789abcdef";
	int i = 0;
	int nb_char_displayed = 0;

	if (dec_int == 0) {
		converted_arr[i] = '0';
		i += 1;
	}
	while (dec_int != 0) {
		converted_arr[i] = base_nb[dec_int % base];
		dec_int /= base;
		i += 1;

	}
	nb_char_displayed = print_converted_arr(i, converted_arr);
	return (nb_char_displayed);
}

int	dec_to_majhexa_base(unsigned int dec_int)
{
	char converted_arr[HEXA_BUFFER];
	int base = 16;
	char base_nb[] = "0123456789ABCDEF";
	int i = 0;
	int nb_char_displayed = 0;

	if (dec_int == 0) {
		converted_arr[i] = '0';
		i += 1;
	}
	while (dec_int != 0) {
		converted_arr[i] = base_nb[dec_int % base];
		dec_int /= base;
		i += 1;

	}
	nb_char_displayed = print_converted_arr(i, converted_arr);
	return (nb_char_displayed);
}

int	print_converted_arr(int nb_size, char *converted_arr)
{
	int nb_char = nb_size;

	for (nb_size -= 1; nb_size >= 0; nb_size -= 1)
		my_putchar(converted_arr[nb_size]);
	return (nb_char);
}
