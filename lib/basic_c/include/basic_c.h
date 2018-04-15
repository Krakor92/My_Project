/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** basic_c.h
*/

#ifndef __BASIC_C__H__
	#define __BASIC_C__H__

	/* Library */
	#include <stdbool.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <fcntl.h>
	#include <sys/stat.h>
	#include <sys/types.h>

	/* Macros */
	#define IS_NUMBER(c) '0' <= c && c <= '9'
	#define IS_NB_IN_RANGE_S(nb, min, max) nb > min && nb < max
	#define IS_NB_IN_RANGE(nb, min, max) nb >= min && nb <= max
	#define IS_PRINTABLE(c) 32 <= c && c <= 126
	#define IS_WORDCHAR(c) 32 < c && c <= 126

	/* Constants */
	static const int YES = 1;
	static const int NO = 0;
	static const char INVALID_MALLOC[] = "Invalid malloc !\n";
	static const char INVALID_OPEN[] = "Invalid open!\n";
	static const char INVALID_READ[] = "Invalid read!\n";
	static const char INVALID_STAT[] = "Invalid stat!\n";

	/* Enums */
	typedef enum bool_e
	{
		FALSE,
		TRUE
	} bool_t;

	/* Prototypes */
	//my_char_count.c//
	size_t my_char_count(const char*, char);
	int my_line_char_count(char*, char, int);
	//my_char_check.c//
	bool_t is_a_number(char);
	bool_t is_a_letter(char);
	bool_t is_a_printable_char(char c);
	//FILE_NAME//
	int my_getnbr(char const*, int*);
	int my_getnchar_id(char const*, char, size_t);
	int my_int_error(char const*);
	size_t my_nbrlen(int, bool_t);
	size_t my_nlinelen(char const*, size_t, bool_t);
	void *my_ptr_error(char const*);
	void my_putchar(char);
	size_t my_putnbr(int);
	size_t my_putstr_error(char const*);
	size_t my_putstr(char const*);
	unsigned int my_putunbr(unsigned int);
	bool_t my_strcheck(const char*, const char*);
	char *my_strcpy(char*, char const*);
	char *my_strdup(char const*);
	int my_strequal(const char*, const char*);
	int my_strlen(char const*);
	char *my_strsub(char*, char, char);
	unsigned int my_unbrlen(unsigned int);
	//my_strncpy.c//
	char *my_strncpy(char*, char const*, size_t);
	char *my_strcpy_from_a2b(char*, char const*, size_t, size_t);
	char *my_strcpy_till_char(char*, char const*, char, bool_t);
	//////////////////////////////////////////////////////////

	////2d_arrays////
	//create_2d_arr.c//
	char **create_2d_char_arr(size_t, size_t);
	int **create_2d_int_arr(size_t, size_t);
	//destroy_2d_arr.c//
	void destroy_2d_char_arr(char**);
	void destroy_2d_char_arr_hard(char**);
	void destroy_2d_int_arr(int**);
	void destroy_2d_int_arr_hard(int**);
	//print_2d_arr.c//
	void print_2d_char_arr(char**);
	void print_2d_int_arr(int**);

	////file_manip////
	//copy_file_in_str.c//
	char *copy_file_in_str(char*);

	////str_manip////
	//my_str_count_words.c//
	size_t my_str_count_words(const char *str);
	//my_str_realloc.c//
	char *my_str_realloc(char*, size_t, size_t);
	//my_str_to_wordtab.c//
	char **my_str_to_wordarr(char const*);
	//my_strcat.c//
	char *my_strcat(char*, const char*);
#endif
