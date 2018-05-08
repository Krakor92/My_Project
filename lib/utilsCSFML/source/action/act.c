/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Functions that are relative to the basics of double linked lists
*/

#include "utilsCSFML.h"

act_t *act__malloc(void)
{
	act_t *act = NULL;

	act = malloc(sizeof(*act));
	if (!act)
		return my_ptr_error(INVALID_MALLOC);
	act->name = NULL;
	act->sound  = NULL;
	act->action = NULL;
	act->anim = NULL;
	act->move = NULL;
	act->chrono = NULL;
	act->loop = FALSE;
	act->on_hold = FALSE;
	act->active = FALSE;
	act->started = FALSE;
//	act->finished = FALSE;
	act->dependencies = NULL;
	act->interdictions = NULL;
	return act;
}

act_t *act__create(char *name,
			int (*action)(act_t*, gobject_t*, gobject_list_t*),
			anim_index_t *anim,
			move_index_t *move)
{
	act_t *act = NULL;

	if (!name)
		return NULL;
	act = act__malloc();
	if (!act)
		return NULL;
	act->name = name;
	act->action = action;
	act->anim = anim;
	act->move = move;
	return act;
}

int act__fill_special_list(act_t *act,
				act_list_index_t *dependencies,
				act_list_index_t *interdictions)
{
	if (!act)
		return -1;
	act->dependencies = dependencies;
	act->interdictions = interdictions;
	return 0;
}

int act__fill_sf_info(act_t *act, sfEvent event, sfMusic *sound)
{
	if (!act)
		return -1;
	act->event = event;
	act->sound = sound;
	return 0;
}

void act__hold_on_if_event(act_t *act, sfEvent event)
{
	if (!act || act->active)
		return;
	if (the_events_are_the_same(act->event, event))
		act->on_hold = TRUE;
}

bool_t act__active_if_conditions(act_t *act)
{
	if (!act)
		return FALSE;
	if (!act->active && act->on_hold &&
	!act_list_index__there_are_active_act(act->interdictions) &&
	act_list_index__all_are_active_act(act->dependencies)) {
		act->on_hold = FALSE;
		act->active = TRUE;
		return TRUE;
	}
/*	Pour l'instant l'act perd son état on_hold, ça changera pour certains act (la course par exemple)
	Dans le sens ou si j'appuie sur la flèche alors que le perso attaque, le perso ne bougera pas,
	mais si je reste appuyé sur cette même flèche, il se mettra a bouger une fois l'action de taper terminé*/
	if (act->type == ONE_SHOT)
		act->on_hold = FALSE;
	return FALSE;
}

bool_t act__stop_if_not_condition(act_t *act)
{
	if (!act)
		return FALSE;
	if (act->active &&
	(act_list_index__there_are_active_act(act->interdictions) ||
	!act_list_index__all_are_active_act(act->dependencies))) {
		act__reset(act);
		return TRUE;
	}
	return FALSE;
}

void act__update(act_t *act)
{
	if (!act)
		return;
	act__stop_if_not_condition(act);
	act__active_if_conditions(act);
}

move_node_t *act__get_move_current_node(act_t *act)
{
	if (!act || !act->move)
		return NULL;
	return act->move->current;
}

void act__set_move_current_node(act_t *act, size_t node_nb)
{
	if (!act)
		return;
	move_index__set_move_node_current(act->move, node_nb);
}
