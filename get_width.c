#include "main.h"
/**
 * handle_width - a function to handle width specifiers
 * @vi: arguments
 * @y: pointer to be used
 * Return: characters
 */

int handle_width(va_list vi, flags_x *y)
{
	unsigned int num = va_arg(vi, unsigned int);
	char str[32];
	int count = 0;
	int str_length;
	unsigned int w;

	str_length = strlen(str);

	if (y->width > str_length)
	{
		num = y->width - str_length;

		if (y->hash == 1 && str[0] != '0')
		{
		count += _puts("0x");
		}

	for (w = 0; w < num; w++)
	{
		_putchar(' ');
		count++;
	}
	}

	if (y->hash == 1 && str[0] != '0')
	{
	count += _puts("0x");
	}

	count += _puts(str);

	return (count);
}
