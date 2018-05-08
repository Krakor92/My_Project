/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** float_compar.c
*/

#include "basic_c.h"
#include "my_math.h"

/*
** my_float_equal =
** Tell if two floats are equal (with a spread of epsilon)
**
** @param	a	First float
** @param	b	Second float
** @param	epsilon	Spread
** @return	TRUE	if there is an intersection
** 		FALSE	otherwise
*/
bool_t my_float_equal(float a, float b, float epsilon)
{
	float a_minus_b = a - b;

	if (-epsilon <= a_minus_b && a_minus_b <= epsilon)
		return TRUE;
	return FALSE;
}
