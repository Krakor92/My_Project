/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** handle_events.c
*/

#include "utilsCSFML.h"

void sfEvtKeyPressed_events(sfRenderWindow *window,
			    gobject_list_t *list,
				   sfEvent event)
{
	if (event.key.code == sfKeyEscape)
		sfRenderWindow_close(window);
	if (event.key.code == sfKeyR) {
		gobject_list__set_gobject_current_anim(list, "Mickey", "running");
		my_printf("R");
	}
}

void sfEvtKeyReleased_events(sfRenderWindow *window,
			    gobject_list_t *list,
				   sfEvent event)
{
	if (event.key.code == sfKeyQ)
		sfRenderWindow_close(window);
	if (event.key.code == sfKeyR) {
		gobject_list__set_gobject_current_anim(list, "Mickey", "idle");
		my_printf("\n");
	}
}
