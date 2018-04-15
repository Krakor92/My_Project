/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** my_str_to_wordtab.c
*/

#include <stdarg.h>
#include "basic_c.h"

char **my_str_to_wordarr(char const *str)
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

/*
char **my_str_to_wordtab(char *str, char separator, ...)
{
	va_list ap;
	int	nb_sep = my_char_count(str, separator);
	char	**wordtab = NULL;
	int	i = 0;
	int	index_sep = 0;

	va_start(ap, separator);
	wordtab = malloc(sizeof(*wordtab) * (nb_sep + 2));
	if (!wordtab)
		return my_ptr_error(INVALID_MALLOC);
	while (str[i]) {
		if (str[i] == separator) {
			wordtab[index_sep] = malloc((i + 1) * sizeof(*wordtab[index_sep]));
			if (!wordtab[index_sep])
				return my_ptr_error(INVALID_MALLOC);
			my_strncpy(wordtab[index_sep], str, i);
			str += i + 1;
			i = 0;
			++index_sep;
		}
		i++;
	}
	wordtab[index_sep] = malloc(sizeof(char) * (i + 1));
	if (!wordtab[index_sep])
		return my_ptr_error(INVALID_MALLOC);
	my_strcpy(wordtab[index_sep], str);
	wordtab[nb_sep + 1] = NULL;
	va_end(ap);
	return wordtab;
}
*/
