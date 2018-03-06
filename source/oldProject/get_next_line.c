/*
** EPITECH PROJECT, 2017
** [GNL] {Vincent FAIVRE}
** File description:
** Get the next line of a text each time you call it
*/

#include "get_next_line.h"
#include "utils1.h"

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
			return ('\0');
	}
	new_char = buffer[cpt];
	cpt += 1;
	char_read -= 1;
	return (new_char);
}

static char *str_realloc(char* old_str, int size, int new_size)
{
	char *new_str = malloc(sizeof(char) * new_size);
	int cpt = 0;

	if (new_str == NULL)
		return (NULL);
	while (cpt < size) {
		new_str[cpt] = old_str[cpt];
		cpt += 1;
	}
	free(old_str);
	old_str = NULL;
	return (new_str);
}

static char *read_loop(int fd, char *str)
{
	char next_char;
	int len = 0;
	int read_size = READ_SIZE;

	next_char = get_next_char(fd);
	while (next_char != '\n' && next_char != '\0') {
		str[len] = next_char;
		next_char = get_next_char(fd);
		len += 1;
		if (len == read_size) {
			str = str_realloc(str, len, len + 1);
			read_size += 1;
			if (str == NULL)
				return (my_ptr_error(INVALID_MALLOC));
		}
	}
	str[len] = '\0';
	return (str);
}

char *get_next_line(int fd)
{
	char *str = NULL;

	if (READ_SIZE < 1)
		return (my_ptr_error(INVALID_READ_SIZE));
	str = malloc(READ_SIZE + 1);
	if (str == NULL)
		return (my_ptr_error(INVALID_MALLOC));
	str = read_loop(fd, str);
	return (str);
}
