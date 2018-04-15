/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** gobject_anim.c
*/

#include "utilsCSFML.h"

animation_t *animation__malloc(void)
{
	animation_t *animation = NULL;

	animation = malloc(sizeof(*animation));
	if (!animation)
		return my_ptr_error(INVALID_MALLOC);
	animation->standard = NULL;
	animation->current = NULL;
	animation->anims = NULL;
	return animation;
}

animation_t *animation__create(anim_list_index_t *anims, char *standard)
{
	animation_t *animation = NULL;

	if (!standard || !anims)
		return NULL;
	animation = animation__malloc();
	if (!animation)
		return NULL;
	animation->standard = anim_list_index__find_anim_index(anims, standard);
	if (!animation->standard)
		return NULL;
	animation->anims = anims;
	return animation;
}


int animation__set_current_anim(animation_t *animation, char *name)
{
	if (!animation || !name)
		return -1;
	animation->current = anim_list_index__find_anim_index(animation->anims,
							      name);
	if (!animation->current)
		return my_int_error("Current anim not found in anim_list!\n");
	return 0;
}

void animation__destroy(animation_t *animation)
{
	if (animation) {
		anim_list_index__destroy(animation->anims);
		free(animation);
	}
}
