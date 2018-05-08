/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** gobject.c
*/

#include "utilsCSFML.h"

sfVector2f gobject__get_top_left_corner_position(gobject_t *gobject)
{
	sfVector2f top_left;

	top_left.x = gobject->position.x - gobject->origin.x;
	top_left.y = gobject->position.y - gobject->origin.y;
	return top_left;
}

sfVector2u gobject__get_texture_rect_dimension(gobject_t *gobject)
{
	sfVector2u dim;

	dim.x = gobject->rect.width;
	dim.y = gobject->rect.height;
	return dim;
}

//A appeler à chaque fois que le gobject change (de position (move), visuellement (anim))
//en gros faire: gobject->hitbox = gobject__get_new_hitbox(gobject);
sfFloatRect gobject__get_new_hitbox(gobject_t *gobject)
{
	sfVector2f pos = gobject__get_top_left_corner_position(gobject);
	sfVector2u dim = gobject__get_texture_rect_dimension(gobject);
	sfFloatRect hitbox;

	if (gobject->animation && gobject->animation->current) {
		pos.x += gobject->animation->current->current->hitbox.left;
		pos.y += gobject->animation->current->current->hitbox.top;
		dim.x = gobject->animation->current->current->hitbox.width;
		dim.y = gobject->animation->current->current->hitbox.height;
	}
	hitbox.left = pos.x;
	hitbox.top = pos.y;
	hitbox.width = dim.x;
	hitbox.height = dim.y;
	return hitbox;
}

/*
bool_t gobject__collide_a_gobject(gobject_t *g1, gobject_t *g2)
{
	sfVector2f pos1 = gobject__get_top_left_corner_position(g1);
	sfVector2f pos2 = gobject__get_top_left_corner_position(g2);


	return FALSE;
}
*/

//Next move will collide the gobject
bool_t gobject__move_will_collide_the_gobject(gobject_t *g1, gobject_t *g2)
{
	sfFloatRect hitbox1 = g1->hitbox;
	hitbox1.left += g1->speed.x;
	hitbox1.top += g1->speed.y;

	if (sfFloatRect__collide_a_sfFloatRect(hitbox1, g2->hitbox))
		return TRUE;
	return FALSE;
}

/*Va vérifier si le mouvement à faire ne va pas faire entrer le gobject en colision avec d'autre
A creuser (beaucoup de choses possibles)*/
/*void gobject__check_move_collision(gobject_t *gobject, gobject_list_t *list)
{
	for (; list; list = list->next) {
		if ()
	}

}
*/
