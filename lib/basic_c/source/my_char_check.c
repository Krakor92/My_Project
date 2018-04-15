/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** 22 rows
*/

#include "basic_c.h"

bool_t is_a_number(char c)
{
	if ('0' <= c && c <= '9')
		return TRUE;
	return FALSE;
}

bool_t is_a_letter(char c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
		return TRUE;
	return FALSE;
}

bool_t is_a_printable_char(char c)
{
	if (32 <= c && c <= 126)
		return TRUE;
	return FALSE;
}
