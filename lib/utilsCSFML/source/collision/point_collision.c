/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** gobject.c
*/

#include "utilsCSFML.h"

bool_t sfVector2f__is_in_sfFloatRect(sfVector2f point, sfFloatRect rect)
{
	if (rect.left <= point.x && point.x <= rect.left + rect.width &&
	rect.top <= point.y && point.y <= rect.top + rect.height)
		return TRUE;
	return FALSE;
}

void sfVector2f__check_move_collision(sfVector2f point, sfVector2f move, sfFloatRect rect)
{
	sfVector2f point_t1;

	point_t1.x = point.x + move.x;
	point_t1.y = point.y + move.y;
	if (sfVector2f__is_in_sfFloatRect(point_t1, rect)) {

	}
}
