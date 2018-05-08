/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Unit_tests (Ouvre le favoris Unit Tests!!!!)
*/

#include <criterion/criterion.h>
#include "utilsCSFML.h"

/*******************
* rect_collision.c *
*******************/
Test(sfVector2f__is_in_sfFloatRect, tests)
{
	sfFloatRect rect = (sfFloatRect){0, 0, 40, 40};
	sfVector2f p1 = (sfVector2f){-1, -1};
	sfVector2f p2 = (sfVector2f){0, 0};
	sfVector2f p3 = (sfVector2f){-1, 0};
	sfVector2f p4 = (sfVector2f){40, 40};
	bool_t retval = FALSE;

	retval = sfVector2f__is_in_sfFloatRect(p1, rect);
	cr_assert_eq(retval, FALSE);
	retval = sfVector2f__is_in_sfFloatRect(p2, rect);
	cr_assert_eq(retval, TRUE);
	retval = sfVector2f__is_in_sfFloatRect(p3, rect);
	cr_assert_eq(retval, FALSE);
	retval = sfVector2f__is_in_sfFloatRect(p4, rect);
	cr_assert_eq(retval, TRUE);
}

Test(sfFloatRect__collide_a_sfFloatRect, tests)
{
	sfFloatRect r1 = (sfFloatRect){0, 0, 40, 40};
	sfFloatRect r2 = (sfFloatRect){20, 20, 30, 30};
	sfFloatRect r3 = (sfFloatRect){40.001, 40, 30, 30};
	bool_t retval = FALSE;

	retval = sfFloatRect__collide_a_sfFloatRect(r1, r2);
	cr_assert_eq(retval, TRUE);
	retval = sfFloatRect__collide_a_sfFloatRect(r1, r3);
	cr_assert_eq(retval, FALSE);
}
