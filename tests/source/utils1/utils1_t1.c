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
	cr_assert_eq(id, -2);
}
