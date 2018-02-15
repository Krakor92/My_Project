/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** 1 function
*/

/*
** my_unbrlen =
** Get the length of an unsigned int (count the minus if there is one)
**
** @param	unbr	Unsigned number to get the length
** @return	The length of the {unbr}
*/
unsigned int my_unbrlen(unsigned int unbr)
{
	int unbr_len = 0;

	if (unbr == 0)
		return (1);
	while (unbr != 0) {
		unbr /= 10;
		++unbr_len;
	}
	return (unbr_len);
}
