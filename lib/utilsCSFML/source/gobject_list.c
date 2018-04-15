/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** chrono.c
*/

#include "utilsCSFML.h"

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

bool_t gobject_list__is_empty(gobject_list_t *list)
{
	if (!list->gobject && !list->prev && !list->next)
		return TRUE;
	return FALSE;
}

int gobject_list__add_elem(gobject_list_t *list, gobject_t *gobject)
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

/*
* We have a pointer on the TAIL of the list
*/
void gobject_list__remove_head(gobject_list_t *list)
{
	gobject_list_t *tlist = list;

	if (!tlist || gobject_list__is_empty(tlist))
		return;
	while (tlist->next != NULL)
		tlist = tlist->next;
	gobject__destroy(tlist->gobject);
	tlist->gobject = NULL;
	if (tlist->prev) {
		tlist->prev->next = NULL;
		free(tlist);
	}
}

void gobject_list__remove_tail(gobject_list_t *list)
{
	gobject_list_t *tlist = list->next;

	if (!list || gobject_list__is_empty(list))
		return;
	gobject__destroy(list->gobject);
	list->gobject = NULL;
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
}

gobject_t *gobject_list__get_gobject(gobject_list_t *list, char *name)
{
	gobject_list_t *tlist = list;

	if (!list || !name)
		return NULL;
	while (tlist) {
		if (my_strequal(name, tlist->gobject->name))
			return tlist->gobject;
	}
	return NULL;
}

int gobject_list__set_gobject_current_anim(gobject_list_t *list,
						     char *gobject_name,
						     char *current_anim)
{
	gobject_t *gobject = NULL;

	gobject = gobject_list__get_gobject(list, gobject_name);
	if (!gobject)
		return -1;
	if (animation__set_current_anim(gobject->animation, current_anim) == -1)
		return -1;
	return 0;
}
