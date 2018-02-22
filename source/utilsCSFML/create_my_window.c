/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** 1 function
*/

#include "utilsCSFML.h"

/*
** create_my_window =
** Create a CSFML window
**
** @param	width	The width of the window (in pixels)
** @param	height	The height of the window (in pixels)
** @return	The address in memory of the window
*/
sfRenderWindow *create_my_window(unsigned int width, unsigned int heigth)
{
	sfRenderWindow *window;
	sfVideoMode video_mode;

	video_mode.width = width;
	video_mode.height = heigth;
	video_mode.bitsPerPixel = 32;
	window = sfRenderWindow_create(video_mode,
					"My Window",
					sfResize | sfClose,
					NULL);
	sfRenderWindow_setFramerateLimit(window, 60);
	return (window);
}
