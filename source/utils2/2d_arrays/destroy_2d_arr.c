/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** Functions that destroy 2 dimensions arrays (char**, int**, etc...)
*/

#include "utils2.h"

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
