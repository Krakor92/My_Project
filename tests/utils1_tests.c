/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Unit_tests (Ouvre le favoris Unit Tests!!!!)
*/

#include <criterion/criterion.h>
#include "my_project.h"

/******************
* my_char_count.c *
******************/
Test(my_char_count, tests)
{
	char str[] = "And more, much more than this\nI did it my way!";
	char *null = NULL;
	int nb_char;

	nb_char = my_char_count(str, ' ');
	cr_assert_eq(nb_char, 9);
	nb_char = my_char_count(str, 'a');
	cr_assert_eq(nb_char, 2);
	nb_char = my_char_count(str, '\n');
	cr_assert_eq(nb_char, 1);
	nb_char = my_char_count(str, 'z');
	cr_assert_eq(nb_char, 0);
	nb_char = my_char_count(null, ' ');
	cr_assert_eq(nb_char, -1);

}

/**************
* my_getnbr.c *
**************/
Test(my_getnbr, basicTests1)
{
	char str1[] = "ecoekoek--2";
	char str2[] = "-2xexencence";
	char str3[] = "ede--- d34-ded";
	int retval;
	int nb;

	retval = my_getnbr(str1, &nb);
	cr_assert_eq(nb, 2);
	cr_assert_eq(retval, 0);
	retval = my_getnbr(str2, &nb);
	cr_assert_eq(nb, -2);
	cr_assert_eq(retval, 0);
	retval = my_getnbr(str3, &nb);
	cr_assert_eq(nb, 34);
	cr_assert_eq(retval, 0);
}

Test(my_getnbr, errorTests)
{
	char str[] = "And more, much more than this\nI did it my way!";
	char *null = NULL;
	int retval;
	int nb;

	retval = my_getnbr(str, &nb);
	cr_assert_eq(retval, -1);
	retval = my_getnbr(null, &nb);
	cr_assert_eq(retval, -1);

}

/*******************
* my_getnchar_id.c *
*******************/
Test(my_getnchar_id, basicTests)
{
	char str[] = "And more, much more than this\nI did it my way!";
	int id;

	id = my_getnchar_id(str, ' ', 1);
	cr_assert_eq(id, 3);
	id = my_getnchar_id(str, ' ', 2);
	cr_assert_eq(id, 9);
	id = my_getnchar_id(str, '\n', 1);
	cr_assert_eq(id, 29);
	id = my_getnchar_id(str, '\n', 1);
	cr_assert_eq(id, 29);
}

Test(my_getnchar_id, errorTests)
{
	char str[] = "And more, much more than this\nI did it my way!";
	int id;

	id = my_getnchar_id(str, '?', 1);
	cr_assert_eq(id, -1);
	id = my_getnchar_id(str, '\n', 2);
	cr_assert_eq(id, -1);
	id = my_getnchar_id(str, ' ', 0);
	cr_assert_eq(id, -1);
}

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
	int str_len;
	char *arr = NULL;
	return;

	str_len = my_strlen(str);
	cr_assert_eq(str_len, 15);
	arr = malloc(sizeof(char) * str_len);
	if (arr == NULL)
		return;
	my_strcpy(arr, str);
	cr_assert_str_eq(arr, str);
	free(arr);
}

Test(my_strcpy, errorTests)
{
	char *str = NULL;
	char *arr = NULL;
	return;

	my_strcpy(arr, str);
	cr_assert_str_eq(arr, str);
}
