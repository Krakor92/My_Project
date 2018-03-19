/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** 22 rows
*/

#include "basic_c.h"

char *my_strsub(char *str, char a, char z)
{
	int i;

	if (!str)
		return NULL;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == a)
			str[i] = z;
	}
	return str;
}
