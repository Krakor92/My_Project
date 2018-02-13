/*
** EPITECH PROJECT, 2018
** [N/A]
** File description:
** Functions that destroy 2 dimensions arrays (char**, int**, etc...)
*/
#include "utils2.h"

void destroy_2d_char_arr(char **arr)
{
	free(arr[0]);
	free(arr);
}

void destroy_2d_int_arr(int **arr)
{
	free(arr[0]);
	free(arr);
}
