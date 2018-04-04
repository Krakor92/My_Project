/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Init OR Set the value of sfRect
*/

#include "utilsCSFML.h"

/*
** sfIntRect_init =
** Malloc a sfIntRect and set it values
**
** @param	left	The x coordonate of the top-left point of the rectangle
** @param	top	The y coordonate of the top-left point of the rectangle
** @param	width	The width of the rectangle
** @param	height	The height of the rectangle
** @return	rect	The rectangle with it values
** 		NULL	Otherwise
*/
sfIntRect *sfIntRect_init(int left, int top, int width, int height)
{
	sfIntRect *rect = NULL;

	rect = malloc(sizeof(*rect));
	if (!rect)
		return my_ptr_error(INVALID_MALLOC);
	rect->left = left;
	rect->top = top;
	rect->width = width;
	rect->height = height;
	return rect;
}

/*
** sfIntRect_set_value =
** Set new values to sfIntRect if it's already allocated
**
** @param	l	The x coordonate of the top-left point of the rectangle
** @param	t	The y coordonate of the top-left point of the rectangle
** @param	w	The width of the rectangle
** @param	h	The height of the rectangle
** @return	N/A
*/
void sfIntRect_set_value(sfIntRect *rect, int l, int t, int w, int d)
{
	if (!rect)
		return;
	rect->left = l;
	rect->top = t;
	rect->width = w;
	rect->height = d;
}

/*
** sfFloatRect_init =
** Malloc a sfFloatRect and set it values
**
** @param	left	The x coordonate of the top-left point of the rectangle
** @param	top	The y coordonate of the top-left point of the rectangle
** @param	width	The width of the rectangle
** @param	height	The height of the rectangle
** @return	rect	The rectangle with it values
** 		NULL	Otherwise
*/
sfFloatRect *sfFloatRect_init(float left, float top, float width, float height)
{
	sfFloatRect *rect = NULL;

	rect = malloc(sizeof(*rect));
	if (!rect)
		return my_ptr_error(INVALID_MALLOC);
	rect->left = left;
	rect->top = top;
	rect->width = width;
	rect->height = height;
	return rect;
}

/*
** sfFloatRect_set_value =
** Set new values to sfFloatRect if it is already allocated
**
** @param	l	The x coordonate of the top-left point of the rectangle
** @param	t	The y coordonate of the top-left point of the rectangle
** @param	w	The width of the rectangle
** @param	h	The height of the rectangle
** @return	N/A
*/
void sfFloatRect_set_value(sfFloatRect *rect, float l, float t, float w,
				float d)
{
	if (!rect)
		return;
	rect->left = l;
	rect->top = t;
	rect->width = w;
	rect->height = d;
}
