/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** sfRenderStates.c
*/

#include "utilsCSFML.h"

sfRenderStates *sfRenderStates_create(sfTexture *texture)
{
	sfRenderStates *r_states = NULL;

	r_states = malloc(sizeof(*r_states));
	if (!r_states)
		return my_ptr_error(INVALID_MALLOC);
	r_states->blendMode = sfBlendAlpha;
	r_states->transform = sfTransform_Identity;
	r_states->texture = texture;
	r_states->shader = NULL;
	return r_states;
}

void sfRenderStates_destroy(sfRenderStates *r_states)
{
	free(r_states);
	r_states = NULL;
}
