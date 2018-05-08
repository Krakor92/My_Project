/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** My main function
*/

#include "basic_c.h"
#include "my_math.h"

/*
** line__fill_intersection_with_a_line =
** Find the intersection between two lines
**
** @param	l1	First line
** @param	l2	Second line
** @param	inter	Struct to fill (dot_t)
** @return	TRUE	if there is an intersection
** 		FALSE	otherwise
*/
bool_t line2d__find_intersection_with_another_one(line2d_t l1,
						line2d_t l2,
						double2d_t *inter)
{
	line2d_t line = l1;

	if (!inter || l1.a == l2.a)
		return FALSE;
	l2.b -= l1.b;
	l1.a -= l2.a;
	l2.b /= l1.a;
	inter->x = l2.b;
	inter->y = line.a * inter->x + line.b;
	return TRUE;
}
