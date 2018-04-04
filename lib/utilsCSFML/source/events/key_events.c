/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** handle_events.c
*/

#include "utilsCSFML.h"

void sfEvtKeyPressed_events(sfRenderWindow *window, sfEvent event)
{
	if (event.key.code == sfKeyEscape || event.key.code == sfKeyQ)
			sfRenderWindow_close(window);
}
