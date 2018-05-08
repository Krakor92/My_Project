/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Utils functions header
*/

#ifndef __UTILSCSFML__H__
	#define __UTILSCSFML__H__

	/* Library */
	#include <SFML/Graphics.h>
	#include <SFML/Window.h>
	#include <SFML/Audio.h>

	#include "basic_c.h"
	#include "my_printf.h"

	/* Constants */
	static const int WIDTHSCREEN = 1920;
	static const int HEIGHTSCREEN = 1080;

	/* Typedefs */
	typedef struct player_info_s player_info_t;
	typedef struct pnj_info_s pnj_info_t;
	typedef struct structure_info_s structure_info_t;
	typedef struct gobject_info_s gobject_info_t;

	typedef struct stats_s stats_t;
	typedef struct player_s player_t;
	typedef struct chrono_s chrono_t;
	typedef struct gobject_s gobject_t;
	typedef struct gobject_list_s gobject_list_t;
	typedef struct chrono_list_s chrono_list_t;

	typedef struct anim_list_index_s anim_list_index_t;
	typedef struct anim_list_node_s anim_list_node_t;
	typedef struct anim_index_s anim_index_t;
	typedef struct anim_node_s anim_node_t;
	typedef struct animation_s animation_t;

	typedef struct move_list_index_s move_list_index_t;
	typedef struct move_list_node_s move_list_node_t;
	typedef struct move_info_s move_info_t;
	typedef struct move_index_s move_index_t;
	typedef struct move_node_s move_node_t;
	typedef struct movement_s movement_t;

	typedef struct act_list_index_s act_list_index_t;
	typedef struct act_list_node_s act_list_node_t;
	typedef struct act_s act_t;
	typedef struct action_s action_t;

	/* Enums */
	typedef enum gobject_type_e
	{
		N_A,
		PNJ,
		PLAYER,
		STRUCTURE,
		LANDSCAPE,
		ITEM
	} gobject_type_t;

	typedef enum pnj_type_e
	{
		FRIENDLY,
		HOSTILE
	} pnj_type_t;

	typedef enum structure_type_e
	{
		NO_INTERRACTION,
		INTERRACTION
	} structure_type_t;



	/* Structs */
	struct player_info_s
	{
		char *name;
		stats_t *stats;
		char **inventory;
	};
//Pour l'inventaire, je sais pas encore comment m'y prendre, surement un tableau
//de tableau de string
	struct pnj_info_s
	{
		char *name;
		pnj_type_t type;
		stats_t *stats;
		char **inventory;
	};

	struct structure_info_s
	{
		char *name;
		structure_type_t type;
	};

	struct gobject_info_s
	{
		gobject_type_t type;
		player_info_t *player_i;
		pnj_info_t *pnj_i;
		structure_info_t *structure_i;
	};



	struct frame;

	struct stats_s
	{
		int life;
		int mana;
		int stamina;
		int shield;
		int dps;
	};

	struct player_s
	{
		gobject_t *obj;
		stats_t *stats;
		char **inventory;
	};

	struct gobject_s
	{
		char *name; // (in the code, not in the game)
		gobject_info_t *info;
		gobject_type_t type;
		bool_t show;
		sfSprite *sprite;
		sfTexture *texture;
		sfIntRect rect;
		sfFloatRect hitbox;//plus précis que sfIntRect
		sfVector2f origin;
		sfVector2f position;
		sfVector2f scale;
		sfVector2f speed;
		sfVector2f acceleration;// Pour l'instant pas utilisé
//		sfVector2f max_speed; exemple: 16
		animation_t *animation;
		movement_t *movement;
		action_t *action;
//		gobject_list_t *sub; Sous objets (style la tête, le corps) si il est nécessaire de séparer des parties d'un même objets en objets
//		exemple: The Binding of Isaac => Isaac a 2 sous objet, le sous objet TÊTE et le sous objet CORPS
	};

/* I need to implement this version cause we need
a global chrono to move objects
Avec possibilité de faire pointer tous les chronos de
toutes les structure move_index_t sur ce chrono global
Ou alors directement enlever les chronos dans les move_index_t
car ils ne sont plus utiles.

	struct gobject_list_index_s
	{
		chrono_t *move_chrono;
		gobject_list_node_t *head;
		gobject_list_node_t *tail;
	}

	struct gobject_list_node_s
	{
		gobject_t *gobject;
		gobject_list_node_t *next;
		gobject_list_node_t *prev;
	}

EDIT: Chaque gobject à son chrono de mouvement présent dans
sa structure movement
*/
	struct gobject_list_s
	{
		gobject_t *gobject;
		struct gobject_list_s *next;
		struct gobject_list_s *prev;
	};

	struct chrono_s
	{
		char *name;//je sais pas si c'est vraiment utile mais bon...
		sfClock *clock;
		sfTime time;
		double elapsed;
		double restart;
		void (*restart_action)(void);
		bool_t (*update)(chrono_t*);
	};
