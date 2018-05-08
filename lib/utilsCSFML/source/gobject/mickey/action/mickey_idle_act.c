/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** launch_csfml.c
*/

#include "utilsCSFML.h"
#include "my_math.h"

bool_t mickey__idle_criterion(act_t *act, gobject_t *gobject,
				gobject_list_t *gobjlist)
{
	float epsilon = 0.000001;

	(void) act;
	(void) gobjlist;
	if (!my_float_equal(gobject->speed.x, 0, epsilon) ||
	!my_float_equal(gobject->speed.y, 0, epsilon))
		return FALSE;
	if (gobject->animation->current &&
	my_strequal(gobject->animation->current->name, "jump"))
		return FALSE;
	return TRUE;
}

int mickey__idle(act_t *act, gobject_t *gobject, gobject_list_t *gobjlist)
{
	(void) gobjlist;
	if (act->criterion && !act->criterion(act, gobject, gobjlist))
		return -1;
	if (!act->started) {
		my_printf("START idle\n");
		if (act->sound)
			sfMusic_play(act->sound);
	}
	gobject->speed = (sfVector2f){0, 0};
	my_printf("%s => %s\n", gobject->name, act->name);
	gobject__do_move(gobject, act->move);
	gobject__do_anim(gobject, act->anim);
	act->started = TRUE;
	return 0;
}

act_list_index_t *mickey__create_idle_act_interdictions(
					act_list_index_t *act_list,
					gobject_list_t *gobjects)
{
	(void) gobjects;
	act_list_index_t *interdictions = NULL;

	if (!act_list)
		return NULL;
	interdictions = act_list_index__create();
	if (!interdictions)
		return NULL;
	act_list_index__insert_new_node_tail(interdictions,
		act_list_index__find_act(act_list, "run_right"));
	act_list_index__insert_new_node_tail(interdictions,
		act_list_index__find_act(act_list, "stop_run_right"));
	act_list_index__insert_new_node_tail(interdictions,
		act_list_index__find_act(act_list, "run_left"));
	act_list_index__insert_new_node_tail(interdictions,
		act_list_index__find_act(act_list, "stop_run_left"));
	return interdictions;
}

act_t *mickey__create_idle_act(anim_index_t *anim,
				move_index_t *move,
				act_list_index_t *dependencies,
				act_list_index_t *interdictions)
{
	act_t *act = NULL;
	sfEvent event;

	event.type = sfEvtCount;

	act = act__create("idle", mickey__idle, anim, move);
	if (!act)
		return NULL;
	act->criterion = mickey__idle_criterion;
	act__fill_special_list(act, dependencies, interdictions);
	act__fill_sf_info(act, event, NULL);
	return act;
}
