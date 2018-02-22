/*
** EPITECH PROJECT, 2017
** [N/A]
** File description:
** Utils functions header
*/

#ifndef UTILSCSFML_H
	#define UTILSCSFML_H

	/* Library */
	#include <stdlib.h>
	#include <SFML/Graphics.h>
	#include "utils1.h"

	/* Prototypes */
	//create_2d_sfVector.c
	sfVector2f *init_sfVector2f(double, double);
	sfVector2u *init_sfVector2u(int, int);
	sfVector2f *set_sfVector2f_value(sfVector2f*, double, double);
	sfVector2u *set_sfVector2u_value(sfVector2u*, int, int);
	//create_my_window.c
	sfRenderWindow *create_my_window(unsigned int, unsigned int);
	//create_sfRect.c
	sfIntRect *init_sfIntRect(int, int, int, int);
	sfIntRect *set_sfIntRect_value(sfIntRect*, int, int, int, int);
	//handle_events.c
	void handle_events(sfRenderWindow*, sfEvent);
#endif
