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

	/* Structs */
	// Définition d'un maillon de la Double_list
	typedef struct Double_ListNode
	{
		char *val;
		struct Double_ListNode *prev;
		struct Double_ListNode *next;
	}*DListNode_ptr, DListNode_t;

	// Définition d'une Double_List
	typedef struct Double_ListCore
	{
		int length;
		DListNode_t *head;
		DListNode_t *tail;
	}*DListCore_ptr, DListCore_t;

	/* Prototypes */
	DListCore_t *get_new_dlist(void);
	DListNode_t *get_new_node(char *str);
	int dlist_is_null(DListCore_ptr dlist);
	int dlist_is_empty(DListCore_ptr dlist);
	//insert_n_get_dlist.c
	int get_dlist_length(DListCore_ptr dlist);
	char *get_dlist_head_value(DListCore_ptr dlist);
	char *get_dlist_tail_value(DListCore_ptr dlist);
	int insert_head_dlist(DListCore_ptr dlist, char *str);
	int insert_tail_dlist(DListCore_ptr dlist, char *str);
	//delete_dlists.c
	int delete_head_dlist(DListCore_ptr dlist);
	int delete_tail_dlist(DListCore_ptr dlist);
	void clean_dlist(DListCore_ptr dlist);
	DListCore_t *destroy_dlist(DListCore_ptr dlist);
#endif
