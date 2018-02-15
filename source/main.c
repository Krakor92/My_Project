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

static void print_all_nb_conversion(int nb)
{
	my_printf("%d\nEn binaire = %b\nEn octal = %o\nEn hexadécimal = %x\n",
	nb, nb, nb, nb);
}

int main(int ac, char **av)
{
	if (ac == 2 && my_strequal(av[1], "-h")) {
		print_help();
		return (SUCCESS);
	}
	print_all_nb_conversion(120);
	return (SUCCESS);
}
