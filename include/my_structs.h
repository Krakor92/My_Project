/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** my_structs.h
*/

#ifndef __MY_STRUCTS__H__
	#define __MY_STRUCTS__H__

	/* Library */
	#include <stddef.h>
	#include "my_typedefs.h"

	/* Structs */
	struct size_t2d_s
	{
		size_t x;
		size_t y;
	};

	struct size_t3d_s
	{
		size_t x;
		size_t y;
		size_t z;
	};

	struct int2d_s
	{
		int x;
		int y;
	};

	struct int3d_s
	{
		int x;
		int y;
		int z;
	};

	struct float2d_s
	{
		float x;
		float y;
	};

	struct float3d_s
	{
		float x;
		float y;
		float z;
	};

	struct double2d_s
	{
		double x;
		double y;
	};
#endif
