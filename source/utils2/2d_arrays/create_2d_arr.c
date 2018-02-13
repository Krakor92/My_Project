/*
** EPITECH PROJECT, 2018
** [N/A]
** File description:
** Functions that create 2 dimensions arrays (char**, int**, etc...)
*/
#include "utils2.h"

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
