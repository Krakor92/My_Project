/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** launch_csfml.c
*/

#include "utilsCSFML.h"

static void rainbow(sfColor *color)
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

gobject_list_t *gobject_list__init(void)
{
	gobject_list_t *list = NULL;
	int retval = 0;

	list = gobject_list__malloc();
	if (!list)
		return NULL;
	retval += gobject_list__add_node(list, mickey__create());
	if (retval < 0)
		return NULL;
	return list;
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
	sfEvent event;
	sfColor color = sfColor_fromRGBA(255, 0, 0, 255);
	sfRenderStates *r_states = sfRenderStates_create(NULL);
	chrono_t *chrono_color = chrono__create(0.01, NULL, chrono__update);
	gobject_list_t *gobjects = gobject_list__init();

	if (!r_states || !chrono_color || !gobjects)
		return -1;
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event))
			handle_events(window, gobjects, event);
		if (chrono_color->update(chrono_color))
		//if (chrono_update(chrono_color))
			rainbow(&color);
		sfRenderWindow_clear(window, color);
		gobject_list__update_acts(gobjects);
		gobject_list__do_action(gobjects);
		gobject_list__move(gobjects);
		gobject_list__draw(window, gobjects);
		sfRenderWindow_display(window);
	}
	gobject_list__destroy(gobjects);
	chrono__destroy(chrono_color);
	sfRenderStates_destroy(r_states);
	sfRenderWindow_destroy(window);
	return 0;
}


/*
int launch_csfml(void)
{
	sfRenderWindow *window = create_my_window(WIDTHSCREEN, HEIGHTSCREEN);
	sfColor color = sfColor_fromRGBA(255, 0, 0, 255);
	chrono_t *chrono_color = chrono__create(0.01, NULL, chrono__update);

	if (!window || !chrono_color)
		return -1;
	while (sfRenderWindow_isOpen(window)) {
//		while (sfRenderWindow_pollEvent(window, &event))
//			handle_events(window, gobjects, event);
		if (chrono__update(chrono_color))
			rainbow(&color);
		sfRenderWindow_clear(window, color);
		sfRenderWindow_display(window);
	}
	sfRenderWindow_destroy(window);
	return 0;
}
*/
