/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** mickey.c
*/

#include "utilsCSFML.h"

static anim_list_index_t *mickey__create_anim_list(sfTexture *texture)
{
	anim_list_index_t *anim_list = NULL;

	anim_list = anim_list_index__create();
	if (!anim_list)
		return NULL;
	anim_list_index__insert_new_node_head(anim_list,
		mickey__create_idle_anim(texture));
	anim_list_index__insert_new_node_head(anim_list,
		mickey__create_run_anim(texture));
	anim_list_index__insert_new_node_head(anim_list,
		mickey__create_jump_anim(texture));
	return anim_list;
}

static move_list_index_t *mickey__create_move_list(void)
{
	move_list_index_t *move_list = NULL;

	move_list = move_list_index__create();
	if (!move_list)
		return NULL;
	move_list_index__insert_new_node_head(move_list,
		mickey__create_run_right_move());
	move_list_index__insert_new_node_head(move_list,
		mickey__create_stop_run_right_move());
	move_list_index__insert_new_node_head(move_list,
		mickey__create_run_left_move());
	move_list_index__insert_new_node_head(move_list,
		mickey__create_stop_run_left_move());
	move_list_index__insert_new_node_head(move_list,
		mickey__create_jump_move());
	return move_list;
}

static act_list_index_t *mickey__create_act_list(anim_list_index_t *anim_list,
						move_list_index_t *move_list)
{
	(void) move_list;
	act_list_index_t *act_list = NULL;
	anim_index_t *anim = NULL;
	move_index_t *move = NULL;

	act_list = act_list_index__create();
	if (!act_list)
		return NULL;
	anim = anim_list_index__find_anim_index(anim_list, "run");
	move = move_list_index__find_move_index(move_list, "run_right");
	act_list_index__insert_new_node_tail(act_list,
		mickey__create_run_right_act(anim, move, NULL, NULL));
	move = move_list_index__find_move_index(move_list, "stop_run_right");
	act_list_index__insert_new_node_tail(act_list,
		mickey__create_stop_run_right_act(NULL, move, NULL, NULL));
	move = move_list_index__find_move_index(move_list, "run_left");
	act_list_index__insert_new_node_tail(act_list,
		mickey__create_run_left_act(anim, move, NULL, NULL));
	move = move_list_index__find_move_index(move_list, "stop_run_left");
	act_list_index__insert_new_node_tail(act_list,
		mickey__create_stop_run_left_act(NULL, move, NULL, NULL));
	anim = anim_list_index__find_anim_index(anim_list, "idle");
	act_list_index__insert_new_node_tail(act_list,
		mickey__create_idle_act(anim, NULL, NULL, NULL));
	act_list_index__insert_new_node_tail(act_list,
		mickey__create_toasty_act(NULL, NULL, NULL, NULL));
	act_list_index__insert_new_node_tail(act_list,
		mickey__create_stop_toasty_act(NULL, NULL, NULL, NULL));
	anim = anim_list_index__find_anim_index(anim_list, "jump");
	move = move_list_index__find_move_index(move_list, "jump");
	act_list_index__insert_new_node_tail(act_list,
		mickey__create_jump_act(anim, move, NULL, NULL));
	act_list_index__insert_new_node_tail(act_list,
		mickey__create_hide_act(NULL, NULL, NULL, NULL));
	return act_list;
}

gobject_t *mickey__create(void)
{
	gobject_t *mickey = NULL;
	int retval = 0;
	chrono_t *move_chrono = NULL;
	anim_list_index_t *anim_list = NULL;
	move_list_index_t *move_list = NULL;
	act_list_index_t *act_list = NULL;

	move_chrono = chrono__create(0.015, NULL, chrono__update);
	mickey = gobject__create("Mickey", PLAYER, TRUE);
	if (!mickey)
		return NULL;
	retval += gobject__fill_visual_info(mickey,
			"lib/utilsCSFML/texture/mickey_spritesheet.png",
			(sfIntRect){0, 0, 40, 40}, (sfVector2f){4, 4});
	retval += gobject__fill_placement_info(mickey, (sfVector2f){20, 20},
	(sfVector2f){(WIDTHSCREEN / 2), (HEIGHTSCREEN / 2)});
	anim_list = mickey__create_anim_list(mickey->texture);
	retval += gobject__fill_animation(mickey, anim_list);
	if (retval == -1)
		return my_ptr_error("Erreur pour mickey animation!\n");
	move_list = mickey__create_move_list();
	retval += gobject__fill_movement(mickey, move_list, move_chrono);
	if (retval == -1)
		return my_ptr_error("Erreur pour mickey movement!\n");
	act_list = mickey__create_act_list(mickey->animation->anims,
						mickey->movement->moves);
	retval += gobject__fill_action(mickey, act_list);
	if (retval < 0)
		return my_ptr_error("Erreur pour mickey!\n");
	return mickey;
}
