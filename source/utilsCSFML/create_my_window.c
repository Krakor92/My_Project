/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Create my window
*/
#include "utilsCSFML.h"

sfRenderWindow *create_my_window(unsigned int width, unsigned int heigth)
{
	sfRenderWindow *window;
	sfVideoMode video_mode;

	video_mode.width = width;
	video_mode.height = heigth;
	video_mode.bitsPerPixel = 32;
	window = sfRenderWindow_create(video_mode,
					"My Hunter Window",
					sfResize | sfClose,
					NULL);
	sfRenderWindow_setFramerateLimit(window, 60);
	return (window);
}
