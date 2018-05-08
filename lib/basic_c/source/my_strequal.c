/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** 1 function
*/

#include "basic_c.h"

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

	if (!s1 && !s2)
		return true;
	else if (!s1 ^ !s2)
		return false;
	while (s1[i] != '\0' || s2[i] != '\0') {
		if (s1[i] != s2[i])
			return false;
		i++;
	}
	if ((s1[i] == '\0') ^ (s2[i] == '\0'))
		return false;
	return true;
}

/*
** my_strequal_from_a2b =
** Check that the first string from a to b is the same as the second
** from 0 to (b - a)
** [i]b can be bigger than the first string[i]
**
** @param	s1	String one
** @param	s2	String two
** @param	a	Id of the char from which the s1 comp start
** @param	b	Id of the char from which the s1 comp end
** @return	true (1) if s1 and s2 are the same
** 		false (0) if it's not the case
** 		-1 if params aren't usable
*/
int my_strequal_from_a2b(char const *s1, char const *s2, size_t a, size_t b)
{
	size_t i = 0;
	size_t s1_len = my_strlen(s1);;

	if (!s1 && !s2)
		return true;
	if (!s1 ^ !s2)
		return false;
	if (a > b || a >= s1_len || b >= s1_len)
		return my_int_error("Error: Invalid a or Invalid b!\n");
	while ((s1[a] || s2[i]) && a <= b) {
		if (s1[a] != s2[i])
			return false;
		i++;
		a++;
	}
	if (s2[i])
		return false;
	return true;
}
