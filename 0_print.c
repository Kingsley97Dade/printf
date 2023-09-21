#include "main.h"

/**
 * _printf - printf function
 * @format: format string specifier being used
 * Return: The number of characters in the function
 * Authors: Kingsley Dade and Gabriel Akinshola
 */

int _printf(const char *format, ...)
{
	int (*pfunx)(va_list, flags_x *);
	const char *p;
	va_list arguments;
	flags_x flags = {0, 0, 0, 0};

	register int count = 0;

	va_start(arguments, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*p, &flags))
				p++;
			pfunx = get_print(*p);
			count += (pfunx)
				? pfunx(arguments, &flags)
				: _printf("%%%c", *p);
		}
		else
		{
			count += _putchar(*p);
		}
	}
	_putchar(-1);
	va_end(arguments);
	return (count);
}
