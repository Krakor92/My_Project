/*
** EPITECH PROJECT, 2017
** [MY_PRINTF] {Vincent FAIVRE}
** File description:
** My_printf's Header
*/

#ifndef	MY_PRINTF_H
	#define MY_PRINTF_H

	/* Library */
	#include <stdarg.h>
	#include "basic_c.h"

	/* Constants */
	static const int BINARY_BUFFER = 32;
	static const int OCTAL_BUFFER = 11;
	static const int HEXA_BUFFER = 8;

	/* Structs */
	typedef struct converter_flags
	{
		int (*ptrfunction)(va_list);
		char keyword;
	} converter_t;

	/* Prototypes */
	//base_converter_flags.c
	int b_flag(va_list);
	int o_flag(va_list);
	int x_flag(va_list);
	int majx_flag(va_list);
	///////////////////////
	//base_converter.c
	int dec_to_binary_base(unsigned int);
	int dec_to_octal_base(unsigned int);
	int dec_to_hexa_base(unsigned int);
	int dec_to_majhexa_base(unsigned int);
	int print_converted_arr(int, char*);
	//////////////////////////////////////
	//basic_flags.c
	int c_flag(va_list);
	int di_flag(va_list);
	int s_flag(va_list);
	int u_flag(va_list);
	/////////////////////
	//my_printf.c
	int my_printf(const char*, ...);
	//specific_flags.c
	int percent_flag(va_list);
	int p_flag(va_list);
	//////////////////////////
#endif
