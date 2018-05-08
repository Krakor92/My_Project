/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Functions that are relative to the basics of double linked lists
*/

#include "utilsCSFML.h"

anim_index_t *anim_list_index__find_anim_index(anim_list_index_t *index,
						char *name)
{
	anim_list_node_t *node = NULL;

	if (!index || !name)
		return NULL;
	for (node = index->tail; node; node = node->next) {
		if (my_strequal(name, node->anim->name))
			return node->anim;
	}
	my_putstr_error("\"");
	my_putstr_error(name);
	return my_ptr_error("\" move not found in anim_list!\n");
}
