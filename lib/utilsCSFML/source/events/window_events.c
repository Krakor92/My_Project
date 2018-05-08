/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** window_events.c
*/

#include "utilsCSFML.h"

void sfEvtClosed_events(sfRenderWindow *window, sfEvent event)
{
	(void) event;
	my_printf("*** END ***\n");
	sfRenderWindow_close(window);
}
