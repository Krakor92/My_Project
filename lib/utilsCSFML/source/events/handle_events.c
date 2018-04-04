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
		sfEvtClosed_events(window, event);
	if (event.type == sfEvtKeyPressed)
		sfEvtKeyPressed_events(window, event);
	if (event.type == sfEvtMouseButtonPressed)
		sfEvtMouseButtonPressed_events(window, event);
	if (event.type == sfEvtMouseButtonReleased)
		sfEvtMouseButtonReleased_events(window, event);
}
