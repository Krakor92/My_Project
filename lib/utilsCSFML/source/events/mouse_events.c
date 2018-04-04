/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** handle_events.c
*/

#include "utilsCSFML.h"

/*
* Pour que le clique fonctionne, il faut que la pression et le relachement
* soit sur la même zone pour l'activer
* Un peu comme sur le web quand tu appuie mais que tu restes appuyé si tu t'es
* trompé
*/
void sfEvtMouseButtonPressed_events(sfRenderWindow *window, sfEvent event)
{
	(void) window;
	my_printf("Pressed : x = %d, y = %d\n", event.mouseButton.x,
	event.mouseButton.y);
}

void sfEvtMouseButtonReleased_events(sfRenderWindow *window, sfEvent event)
{
	(void) window;
	my_printf("Released : x = %d, y = %d\n\n", event.mouseButton.x,
	event.mouseButton.y);
}
