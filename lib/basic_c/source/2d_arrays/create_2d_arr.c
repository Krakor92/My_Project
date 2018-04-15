/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** Functions that create 2 dimensions arrays (char**, int**, etc...)
*/

#include "basic_c.h"

/*
** create_2d_char_arr =
** Create an allocated array of a certain number of strings of a certain size
**
** @param	nb_array	Number of string in the 2d_array
** @param	array_size	Size of each string in the 2d_array
** @return	The array with '\0' at the end of each string if
** 		the allocation worked well OR NULL
*/
char **create_2d_char_arr(size_t nb_array, size_t array_size)
{
	char **arr2d = NULL;
	char *arr = NULL;
	size_t i = 0;

	arr2d = malloc((nb_array + 1) * sizeof(*arr2d));
	if (!arr2d)
		return my_ptr_error(INVALID_MALLOC);
	arr = malloc((nb_array + 1) * (array_size + 1) * sizeof(*arr));
	if (!arr)
		return my_ptr_error(INVALID_MALLOC);
	for (i = 0; i < nb_array; i++) {
		arr2d[i] = &arr[i * (array_size + 1)];
		arr2d[i][array_size] = '\0';
	}
	arr2d[nb_array] = NULL;
	return arr2d;
}

/*
** create_2d_int_arr =
** Create an allocated array of a certain number of int arrays of a certain size
**
** @param	nb_array	Number of int arrays in the 2d_array
** @param	array_size	Number of int in each array
** @return	The array with -1 at the end of each int array if
** 		the allocation worked well OR NULL
*/
int **create_2d_int_arr(size_t nb_array, size_t array_size)
{
	int **arr2d = NULL;
	int *arr = NULL;
	size_t i;

	arr2d = malloc((nb_array + 1) * sizeof(*arr2d));
	if (!arr2d)
		return my_ptr_error(INVALID_MALLOC);
	arr = malloc((nb_array + 1) * (array_size + 1) * sizeof(*arr));
	if (!arr)
		return my_ptr_error(INVALID_MALLOC);
	for (i = 0; i < nb_array; i++) {
		arr2d[i] = &arr[i * (array_size + 1)];
		arr2d[i][array_size] = -1;
	}
	arr2d[nb_array] = NULL;
	return arr2d;
}
