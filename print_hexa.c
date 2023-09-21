#include "main.h"

/**
 * print_hexa - This fuction prints a number in
 * hexadecimal base in lowercase
 * @y: pointer being used
 * @vi: va_list argument
 * Authors: Kingsley Dade and Gabriel Akinshola
 * Return: number of characters being printed
 */

int print_hexa(va_list vi, flags_x *y)
{
	unsigned int num = va_arg(vi, unsigned int);
	char *str = convert(num, 16, 1);
	int count = 0;

	if (y->hash == 1 && str[0] != '0')
		count += _puts("0x");
	count += _puts(str);

	return (count);
}

/**
 * print_hexa_big - This function prints a number
 * in hexadecimal base in uppercase
 * @y: pointer being used
 * @vi: va_list arguments
 *
 * Return: number of characters
 */

int print_hexa_big(va_list vi, flags_x *y)
{
	int count = 0;
	unsigned int num = va_arg(vi, unsigned int);
	char *str = convert(num, 16, 0);

	if (y->hash == 1 && str[0] != '0')
		count += _puts("0X");
	count += _puts(str);

	return (count);
}

/**
 * print_binary - This function prints numbers in base 2
 * @y: pointer being used
 * @vi: va_list arguments
 *
 * Return: number of characters being printed
 */

int print_binary(va_list vi, flags_x *y)
{
	unsigned int num = va_arg(vi, unsigned int);
	char *str = convert(num, 2, 0);

	(void)y;

	return (_puts(str));
}

/**
 * print_octal - This function that prints numbers in base 8
 * @y: pointer being used
 * @vi: va_list arguments
 *
 * Return: number of characters being printed
 */

int print_octal(va_list vi, flags_x *y)
{
	unsigned int num = va_arg(vi, unsigned int);
	char *str = convert(num, 8, 0);
	int count = 0;

	if (y->hash == 1 && str[0] != '0')
		count += _putchar('0');
	count += _puts(str);

	return (count);
}
