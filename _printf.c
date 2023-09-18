#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string containing directives
 * @...: Additional arguments based on format specifiers
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;

			switch (*format)
			{
				case 'c':
					printed_chars += putchar(va_arg(args, int));
					break;
				case 's':
					{
						char *str = va_arg(args, char *);

						if (str == NULL)
							str = "(null)";
						printed_chars += fputs(str, stdout);
						break;
					}
				case '%':
					printed_chars += putchar('%');
					break;
				default:
					printed_chars += putchar('%');
					printed_chars += putchar(*format);
			}
		}
		else
		{
			printed_chars += putchar(*format);
		}
		format++;
	}

	va_end(args);
	return (printed_chars);
}

