/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** 2 functions
*/

#include "basic_c.h"

/*
** my_nbrlen =
** Get the length of an int (count the minus if there is one)
**
** @param	nbr		Number to get the length
** @param	count_minus	Count the '-' if there is one ?
** 				YES(1) or NO(0)
** @return	The length of the {nbr}
*/
unsigned int my_nbrlen(int nbr, int count_minus)
{
	unsigned int nbr_len = 0;

	if (nbr == 0)
		return (1);
	if (nbr < 0 && count_minus == YES)
		nbr_len++;
	while (nbr != 0) {
		nbr /= 10;
		nbr_len++;
	}
	return nbr_len;
}
