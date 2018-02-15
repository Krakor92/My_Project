/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** 1 function
*/
#include "utils1.h"

/*
** my_strdup =
** Malloc a string with a size equal as the string given as parameter,
** then copy the content of it in the allocated one
**
** @param	str	String to duplicate
** @return	Copy of {str} if the allocation worked OR NULL
*/
char *my_strdup(char const *str)
{
	char *copy = NULL;
	int str_len = my_strlen(str);
	int i = 0;

	copy = malloc(sizeof(char) * str_len + 1);
	if (copy == NULL)
		return(my_ptr_error(INVALID_MALLOC));
	while (*str != '\0') {
		copy[i] = *str;
		++i;
		++str;
	}
	copy[i] = '\0';
	return (copy);
}
