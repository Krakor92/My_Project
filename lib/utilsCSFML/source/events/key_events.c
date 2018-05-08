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
	(void) list;
	if (event.key.code == sfKeyEscape)
		sfRenderWindow_close(window);
}

void sfEvtKeyReleased_events(sfRenderWindow *window,
			    gobject_list_t *list,
				   sfEvent event)
{
	(void) list;
	if (event.key.code == sfKeyQ)
		sfRenderWindow_close(window);
}
