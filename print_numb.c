#include "main.h"

/**
 * print_int - This function prints an integer
 * @vi: va_list of arguments
 * @y: pointer being used
 * By Kingsley Dade and Gabriel Akinshola
 * Return: number of characters printed
 */

int print_int(va_list vi, flags_x *y)
{
	int n = va_arg(vi, int);
	int res = count_digit(n);

	if (y->space == 1 && y->plus == 0 && n >= 0)
		res += _putchar(' ');
	if (y->plus == 1 && n >= 0)
		res += _putchar('+');
	if (n <= 0)
		res++;
	print_number(n);
	return (res);
}

/**
 * print_unsigned - This is a function that prints an unsigned integer
 * @vi: va_list of arguments
 * @y: pointer being used
 * Return: number of characters being printed
 */

int print_unsigned(va_list vi, flags_x *y)
{
	unsigned int u = va_arg(vi, unsigned int);
	char *str = convert(u, 10, 0);

	(void)y;
	return (_puts(str));
}

/**
 * print_number - This is a function that looks through
 * the loop and integer and prints all its digits
 * @n: integer being printed
 */

void print_number(int n)
{
	unsigned int n1;

	if (n < 0)
	{
		_putchar('-');
		n1 = -n;
	}
	else
		n1 = n;

	if (n1 / 10)
		print_number(n1 / 10);
	_putchar((n1 % 10) + '0');
}

/**
 * count_digit - a function that returns the number
 * of digits in an integer
 * @y: integer that evaluates
 * Return: number of digits printed
 */

int count_digit(int y)
{
	unsigned int d = 0;
	unsigned int u;

	if (y < 0)
		u = y * -1;
	else
		u = y;
	while (u != 0)
	{
		u /= 10;
		d++;
	}
	return (d);
}
