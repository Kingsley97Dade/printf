#include "main.h"

/**
 * print_address - This is a function that prints the address
 * of the input in hexadecimal
 * @y: pointer to the struct being used
 * @vi: va_list argument being used
 * By Kingsley Dade and Gabriel Akinshola
 * Return: number of characters being printed
 */

int print_address(va_list vi, flags_x *y)
{
	char *str;
	unsigned long int p = va_arg(vi, unsigned long int);

	register int count = 0;

	(void)y;

	if (!p)
		return (_puts("(nil)"));

	str = convert(p, 16, 1);
	count += _puts("0x");
	count += _puts(str);

	return (count);
}
