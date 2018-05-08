/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** launch_csfml.c
*/

#include "utilsCSFML.h"

int mickey__toasty(act_t *act, gobject_t *gobject, gobject_list_t *gobjlist)
{
	(void) gobjlist;
	if (!act->started) {
		if (act->sound)
			sfMusic_play(act->sound);
	}
	my_printf("%s => %s\n", gobject->name, act->name);
	gobject__do_anim(gobject, act->anim);
	gobject__do_move(gobject, act->move);
	act->started = TRUE;
	return 0;
}

int mickey__stop_toasty(act_t *act, gobject_t *gobject,
			gobject_list_t *gobjlist)
{
	(void) gobjlist;
	if (!act->started) {
		if (act->sound)
			sfMusic_play(act->sound);
	}
	my_printf("%s => %s\n", gobject->name, act->name);
	gobject__do_anim(gobject, act->anim);
	gobject__do_move(gobject, act->move);
	act__reset(gobject__get_act(gobject, "toasty"));
	act__reset(act);
	return 0;
}


act_t *mickey__create_toasty_act(anim_index_t *anim,
				move_index_t *move,
				act_list_index_t *dependencies,
				act_list_index_t *interdictions)
{
	act_t *act = NULL;
	sfMusic *music = NULL;
	sfEvent event;

	music = sfMusic_createFromFile("lib/utilsCSFML/music/TOASTY.ogg");
	event.type = sfEvtKeyPressed;
	event.key.code = sfKeyT;
	event.key.alt = FALSE;
	event.key.control = FALSE;
	event.key.shift = FALSE;
	event.key.system = FALSE;

	act = act__create("toasty", mickey__toasty, anim, move);
	if (!act)
		return NULL;
	act__fill_special_list(act, dependencies, interdictions);
	act__fill_sf_info(act, event, music);
	return act;
}

act_t *mickey__create_stop_toasty_act(anim_index_t *anim,
					move_index_t *move,
					act_list_index_t *dependencies,
					act_list_index_t *interdictions)
{
	act_t *act = NULL;
	sfEvent event;

	event.type = sfEvtKeyReleased;
	event.key.code = sfKeyT;
	event.key.alt = FALSE;
	event.key.control = FALSE;
	event.key.shift = FALSE;
	event.key.system = FALSE;

	act = act__create("stop_toasty", mickey__stop_toasty, anim, move);
	if (!act)
		return NULL;
	act__fill_special_list(act, dependencies, interdictions);
	act__fill_sf_info(act, event, NULL);
	return act;
}
/*
int shiftp(act_t *act, gobject_t *gobject, gobject_list_t *gobjlist)
{
	(void) gobject;
	(void) gobjlist;
	if (!act->started)
		my_printf("START shiftp!\n");
	my_printf("shiftp\n");
	act->started = TRUE;
	return 0;
}

act_t *create_shiftp_act(anim_index_t *anim,
				move_index_t *move,
				act_list_index_t *dependencies,
				act_list_index_t *interdictions)
{
	act_t *act = NULL;
	sfEvent event;

	event.type = sfEvtKeyPressed;
	event.key.code = sfKeyP;
	event.key.alt = FALSE;
	event.key.control = TRUE;
	//le shift ne fonctionne pas :/ et je sais pas c'est quoi system
	event.key.shift = FALSE;
	event.key.system = FALSE;

	act = act__create("shiftp", shiftp, anim, move);
	if (!act)
		return NULL;
	act__fill_special_list(act, dependencies, interdictions);
	act__fill_sf_info(act, event, NULL);
	return act;
}

int stop_shiftp(act_t *act, gobject_t *gobject, gobject_list_t *gobjlist)
{
	(void) gobject;
	(void) gobjlist;
	if (!act->started) {
		my_printf("STOP shiftp!\n");
		act__reset(gobject__get_act(gobject, "shiftp"));
	}
	my_printf("stop_shiftp\n");
	act->started = TRUE;
	act__reset(act);
	return 0;
}

act_t *create_stop_shiftp_act(anim_index_t *anim,
				move_index_t *move,
				act_list_index_t *dependencies,
				act_list_index_t *interdictions)
{
	act_t *act = NULL;
	sfEvent event;

	event.type = sfEvtKeyReleased;
	event.key.code = sfKeyP;
	event.key.alt = FALSE;
	event.key.control = FALSE;
	//le shift ne fonctionne pas :/ et je sais pas c'est quoi system
	event.key.shift = FALSE;
	event.key.system = FALSE;

	act = act__create("stop_shiftp", stop_shiftp, anim, move);
	if (!act)
		return NULL;
	act__fill_special_list(act, dependencies, interdictions);
	act__fill_sf_info(act, event, NULL);
	return act;
}
*/
