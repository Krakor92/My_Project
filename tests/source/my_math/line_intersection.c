/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Unit_tests (Ouvre le favoris Unit Tests!!!!)
*/

#include <criterion/criterion.h>

#include "my_math.h"

/**********************
* line_intersection.c *
**********************/
Test(line_int2d__find_intersection_with_another_one, test1)
{
	line2d_t l1 = {2, 3};
	line2d_t l2 = {-1, -5};
	double2d_t intersection;
	bool_t retval = FALSE;

	retval = line2d__find_intersection_with_another_one(l1, l2, &intersection);
	cr_assert_eq(retval, TRUE);
	cr_assert_float_eq(intersection.x, -2.6666666666, 0.000001);
	cr_assert_float_eq(intersection.y, -2.3333333333, 0.000001);
}

Test(line_int2d__find_intersection_with_another_one, test2)
{
	line2d_t l1 = {-2.78, 3.8};
	line2d_t l2 = {1034, -598.01111};
	double2d_t intersection;
	bool_t retval = FALSE;

	retval = line2d__find_intersection_with_another_one(l1, l2, &intersection);
	cr_assert_eq(retval, TRUE);
	cr_assert_float_eq(intersection.x, 0.5804617276, 0.000001);
	cr_assert_float_eq(intersection.y, 2.1863163971, 0.000001);
}
