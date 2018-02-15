/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** 1 function
*/
#include <stdbool.h>

/*
** my_strequal =
** Check that the strings given as parameters are the same
**
** @param	s1	String one
** @param	s2	String two
** @return	true (1) if s1 and s2 are the same OR
** 		false (0) if it's not the case
*/
int my_strequal(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] != '\0' || s2[i] != '\0') {
		if (!(s1[i] == s2[i]))
			return (false);
		++i;
	}
	if ((s1[i] == '\0') ^ (s2[i] == '\0'))
		return (false);
	return (true);
}
