/*
** EPITECH PROJECT, 2017
** [N/A] Vincent FAIVRE
** File description:
** Function that copies the content of a file in a str
*/

#include "basic_c.h"

char *copy_file_in_str(char *file)
{
	struct stat info;
	char *str = NULL;
	int fd;
	int len;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return my_ptr_error(INVALID_OPEN);
	if (stat(file, &info) == -1)
		return my_ptr_error(INVALID_STAT);
	str = malloc((info.st_size + 1) * sizeof *str);
	if (!str)
		return my_ptr_error(INVALID_MALLOC);
	len = read(fd, str, info.st_size);
	if (len < 0)
		return my_ptr_error(INVALID_READ);
	str[info.st_size] = '\0';
	close(fd);
	return str;
}

/*
char *copy_file_in_str_2(char *file) //without using "struct stat", only with get_next_line
{
	char *str;
	int fd;
	int len;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return my_ptr_error(INVALID_OPEN);
	str = malloc((info.st_size + 1) * sizeof *str);
	if (!str)
		return my_ptr_error(INVALID_MALLOC);
	len = read(fd, str, info.st_size);
	if (len < 0)
		return my_ptr_error(INVALID_READ);
	str[info.st_size] = '\0';
	close(fd);
	return str;
}
*/
