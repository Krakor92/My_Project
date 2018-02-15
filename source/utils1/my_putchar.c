/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** 1 function
*/
#include <unistd.h>

/*
** my_putchar =
** Displays the character given as a parameter on the stdout (fd = 1)
**
** @param	c	Character to print
** @return	N/A
*/
void my_putchar(char c)
{
	write(1, &c, 1);
}
