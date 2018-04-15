/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Unit_tests (Ouvre le favoris Unit Tests!!!!)
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
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
	int len;

	ptr = get_next_line(fd, &len);
	cr_assert_str_eq(ptr, "The quick brown fox jumps over the lazy dog\n");
	cr_assert_eq(len, 44);
	free(ptr);
	ptr = get_next_line(fd, &len);
	cr_assert_str_eq(ptr, "The above phrase contains all the alphabetical \
letters\n");
	cr_assert_eq(len, 55);
	free(ptr);
	ptr = get_next_line(fd, &len);
	cr_assert_str_eq(ptr, "Yep it's impressive!\n");
	cr_assert_eq(len, 21);
	free(ptr);
	ptr = get_next_line(fd, &len);
	cr_assert_str_eq(ptr, "");
	cr_assert_eq(len, 0);
	free(ptr);
	ptr = get_next_line(fd, &len);
	cr_assert_str_eq(ptr, "");
	cr_assert_eq(len, 0);
	free(ptr);
}

/*
Test(get_next_line, Basic1)
{
	char *ptr = NULL;
	int len = 0;

	cr_redirect_stdout ();
	ptr = get_next_line(0, &len);
	printf("\n%d, %s", len, ptr);

	cr_assert_eq(ptr, "gout bite");
}
*/
