/*
** EPITECH PROJECT, 2017
** my_str_to_word_array
** File description:
** take a string as parameter and return an array
*/

#include <stdlib.h>
#include <string.h>

char **str_to_word_array(char const *str, char s)
{
	char **array;
	int nb_word = 0;
	int len_str = strlen(str);
	int j = 0;
	int i = 0;

	for (; i <= len_str; i++)
		if (str[i] == s || str[i] == '\0')
			nb_word++;
	array = malloc(sizeof(char *) * (nb_word + 1));
	for (i = 0; i < nb_word; i++, str++) {
		for (j = 0; str[j] != s && str[j] != '\0'; j++);
		array[i] = malloc(sizeof(char) * (j + 1));
		for (j = 0; *str != s && *str != '\0';	str++, j++)
			array[i][j] = *str;
		array[i][j] = '\0';
	}
	array[i] = NULL;
	return (array);
}
