/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Functions that delete or clean dlist
*/

#include "str_dlist.h"

void delete_head_dlist(DListIndex_t *dlist)
{
	DListNode_t *temp = NULL;

	if (dlist_is_null(dlist) || dlist_is_empty(dlist))
		return;
	if (dlist->length == 1) {
		free(dlist->head->val);
		free(dlist->head);
		dlist->head = NULL;
		dlist->tail = NULL;
		dlist->length = 0;
		return;
	}
	temp = dlist->head;
	dlist->head = dlist->head->prev;
	dlist->head->next = NULL;
	free(temp->val);
	free(temp);
	dlist->length--;
}

void delete_tail_dlist(DListIndex_t *dlist)
{
	DListNode_t *temp = NULL;

	if (dlist_is_null(dlist) || dlist_is_empty(dlist))
		return;
	if (dlist->length == 1) {
		free(dlist->tail->val);
		free(dlist->tail);
		dlist->head = NULL;
		dlist->tail = NULL;
		dlist->length = 0;
		return;
	}
	temp = dlist->tail;
	dlist->tail = dlist->tail->next;
	dlist->tail->prev = NULL;
	free(temp->val);
	free(temp);
	dlist->length--;
}

void clean_dlist(DListIndex_t *dlist)
{
	while (!dlist_is_empty(dlist))
		delete_head_dlist(dlist);
}

void destroy_dlist(DListIndex_t *dlist)
{
	clean_dlist(dlist);
	free(dlist);
}