/*
Peut être faire une liste de chrono pour mieux s'y retrouver
	struct chrono_list_s
	{
		chrono_t *chrono;
		struct chrono_list_s *next;
		struct chrono_list_s *prev;
	};
EDIT: Non.
*/


/*****************
*    ANIMATION   *
*****************/

	struct anim_list_index_s
	{
		size_t nb_anims;
		anim_list_node_t *head;
		anim_list_node_t *tail;
	};

	struct anim_list_node_s
	{
		anim_index_t *anim;
		anim_list_node_t *next;
		anim_list_node_t *prev;
	};

	//Here, start is the "tail" and end the "head"
	struct anim_index_s
	{
		char *name;
		sfTexture *texture;//ne sert à rien
		size_t nb_frames;
		chrono_t *chrono;
		anim_node_t *start;
		anim_node_t *current;
		anim_node_t *end;
		bool_t started;
		bool_t finished;
		bool_t loop;//savoir si le dernier ajout est relié au premier
	};

	/*
	* It would be interesting (or not) to loop the last anim_node with the
	* first one if the animation need to be triggered more than one time
	*
	* if on = 1, then the frame displayed will not be affected;
	* if on = 0.5, the frame will be displayed two times less than on = 1;
	* if on = 2, the frame will be displayed two times longer than on = 1;
	*/
	struct anim_node_s
	{
		size_t number;
		sfIntRect rect;
		sfIntRect hitbox;
		double on;
		anim_node_t *next;
		anim_node_t *prev;
	};

	struct animation_s
	{
		anim_index_t *current;
		anim_list_index_t *anims;
	};

	////animation////
	//anim_delete.c//
	void anim_index__remove_end(anim_index_t *);
	void anim_index__remove_start(anim_index_t *);
	void anim_index__clean(anim_index_t *);
	void anim_index__destroy(anim_index_t *);
	//anim_insert.c//
	int anim_index__insert_node_start(anim_index_t *, anim_node_t *);
	int anim_index__insert_node_end(anim_index_t *, anim_node_t *);
	int anim_index__insert_new_node_start(anim_index_t *, sfIntRect,
						sfIntRect, double);
	int anim_index__insert_new_node_end(anim_index_t *, sfIntRect,
						sfIntRect, double);
	//anim_list_delete.c//
	void anim_list_index__remove_head(anim_list_index_t *);
	void anim_list_index__remove_tail(anim_list_index_t *);
	void anim_list_index__clean(anim_list_index_t *);
	void anim_list_index__destroy(anim_list_index_t *);
	//anim_list_insert.c//
	int anim_list_index__insert_node_tail(anim_list_index_t *,
					      anim_list_node_t *);
	int anim_list_index__insert_node_head(anim_list_index_t *,
					      anim_list_node_t *);
	int anim_list_index__insert_new_node_tail(anim_list_index_t *,
						  anim_index_t *);
	int anim_list_index__insert_new_node_head(anim_list_index_t *,
						  anim_index_t *);
	//anim_list_manip.c//
	anim_index_t *anim_list_index__find_anim_index(anim_list_index_t *,
							char *);
	//anim_list.c//
	anim_list_index_t *anim_list_index__malloc(void);
	anim_list_index_t *anim_list_index__create(void);
	anim_list_node_t *anim_list_node__malloc(void);
	anim_list_node_t *anim_list_node__create(anim_index_t *);
	bool_t anim_list_index__is_empty(anim_list_index_t *);
	//anim_reset.c//
	void anim_index__reset(anim_index_t *);
	//anim_test.c//
	anim_index_t *create_mickey_idle_anim(sfTexture *);
	anim_index_t *create_mickey_running_anim(sfTexture *);
	//anim.c//
	anim_index_t *anim_index__malloc(void);
	anim_index_t *anim_index__create(char *, sfTexture *, chrono_t *, bool_t);
	anim_node_t *anim_node__malloc(void);
	anim_node_t *anim_node__create(sfIntRect, sfIntRect, double);
	bool_t anim_index__is_empty(anim_index_t *);
	//animation.c//
	animation_t *animation__malloc(void);
	animation_t *animation__create(anim_list_index_t *);
	void animation__destroy(animation_t *);


