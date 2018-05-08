/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** launch_csfml.c
*/

#include "utilsCSFML.h"
#include "my_math.h"

bool_t mickey__jump_criterion(act_t *act, gobject_t *gobject,
				gobject_list_t *gobjlist)
{
	float epsilon = 0.000001;

	(void) act;
	(void) gobjlist;
	if (!my_float_equal(gobject->speed.y, 0, epsilon))
		return FALSE;
	return TRUE;
}

int mickey__jump(act_t *act, gobject_t *gobject, gobject_list_t *gobjlist)
{
	(void) gobjlist;
	if (!act->started) {
		my_printf("START jump\n");
		if (act->sound)
			sfMusic_play(act->sound);
	}
	my_printf("%s => %s\n", gobject->name, act->name);
	gobject__do_move(gobject, act->move);
	gobject__do_anim(gobject, act->anim);
	if (act->move->finished) {
		my_printf("END jump!\n");
		gobject->animation->current = NULL;
		act__reset(act);
		return 0;
	}
	act->started = TRUE;
	return 0;
}

act_t *mickey__create_jump_act(anim_index_t *anim,
				move_index_t *move,
				act_list_index_t *dependencies,
				act_list_index_t *interdictions)
{
	act_t *act = NULL;
	sfEvent event;

	event.type = sfEvtKeyPressed;
	event.key.code = sfKeyUp;
	event.key.alt = FALSE;
	event.key.control = FALSE;
	event.key.shift = FALSE;
	event.key.system = FALSE;

	act = act__create("jump", mickey__jump, anim, move);
	if (!act)
		return NULL;
	act->criterion = mickey__jump_criterion;
	act__fill_special_list(act, dependencies, interdictions);
	act__fill_sf_info(act, event, NULL);
	return act;
}
