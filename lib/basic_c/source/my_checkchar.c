/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** 22 rows
*/

#include "basic_c.h"

int is_a_number(char c)
{
	if ('0' <= c && c <= '9')
		return true;
	return false;
}

int is_a_letter(char c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
		return true;
	return false;
}
