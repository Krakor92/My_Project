/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** basic_c.h
*/

#ifndef __MY_GETNBR__H__
	#define __MY_GETNBR__H__

	#include <stddef.h>

	typedef struct strnbr_s
	{
		char const *str;
		size_t id_first_digit;
		size_t id_last_digit;
		int neg_factor;
		int nbr;
	} strnbr_t;

#endif
