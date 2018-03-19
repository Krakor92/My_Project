/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Utils functions header
*/

#ifndef UTILSCSFML_H
	#define UTILSCSFML_H

	/* Library */
	#include <SFML/Graphics.h>
	#include "basic_c.h"

	/* Prototypes */
	//create_2d_sfVector.c
	sfVector2f *init_sfVector2f(double, double);
	sfVector2u *init_sfVector2u(int, int);
	sfVector2f *set_sfVector2f_value(sfVector2f*, double, double);
	sfVector2u *set_sfVector2u_value(sfVector2u*, int, int);
	//////////////////////////////////////////////////////////////
	sfRenderWindow *create_my_window(unsigned int, unsigned int);
	//create_sfRect.c
	sfIntRect *init_sfIntRect(int, int, int, int);
	sfIntRect *set_sfIntRect_value(sfIntRect*, int, int, int, int);
	///////////////////////////////////////////////////////////////
	void handle_events(sfRenderWindow*, sfEvent);
#endif
