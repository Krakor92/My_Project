/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Unit_tests (Ouvre le favoris Unit Tests!!!!)
*/

#include <criterion/criterion.h>
#include "basic_c.h"

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
	cr_assert_eq(nb_char, 0);

}

/****************
* my_strcheck.c *
****************/
Test(my_strcheck, basicTests)
{
	char test[] = "OOHHHH";
	bool_t retval;

	retval = my_strcheck(test, "OH");
	cr_assert_eq(retval, TRUE);
	retval = my_strcheck(test, "OH ko");
	cr_assert_eq(retval, TRUE);
	retval = my_strcheck(test, "se");
	cr_assert_eq(retval, FALSE);
}

/**************
* my_getnbr_v2.c *
**************/
Test(my_getnbr_v2, basic)
{
	char str1[] = "2147483647";
	char str2[] = "-2xexencence";
	char str3[] = "ede--- d34-ded";
	char str4[] = "-2147483648";
	int retval;
	int nb;

	retval = my_getnbr_v2(str1, &nb);
	cr_assert_eq(nb, 2147483647);
	cr_assert_eq(retval, 0);
	retval = my_getnbr_v2(str2, &nb);
	cr_assert_eq(nb, -2);
	cr_assert_eq(retval, 0);
	retval = my_getnbr_v2(str3, &nb);
	cr_assert_eq(nb, 34);
	cr_assert_eq(retval, 0);
	retval = my_getnbr_v2(str4, &nb);
	cr_assert_eq(nb, -2147483648);
	cr_assert_eq(retval, 0);
}

Test(my_getnbr_v2, overflow)
{
	char str1[] = "2147483648";
	char str2[] = "12327382492231";
	char str3[] = "2453728492";
	char str4[] = "-2147483649";
	int retval;
	int nb;

	retval = my_getnbr_v2(str1, &nb);
	cr_assert_eq(retval, -1);
	retval = my_getnbr_v2(str2, &nb);
	cr_assert_eq(retval, -1);
	retval = my_getnbr_v2(str3, &nb);
	cr_assert_eq(retval, -1);
	retval = my_getnbr_v2(str4, &nb);
	cr_assert_eq(retval, -1);
}

Test(my_getnbr_v2, exception)
{
	char str[] = "The quick brown fox jumps over the lazy dog!\n";
	char *null = NULL;
	int retval;
	int nb;

	retval = my_getnbr_v2(str, &nb);
	cr_assert_eq(retval, -1);
	retval = my_getnbr_v2(null, &nb);
	cr_assert_eq(retval, -1);
	retval = my_getnbr_v2(str, NULL);
	cr_assert_eq(retval, -1);
	retval = my_getnbr_v2(NULL, NULL);
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
	cr_assert_eq(id, -2);
}
