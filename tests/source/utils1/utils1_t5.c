/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Unit_tests (Ouvre le favoris Unit Tests!!!!)
*/

#include <criterion/criterion.h>
#include "basic_c.h"

/***********************
* my_str_count_words.c *
***********************/
Test(my_str_count_words, Basic_test_1)
{
	char str[] = "And more, much more than this\nI did it my way!";
	int nb_char;

	nb_char = my_str_count_words(str);
	cr_assert_eq(nb_char, 11);
}

/**********************
* my_str_to_wordarr.c *
**********************/
Test(my_str_to_wordarr, Basic_test)
{
	char str[] = "The quick  brown fox\t jumps over\nthe lazy dog!\n";
	char **wordarr = NULL;

	wordarr = my_str_to_wordarr(str);
	cr_assert_str_eq(wordarr[0], "The");
	cr_assert_str_eq(wordarr[1], "quick");
	cr_assert_str_eq(wordarr[2], "brown");
	cr_assert_str_eq(wordarr[3], "fox");
	cr_assert_str_eq(wordarr[4], "jumps");
	cr_assert_str_eq(wordarr[5], "over");
	cr_assert_str_eq(wordarr[6], "the");
	cr_assert_str_eq(wordarr[7], "lazy");
	cr_assert_str_eq(wordarr[8], "dog!");
	cr_assert_str_eq(str, "The quick  brown fox\t jumps over\nthe lazy dog!\n");
	destroy_2d_char_arr_hard(wordarr);
}

Test(my_str_to_wordarr, Error_test)
{
	char **wordarr = NULL;
	char *str = NULL;

	wordarr = my_str_to_wordarr(str);
	cr_assert_eq(wordarr, NULL);
}
