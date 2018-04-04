/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** launch_csfml.c
*/

#include "utilsCSFML.h"

/*
** launch_csfml = 16l
** Launch the CSFML basic configuration
**
** @param	N/A
** @return	0	if everything works
** 		-1	otherwise
*/
int launch_csfml(void)
{
	sfRenderWindow *window = create_my_window(1920, 1080);
	sfColor color = sfColor_fromRGBA(0, 10, 60, 255);
	sfRenderStates *r_states = NULL;
	sfEvent event;

	r_states = sfRenderStates_create(NULL);
	if (!r_states)
		return -1;
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event))
			handle_events(window, event);
		sfRenderWindow_clear(window, color);
		sfRenderWindow_display(window);
	}
	sfRenderStates_destroy(r_states);
	sfRenderWindow_destroy(window);
	return 0;
}
