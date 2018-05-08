/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** gobject_list.c
*/

#include "utilsCSFML.h"

/*****************
*    CREATION    *
*****************/
gobject_list_t *gobject_list__malloc(void)
{
	gobject_list_t *gobject_list = NULL;

	gobject_list = malloc(sizeof(*gobject_list));
	if (!gobject_list)
		return my_ptr_error(INVALID_MALLOC);
	gobject_list->gobject = NULL;
	gobject_list->next = NULL;
	gobject_list->prev = NULL;
	return gobject_list;
}

gobject_list_t *gobject_list__create(gobject_t *gobject)
{
	gobject_list_t *gobject_list = NULL;

	gobject_list = gobject_list__malloc();
	if (!gobject_list)
		return NULL;
	gobject_list->gobject = gobject;
	return gobject_list;
}

/**************
*    OTHER    *
**************/
bool_t gobject_list__is_empty(gobject_list_t *list)
{
	if (!list->gobject && !list->prev && !list->next)
		return TRUE;
	return FALSE;
}

/************
*    ADD    *
************/
int gobject_list__add_node(gobject_list_t *list, gobject_t *gobject)
{
	gobject_list_t *tlist = list;

	if (!tlist || !gobject)
		return -1;
	if (gobject_list__is_empty(tlist)) {
		tlist->gobject = gobject;
		return 0;
	}
	while (tlist->next != NULL)
		tlist = tlist->next;
	tlist->next = gobject_list__create(gobject);
	if (!tlist->next)
		return -1;
	tlist->next->prev = tlist;
	return 0;
}

/********************
*    NODE REMOVE    *
********************/
void gobject_list__clean_node(gobject_list_t *node)
{
	if (!node)
		return;
	if (node->gobject)
		gobject__destroy(node->gobject);
	node->gobject = NULL;
}

void gobject_list__destroy_node(gobject_list_t *node)
{
	if (!node)
		return;
	if (node->next && node->prev) {
		node->next->prev = node->prev;
		node->prev->next = node->next;
	}
	if (node->next && !node->prev)
		node->next->prev = NULL;
	if (!node->next && node->prev)
		node->prev->next = NULL;
	gobject_list__clean_node(node);
	node->next = NULL;
	node->prev = NULL;
	free(node);
	node = NULL;
}

/*********************
*    ELEMS REMOVE    *
*********************/
void gobject_list__clean_elem(gobject_list_t *list, char *name)
{
	if (!list || gobject_list__is_empty(list))
		return;
	for (; list; list = list->next) {
		if (my_strequal(name, list->gobject->name)) {
			gobject_list__clean_node(list);
			return;
		}
	}
}

void gobject_list__remove_elem(gobject_list_t *list, char *name)
{
	if (!list || gobject_list__is_empty(list))
		return;
	for (; list; list = list->next) {
		if (my_strequal(name, list->gobject->name)) {
			gobject_list__destroy_node(list);
			return;
		}
	}
}

/********************
*    LIST REMOVE    *
********************/
/*
* We have a pointer on the TAIL of the list
*/
void gobject_list__remove_head(gobject_list_t *list)
{
	gobject_list_t *tlist = NULL;

	if (!tlist || gobject_list__is_empty(tlist))
		return;
	for (tlist = list; tlist->next; tlist = tlist->next);
	gobject_list__destroy_node(tlist);
}

void gobject_list__remove_tail(gobject_list_t *list)
{
	gobject_list_t *tlist = list->next;

	if (!list || gobject_list__is_empty(list))
		return;
	gobject_list__clean_node(list);
	if (tlist) {
		free(list);
		list = NULL;
		tlist->prev = NULL;
		list = tlist;
	}
}

void gobject_list__clean(gobject_list_t *list)
{
	while (!gobject_list__is_empty(list))
		gobject_list__remove_tail(list);
}

void gobject_list__destroy(gobject_list_t *list)
{
	gobject_list__clean(list);
	free(list);
	list = NULL;
}

/*************
*    FIND    *
*************/
gobject_t *gobject_list__get_gobject(gobject_list_t *list, char *name)
{
	if (!list || !name)
		return NULL;
	for (; list; list = list->next) {
		if (my_strequal(list->gobject->name, name))
			return list->gobject;
	}
	return NULL;
}

/*************
*    MOVE    *
*************/
void gobject_list__move(gobject_list_t *list)
{
	if (!list)
		return;
	for (; list; list = list->next)
		gobject__move(list->gobject);
}

/************
*    ACT    *
************/
void gobject_list__do_action(gobject_list_t *list)
{
	if (!list)
		return;
	for (; list; list = list->next)
		gobject__do_action(list->gobject, list);
}

void gobject_list__update_acts(gobject_list_t *list)
{
	if (!list)
		return;
	for (; list; list = list->next)
		gobject__update_acts(list->gobject);
}

act_t *gobject_list__get_gobject_act(gobject_list_t *list,
					char *gobj_name,
					char *act_name)
{
	gobject_t *gobject = NULL;
	act_t *act = NULL;

	if (!list || !gobj_name || !act_name)
		return NULL;
	gobject = gobject_list__get_gobject(list, gobj_name);
	if (!gobject)
		return NULL;
	act = gobject__get_act(gobject, act_name);
	return act;
}


/**************
*    EVENT    *
**************/

void gobject_list__hold_on_act_if_event(gobject_list_t *list, sfEvent event)
{
	if (!list)
		return;
	for (; list; list = list->next)
		gobject__hold_on_act_if_event(list->gobject, event);
}

void gobject_list__active_act_if_conditions(gobject_list_t *list)
{
	if (!list)
		return;
	for (; list; list = list->next)
		gobject__active_act_if_conditions(list->gobject);
}

bool_t gobject_list__act_is_active(gobject_list_t *list, char *act_name)
{
	if (!list || !act_name)
		return FALSE;
	for (; list; list = list->next)
		if (gobject__act_is_active(list->gobject, act_name))
			return TRUE;
	return FALSE;
}



/*************
*    DRAW    *
*************/

void gobject_list__draw(sfRenderWindow *win, gobject_list_t *list)
{
	if (!win || !list)
		return;
	for (; list; list = list->next)
		gobject__draw(win, list->gobject);
}
