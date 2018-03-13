/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Unit_tests (Ouvre le favoris Unit Tests!!!!)
*/

#include <criterion/criterion.h>
#include "utils1.h"

/***************
* my_strncpy.c *
***************/
Test(my_strncpy, basicTests1)
{
	char str[] = "BUM BUM TAM TAM";
	char s[] = "BUM B";
	int str_len;
	char *arr = NULL;

	str_len = my_strlen(s);
	arr = malloc(str_len * sizeof *arr);
	if (!arr)
		return;
	my_strncpy(arr, str, 5);
	printf("%s", arr);
	cr_assert_str_eq(arr, s);
	free(arr);
}

Test(my_strncpy, basicTests2)
{
	char str[] = "BUM BUM TAM TAM";
	int str_len;
	char *arr = NULL;

	str_len = my_strlen(str);
	arr = malloc(str_len * sizeof *arr);
	if (!arr)
		return;
	my_strncpy(arr, str, 20);
	cr_assert_str_eq(arr, str);
	free(arr);
}

Test(my_strcpy_from_a_to_b, basicTests1)
{
	char str[] = "BUM BUM TAM TAM";
	char s[6];
	char *arr = NULL;

	arr = my_strcpy_from_a_to_b(s, str, 0, 4);
	cr_assert_str_eq(arr, "BUM B");
	my_strcpy_from_a_to_b(s, str, 4, 6);
	cr_assert_str_eq(arr, "BUM");
	my_strcpy_from_a_to_b(arr, str, 7, 10);
	cr_assert_str_eq(s, " TAM");
}

Test(my_strcpy_till_char, basicTests1)
{
	char str[] = "Hog is the best!";
	char s[15];

	my_strcpy_till_char(s, str, ' ', NO);
	cr_assert_str_eq(s, "Hog");
	my_strcpy_till_char(s, str, 's', YES);
	cr_assert_str_eq(s, "Hog is");
	my_strcpy_till_char(s, str, 'e', YES);
	cr_assert_str_eq(s, "Hog is the");
}
