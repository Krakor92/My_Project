/*
** EPITECH PROJECT, 2017
** [GNL] {Vincent FAIVRE}
** File description:
** Get_next_line's header
*/

#ifndef GET_NEXT_LINE_H
	#define GET_NEXT_LINE_H
	#define READ_SIZE 1

	/* Library */
	#include <stdlib.h>
	#include <unistd.h>
	#include "basic_c.h"

	/* Constants */
	static const char INVALID_READ_SIZE[] = "Invalid READ_SIZE !\n";

	/* Prototypes */
	char *get_next_line(int);
#endif
