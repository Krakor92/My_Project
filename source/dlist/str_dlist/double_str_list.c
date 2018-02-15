/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Functions that are relative to the basics of double linked lists
*/
#include "str_dlist.h"

DListCore_ptr get_new_dlist(void)
{
	DListCore_ptr dlist;
	dlist = malloc(sizeof(*dlist));
	if (dlist == NULL)
		return (NULL);
	dlist->length = 0;
	dlist->head = NULL;
	dlist->tail = NULL;
	return (dlist);
}

DListNode_ptr get_new_node(char *str)
{
	DListNode_ptr newnode;
	newnode = malloc(sizeof(*newnode));
	if (newnode == NULL)
		return (NULL);
	newnode->val = str;
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}

int dlist_is_null(DListCore_ptr dlist)
{
	if (dlist == NULL)
		return (true);
	return (false);
}

int dlist_is_empty(DListCore_ptr dlist)
{
	if (dlist->length == 0 && dlist->head == NULL && dlist->tail == NULL)
		return (true);
	return (false);
}
