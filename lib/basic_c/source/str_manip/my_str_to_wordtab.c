/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** my_str_to_wordtab.c
*/

#include <stdarg.h>
#include "basic_c.h"

char **my_str_to_wordtab(char const *str)
{
	size_t nb_words = my_str_count_words(str);
	size_t i = 0;
	size_t word_id = 0;
	bool_t word_met = FALSE;
	char **wordarr = NULL;

	if(!str)
		return NULL;
	wordarr = malloc((nb_words + 1) * sizeof(*wordarr));
	if (!wordarr)
		return my_ptr_error(INVALID_MALLOC);

	while (str[i] && word_id < nb_words) {
		while (IS_WORDCHAR(str[i])) {
			word_met = TRUE;
			i++;
		}
		if (word_met == TRUE) {
			wordarr[word_id] = malloc((i + 1) * sizeof(*wordarr[word_id]));
			my_strncpy(wordarr[word_id], str, i);
			str += i;
			i = 0;
			word_id++;
			word_met = FALSE;
		}
		str++;
	}
	return wordarr;
}

char **my_str_to_wordtab_2(char const *str, char separator)
{
	size_t nb_words = my_str_count_words_2(str, separator);
	size_t i = 0;
	size_t word_id = 0;
	bool_t word_met = FALSE;
	char **wordarr = NULL;

	if(!str)
		return NULL;
	wordarr = malloc((nb_words + 1) * sizeof(*wordarr));
	if (!wordarr)
		return my_ptr_error(INVALID_MALLOC);
	while (str[i] && word_id < nb_words) {
		while (IS_WORDCHAR(str[i]) && str[i] != separator) {
			word_met = TRUE;
			i++;
		}
		if (word_met == TRUE) {
			wordarr[word_id] = malloc((i + 1) * sizeof(*wordarr[word_id]));
			my_strncpy(wordarr[word_id], str, i);
			str += i;
			i = 0;
			word_id++;
			word_met = FALSE;
		}
		str++;
	}
	return wordarr;
}
