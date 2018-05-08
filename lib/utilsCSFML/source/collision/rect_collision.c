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

bool_t sfFloatRect__collide_a_sfFloatRect(sfFloatRect r1, sfFloatRect r2)
{
	sfVector2f r1_top_left = (sfVector2f){r1.left, r1.top};
	sfVector2f r1_top_right = (sfVector2f){r1.left + r1.width, r1.top};
	sfVector2f r1_bot_left = (sfVector2f){r1.left, r1.top + r1.height};
	sfVector2f r1_bot_right = (sfVector2f){r1.left + r1.width,
						r1.top + r1.height};

	if (sfVector2f__is_in_sfFloatRect(r1_top_left, r2) ||
	sfVector2f__is_in_sfFloatRect(r1_top_right, r2) ||
	sfVector2f__is_in_sfFloatRect(r1_bot_left, r2) ||
	sfVector2f__is_in_sfFloatRect(r1_bot_right, r2))
		return TRUE;
	return FALSE;
}

/*
sfVector2f sfFloatRect__get_moveback_with_sfFloatRect(sfFloatRect r1,
							sfFloatRect r2,
							sfVector2f move)
{
	sfVector2f back;

	if (!sfFloatRect__collide_a_sfFloatRect(r1, r2))
		return (sfVector2f){0, 0};

	return back;
}
*/
