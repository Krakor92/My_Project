/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Utils functions header
*/

#ifndef UTILS2_H
	#define UTILS2_H

	/* Library */
	#include <fcntl.h>
	#include <sys/stat.h>
	#include <sys/types.h>
	#include "utils1.h"

	/* Constants */
	static const char INVALID_OPEN[] = "Invalid open!\n";
	static const char INVALID_READ[] = "Invalid read!\n";
	static const char INVALID_STAT[] = "Invalid stat!\n";

	/* Prototypes */
	//2d_arrays//
	//create_2d_arr.c
	char **create_2d_char_arr(unsigned int, unsigned int);
	int **create_2d_int_arr(unsigned int, unsigned int);
	////////////////////////////////////
	//destroy_2d_arr.c
	void destroy_2d_char_arr(char**);
	void destroy_2d_int_arr(int**);
	/////////////////////////////////
	//file//
	//copy_file_in_str.c
	char *copy_file_in_str(char*);
#endif
