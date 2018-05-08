/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** launch_csfml.c
*/

#include "utilsCSFML.h"
#include "my_math.h"

int mickey__run_right(act_t *act, gobject_t *gobject,
			gobject_list_t *gobjlist)
{
	(void) gobjlist;
	if (!act->started) {
		my_printf("START run right!\n");
		if (act->sound)
			sfMusic_play(act->sound);
	}
	my_printf("%s => %s\n", gobject->name, act->name);
	gobject__do_move(gobject, act->move);
	if (gobject->speed.x < 0 || my_float_equal(gobject->speed.x, 0, 0.000001))
		return 0;
	gobject->scale.x = 4;
	sfSprite_setScale(gobject->sprite, gobject->scale);
	if (!gobject->animation->current || (gobject->animation->current &&
	!my_strequal(gobject->animation->current->name, "jump")))
		gobject__do_anim(gobject, act->anim);
	act->started = TRUE;
	return 0;
}

act_t *mickey__create_run_right_act(anim_index_t *anim,
					move_index_t *move,
					act_list_index_t *dependencies,
					act_list_index_t *interdictions)
{
	act_t *act = NULL;
	sfEvent event;

	event.type = sfEvtKeyPressed;
	event.key.code = sfKeyRight;
	event.key.alt = FALSE;
	event.key.control = FALSE;
	event.key.shift = FALSE;
	event.key.system = FALSE;

	act = act__create("run_right", mickey__run_right, anim, move);
	if (!act)
		return NULL;
	act__fill_special_list(act, dependencies, interdictions);
	act__fill_sf_info(act, event, NULL);
	return act;
}
