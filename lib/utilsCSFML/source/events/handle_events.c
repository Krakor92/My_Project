/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** handle_events.c
*/

#include "utilsCSFML.h"

void handle_events(sfRenderWindow *window, gobject_list_t *list, sfEvent event)
{
	if (event.type == sfEvtClosed)
		sfEvtClosed_events(window, event);
	if (event.type == sfEvtKeyPressed)
		sfEvtKeyPressed_events(window, list, event);
	if (event.type == sfEvtKeyReleased)
		sfEvtKeyReleased_events(window, list, event);
	if (event.type == sfEvtMouseButtonPressed)
		sfEvtMouseButtonPressed_events(window, event);
	if (event.type == sfEvtMouseButtonReleased)
		sfEvtMouseButtonReleased_events(window, event);
	gobject_list__hold_on_act_if_event(list, event);
}
