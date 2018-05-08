/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** mickey_movement.c
*/

#include "utilsCSFML.h"

move_index_t *mickey__create_stop_run_left_move(void)
{
	move_index_t *move = NULL;
	chrono_t *chrono = NULL;
	int retval = 0;

	chrono = chrono__create(0.015, NULL, chrono__update);
	move = move_index__create("stop_run_left", FIXED, SINGLE_LOOP, chrono);
	if (!move)
		return NULL;
	retval += move_index__insert_several_new_node_end(move, (sfVector2f){0.5, 0}, 10);
/*	retval += move_index__insert_new_node_end(move, (sfVector2f){1.1, 0}, 1);
	retval += move_index__insert_new_node_end(move, (sfVector2f){0.9, 0}, 1);
	retval += move_index__insert_new_node_end(move, (sfVector2f){0.8, 0}, 1);
	retval += move_index__insert_new_node_end(move, (sfVector2f){0.7, 0}, 1);
	retval += move_index__insert_new_node_end(move, (sfVector2f){0.6, 0}, 1);
	retval += move_index__insert_new_node_end(move, (sfVector2f){0.4, 0}, 1);
	retval += move_index__insert_new_node_end(move, (sfVector2f){0.3, 0}, 1);
	retval += move_index__insert_new_node_end(move, (sfVector2f){0.2, 0}, 1);
*/	if (retval < 0)
		return NULL;
	return move;
}
