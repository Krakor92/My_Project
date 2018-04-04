/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Utils functions header
*/

#ifndef __UTILSCSFML__H__
	#define __UTILSCSFML__H__

	/* Library */
	#include <SFML/Graphics.h>
	#include "basic_c.h"

	/* Prototypes */
	sfRenderWindow *create_my_window(unsigned int, unsigned int);
	void handle_events(sfRenderWindow*, sfEvent);
	int launch_csfml(void);
	/////////////////////////////////////////////////////////////
	//create_2d_sfVector.c///////////////////////////////////////
	sfVector2u *sfVector2u_init(int, int);
	sfVector2f *sfVector2f_init(float, float);
	void sfVector2u_set_value(sfVector2u*, int, int);
	void sfVector2f_set_value(sfVector2f*, float, float);
	//////////////////////////////////////////////////////////////
	//create_sfRect.c//////////////////////////////////////////////
	sfIntRect *sfIntRect_init(int, int, int, int);
	sfFloatRect *sfFloatRect_init(float, float, float, float);
	void sfIntRect_set_value(sfIntRect*, int, int, int, int);
	void sfFloatRect_set_value(sfFloatRect*, float, float, float, float);
	///////////////////////////////////////////////////////////////
	//sfRenderStates.c////////////////////////////////
	sfRenderStates *sfRenderStates_create(sfTexture*);
	void sfRenderStates_destroy(sfRenderStates*);
	//////////////////////////////////////////////////
#endif
