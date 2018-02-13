/*
** EPITECH PROJECT, 2017
** [N/A]
** File description:
** 3 functions :
**
** 1. pos_or_neg =
** Works with my_getnbr only !
** Check whether the number in the text is negative or positive
**
** @param	str		String to parse
** @param	id_first_digit	Id of the first digit encountered
** 				in the {str}
** @return	1 if the number is positive OR -1 if it's negative
**
**
** 2. get_the_nb_bounds =
** Works with my_getnbr only !
** Fill the 3 ints given as parameter (with info about
** the position of the number in the string)
**
** @param	str		String to parse
** @param	id_first	Id of the first digit of the number
** @param	id_final	Id of the last digit of the number
** @param	nb_bounds	Said whether or not the function encountered
**				The first digit (=1), first and last (=2)
**				or none (=0)
** @return	N/A
**
**
** 3. my_getnbr =
** Get the first number encountered in a str and put it in a int
**
** @param	str	String to parse
** @param	nb	Int to fill
** @return	0 if it works well (a number is present in the {str}) OR
**		-1 if there is no number in the {str}
*/
#include <stdio.h>
#include "utils1.h"

static int pos_or_neg(char const *str, int *id_first_digit)
{
	int i = 0;
	int minus_count = 0;

	while (i < *id_first_digit) {
		if (str[i] == '-') {
			minus_count += 1;
		}
		else if (str[i] != '+') {
			minus_count = 0;
		}
		i += 1;
	}
	if ((minus_count % 2) == 0) {
		return (1);
	}
	return (-1);
}

static void get_the_nb_bounds(char const *str,
				int *id_first,
				int *id_final,
				int *nb_bounds)
{
	int i = 0;

	while (str[i] != '\0') {
		if (IS_NUMBER(str[i])) {
			if (*nb_bounds == 0) {
				*id_first = i;
				*nb_bounds = 1;
			}
		}
		else if (*nb_bounds == 1) {
			*id_final = i - 1;
			*nb_bounds = 2;
			return;
		}
		i += 1;
	}
	if (*nb_bounds == 0)
		return;
	*id_final = i - 1;
}

int my_getnbr(char const *str, int *nb)
{
	int i = 0;
	int id_first = 0;
	int id_final = 0;
	int nb_limit = 0;
	int p_or_n = 0;

	*nb = 0;
	get_the_nb_bounds(str, &id_first, &id_final, &nb_limit);
	if (nb_limit == 0 || ((id_final - id_first + 1) > 10))
		return (-1);
	p_or_n = pos_or_neg(str, &id_first);
	for (i = id_first; i <= id_final; i += 1)
		*nb = *nb * 10 + (str[i] - '0');
	if ((id_final - id_first + 1) == 10) {
		if ((str[id_final - 9] > '2') || (*nb < 0))
			return (-1);
	}
	*nb = *nb * p_or_n;
	return (0);
}
