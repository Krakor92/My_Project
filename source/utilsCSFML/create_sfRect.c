/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Init OR Set the value of sfRect
*/
#include "utilsCSFML.h"

sfIntRect *init_sfIntRect(int left, int top, int width, int down)
{
	sfIntRect *rect = NULL;

	rect = malloc(sizeof(sfIntRect));
	if (rect == NULL)
		return (my_ptr_error(INVALID_MALLOC));
	rect->left = left;
	rect->top = top;
	rect->width = width;
	rect->height = down;
	return (rect);
}

sfIntRect *set_sfIntRect_value(sfIntRect *rect, int l, int t, int w, int d)
{
	if (rect == NULL)
		return (NULL);
	rect->left = l;
	rect->top = t;
	rect->width = w;
	rect->height = d;
	return (rect);
}
