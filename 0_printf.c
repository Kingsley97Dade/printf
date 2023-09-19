#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: the format string
 * By Gabriel Akinshola and Kingsley Dade.
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (format && *format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				if (str)
				{
					while (*str)
					{
						write(1, str, 1);
						str++;
						count++;
					}
				}
				else
				{
					write(1, "(null)", 6);
					count += 6;
				}
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else
			{
				write(1, "%", 1);
				count++;
			}
		}
		format++;
	}

	va_end(args);

	return (count);
}

