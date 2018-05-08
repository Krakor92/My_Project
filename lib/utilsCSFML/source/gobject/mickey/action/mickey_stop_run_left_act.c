/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** launch_csfml.c
*/

#include "utilsCSFML.h"

static void mickey__start_stop_running_left(act_t *act, gobject_t *gobject,
						gobject_list_t *gobjlist)
{
	act_t *run = NULL;
	move_node_t *run_move_current_node = NULL;
	size_t nb;

	(void) gobjlist;
	run = gobject__get_act(gobject, "run_left");
	if (!run)
		return;
	run_move_current_node = act__get_move_current_node(run);
	if (run_move_current_node) {
		nb = (act->move->nb_steps + 1 - run_move_current_node->number);
//		printf("\n\n\n\n\n\n\n\n%ld\n\n\n\n\n\n\n\n", nb);
		sfClock_restart(act->move->chrono->clock);
		move_index__set_move_node_current(act->move, nb);
		act->started = TRUE;
	}
	my_printf("START stop run left!\n");
	act__reset(run);
	if (act->sound)
		sfMusic_play(act->sound);
}

int mickey__stop_run_left(act_t *act, gobject_t *gobject,
				gobject_list_t *gobjlist)
{
	if (!act->started)
		mickey__start_stop_running_left(act, gobject, gobjlist);
	my_printf("%s => %s\n", gobject->name, act->name);
	gobject__do_anim(gobject, act->anim);
	gobject__do_move(gobject, act->move);
	if (act->move->finished) {
		my_printf("END jump!\n");
		act__reset(act);
		return 0;
	}
//	printf("stop run: {%f, %f}\n", gobject->speed.x, gobject->speed.y);
	act->started = TRUE;
	return 0;
}

act_t *mickey__create_stop_run_left_act(anim_index_t *anim,
					move_index_t *move,
					act_list_index_t *dependencies,
					act_list_index_t *interdictions)
{
	act_t *act = NULL;
	sfEvent event;

	event.type = sfEvtKeyReleased;
	event.key.code = sfKeyLeft;
	event.key.alt = FALSE;
	event.key.control = FALSE;
	event.key.shift = FALSE;
	event.key.system = FALSE;

	act = act__create("stop_run_left", mickey__stop_run_left, anim, move);
	if (!act)
		return NULL;
	act__fill_special_list(act, dependencies, interdictions);
	act__fill_sf_info(act, event, NULL);
	return act;
}
