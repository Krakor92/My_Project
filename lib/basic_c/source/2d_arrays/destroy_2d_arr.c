/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** Functions that destroy 2 dimensions arrays (char**, int**, etc...)
*/

#include "basic_c.h"

/*
** destroy_2d_char_arr =
** Destroy an allocated array of strings
**
** @param	arr	The array of strings
** @return	N/A
*/
void destroy_2d_char_arr(char **arr2d)
{
	free(arr2d[0]);
	free(arr2d);
}

void destroy_2d_char_arr_hard(char **arr2d)
{
	size_t i = 0;

	for (i = 0; arr2d[i]; i++)
		free(arr2d[i]);
	free(arr2d);
}

/*
** destroy_2d_int_arr =
** Destroy an allocated array of int arrays
**
** @param	arr	The array of int arrays
** @return	N/A
*/
void destroy_2d_int_arr(int **arr2d)
{
	free(arr2d[0]);
	free(arr2d);
}

void destroy_2d_int_arr_hard(int **arr2d)
{
	size_t i = 0;

	for (i = 0; arr2d[i]; i++)
		free(arr2d[i]);
	free(arr2d);
}
