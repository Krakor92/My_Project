/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Functions that delete or clean dlist
*/
#include "str_dlist.h"

int delete_head_dlist(DListCore_ptr dlist)
{
	if (dlist_is_null(dlist) || dlist_is_empty(dlist))
		return (0);
	else if (dlist->length == 1) {
		free(dlist->head->val);
		free(dlist->head);
		dlist->head = NULL;
		dlist->tail = NULL;
		dlist->length = 0;
		return (0);
	}
	DListNode_ptr temp = dlist->head;
	dlist->head = dlist->head->next;
	dlist->head->prev = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	free(temp->val);
	free(temp);
	temp = NULL;
	--dlist->length;
	return (0);
}

int delete_tail_dlist(DListCore_ptr dlist)
{
	if (dlist_is_null(dlist) || dlist_is_empty(dlist))
		return (0);
	else if (dlist->length == 1) {
		free(dlist->tail->val);
		free(dlist->tail);
		dlist->head = NULL;
		dlist->tail = NULL;
		dlist->length = 0;
		return (0);
	}
	DListNode_ptr temp = dlist->tail;
	dlist->tail = dlist->tail->prev;
	dlist->tail->next = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	free(temp->val);
	free(temp);
	temp = NULL;
	--dlist->length;
	return (0);
}

void clean_dlist(DListCore_ptr dlist)
{
	while (dlist->length > 1) {
		DListNode_ptr temp = dlist->head;
		free(dlist->head->val);
		dlist->head = dlist->head->next;
		dlist->head->prev = NULL;
		temp->next = NULL;
		temp->prev = NULL;
		free(temp);
		temp = NULL;
		--dlist->length;
	}
	if (dlist->length == 1) {
		free(dlist->head->val);
		free(dlist->head);
		dlist->head = NULL;
		dlist->tail = NULL;
		dlist->length = 0;
	}
}

DListCore_ptr destroy_dlist(DListCore_ptr dlist)
{
	clean_dlist(dlist);
	free(dlist);
	dlist = NULL;
	return (dlist);
}
