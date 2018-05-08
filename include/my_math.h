/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** My Project's Header
*/

#ifndef __MY_MATH__H__
	#define __MY_MATH__H__

	/* Library */
	#include "basic_c.h"
	#include "my_structs.h"

	/* Macros */

	/* Constants */

	/* Typedefs */
	typedef struct line2d_s line2d_t;

	/* Structs */
	struct line2d_s
	{
		double a;
		double b;
	};

	/* Prototypes */
	bool_t my_float_equal(float, float, float);
	bool_t line2d__find_intersection_with_another_one(line2d_t, line2d_t, double2d_t *);
#endif
