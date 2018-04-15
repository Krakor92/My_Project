/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** chrono.c
*/

#include "utilsCSFML.h"

gobject_t *gobject__malloc(void)
{
	gobject_t *gobject = NULL;

	gobject = malloc(sizeof(*gobject));
	if (!gobject)
		return my_ptr_error(INVALID_MALLOC);
	gobject->name = NULL;
	gobject->type = N_A;
	gobject->show = FALSE;
	gobject->sprite = NULL;
	gobject->texture = NULL;
	gobject->origin = (sfVector2f){0, 0};
	gobject->position = (sfVector2f){0, 0};
	gobject->scale = (sfVector2f){1, 1};
	gobject->speed = (sfVector2f){0, 0};
	gobject->acceleration = (sfVector2f){0, 0};
	gobject->animation = NULL;
	return gobject;
}

gobject_t *gobject__create(char *name, gobject_type_t type, bool_t show)
{
	gobject_t *gobject = NULL;

	gobject = gobject__malloc();
	if (!gobject)
		return NULL;
	gobject__fill_sprite(gobject);
	gobject__fill_basic_info(gobject, name, type, show);
	return gobject;
}

int gobject__fill_sprite(gobject_t *gobject)
{
	if (!gobject)
		return -1;
	gobject->sprite = sfSprite_create();
	if (!gobject->sprite)
		return my_int_error("Invalid Sprite!\n");
	return 0;
}

int gobject__fill_basic_info(gobject_t *gobject,
				   char *name,
			 gobject_type_t type,
				 bool_t show)
{
	if (!gobject)
		return -1;
	gobject->name = name;
	gobject->type = type;
	gobject->show = show;
	return 0;
}

int gobject__fill_visual_info(gobject_t *gobject,
				   char *texture_path,
			      sfIntRect rect,
			     sfVector2f scale)
{
	if (!gobject || !gobject->sprite)
		return -1;
	gobject->texture = sfTexture_createFromFile(texture_path, NULL);
	if (!gobject->texture)
		return my_int_error("Invalid Texture!\n");
	gobject->rect = rect;
	gobject->scale = scale;
	sfSprite_setTexture(gobject->sprite, gobject->texture, TRUE);
	sfSprite_setTextureRect(gobject->sprite, gobject->rect);
	sfSprite_setScale(gobject->sprite, gobject->scale);
	return 0;
}

int gobject__fill_placement_info(gobject_t *gobject,
				sfVector2f origin,
				sfVector2f position)
{
	if (!gobject || !gobject->sprite)
		return -1;
	gobject->origin = origin;
	gobject->position = position;
	sfSprite_setPosition(gobject->sprite, gobject->position);
	return 0;
}

int gobject__fill_movement_info(gobject_t *gobject,
			       sfVector2f speed,
			       sfVector2f acceleration)
{
	if (!gobject)
		return -1;
	gobject->speed = speed;
	gobject->acceleration = acceleration;
	return 0;
}

int gobject__fill_anims(gobject_t *gobject,
			     char *standard,
		anim_list_index_t *anims)
{
	if (!gobject)
		return -1;
	gobject->animation = animation__create(anims, standard);
	if (!gobject->animation)
		return -1;
	return 0;
}

int gobject__set_texture_rect(gobject_t *gobject, sfIntRect rect)
{
	if (!gobject)
		return -1;
	gobject->rect = rect;
	sfSprite_setTextureRect(gobject->sprite, gobject->rect);
	return 0;
}

void gobject__destroy(gobject_t *gobject)
{
	sfSprite_destroy(gobject->sprite);
	sfTexture_destroy(gobject->texture);
	animation__destroy(gobject->animation);
	free(gobject);
}
