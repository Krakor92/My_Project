/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** launch_csfml.c
*/

#include "utilsCSFML.h"

void rainbow(sfColor *color)
{
	if (color->r == 255 && color->g < 255 && color->b == 0)
		color->g++;
	if (color->r > 0 && color->g == 255 && color->b == 0)
		color->r--;
	if (color->r == 0 && color->g == 255 && color->b < 255)
		color->b++;
	if (color->r == 0 && color->g > 0 && color->b == 255)
		color->g--;
	if (color->r < 255 && color->g == 0 && color->b == 255)
		color->r++;
	if (color->r == 255 && color->g == 0 && color->b > 0)
		color->b--;
}

anim_list_index_t *create_mickey_anim_list(sfTexture *texture)
{
	anim_list_index_t *anim_list = NULL;

	anim_list = anim_list_index__create();
	if (!anim_list)
		return NULL;
	anim_list_index__insert_new_node_head(anim_list, create_mickey_idle_anim(texture));
	anim_list_index__insert_new_node_head(anim_list, create_mickey_running_anim(texture));
	return anim_list;
}

anim_list_index_t *new_create_mickey_anim_list(sfTexture *texture)
{
	anim_list_index_t *anim_list = NULL;

	anim_list = anim_list_index__create();
	if (!anim_list)
		return NULL;
	anim_list_index__insert_new_node_head(anim_list, create_mickey_new_idle_anim(texture));
	anim_list_index__insert_new_node_head(anim_list, create_mickey_new_running_anim(texture));
	return anim_list;
}


gobject_t *new_create_mickey(void)
{
	gobject_t *mickey = NULL;
	sfVector2f origin;
	int retval = 0;
	anim_list_index_t *anim_list = NULL;

	mickey = gobject__create("Mickey", CHARACTER, TRUE);
	if (!mickey)
		return NULL;
	retval += gobject__fill_visual_info(mickey,
				  "lib/utilsCSFML/texture/mickey_spritesheet.png",
				  (sfIntRect){0, 0, 40, 40},
				  (sfVector2f){6, 6});
	origin.x = (WIDTHSCREEN / 2) - (mickey->rect.width / 2) * (mickey->scale.x);
	origin.y = (HEIGHTSCREEN / 2) - (mickey->rect.height / 2) * (mickey->scale.y);
	retval += gobject__fill_placement_info(mickey, origin, origin);
	anim_list = new_create_mickey_anim_list(mickey->texture);
	retval += gobject__fill_anims(mickey, "idle", anim_list);
	if (retval < 0)
		my_int_error("Erreur pour mickey!\n");
	return mickey;
}


gobject_t *create_mickey(void)
{
	gobject_t *mickey = NULL;
	sfVector2f origin;
	int retval = 0;
	anim_list_index_t *anim_list = NULL;

	mickey = gobject__create("Mickey", CHARACTER, TRUE);
	if (!mickey)
		return NULL;
	retval += gobject__fill_visual_info(mickey,
				  "lib/utilsCSFML/texture/mickey_sprite.png",
				  (sfIntRect){0, 0, 24, 40},
				  (sfVector2f){6, 6});
	origin.x = (WIDTHSCREEN / 2) - (mickey->rect.width / 2) * (mickey->scale.x);
	origin.y = (HEIGHTSCREEN / 2) - (mickey->rect.height / 2) * (mickey->scale.y);
	retval += gobject__fill_placement_info(mickey, origin, origin);
	anim_list = create_mickey_anim_list(mickey->texture);
	retval += gobject__fill_anims(mickey, "idle", anim_list);
	if (retval < 0)
		my_int_error("Erreur pour mickey!\n");
	return mickey;
}


/*
** launch_csfml = 16l
** Launch the CSFML basic configuration
**
** @param	N/A
** @return	0	if everything works
** 		-1	otherwise
*/
int launch_csfml(void)
{
	sfRenderWindow *window = create_my_window(WIDTHSCREEN, HEIGHTSCREEN);
	sfColor color = sfColor_fromRGBA(255, 0, 0, 255);
	sfRenderStates *r_states = NULL;
	sfEvent event;
	chrono_t *chrono_color = chrono__create(0.01, NULL, chrono__update);
	gobject_t *mickey = new_create_mickey();
	gobject_list_t *gobjects = gobject_list__malloc();

	gobject_list__add_elem(gobjects, mickey);
	r_states = sfRenderStates_create(NULL);
	if (!r_states)
		return -1;
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event))
			handle_events(window, gobjects, event);
		if (chrono_color->update(chrono_color))
			rainbow(&color);
		sfRenderWindow_clear(window, color);
		gobject_list__anim(gobjects);
		gobject_list__draw(window, gobjects);
		sfRenderWindow_display(window);
	}
	gobject_list__destroy(gobjects);
	chrono__destroy(chrono_color);
	sfRenderStates_destroy(r_states);
	sfRenderWindow_destroy(window);
	return 0;
}
