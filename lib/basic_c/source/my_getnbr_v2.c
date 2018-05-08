/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** 3 functions
*/

#include "basic_c.h"
#include "my_getnbr.h"

static int check_int_overflow(strnbr_t *strnbr)
{
	if (!strnbr)
		return -2;
	if (strnbr->nbr == -2147483648)
		return 0;
	if ((strnbr->id_last_digit - strnbr->id_first_digit + 1) == 10 &&
	((strnbr->str[strnbr->id_last_digit - 9] > '2') || (strnbr->nbr < 0)))
		return -1;
	return 0;
}

static int extract_the_nbr_from_the_str(strnbr_t *strnbr)
{
	size_t i = 0;

	if ((my_strequal_from_a2b(strnbr->str, "2147483648",
	strnbr->id_first_digit, strnbr->id_last_digit) == true)
	&& strnbr->neg_factor == -1) {
		strnbr->nbr = -2147483648;
		strnbr->neg_factor = 1;
		return 0;
	}
	for (i = strnbr->id_first_digit; i <= strnbr->id_last_digit; i++)
		strnbr->nbr = strnbr->nbr * 10 + (strnbr->str[i] - '0');
	if (strnbr->nbr == -2147483648)
		return -1;
	return 0;
}

static void is_nbr_pos_or_neg(strnbr_t *strnbr)
{
	size_t i = 0;
	size_t minus_count = 0;

	if (!strnbr || !strnbr->str)
		return;
	for (i = 0; i < strnbr->id_first_digit; i++) {
		if (strnbr->str[i] == '-')
			minus_count++;
		else if (strnbr->str[i] != '+')
			minus_count = 0;
	}
	if ((minus_count % 2) == 0)
		strnbr->neg_factor = 1;
	else
		strnbr->neg_factor = -1;
}

static void get_the_nb_bounds_v2(strnbr_t *strnbr, size_t *nb_bounds)
{
	size_t i = 0;

	if (!strnbr || !strnbr->str)
		return;
	for (i = 0; strnbr->str[i]; i++) {
		if (IS_NUMBER(strnbr->str[i]) && *nb_bounds == 0) {
			strnbr->id_first_digit = i;
			*nb_bounds = 1;
		}
		if (!(IS_NUMBER(strnbr->str[i])) && *nb_bounds == 1) {
			strnbr->id_last_digit = i - 1;
			*nb_bounds = 2;
			return;
		}
	}
	if (*nb_bounds == 1)
		strnbr->id_last_digit = i - 1;
}

int my_getnbr_v2(char const *str, int *nb)
{
	strnbr_t strnbr;
	size_t nb_bounds = 0;

	if (!str || !nb)
		return -1;
	strnbr.str = str;
	strnbr.nbr = 0;
	get_the_nb_bounds_v2(&strnbr, &nb_bounds);
	if (!nb_bounds ||
		(strnbr.id_last_digit - strnbr.id_first_digit + 1) > 10)
		return my_int_error("Int Overflow! (More than 10 digits)\n");
	is_nbr_pos_or_neg(&strnbr);
	if (extract_the_nbr_from_the_str(&strnbr))
		return my_int_error("Int Overflow!\n");
	if (check_int_overflow(&strnbr) == -1)
		return my_int_error("Int Overflow!\n");
	*nb = strnbr.nbr * strnbr.neg_factor;
	return 0;
}
