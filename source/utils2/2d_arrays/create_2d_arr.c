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
char **create_2d_char_arr(int nb_str, int str_size)
{
	char **arr = NULL;
	char *str = NULL;
	int i = 0;

	arr = (char**)malloc(sizeof(char*) * (nb_str + 1));
	if (arr == NULL)
		return (my_ptr_error(INVALID_MALLOC));
	str = (char*)malloc(sizeof(char) * (nb_str + 1) * (str_size + 1));
	if (str == NULL)
		return (my_ptr_error(INVALID_MALLOC));
	for (; i < nb_str; i++) {
		arr[i] = &str[i * (str_size + 1)];
		arr[i][str_size] = '\0';
	}
	arr[i] = NULL;
	return (arr);
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
int **create_2d_int_arr(int nb_args, int size_line)
{
	int **arr = NULL;
	int *str = NULL;
	int i = 0;

	arr = (int**)malloc(sizeof(int*) * (nb_args + 1));
	if (arr == NULL)
		return (my_ptr_error(INVALID_MALLOC));
	str = (int*)malloc(sizeof(int) * (nb_args + 1) * (size_line + 1));
	if (str == NULL)
		return (my_ptr_error(INVALID_MALLOC));
	for (; i < nb_args; i++) {
		arr[i] = &str[i * (size_line + 1)];
		arr[i][size_line] = -1;
	}
	arr[i] = NULL;
	return (arr);
}
