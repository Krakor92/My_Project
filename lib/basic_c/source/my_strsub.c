/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** my_strsub.c
*/

#include "basic_c.h"

char *my_strsub(char *str, char a, char z)
{
	int i = 0;

	if (!str)
		return NULL;
	for (i = 0; str[i]; i++) {
		if (str[i] == a)
			str[i] = z;
	}
	return str;
}
