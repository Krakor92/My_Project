/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Functions that are relative to the basics of double linked lists
*/

#include "utilsCSFML.h"

act_t *act_list_index__find_act(act_list_index_t *act_list,
				char *name)
{
	act_list_node_t *act_node = NULL;

	for (act_node = act_list->tail; act_node; act_node = act_node->next) {
		if (my_strequal(name, act_node->act->name))
			return act_node->act;
	}
	return NULL;
}

int act_list_index__change_act_active(act_list_index_t *act_list,
					char *act_name,
					bool_t new_active)
{
	act_t *act = NULL;

	if (!act_list || !act_name)
		return -1;
	act = act_list_index__find_act(act_list, act_name);
	if (!act)
		return my_int_error("Act not found in act_list!\n");
	act->active = new_active;
	return 0;
}

bool_t act_list_index__there_are_active_act(act_list_index_t *list)
{
	act_list_node_t *node = NULL;

	if (!list)
		return FALSE;
	for (node = list->tail; node; node = node->next) {
		if (node->act->active)
			return TRUE;
	}
	return FALSE;
}

bool_t act_list_index__all_are_active_act(act_list_index_t *list)
{
	act_list_node_t *node = NULL;

	if (!list)
		return TRUE;
	for (node = list->tail; node; node = node->next) {
		if (!node->act->active)
			return FALSE;
	}
	return TRUE;
}
