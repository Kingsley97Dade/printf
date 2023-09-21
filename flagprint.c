#include "main.h"

/**
 * get_flag - A function that turns on flags if
 *            _printf finds a flag modifier in the format string.
 * @s:       Character specifier to be used.
 * @y:       Pointer to the struct flags to be used.
 *
 * This function checks the input character 's' and updates the
 * corresponding flag in the 'flags_x' structure 'y' if a flag modifier
 * is found.
 *
 * Return:   1 if a flag modifier was found and processed, 0 otherwise.
 *
 * Authors:  Kingsley Dade and Gabriel Akinshola
 */

int get_flag(char s, flags_x *y)
{
	int w = 0;

	switch (s)
	{
		case '+':
			y->plus = 1;
			w = 1;
			break;
		case ' ':
			y->space = 1;
			w = 1;
			break;
		case '#':
			y->hash = 1;
			w = 1;
			break;
	}
	return (w);
}
