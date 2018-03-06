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
	//
	int my_getnbr(char const*, int*);
	int my_getnchar_id(char const*, char, int);
	int my_int_error(char const*);
	//my_nbrlen.c
	unsigned int my_nbrlen(int, int);
	unsigned int my_nb_digits(int);
	//
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
	char *my_strncpy(char*, char const*, int);
	unsigned int my_unbrlen(unsigned int);
#endif
