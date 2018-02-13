/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Init OR Set the value of sfVector2f/u
*/
#include "utilsCSFML.h"

sfVector2f *init_sfVector2f(double valx, double valy)
{
	sfVector2f *vect = NULL;

	vect = malloc(sizeof(*vect));
	if (vect == NULL)
		return (my_ptr_error(INVALID_MALLOC));
	vect->x = valx;
	vect->y = valy;
	return (vect);
}

sfVector2u *init_sfVector2u(int valx, int valy)
{
	sfVector2u *vect = NULL;

	vect = malloc(sizeof(*vect));
	if (vect == NULL)
		return(my_ptr_error(INVALID_MALLOC));
	vect->x = valx;
	vect->y = valy;
	return (vect);
}

sfVector2f *set_sfVector2f_value(sfVector2f *pos, double newx, double newy)
{
	if (pos == NULL)
		return (NULL);
	pos->x = newx;
	pos->y = newy;
	return (pos);
}

sfVector2u *set_sfVector2u_value(sfVector2u *pos, int newx, int newy)
{
	if (pos == NULL)
		return (NULL);
	pos->x = newx;
	pos->y = newy;
	return (pos);
}
