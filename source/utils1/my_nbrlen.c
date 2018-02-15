/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** 2 functions
*/

/*
** my_nbrlen =
** Get the length of an int (count the minus if there is one)
**
** @param	nbr	Number to get the length
** @return	The length of the {nbr}
*/
unsigned int my_nbrlen(int nbr)
{
	unsigned int nbr_len = 0;

	if (nbr == 0)
		return (1);
	if (nbr < 0)
		++nbr_len;
	while (nbr != 0) {
		nbr /= 10;
		++nbr_len;
	}
	return (nbr_len);
}

/*
** my_nb_digits =
** Get the lenghth of an int without counting the minus if there is one
**
** @param	nbr	Number to get the length
** @return	The length of the {nbr}
*/
unsigned int my_nb_digits(int nbr)
{
	unsigned int nbr_len = 0;

	if (nbr == 0)
		return (1);
	while (nbr != 0) {
		nbr /= 10;
		++nbr_len;
	}
	return (nbr_len);
}
