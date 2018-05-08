/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** gobject_anim.c
*/

#include "utilsCSFML.h"

action_t *action__malloc(void)
{
	action_t *action = NULL;

	action = malloc(sizeof(*action));
	if (!action)
		return my_ptr_error(INVALID_MALLOC);
	action->acts = NULL;
	return action;
}

action_t *action__create(act_list_index_t *acts)
{
	action_t *action = NULL;

	if (!acts)
		return NULL;
	action = action__malloc();
	if (!action)
		return NULL;
	action->acts = acts;
	return action;
}

/*
int action__set_current_act(action_t *action, char *name)
{
	if (!action)
		return -1;
	if (!name)
		action->current = NULL;
	action->current = act_list_index__find_act(action->acts,
						   name);
	if (!action->current)
		return my_int_error("Current anim not found in anim_list!\n");
	return 0;
}
*/

void action__destroy(action_t *action)
{
	if (!action)
		return;
	act_list_index__destroy(action->acts);
	free(action);
	action = NULL;
}
