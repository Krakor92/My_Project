/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Functions that are relative to the basics of double linked lists
*/

#include "utilsCSFML.h"

anim_index_t *anim_list_index__find_anim_index(anim_list_index_t *anim_list,
							    char *name)
{
	anim_list_node_t *anim_node = anim_list->tail;

	while (anim_node) {
		if (my_strequal(name, anim_node->anim->name))
			return anim_node->anim;
		anim_node = anim_node->next;
	}
	return NULL;
}
