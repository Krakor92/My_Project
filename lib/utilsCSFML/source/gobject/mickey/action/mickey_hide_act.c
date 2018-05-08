/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** launch_csfml.c
*/

#include "utilsCSFML.h"

int mickey__hide(act_t *act, gobject_t *gobject, gobject_list_t *gobjlist)
{
	(void) gobjlist;
	if (!act->started) {
		my_printf("START hide\n");
		if (act->sound)
			sfMusic_play(act->sound);
	}
	my_printf("%s => %s\n", gobject->name, act->name);
	gobject->show = !gobject->show;
/*	if (gobject->show == TRUE)
		gobject->show = FALSE;
	else
		gobject->show = TRUE;
*/	act__reset(act);
	return 0;
}

act_t *mickey__create_hide_act(anim_index_t *anim,
				move_index_t *move,
				act_list_index_t *dependencies,
				act_list_index_t *interdictions)
{
	act_t *act = NULL;
	sfEvent event;

	event.type = sfEvtKeyPressed;
	event.key.code = sfKeyH;
	event.key.alt = FALSE;
	event.key.control = FALSE;
	event.key.shift = FALSE;
	event.key.system = FALSE;

	act = act__create("hide", mickey__hide, anim, move);
	if (!act)
		return NULL;
	act__fill_special_list(act, dependencies, interdictions);
	act__fill_sf_info(act, event, NULL);
	return act;
}
