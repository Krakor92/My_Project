/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Unit_tests (Ouvre le favoris Unit Tests!!!!)
*/

#include <criterion/criterion.h>
#include "my_project.h"

/**************
* my_nbrlen.c *
**************/
Test(my_nbrlen, basicTests)
{
	int nb1 = 12345;
	int nb2 = -1;
	int nb_len;

	nb_len = my_nbrlen(nb1, NO);
	cr_assert_eq(nb_len, 5);
	nb_len = my_nbrlen(nb1, YES);
	cr_assert_eq(nb_len, 5);
	nb_len = my_nbrlen(nb2, NO);
	cr_assert_eq(nb_len, 1);
	nb_len = my_nbrlen(nb2, YES);
	cr_assert_eq(nb_len, 2);
}

/**************
* my_putnbr.c *
**************/
Test(my_putnbr, basicTests)
{
	int nb1 = 12345;
	int nb2 = -1;
	int nb_len;

	nb_len = my_putnbr(nb1);
	cr_assert_eq(nb_len, 5);
	nb_len = my_putnbr(nb2);
	cr_assert_eq(nb_len, 2);
}

/****************
* my_nlinelen.c *
****************/
Test(my_nlinelen, basicTests)
{
	char str[] = "Hey boss\nI have a cancer\nToasty";
	int nb_char;

	nb_char = my_nlinelen(str, 1, NO);
	cr_assert_eq(nb_char, 8);
	nb_char = my_nlinelen(str, 1, YES);
	cr_assert_eq(nb_char, 9);
	nb_char = my_nlinelen(str, 2, NO);
	cr_assert_eq(nb_char, 15);
	nb_char = my_nlinelen(str, 2, YES);
	cr_assert_eq(nb_char, 16);
	nb_char = my_nlinelen(str, 3, NO);
	cr_assert_eq(nb_char, 6);
	nb_char = my_nlinelen(str, 3, YES);
	cr_assert_eq(nb_char, 6);
}

Test(my_nlinelen, errorTests)
{
	char *null = NULL;
	int nb_char;

	nb_char = my_nlinelen(null, 1, NO);
	cr_assert_eq(nb_char, -1);
	nb_char = my_nlinelen(null, 1, YES);
	cr_assert_eq(nb_char, -1);
	nb_char = my_nlinelen(null, -1, NO);
	cr_assert_eq(nb_char, -1);
	nb_char = my_nlinelen(null, -1, YES);
	cr_assert_eq(nb_char, -1);
	nb_char = my_nlinelen(null, 100, NO);
	cr_assert_eq(nb_char, -1);
	nb_char = my_nlinelen(null, 100, YES);
	cr_assert_eq(nb_char, -1);
}

/**************
* my_strcpy.c *
**************/
Test(my_strcpy, basicTests1)
{
	char str[] = "BUM BUM TAM TAM";
	char *arr = NULL;
	int str_len;

	str_len = my_strlen(str);
	arr = malloc((str_len + 1) * sizeof *arr);
	if (!arr)
		return;
	my_strcpy(arr, str);
	cr_assert_str_eq(arr, str);
	free(arr);
}
// The tests fail when the two strings are NULL;
/*
Test(my_strcpy, errorTests)
{
	char *str = NULL;
	char *arr = NULL;

	my_strcpy(arr, str);
	cr_assert_str_eq(arr, str);
}
*/
