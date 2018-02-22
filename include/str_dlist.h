/*
** EPITECH PROJECT, 2017
** [N/A]
** File description:
** Double Str Linked List Header
*/

#ifndef DOUBLE_STR_LIST_H
	#define DOUBLE_STR_LIST_H

	/* Library */
	#include <stdbool.h>
	#include <stdlib.h>
	#include "utils1.h"

	/* Structs */
	// Définition d'un maillon de la Double_list
	typedef struct DoubleListNode_s
	{
		char *val;
		struct DoubleListNode_s *prev;
		struct DoubleListNode_s *next;
	}*DListNode_ptr, DListNode_t;

	// Définition d'une Double_List
	typedef struct DoubleListIndex_s
	{
		int length;
		DListNode_t *head;
		DListNode_t *tail;
	}*DListCore_ptr, DListIndex_t;

	/* Prototypes */
	//delete_dlists.c
	void delete_head_dlist(DListIndex_t *dlist);
	void delete_tail_dlist(DListIndex_t *dlist);
	void clean_dlist(DListIndex_t *dlist);
	void destroy_dlist(DListIndex_t *dlist);
	//double_str_list.c
	DListIndex_t *get_new_dlist(void);
	DListNode_t *get_new_node(char *str);
	int dlist_is_null(DListIndex_t *dlist);
	int dlist_is_empty(DListIndex_t *dlist);
	//insert_n_get_dlist.c
	int get_dlist_length(DListIndex_t *dlist);
	char *get_dlist_head_value(DListIndex_t *dlist);
	char *get_dlist_tail_value(DListIndex_t *dlist);
	int insert_head_dlist(DListIndex_t *dlist, char *str);
	int insert_tail_dlist(DListIndex_t *dlist, char *str);
#endif
