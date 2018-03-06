/*
** EPITECH PROJECT, 2017
** [N/A] Vincent FAIVRE
** File description:
** Function that copies the content of a file in a str
*/

#include "utils2.h"

char *copy_file_in_str(char *file)
{
	struct stat info;
	char *str;
	int fd;
	int retstat;
	int len;

	fd = open(file, O_RDONLY);
	if (fd  == -1)
		return (my_ptr_error(INVALID_OPEN));
	retstat = stat(file, &info);
	if (retstat == -1)
		return (my_ptr_error(INVALID_STAT));
	str = malloc(sizeof(char) * (info.st_size + 1));
	len = read(fd, str, info.st_size);
	if (len < 0)
		return (my_ptr_error(INVALID_READ));
	str[info.st_size] = '\0';
	close(fd);
	return (str);
}
