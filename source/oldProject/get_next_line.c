/*
** EPITECH PROJECT, 2017
** [GNL] {Vincent FAIVRE}
** File description:
** Get the next line of a text each time you call it
*/

#include "get_next_line.h"

static char get_next_char(int fd)
{
	static char buffer[READ_SIZE];
	static int char_read = 0;
	static int cpt = 0;
	char new_char;

	if (char_read == 0) {
		char_read = read(fd, buffer, READ_SIZE);
		cpt = 0;
		if (char_read <= 0)
			return '\0';
	}
	new_char = buffer[cpt];
	cpt++;
	char_read--;
	return new_char;
}

/*
static char *gnl_str_realloc(char* old_str, int size, int new_size)
{
	char *new_str;
	int cpt = 0;

	new_str = malloc(new_size * sizeof(*new_str));
	if (!new_str)
		return NULL;
	while (cpt < size) {
		new_str[cpt] = old_str[cpt];
		cpt++;
	}
	free(old_str);
	return new_str;
}
*/

char *end_read_loop(char next_char, char *str, int *len, int *len_read)
{
	if (next_char == '\n') {
		str = my_str_realloc(str, *len, *len + 2);
		str[*len] = '\n';
		*len = *len + 1;
	}
	str[*len] = '\0';
	if (len_read)
		*len_read = *len;
	return str;
}

static char *read_loop(int fd, char *str, int *len_read)
{
	char next_char;
	int read_size = READ_SIZE;
	int len = 0;

	next_char = get_next_char(fd);
	while (next_char != '\n' && next_char != '\0') {
		str[len] = next_char;
		next_char = get_next_char(fd);
		len++;
		if (len == read_size) {
			str = my_str_realloc(str, len, len + 1);
			read_size++;
			if (!str)
				return my_ptr_error(INVALID_MALLOC);
		}
	}
	str = end_read_loop(next_char, str, &len, len_read);
	return str;
}

char *get_next_line(int fd, int *len_read)
{
	char *str = NULL;

	if (READ_SIZE < 1)
		return my_ptr_error(INVALID_READ_SIZE);
	str = malloc((READ_SIZE + 1) * sizeof(*str));
	if (!str)
		return my_ptr_error(INVALID_MALLOC);
	str = read_loop(fd, str, len_read);
	return str;
}
