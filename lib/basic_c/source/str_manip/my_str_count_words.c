/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** my_str_to_wordtab.c
*/

#include "basic_c.h"

size_t my_str_count_words(char const *str)
{
	size_t nb_words = 0;
	int i = 0;

	if (!str)
		return nb_words;
	for (i = 0; str[i]; i++) {
		if (IS_WORDCHAR(str[i])) {
			nb_words++;
			while (IS_WORDCHAR(str[i]))
				i++;
		}
	}
	return nb_words;
}

size_t my_str_count_words_2(char const *str, char separator)
{
	size_t nb_words = 0;
	int i = 0;

	if (!str)
		return nb_words;
	for (i = 0; str[i]; i++) {
		if (IS_WORDCHAR(str[i]) && str[i] != separator) {
			nb_words++;
			while (IS_WORDCHAR(str[i]) && str[i] != separator)
				i++;
		}
	}
	return nb_words;
}
