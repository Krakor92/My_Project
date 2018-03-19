/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Utils functions header
*/

#ifndef UTILS1_H
	#define UTILS1_H

	/* Library */
	#include <stdbool.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>

	/* Macros */
	#define IS_NUMBER(c) c >= '0' && c <= '9'
	#define IS_NB_IN_RANGE_S(nb, min, max) nb > min && nb < max
	#define IS_NB_IN_RANGE(nb, min, max) nb >= min && nb <= max

	/* Constants */
	static const char INVALID_MALLOC[] = "Invalid malloc !\n";
	static const int YES = 1;
	static const int NO = 0;

	/* Prototypes */
	//my_char_count.c
	int my_char_count(const char*, char);
	int my_line_char_count(char*, char, int);
	/////////////////////////////////////////
	//my_checkchar.c
	int is_a_number(char);
	int is_a_letter(char);
	//////////////////////
	int my_checkstr(char*, char*);
	int my_getnbr(char const*, int*);
	int my_getnchar_id(char const*, char, int);
	int my_int_error(char const*);
	unsigned int my_nbrlen(int, int);
	int my_nlinelen(char const*, int, int);
	void *my_ptr_error(char const*);
	void my_putchar(char);
	int my_putnbr(int);
	int my_putstr_error(char const*);
	int my_putstr(char const*);
	unsigned int my_putunbr(unsigned int);
	char *my_strcpy(char*, char const*);
	char *my_strdup(char const*);
	int my_strequal(const char*, const char*);
	int my_strlen(char const*);
	char *my_strsub(char*, char, char);
	///////////////////////////////////////////
	//my_strncpy.c
	char *my_strncpy(char*, char const*, int);
	char *my_strcpy_from_a_to_b(char*, char const*, int, int);
	char *my_strcpy_till_char(char*, char const*, char, int);
	//////////////////////////////////////////////////////////
	unsigned int my_unbrlen(unsigned int);
#endif
