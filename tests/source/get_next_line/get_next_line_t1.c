/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Unit_tests (Ouvre le favoris Unit Tests!!!!)
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

/************************
* get_next_line configs *
************************/
int fd;

void openfile(void)
{
	fd = open("source/get_next_line/file.txt", O_RDONLY);
	cr_assert_neq(fd, -1, "Invalid open!\n");
}

void closefile(void)
{
	if (fd != -1)
		close(fd);
}

TestSuite(get_next_line, .init = openfile, .fini = closefile);

Test(get_next_line, Basic)
{
	char *ptr = NULL;

	ptr = get_next_line(fd);
	cr_assert_str_eq(ptr, "The quick brown fox jumps over the lazy dog");
	ptr = get_next_line(fd);
	cr_assert_str_eq(ptr, "The above phrase contains all the alphabetical \
letters");
	ptr = get_next_line(fd);
	cr_assert_str_eq(ptr, "Yep it's impressive!");
	ptr = get_next_line(fd);
	cr_assert_str_eq(ptr, "");
	free(ptr);
}
