/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** handle_events.c
*/

#include "utilsCSFML.h"

void handle_events(sfRenderWindow *window, sfEvent event)
{
	if (event.type == sfEvtClosed)
		sfRenderWindow_close(window);
	if (event.type == sfEvtKeyPressed) {
		if (event.key.code == sfKeyEscape || event.key.code == sfKeyQ)
			sfRenderWindow_close(window);
	}
}
