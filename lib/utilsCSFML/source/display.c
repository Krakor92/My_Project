/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** chrono.c
*/

#include "utilsCSFML.h"

void gobject__draw(sfRenderWindow *win, gobject_t *gobject)
{
	if (!win || !gobject || !gobject->sprite)
		return;
	if (gobject->show)
		sfRenderWindow_drawSprite(win, gobject->sprite, NULL);
}

void gobject_list__draw(sfRenderWindow *win, gobject_list_t *list)
{
	gobject_list_t *tlist = list;

	if (!win || !tlist)
		return;
	while (tlist) {
		gobject__draw(win, tlist->gobject);
		tlist = tlist->next;
	}
}

void gobject__anim(gobject_t *gobject)
{
	anim_index_t *anim = NULL;

	if (!gobject || !gobject->animation)
		return;
	anim = (gobject->animation->current) ?
	gobject->animation->current : gobject->animation->standard;

	if (!anim->current && !anim->finished) {
		sfClock_restart(anim->chrono->clock);
		anim->current = anim->start;
		gobject__set_texture_rect(gobject, anim->current->rect);
		return;
	}
	if (chrono__update2(anim->chrono, anim->current->on)) {
		anim->current = anim->current->next;
		if (anim->current) {
			gobject__set_texture_rect(gobject, anim->current->rect);
		}
		else
			anim->finished = TRUE;
	}


}

void gobject_list__anim(gobject_list_t *list)
{
	gobject_list_t *tlist = list;

	while (tlist) {
		gobject__anim(tlist->gobject);
		tlist = tlist->next;
	}
}