/****************
*    MOVEMENT   *
*****************/

	typedef enum move_loop_type_e
	{
		SINGLE_LOOP,
//		NB_LOOP, j'oublie, c'est trop chiant à implémenter
		BLOCK_LOOP, //Bloque au dernier mouvement et le continue à l'infini (pratique pour simuler une accélération)
		INF_LOOP
	} move_loop_type_t;

	typedef enum move_type_e
	{
		FIXED,
		VARIABLE
	} move_type_t;


	struct move_list_index_s
	{
		size_t nb_moves;
		move_list_node_t *head;
		move_list_node_t *tail;
	};

	struct move_list_node_s
	{
		move_index_t *move;
		move_list_node_t *next;
		move_list_node_t *prev;
	};

	struct move_info_s
	{
		move_type_t type;
		move_loop_type_t loop_type;
	};

	//Here, start is the "tail" and end the "head"
	struct move_index_s
	{
		char *name;
		size_t nb_steps;
		move_info_t *info;
//		size_t current_loop; //Dans le cas ou le n-loop fonctionne
		chrono_t *chrono;//devrait être un pointeur sur le chrono dans la struct movement du gobject!!! ou pas?
		move_node_t *start;
		move_node_t *current;
		move_node_t *end;
		bool_t started;
		bool_t finished;
		bool_t active;
	};

	/*
	* It would be interesting (or not) to loop the last anim_node with the
	* first one if the animation need to be triggered more than one time
	*
	* if on = 1, then the frame displayed will not be affected;
	* if on = 0.5, the frame will be displayed two times less than on = 1;
	* if on = 2, the frame will be displayed two times longer than on = 1;
	*/
	struct move_node_s
	{
		size_t number;
//		sfVector2f move;
		sfVector2f acc;
		move_node_t *next;
		move_node_t *prev;
	};

	struct movement_s
	{
		chrono_t *chrono;//chrono qui gère le mouvement du gobject, il est fondamental
		move_list_index_t *moves;
//		move_list_index_t *actives;
	};

	////movement////
	//move_delete.c//
	void move_index__remove_start(move_index_t *);
	void move_index__remove_end(move_index_t *);
	void move_index__clean(move_index_t *);
	void move_index__destroy(move_index_t *);
	//move_info.c//
	move_info_t *move_info__malloc(void);
	move_info_t *move_info__create(move_type_t, move_loop_type_t);
	void move_info__destroy(move_info_t *);
	//move_insert.c//
	int move_index__insert_node_start(move_index_t *, move_node_t *);
	int move_index__insert_node_end(move_index_t *, move_node_t *);
	int move_index__insert_new_node_start(move_index_t *, sfVector2f);
	int move_index__insert_new_node_end(move_index_t *, sfVector2f);
	int move_index__insert_several_new_node_start(move_index_t *, sfVector2f, size_t);
	int move_index__insert_several_new_node_end(move_index_t *, sfVector2f, size_t);
	//move_list_delete.c//
	void move_list_index__remove_head(move_list_index_t *);
	void move_list_index__remove_tail(move_list_index_t *);
	void move_list_index__clean(move_list_index_t *);
	void move_list_index__destroy(move_list_index_t *);
	//move_list_insert.c//
	int move_list_index__insert_node_tail(move_list_index_t *,
						move_list_node_t *);
	int move_list_index__insert_node_head(move_list_index_t *,
						move_list_node_t *);
	int move_list_index__insert_new_node_tail(move_list_index_t *,
							move_index_t *);
	int move_list_index__insert_new_node_head(move_list_index_t *,
							move_index_t *);
	//move_list_manip.c//
	move_index_t *move_list_index__find_move_index(move_list_index_t *,
							char *);
	void move_list_index__reset_move_index(move_list_index_t *,
						char *);
	//move_list.c//
	move_list_index_t *move_list_index__malloc(void);
	move_list_index_t *move_list_index__create(void);
	move_list_node_t *move_list_node__malloc(void);
	move_list_node_t *move_list_node__create(move_index_t *);
	bool_t move_list_index__is_empty(move_list_index_t *);
	//move_reset.c//
	void move_index__reset(move_index_t *);
	//move.c//
	move_index_t *move_index__malloc(void);
	move_index_t *move_index__create(char *,
					move_type_t,
					move_loop_type_t,
					chrono_t *);
	move_node_t *move_node__malloc(void);
	move_node_t *move_node__create(sfVector2f);
	bool_t move_index__is_empty(move_index_t *);
	void move_index__set_move_node_current(move_index_t *, size_t);
	//movement.c//
	movement_t *movement__malloc(void);
	movement_t *movement__create(move_list_index_t *, chrono_t *);
	void movement__destroy(movement_t *);




