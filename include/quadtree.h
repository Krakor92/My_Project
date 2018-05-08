/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Double Str Linked List Header
*/

#ifndef __QUADTREE__H__
	#define __QUADTREE__H__

	/* Library */
	#include "utilsCSFML.h"

	/* Typedefs */
	typedef struct quadtree_s quadtree_t;

	/* Structs */
	struct quadtree_s
	{
		size_t max_object;
		size_t max_levels;
		size_t level;
		gobject_list_t *objects;
		sfFloatRect *bounds;
		quadtree_t **nodes;
	};

	/* Prototypes */
#endif
