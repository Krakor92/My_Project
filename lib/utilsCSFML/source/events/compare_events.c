/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** compare_events.c
*/

#include "utilsCSFML.h"

static bool_t the_keys_are_the_same(sfKeyEvent k1, sfKeyEvent k2)
{
	if (k1.code == k2.code && k1.alt == k2.alt && k1.control == k2.control
	&& k1.shift == k2.shift && k1.system == k2.system)
		return TRUE;
	return FALSE;
}

static bool_t the_mouse_buttons_are_the_same(sfMouseButton b1, sfMouseButton b2)
{
	if (b1 == b2)
		return TRUE;
	return FALSE;
}

bool_t the_events_are_the_same(sfEvent e1, sfEvent e2)
{
	if (e1.type == e2.type) {
		if (e1.type == sfEvtKeyPressed || e1.type == sfEvtKeyReleased)
			return the_keys_are_the_same(e1.key, e2.key);
		else if (e1.type == sfEvtMouseButtonPressed ||
			e1.type == sfEvtMouseButtonReleased)
			return the_mouse_buttons_are_the_same(
				e1.mouseButton.button, e2.mouseButton.button);
		else
			return TRUE;
	}
	return FALSE;
}