/**************
*    ACTION   *
**************/

	struct act_list_index_s
	{
		size_t nb_acts;
		act_list_node_t *head;
		act_list_node_t *tail;
	};

	struct act_list_node_s
	{
		act_t *act;
		act_list_node_t *next;
		act_list_node_t *prev;
	};

	typedef enum act_type_e
	{
		ONE_SHOT,
		ENDLESS
	} act_type_t;

	//Here, start is the "tail" and end the "head"
	struct act_s
	{
		char *name;
		act_type_t type;
		int (*action)(act_t *, gobject_t *, gobject_list_t *);//play would be a better name
//		int (*anim)(act_t *, gobject_t *, gobject_list_t *);
//		int (*move)(act_t *, gobject_t *, gobject_list_t *);
		bool_t (*criterion)(act_t *, gobject_t *, gobject_list_t *);
		sfMusic *sound;
		sfEvent event;
		//event_t event; => avec dedans sfEvent et une structure event_details_t details
		anim_index_t *anim;
		move_index_t *move;
		chrono_t *chrono;//Parce que c'est toujours utile d'avoir un chrono ;) (savoir depuis combien de temps l'action est en cours par exemple)
		bool_t loop;//savoir si l'action se répète
		bool_t on_hold;//en attente (demandé par un event par exemple)
		bool_t active; //TRUE == the act is currently used, FALSE == Opposite
		bool_t started;
//		bool_t finished;//inutile (plutôt que de dire que c'est fini, autant reset l'act direct)
		act_list_index_t *dependencies; //list of act that need to be active to active this act
		act_list_index_t *interdictions; // if one of these act are active, you can't active this act
	};

	struct action_s//quel intérêt du coup de garder cette structure ¯\_(ツ)_/¯
	{
		act_list_index_t *acts;
//		act_list_index_t *current; Show which actions are currently actives ()
	};

	/* Prototypes */
	////action////
	//act_delete.c//
	void act__destroy(act_t *);
	//act_list_delete.c//
	void act_list_index__remove_head(act_list_index_t *);
	void act_list_index__remove_tail(act_list_index_t *);
	void act_list_index__clean(act_list_index_t *);
	void act_list_index__destroy(act_list_index_t *);
	void act_list_index__destroy_soft(act_list_index_t *);
	//act_list_insert.c//
	int act_list_index__insert_node_tail(act_list_index_t *,
						act_list_node_t *);
	int act_list_index__insert_node_head(act_list_index_t *,
						act_list_node_t *);
	int act_list_index__insert_new_node_tail(act_list_index_t *,
						act_t*);
	int act_list_index__insert_new_node_head(act_list_index_t *,
						act_t *);
	//act_list_manip//
	act_t *act_list_index__find_act(act_list_index_t *,
					char *);
	int act_list_index__change_act_active(act_list_index_t *, char *,
						bool_t);
	bool_t act_list_index__there_are_active_act(act_list_index_t *);
	bool_t act_list_index__all_are_active_act(act_list_index_t *);
	//act_list.c//
	act_list_index_t *act_list_index__malloc(void);
	act_list_index_t *act_list_index__create(void);
	act_list_node_t *act_list_node__malloc(void);
	act_list_node_t *act_list_node__create(act_t *);
	bool_t act_list_index__is_empty(act_list_index_t *);
	//act_reset.c//
	void act__reset(act_t *);
	//act.c//
	act_t *act__malloc(void);
	act_t *act__create(char *,
				int(*)(act_t *, gobject_t *, gobject_list_t *),
				anim_index_t *,
				move_index_t *);
	int act__fill_special_list(act_t *,
					act_list_index_t *,
					act_list_index_t *);
	int act__fill_sf_info(act_t *, sfEvent, sfMusic *);
	void act__hold_on_if_event(act_t *, sfEvent);
	bool_t act__active_if_conditions(act_t *);
	bool_t act__stop_if_not_condition(act_t *);
	void act__update(act_t *);
	move_node_t *act__get_move_current_node(act_t *);
	void act__set_move_current_node(act_t *, size_t);
	//action.c//
	action_t *action__malloc(void);
	action_t *action__create(act_list_index_t *);
	void action__destroy(action_t *);
	////\action////
	////collision////
	bool_t sfVector2f__is_in_sfFloatRect(sfVector2f, sfFloatRect);
	bool_t sfFloatRect__collide_a_sfFloatRect(sfFloatRect, sfFloatRect);
	////\collision////
	////events////
	//compare_events.c//
	bool_t the_events_are_the_same(sfEvent, sfEvent);
	//handle_events.c//
	void handle_events(sfRenderWindow *, gobject_list_t *, sfEvent);
	//key_events.c//
	void sfEvtKeyPressed_events(sfRenderWindow *, gobject_list_t *, sfEvent);
	void sfEvtKeyReleased_events(sfRenderWindow *, gobject_list_t *, sfEvent);
	//mouse_events.c//
	void sfEvtMouseButtonPressed_events(sfRenderWindow *, sfEvent);
	void sfEvtMouseButtonReleased_events(sfRenderWindow *, sfEvent);
	//window_events.c//
	void sfEvtClosed_events(sfRenderWindow *, sfEvent);
	////\events////
	////gobject////
	//////mickey//////
	////////action////////
	//mickey_action.c//
	int mickey__toasty(act_t *, gobject_t *, gobject_list_t *);
	int mickey__stop_toasty(act_t *, gobject_t *, gobject_list_t *);
	act_t *mickey__create_toasty_act(anim_index_t *,
					move_index_t *,
					act_list_index_t *,
					act_list_index_t *);
	act_t *mickey__create_stop_toasty_act(anim_index_t *,
						move_index_t *,
						act_list_index_t *,
						act_list_index_t *);
	//mickey_hide_act.c//
	int mickey__hide(act_t *, gobject_t *, gobject_list_t *);
	act_t *mickey__create_hide_act(anim_index_t *, move_index_t *,
					act_list_index_t *, act_list_index_t *);
	//mickey_idle_act.c//
	int mickey__idle(act_t *, gobject_t *, gobject_list_t *);
	act_list_index_t *mickey__create_idle_act_interdictions(
						act_list_index_t *,
						gobject_list_t *);
	act_t *mickey__create_idle_act(anim_index_t *, move_index_t *,
					act_list_index_t *, act_list_index_t *);
	//mickey_jump_act.c//
	int mickey__jump(act_t *, gobject_t *, gobject_list_t *);
	act_t *mickey__create_jump_act(anim_index_t *, move_index_t *,
					act_list_index_t *, act_list_index_t *);
	//mickey_run_left_act.c//
	int mickey__run_left(act_t *, gobject_t *, gobject_list_t *);
	act_t *mickey__create_run_left_act(anim_index_t *, move_index_t *,
					act_list_index_t *, act_list_index_t *);
	//mickey_run_right_act.c//
	int mickey__run_right(act_t *, gobject_t *, gobject_list_t *);
	act_t *mickey__create_run_right_act(anim_index_t *, move_index_t *,
					act_list_index_t *, act_list_index_t *);
