#include "main.h"

/**
 * get_print - This is a function that selects
 * the specific appropraite printing function
 * @specifier: The character that holds the specifier
 * being converted
 * Authors: Kingsley Dade and Gabriel Akinshola
 * Return: pointer to the matching printing function
 */

int (*get_print(char specifier))(va_list, flags_x *)
{
	ph func_arr[] = {
		{'c', print_char},
		{'s', print_string},
		{'i', print_int},
		{'d', print_int},
		{'u', print_unsigned},
		{'x', print_hexa},
		{'X', print_hexa_big},
		{'b', print_binary},
		{'o', print_octal},
		{'R', print_rot13},
		{'r', print_rev},
		{'p', print_address},
		{'S', print_bigS},
		{'%', print_percent}
	};
	int num_funcs = 14;
	int w;

	for (w = 0; w < num_funcs; w++)
	{
		if (func_arr[w].c == specifier)
		{
			return (func_arr[w].y);
		}
	}

	return (NULL);
}
