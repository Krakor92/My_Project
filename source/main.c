/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** My main function
*/
#include "my_project.h"

static void print_help(void)
{
	my_putstr("Project created in language C by Vincent FAIVRE\n\n");
	my_putstr("USAGE\n ./exe arg1 agr2 ...\n\n");
	my_putstr("DESCRIPTION\n arg1\tdescription.\n ");
	my_putstr("arg2\tdescription.\n\n");
	my_putstr("OPTIONS\n -h\tprint the help and quit.\n");
}

int main(int ac, char **av)
{
	if (ac == 2 && my_strequal(av[1], "-h")) {
		print_help();
		return (SUCCESS);
	}
	return (SUCCESS);
}
