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
	#include "basic_c.h"
	#include "my_printf.h"

	/* Constants */
	static const int WIDTHSCREEN = 1920;
	static const int HEIGHTSCREEN = 1080;

	/* Typedefs */
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

	/* Enums */
	typedef enum gobject_type_e
	{
		N_A,
		CHARACTER,
		STRUCTURE,
		LANDSCAPE,
		ITEM
	} gobject_type_t;

	/* Structs */
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
		char *name;
		gobject_type_t type;
		bool_t show;
		sfSprite *sprite;
		sfTexture *texture;
		sfIntRect rect;
		sfVector2f origin;
		sfVector2f position;
		sfVector2f scale;
		sfVector2f speed;
		sfVector2f acceleration;
		animation_t *animation;
	};

	struct gobject_list_s
	{
		gobject_t *gobject;
		struct gobject_list_s *next;
		struct gobject_list_s *prev;
	};

	struct chrono_s
	{
		char *name;
		sfClock *clock;
		sfTime time;
		double elapsed;
		double restart;
		void (*restart_action)(void);
		bool_t (*update)(chrono_t*);
	};

	struct chrono_list_s
	{
		chrono_t *chrono;
		struct chrono_list_s *next;
		struct chrono_list_s *prev;
	};



	struct anim_list_index_s
	{
		//gobject_t *gobject; à creuser
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
		sfTexture *texture;
		size_t nb_frames;
		chrono_t *chrono;
		anim_node_t *start;
		anim_node_t *end;
		anim_node_t *current;
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
//		sfIntRect hitbox;
		double on;
		anim_node_t *next;
		anim_node_t *prev;
	};

	struct animation_s
	{
		anim_index_t *standard;
		anim_index_t *current;
		anim_list_index_t *anims;
	};



	anim_index_t *create_mickey_new_idle_anim(sfTexture*);
	anim_index_t *create_mickey_new_running_anim(sfTexture*);



	/* Prototypes */
	////animation////
	//anim_delete.c//
	void anim_index__remove_end(anim_index_t*);
	void anim_index__remove_start(anim_index_t*);
	void anim_index__clean(anim_index_t*);
	void anim_index__destroy(anim_index_t*);
	//anim_insert.c//
	int anim_index__insert_node_start(anim_index_t*, anim_node_t*);
	int anim_index__insert_node_end(anim_index_t*, anim_node_t*);
	int anim_index__insert_new_node_start(anim_index_t*, sfIntRect, double);
	int anim_index__insert_new_node_end(anim_index_t*, sfIntRect, double);
	//anim_list_delete.c//
	void anim_list_index__remove_head(anim_list_index_t*);
	void anim_list_index__remove_tail(anim_list_index_t*);
	void anim_list_index__clean(anim_list_index_t*);
	void anim_list_index__destroy(anim_list_index_t*);
	//anim_list_insert.c//
	int anim_list_index__insert_node_tail(anim_list_index_t*,
					       anim_list_node_t*);
	int anim_list_index__insert_node_head(anim_list_index_t*,
					       anim_list_node_t*);
	int anim_list_index__insert_new_node_tail(anim_list_index_t*,
						       anim_index_t*);
	int anim_list_index__insert_new_node_head(anim_list_index_t*,
						       anim_index_t*);
	//anim_list_manip.c//
	anim_index_t *anim_list_index__find_anim_index(anim_list_index_t*,
								    char*);
	//anim_list.c//
	anim_list_index_t *anim_list_index__malloc(void);
	anim_list_index_t *anim_list_index__create(void);
	anim_list_node_t *anim_list_node__malloc(void);
	anim_list_node_t *anim_list_node__create(anim_index_t*);
	bool_t anim_list_index__is_empty(anim_list_index_t*);
	//anim_test.c//
	anim_index_t *create_mickey_idle_anim(sfTexture*);
	anim_index_t *create_mickey_running_anim(sfTexture*);
	//anim.c//
	anim_index_t *anim_index__malloc(void);
	anim_index_t *anim_index__create(char*, sfTexture*, chrono_t*, bool_t);
	anim_node_t *anim_node__malloc(void);
	anim_node_t *anim_node__create(sfIntRect, double);
	bool_t anim_index__is_empty(anim_index_t*);
	//animation.c//
	animation_t *animation__malloc(void);
	animation_t *animation__create(anim_list_index_t*, char*);
	int animation__set_current_anim(animation_t*, char*);
	void animation__destroy(animation_t*);



	////events////
	//handle_events.c//
	void handle_events(sfRenderWindow*, gobject_list_t*, sfEvent);
	//key_events.c//
	void sfEvtKeyPressed_events(sfRenderWindow*, gobject_list_t*, sfEvent);
	void sfEvtKeyReleased_events(sfRenderWindow*, gobject_list_t*, sfEvent);
	//mouse_events.c//
	void sfEvtMouseButtonPressed_events(sfRenderWindow*, sfEvent);
	void sfEvtMouseButtonReleased_events(sfRenderWindow*, sfEvent);
	//window_events.c//
	void sfEvtClosed_events(sfRenderWindow*, sfEvent);

	//other//
	sfRenderWindow *create_my_window(unsigned int, unsigned int);
	int launch_csfml(void);
	//chrono.c//
	chrono_t *chrono__malloc(void);
	chrono_t *chrono__create(double, void (*)(void),
				bool_t (*update)(chrono_t*));
	void chrono__destroy(chrono_t*);
	bool_t chrono__update(chrono_t*);
	bool_t chrono__update2(chrono_t*, double);
	//display.c//
	void gobject__draw(sfRenderWindow*, gobject_t*);
	void gobject_list__draw(sfRenderWindow*, gobject_list_t*);
	void gobject__anim(gobject_t*);
	void gobject_list__anim(gobject_list_t*);
	//gobject_list.c//
	gobject_list_t *gobject_list__malloc(void);
	gobject_list_t *gobject_list__create(gobject_t*);
	int gobject_list__add_elem(gobject_list_t*, gobject_t*);
	bool_t gobject_list__is_empty(gobject_list_t*);
	void gobject_list__remove_head(gobject_list_t*);
	void gobject_list__remove_tail(gobject_list_t*);
	void gobject_list__clean(gobject_list_t*);
	void gobject_list__destroy(gobject_list_t*);
	gobject_t *gobject_list__get_gobject(gobject_list_t*, char*);
	int gobject_list__set_gobject_current_anim(gobject_list_t*,
							     char*,
							     char*);
	//gobject.c//
	gobject_t *gobject__create(char*, gobject_type_t, bool_t);
	void gobject__set_ttr_rect(gobject_t*, sfIntRect);
	int gobject__fill_sprite(gobject_t*);
	int gobject__fill_basic_info(gobject_t*, char*, gobject_type_t, bool_t);
	int gobject__fill_visual_info(gobject_t*, char*, sfIntRect, sfVector2f);
	int gobject__fill_placement_info(gobject_t*, sfVector2f, sfVector2f);
	int gobject__fill_movement_info(gobject_t*, sfVector2f, sfVector2f);
	int gobject__fill_anims(gobject_t*, char*, anim_list_index_t*);
	int gobject__set_texture_rect(gobject_t*, sfIntRect);
	void gobject__destroy(gobject_t*);
	//create_2d_sfVector.c//
	sfVector2u *sfVector2u_init(int, int);
	sfVector2f *sfVector2f_init(float, float);
	void sfVector2u_set_value(sfVector2u*, int, int);
	void sfVector2f_set_value(sfVector2f*, float, float);
	//create_sfRect.c//
	sfIntRect *sfIntRect_init(int, int, int, int);
	sfFloatRect *sfFloatRect_init(float, float, float, float);
	void sfIntRect_set_value(sfIntRect*, int, int, int, int);
	void sfFloatRect_set_value(sfFloatRect*, float, float, float, float);
	//sfRenderStates.c//
	sfRenderStates *sfRenderStates_create(sfTexture*);
	void sfRenderStates_destroy(sfRenderStates*);
#endif
