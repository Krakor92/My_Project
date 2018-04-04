/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Init OR Set the value of sfVector2f/u
*/

#include "utilsCSFML.h"

/*
** init_sfVector2u =
** Malloc a sfVector2u (assimilated as a non-floating point) and set its values
**
** @param	valx	The x value of the non-floating point
** @param	valy	The y value of the non-floating point
** @return	The non-floating point with it values if the
** 		allocation worked well OR NULL
*/
sfVector2u *sfVector2u_init(int valx, int valy)
{
	sfVector2u *point = NULL;

	point = malloc(sizeof(sfVector2u));
	if (point == NULL)
		return(my_ptr_error(INVALID_MALLOC));
	point->x = valx;
	point->y = valy;
	return (point);
}

/*
** set_sfVector2u_value =
** Set sfVector2u's values if it is already allocated
**
** @param	point	An allocated sfVector2u point
** @param	newx	The new x value of the non-floating point
** @param	newy	The new y value of the non-floating point
** @return	The non-floating point with it values if it
** 		was allocated OR NULL
*/
void sfVector2u_set_value(sfVector2u *point, int newx, int newy)
{
	if (!point)
		return;
	point->x = newx;
	point->y = newy;
}

/*
** init_sfVector2f =
** Malloc a sfVector2f (assimilated as a floating point) and set its values
**
** @param	valx	The x value of the floating point
** @param	valy	The y value of the floating point
** @return	The floating point with its values if the
** 		allocation worked well OR NULL
*/
sfVector2f *sfVector2f_init(float valx, float valy)
{
	sfVector2f *fpoint = NULL;

	fpoint = malloc(sizeof(sfVector2f));
	if (!fpoint)
		return my_ptr_error(INVALID_MALLOC);
	fpoint->x = valx;
	fpoint->y = valy;
	return fpoint;
}

/*
** set_sfVector2f_value =
** Set sfVector2f's values if it's already allocated
**
** @param	fpoint	An allocated sfVector2f point
** @param	newx	The new x value of the floating point
** @param	newy	The new y value of the floating point
** @return	The floating point with it new values if it
** 		was allocated OR NULL
*/
void sfVector2f_set_value(sfVector2f *fpoint, float newx, float newy)
{
	if (!fpoint)
		return;
	fpoint->x = newx;
	fpoint->y = newy;
}
