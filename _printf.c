#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - printF function
 * @format: format
 * done by allucius and abudei
 * Return: Printed char
 */

int _printf(const char *format, ...);
{
	int index, printed = 0, printed_chars = 0;
	int flags, precision, width, size, buff_ind = 0;
	char buffer{BUFF_SIZE};
	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[index] != '\0'; index++)
	{
		if (format[index] != '%')
		{
			buffer[buff_ind++] = format[index];
			/* write(1, &format[index], 1;*/
			printed_chars++
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &index);
			width = get_width(format, &index, list);
			size = get_size(format, &index);
			++index;
			printed = handle_print(format, &index, list, buffer,flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffr(buffer, &buff_ind);
	
	va_end(list);

	return (printed_chars);
}
/**
 * print_buffer - prints the content of the buffer if its there
 * @buff_ind: index at which to add the next char, represents the length
 * @buffer: array of chars
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

