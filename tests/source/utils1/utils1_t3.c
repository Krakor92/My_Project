/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Unit_tests (Ouvre le favoris Unit Tests!!!!)
*/

#include <criterion/criterion.h>
#include "basic_c.h"

/**************
* my_strdup.c *
**************/
Test(my_strdup, basicTests1)
{
	char str[] = "BUM BUM TAM TAM";
	char *arr = NULL;

	arr = my_strdup(str);
	if (!arr)
		return;
	cr_assert_str_eq(arr, str);
	free(arr);
}

/****************
* my_strequal.c *
****************/
Test(my_strequal, basicTests1)
{
	char str[] = "BUM BUM TAM TAM";
	char str2[] = "BUM BUM TAM TAM";
	char str3[] = "BUM BUM TAM TAM ";
	char str4[] = "BUM BUM TAM";
	char *arr = NULL;
	int retval;

	retval = my_strequal(str, arr);
	cr_assert_eq(retval, false);
	retval = my_strequal(arr, arr);
	cr_assert_eq(retval, true);
	retval = my_strequal(str, str);
	cr_assert_eq(retval, true);
	retval = my_strequal(str, str2);
	cr_assert_eq(retval, true);
	retval = my_strequal(str, str3);
	cr_assert_eq(retval, false);
	retval = my_strequal(str, str4);
	cr_assert_eq(retval, false);
}

/*************************
* my_strequal_from_a2b.c *
*************************/
Test(my_strequal_from_a2b, basicTests1)
{
	char str[] = "The quick brown fox jumps over the lazy dog!\n";
	int retval;

	retval = my_strequal_from_a2b(str, "quick", 4, 8);
	cr_assert_eq(retval, true);
	retval = my_strequal_from_a2b(str, " ", 3, 3);
	cr_assert_eq(retval, true);
	retval = my_strequal_from_a2b("lul", "lul", 0, 2);
	cr_assert_eq(retval, true);
}

Test(my_strequal_from_a2b, exceptionTests1)
{
	char str[] = "The quick brown fox jumps over the lazy dog!\n";
	char *null = NULL;
	int retval;

	retval = my_strequal_from_a2b(null, NULL, 0, 0);
	cr_assert_eq(retval, true);
	retval = my_strequal_from_a2b(null, str, 3, 3);
	cr_assert_eq(retval, false);
	retval = my_strequal_from_a2b(str, null, 3, 3);
	cr_assert_eq(retval, false);
	retval = my_strequal_from_a2b("lul", "lulul", 0, 2);
	cr_assert_eq(retval, false);
	retval = my_strequal_from_a2b("hello", "hello", 0, 20);
	cr_assert_eq(retval, -1);
	retval = my_strequal_from_a2b("lul", "lul", 1, 0);
	cr_assert_eq(retval, -1);
	retval = my_strequal_from_a2b("lul", "lul", 3, 5);
	cr_assert_eq(retval, -1);
}

/**************
* my_strlen.c *
**************/
Test(my_strlen, basicTests1)
{
	char str[] = "BUM BUM TAM TAM";
	char s[] = "BUM B";
	char *arr = NULL;
	int str_len;

	arr = malloc(10 * sizeof *arr);
	if (!arr)
		return;
	str_len = my_strlen(arr);
	cr_assert_eq(str_len, 0);
	free(arr);
	str_len = my_strlen(str);
	cr_assert_eq(str_len, 15);
	str_len = my_strlen(s);
	cr_assert_eq(str_len, 5);
}
