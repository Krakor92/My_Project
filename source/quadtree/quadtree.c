/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Functions that are relative to the basics of double linked lists
*/

#include "quadtree.h"

quadtree_t *quadtree__malloc(void)
{
	quadtree_t *quadtree = NULL;

	quadtree = malloc (sizeof(*quadtree));
	if (!quadtree)
		return NULL;
	quadtree->max_object = 10;
	quadtree->max_levels = 5;
	quadtree->level = 0;
	quadtree->objects = NULL;
	quadtree->bounds = NULL;
	quadtree->nodes = NULL;
	return quadtree;
}

quadtree_t *quadtree__create(size_t level, sfFloatRect *bounds)
{
	quadtree_t *quadtree = NULL;

	if (!bounds)
		return NULL;
	quadtree = quadtree__malloc();
	if (!quadtree)
		return NULL;
	quadtree->level = level;
	quadtree->bounds = bounds;
	return quadtree;
}

sfFloatRect *sfFloatRect__malloc(float left, float top, float width, float height)
{
	sfFloatRect *rect = NULL;

	rect = malloc(sizeof(*rect));
	if (!rect)
		return NULL;
	rect->left = left;
	rect->top = top;
	rect->width = width;
	rect->height = height;
	return rect;
}

static int quadtree__split_2p(quadtree_t *quadtree, float sub_width, float sub_height)
{
	float x = quadtree->bounds->left;
	float y = quadtree->bounds->top;

	quadtree->nodes[0] = quadtree__create(quadtree->level + 1,
	sfFloatRect__malloc(x, y, sub_width, sub_height));
	if (!quadtree->nodes[0])
		return -1;
	quadtree->nodes[1] = quadtree__create(quadtree->level + 1,
	sfFloatRect__malloc(x + sub_width, y, sub_width, sub_height));
	if (!quadtree->nodes[1])
		return -1;
	quadtree->nodes[2] = quadtree__create(quadtree->level + 1,
	sfFloatRect__malloc(x, y + sub_height, sub_width, sub_height));
	if (!quadtree->nodes[2])
		return -1;
	quadtree->nodes[3] = quadtree__create(quadtree->level + 1,
	sfFloatRect__malloc(x + sub_width, y + sub_height,
				sub_width, sub_height));
	if (!quadtree->nodes[3])
		return -1;
	return 0;
}

int quadtree__split(quadtree_t *quadtree)
{
	float sub_width;
	float sub_height;

	if (!quadtree || !quadtree->bounds || quadtree->nodes)
		return -2;
	quadtree->nodes = malloc(4 * sizeof(*quadtree->nodes));
	if (!quadtree->nodes)
		return -1;
	sub_width = quadtree->bounds->width/2;
	sub_height = quadtree->bounds->height/2;
	return quadtree__split_2p(quadtree, sub_width, sub_height);
}