//
	//mickey_stop_run_left_act.c//
	int mickey__stop_run_left(act_t *, gobject_t *,
					gobject_list_t *);
	act_t *mickey__create_stop_run_left_act(anim_index_t *,
						move_index_t *,
						act_list_index_t *,
						act_list_index_t *);
	//mickey_stop_run_right_act.c//
	int mickey__stop_run_right(act_t *, gobject_t *,
					gobject_list_t *);
	act_t *mickey__create_stop_run_right_act(anim_index_t *,
						move_index_t *,
						act_list_index_t *,
						act_list_index_t *);
	////////////////
	////////animation////////
	anim_index_t *mickey__create_idle_anim(sfTexture *);
	anim_index_t *mickey__create_jump_anim(sfTexture *);
	anim_index_t *mickey__create_run_anim(sfTexture *);
	////////////////
	////////movement////////
	move_index_t *mickey__create_jump_move(void);
	move_index_t *mickey__create_run_right_move(void);
	move_index_t *mickey__create_stop_run_right_move(void);
	move_index_t *mickey__create_run_left_move(void);
	move_index_t *mickey__create_stop_run_left_move(void);
	////////\movement////////
	//mickey.c//
	gobject_t *mickey__create(void);
	//////\mickey//////
	//gobject.c//
	gobject_t *gobject__create(char *, gobject_type_t, bool_t);
	void gobject__set_ttr_rect(gobject_t *, sfIntRect);
	int gobject__fill_sprite(gobject_t *);
	int gobject__fill_basic_info(gobject_t *, char *, gobject_type_t, bool_t);
	int gobject__fill_visual_info(gobject_t *, char *, sfIntRect, sfVector2f);
	int gobject__fill_placement_info(gobject_t *, sfVector2f, sfVector2f);
	int gobject__fill_movement_info(gobject_t *, sfVector2f, sfVector2f);
	int gobject__fill_animation(gobject_t *, anim_list_index_t *);
	int gobject__fill_movement(gobject_t *, move_list_index_t *,
					chrono_t *);
	int gobject__fill_action(gobject_t *, act_list_index_t *);
	int gobject__set_texture_rect(gobject_t *, sfIntRect);
	void gobject__destroy(gobject_t *);
	void gobject__do_animation(gobject_t *);
	void gobject__do_anim(gobject_t *, anim_index_t *);
	void gobject__move(gobject_t *);
	void gobject__update_move(gobject_t *, move_node_t *);
	void gobject__do_movement(gobject_t *);
	void gobject__do_move(gobject_t *, move_index_t *);
	void gobject__do_anim(gobject_t *, anim_index_t *);
	void gobject__do_action(gobject_t *, gobject_list_t *);
	void gobject__update_acts(gobject_t *);
	void gobject__hold_on_act_if_event(gobject_t *, sfEvent);
	void gobject__active_act_if_conditions(gobject_t *);
	bool_t gobject__act_is_active(gobject_t *, char *);
	act_t *gobject__get_act(gobject_t *, char *);
	void gobject__draw(sfRenderWindow *, gobject_t *);
	////\gobject////
	sfRenderWindow *create_my_window(unsigned int, unsigned int);
	int launch_csfml(void);
	//chrono.c//
	chrono_t *chrono__malloc(void);
	chrono_t *chrono__create(double, void(*)(void),
				bool_t(*)(chrono_t *));
	void chrono__destroy(chrono_t *);
	bool_t chrono__update(chrono_t *);
	bool_t chrono__update2(chrono_t *, double);
	//display.c//
	//gobject_list.c//
	gobject_list_t *gobject_list__malloc(void);
	gobject_list_t *gobject_list__create(gobject_t *);
	bool_t gobject_list__is_empty(gobject_list_t *);
	int gobject_list__add_node(gobject_list_t *, gobject_t *);
	void gobject_list__clean_node(gobject_list_t *);
	void gobject_list__destroy_node(gobject_list_t *);
	void gobject_list__clean_elem(gobject_list_t *, char *);
	void gobject_list__remove_elem(gobject_list_t *, char *);
	void gobject_list__remove_head(gobject_list_t *);
	void gobject_list__remove_tail(gobject_list_t *);
	void gobject_list__clean(gobject_list_t *);
	void gobject_list__destroy(gobject_list_t *);
	gobject_t *gobject_list__get_gobject(gobject_list_t *, char *);
	void gobject_list__move(gobject_list_t *);
	void gobject_list__do_action(gobject_list_t *);
	void gobject_list__update_acts(gobject_list_t *);
	act_t *gobject_list__get_gobject_act(gobject_list_t *, char *, char *);
	void gobject_list__hold_on_act_if_event(gobject_list_t *, sfEvent);
	void gobject_list__active_act_if_conditions(gobject_list_t *);
	bool_t gobject_list__act_is_active(gobject_list_t *, char *);
	void gobject_list__handle_act(gobject_list_t *, sfEvent);
	void gobject_list__draw(sfRenderWindow *, gobject_list_t *);
	//create_2d_sfVector.c//
	sfVector2u *sfVector2u_init(int, int);
	sfVector2f *sfVector2f_init(float, float);
	void sfVector2u_set_value(sfVector2u *, int, int);
	void sfVector2f_set_value(sfVector2f *, float, float);
	//create_sfRect.c//
	sfIntRect *sfIntRect_init(int, int, int, int);
	sfFloatRect *sfFloatRect_init(float, float, float, float);
	void sfIntRect_set_value(sfIntRect *, int, int, int, int);
	void sfFloatRect_set_value(sfFloatRect *, float, float, float, float);
	//sfRenderStates.c//
	sfRenderStates *sfRenderStates_create(sfTexture *);
	void sfRenderStates_destroy(sfRenderStates *);
#endif
