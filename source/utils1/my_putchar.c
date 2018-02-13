/*
** EPITECH PROJECT, 2017
** [N/A]
** File description:
**
** my_putchar =
** Displays the character given as a parameter
**
** @param	c	Character to print
** @return	N/A
*/
#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}
