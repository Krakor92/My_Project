/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Init OR Set the value of sfRect
*/

#include "utilsCSFML.h"

/*
** init_sfIntRect =
** Malloc a sfIntRect and set its values
**
** @param	left	The x coordonate of the top-left point of the rectangle
** @param	top	The y coordonate of the top-left point of the rectangle
** @param	width	The width of the rectangle
** @param	height	The height of the rectangle
** @return	The rectangle with its values if the
** 		allocation worked well OR NULL
*/
sfIntRect *init_sfIntRect(int left, int top, int width, int down)
{
	sfIntRect *rect = NULL;

	rect = malloc(sizeof(sfIntRect));
	if (!rect)
		return my_ptr_error(INVALID_MALLOC);
	rect->left = left;
	rect->top = top;
	rect->width = width;
	rect->height = down;
	return (rect);
}

/*
** set_sfIntRect_value =
** Set sfIntRect's values if it's already allocated
**
** @param	left	The x coordonate of the top-left point of the rectangle
** @param	top	The y coordonate of the top-left point of the rectangle
** @param	width	The width of the rectangle
** @param	height	The height of the rectangle
** @return	The rectangle with its new values if it
** 		was allocated OR NULL
*/
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
