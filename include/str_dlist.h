/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Double Str Linked List Header
*/

#ifndef __DOUBLE_STR_LIST__H__
	#define __DOUBLE_STR_LIST__H__

	/* Library */
	#include "basic_c.h"
	#include "my_enums.h"
	#include "my_structs.h"
	#include "my_typedefs.h"

	/* Structs */
	struct dlist_node_s
	{
		char *val;
		struct dlist_node_s *prev;
		struct dlist_node_s *next;
	};

	struct dlist_index_s
	{
		int length;
		dlist_node_t *head;
		dlist_node_t *tail;
	};

	/* Representation:
	*
	*   prev    next   prev     next
	NULL <- node -> ... <- node -> NULL
	*         ^               ^
	*    tail |_______________| head
	*               index
	*/

	/* Prototypes */
	//delete_dlists.c
	void delete_head_dlist(dlist_index_t *dlist);
	void delete_tail_dlist(dlist_index_t *dlist);
	void clean_dlist(dlist_index_t *dlist);
	void destroy_dlist(dlist_index_t *dlist);
	////////////////////////////////////////////
	//double_str_list.c
	dlist_index_t *get_new_dlist(void);
	dlist_node_t *get_new_node(char *str);
	int dlist_is_null(dlist_index_t *dlist);
	int dlist_is_empty(dlist_index_t *dlist);
	////////////////////////////////////////
	//insert_n_get_dlist.c
	int get_dlist_length(dlist_index_t *dlist);
	char *get_dlist_head_value(dlist_index_t *dlist);
	char *get_dlist_tail_value(dlist_index_t *dlist);
	int insert_head_dlist(dlist_index_t *dlist, char *str);
	int insert_tail_dlist(dlist_index_t *dlist, char *str);
	//////////////////////////////////////////////////////
#endif
