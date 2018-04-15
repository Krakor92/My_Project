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
	size_t nb_char;

	nb_char = my_str_count_words(str);
	cr_assert_eq(nb_char, 11);
}

Test(my_str_count_words, Basic_test_2)
{
	char str[] = "The quick   brown fox\t jumps over\nthe lazy dog!\n";
	size_t nb_char;

	nb_char = my_str_count_words(str);
	cr_assert_eq(nb_char, 9);
}

Test(my_str_count_words, Error_test)
{
	char *str = NULL;
	size_t nb_char;

	nb_char = my_str_count_words(str);
	cr_assert_eq(nb_char, 0);
}

/**********************
* my_str_to_wordtab.c *
**********************/
Test(my_str_to_wordtab, Basic_test)
{
	char str[] = "The quick  brown fox\t jumps over\nthe lazy dog!\n";
	char **wordtab = NULL;

	wordtab = my_str_to_wordtab(str);
	cr_assert_str_eq(wordtab[0], "The");
	cr_assert_str_eq(wordtab[1], "quick");
	cr_assert_str_eq(wordtab[2], "brown");
	cr_assert_str_eq(wordtab[3], "fox");
	cr_assert_str_eq(wordtab[4], "jumps");
	cr_assert_str_eq(wordtab[5], "over");
	cr_assert_str_eq(wordtab[6], "the");
	cr_assert_str_eq(wordtab[7], "lazy");
	cr_assert_str_eq(wordtab[8], "dog!");
	cr_assert_str_eq(str, "The quick  brown fox\t jumps over\nthe lazy dog!\n");
	destroy_2d_char_arr_hard(wordtab);
}

Test(my_str_to_wordtab, Error_test)
{
	char **wordtab = NULL;
	char *str = NULL;

	wordtab = my_str_to_wordtab(str);
	cr_assert_eq(wordtab, NULL);
}

Test(my_str_to_wordtab_2, Basic_test)
{
	char str[] = "The;quick  brown;fox\t; jumps;;;over\nthe lazy dog!\n";
	char **wordtab = NULL;

	wordtab = my_str_to_wordtab_2(str, ';');
	cr_assert_str_eq(wordtab[0], "The");
	cr_assert_str_eq(wordtab[1], "quick");
	cr_assert_str_eq(wordtab[2], "brown");
	cr_assert_str_eq(wordtab[3], "fox");
	cr_assert_str_eq(wordtab[4], "jumps");
	cr_assert_str_eq(wordtab[5], "over");
	cr_assert_str_eq(wordtab[6], "the");
	cr_assert_str_eq(wordtab[7], "lazy");
	cr_assert_str_eq(wordtab[8], "dog!");
	cr_assert_str_eq(str, "The;quick  brown;fox\t; jumps;;;over\nthe lazy dog!\n");
	destroy_2d_char_arr_hard(wordtab);
}

Test(my_str_to_wordtab_2, Error_test)
{
	char **wordtab = NULL;
	char *str = NULL;

	wordtab = my_str_to_wordtab(str);
	cr_assert_eq(wordtab, NULL);
}
