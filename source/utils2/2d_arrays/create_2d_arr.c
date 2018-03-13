/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** Functions that create 2 dimensions arrays (char**, int**, etc...)
*/

#include "utils2.h"

/*
** create_2d_char_arr =
** Create an allocated array of a certain number of strings of a certain size
**
** @param	nb_str		Number of string in the array
** @param	str_size	Size of each string in the array
** @return	The array with '\0' at the end of each string if
** 		the allocation worked well OR NULL
*/
char **create_2d_char_arr(unsigned int nb_str, unsigned int str_size)
{
	char **arr2d = NULL;
	char *arr = NULL;
	unsigned int i;

	arr2d = malloc((nb_str + 1) * sizeof *arr2d);
	if (!arr2d)
		return my_ptr_error(INVALID_MALLOC);
	arr = malloc((nb_str + 1) * (str_size + 1) * sizeof **arr2d);
	if (!arr)
		return my_ptr_error(INVALID_MALLOC);
	for (i = 0; i < nb_str; i++) {
		arr2d[i] = &arr[i * (str_size + 1)];
		arr2d[i][str_size] = '\0';
	}
	arr2d[i] = NULL;
	return arr2d;
}

/*
** create_2d_int_arr =
** Create an allocated array of a certain number of int arrays of a certain size
**
** @param	nb_args		Number of int arrays in the array
** @param	size_line	Number of int in each int array
** @return	The array with -1 at the end of each int array if
** 		the allocation worked well OR NULL
*/
int **create_2d_int_arr(unsigned int nb_args, unsigned int size_line)
{
	int **arr2d = NULL;
	int *arr = NULL;
	unsigned int i;

	arr2d = malloc((nb_args + 1) * sizeof *arr2d);
	if (!arr2d)
		return my_ptr_error(INVALID_MALLOC);
	arr = malloc((nb_args + 1) * (size_line + 1) * sizeof **arr2d);
	if (!arr)
		return my_ptr_error(INVALID_MALLOC);
	for (i = 0; i < nb_args; i++) {
		arr2d[i] = &arr[i * (size_line + 1)];
		arr2d[i][size_line] = -1;
	}
	arr2d[i] = NULL;
	return arr2d;
}
