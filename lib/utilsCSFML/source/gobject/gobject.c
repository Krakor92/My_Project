/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** gobject.c
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
	gobject->info = NULL;
	gobject->show = FALSE;
	gobject->sprite = NULL;
	gobject->texture = NULL;
	gobject->origin = (sfVector2f){0, 0};
	gobject->position = (sfVector2f){0, 0};
	gobject->scale = (sfVector2f){1, 1};
	gobject->speed = (sfVector2f){0, 0};
	gobject->acceleration = (sfVector2f){0, 0};
	gobject->animation = NULL;
	gobject->action = NULL;
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
	sfSprite_setOrigin(gobject->sprite, gobject->origin);
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

int gobject__fill_animation(gobject_t *gobject, anim_list_index_t *anims)
{
	if (!gobject)
		return -1;
	gobject->animation = animation__create(anims);
	if (!gobject->animation)
		return -1;
	return 0;
}

int gobject__fill_movement(gobject_t *gobject,
				move_list_index_t *moves,
				chrono_t *chrono)
{
	if (!gobject)
		return -1;
	gobject->movement = movement__create(moves, chrono);
	if (!gobject->movement)
		return -1;
	return 0;
}

int gobject__fill_action(gobject_t *gobject,
				act_list_index_t *acts)
{
	if (!gobject)
		return -1;
	gobject->action = action__create(acts);
	if (!gobject->action)
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

void stats__destroy(stats_t *stats)
{
	if (!stats)
		return;
	free(stats);
	stats = NULL;
}

void player_info__destroy(player_info_t *info)
{
	if (!info)
		return;
	stats__destroy(info->stats);
	//2dtab destroy aussi
	free(info);
	info = NULL;
}

void pnj_info__destroy(pnj_info_t *info)
{
	if (!info)
		return;
	stats__destroy(info->stats);
	//2dtab destroy aussi
	free(info);
	info = NULL;
}

void structure_info__destroy(structure_info_t *info)
{
	if (!info)
		return;
	free(info);
	info = NULL;
}

void gobject_info__destroy(gobject_info_t *info)
{
	if (!info)
		return;
	player_info__destroy(info->player_i);
	pnj_info__destroy(info->pnj_i);
	structure_info__destroy(info->structure_i);
	free(info);
	info = NULL;
}

void gobject__destroy(gobject_t *gobject)
{
	gobject_info__destroy(gobject->info);
	sfSprite_destroy(gobject->sprite);
	sfTexture_destroy(gobject->texture);
	animation__destroy(gobject->animation);
	movement__destroy(gobject->movement);
	action__destroy(gobject->action);
	free(gobject);
	gobject = NULL;
}



/*************
*    ANIM    *
*************/
void gobject__do_anim(gobject_t *gobject, anim_index_t *anim)
{
	if (!gobject || !anim || anim->finished)
		return;
	if (!anim->started) {
		sfClock_restart(anim->chrono->clock);
		anim->current = anim->start;
		anim->started = TRUE;
	}
	else if (chrono__update2(anim->chrono, anim->current->on)) {
		anim->current = anim->current->next;
		if (!anim->current) {
			anim->finished = TRUE;
			return;
		}
	}
	gobject->animation->current = anim;
	gobject__set_texture_rect(gobject, anim->current->rect);
}

/*************
*    MOVE    *
*************/
void gobject__move(gobject_t *gobject)
{
	if (!gobject || !gobject->movement || !gobject->movement->chrono)
		return;
	if (chrono__update(gobject->movement->chrono)) {
		//gobject__check_move_collision(gobject, list);
		sfSprite_move(gobject->sprite, gobject->speed);
		gobject->position = sfSprite_getPosition(gobject->sprite);
	}
}

void gobject__update_move(gobject_t *gobject, move_node_t* move_node)
{
	if (!gobject || !move_node)
		return;
	gobject->speed.x += move_node->acc.x;
	gobject->speed.y += move_node->acc.y;
}

void gobject__do_move(gobject_t *gobject, move_index_t *move)
{
	if (!gobject || !move || move->finished)
		return;
	if (!move->started) {
		sfClock_restart(move->chrono->clock);
		move->current = move->start;
		move->started = TRUE;
	}
	else if (chrono__update(move->chrono)) {
		move->current = move->current->next;
		if (move->info && !move->current &&
		move->info->loop_type == BLOCK_LOOP)
			move->current = move->end;
		if (!move->current) {
			move->finished = TRUE;
			return;
		}
	}
	gobject__update_move(gobject, move->current);
}



/************
*    ACT    *
************/
void gobject__do_action(gobject_t *gobject, gobject_list_t *gobjects)
{
	act_list_node_t *acts = NULL;

	if (!gobject || !gobject->action || !gobject->action->acts || !gobjects)
		return;
	for (acts = gobject->action->acts->tail; acts; acts = acts->next) {
		if (acts->act->active)
			acts->act->action(acts->act, gobject, gobjects);
	}
}

void gobject__active_act_if_conditions(gobject_t *gobject)
{
	act_list_node_t *acts = NULL;

	if (!gobject || !gobject->action || !gobject->action->acts)
		return;
	for (acts = gobject->action->acts->tail; acts; acts = acts->next)
		act__active_if_conditions(acts->act);
}

void gobject__update_acts(gobject_t *gobject)
{
	act_list_node_t *acts = NULL;

	if (!gobject || !gobject->action || !gobject->action->acts)
		return;
	for (acts = gobject->action->acts->tail; acts; acts = acts->next) {
		//Plus tard, event sera une structure comme ça je dis que si !event alors c'est une action qui
		//cherche à s'activer sans évènement particulier (idle)
		if (acts->act->event.type == sfEvtCount)
			acts->act->on_hold = TRUE;
		act__update(acts->act);
	}
}

bool_t gobject__act_is_active(gobject_t *gobject, char *act_name)
{
	act_t *act = NULL;

	act = gobject__get_act(gobject, act_name);
	if (!act)
		return FALSE;
	if (act->active)
		return TRUE;
	return FALSE;
}

act_t *gobject__get_act(gobject_t *gobject, char *act_name)
{
	act_list_node_t *acts = NULL;

	if (!gobject || !gobject->action || !gobject->action->acts || !act_name)
		return NULL;
	for (acts = gobject->action->acts->tail; acts; acts = acts->next)
		if (my_strequal(acts->act->name, act_name))
			return acts->act;
	return NULL;
}


move_node_t *gobject__get_act_move_current_node(gobject_t *gobject, char *act_name)
{
	act_t *act = NULL;

	act = gobject__get_act(gobject, act_name);
	return act__get_move_current_node(act);
}



/**************
*    EVENT    *
**************/

void gobject__hold_on_act_if_event(gobject_t *gobject, sfEvent event)
{
	act_list_node_t *acts = NULL;

	if (!gobject || !gobject->action || !gobject->action->acts)
		return;
	for (acts = gobject->action->acts->tail; acts; acts = acts->next)
		act__hold_on_if_event(acts->act, event);
}



/*************
*    DRAW    *
*************/

void gobject__draw(sfRenderWindow *win, gobject_t *gobject)
{
	if (!win || !gobject || !gobject->sprite)
		return;
	if (gobject->show)
		sfRenderWindow_drawSprite(win, gobject->sprite, NULL);
}
