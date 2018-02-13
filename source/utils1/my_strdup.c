/*
** EPITECH PROJECT, 2017
** [N/A]
** File description:
**
** my_strdup =
** My main function, that's all
**
** @param	str	String to duplicate
** @return	{Copy} of {str} if everything is working OR NULL
*/
#include "utils1.h"

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
