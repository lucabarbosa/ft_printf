/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:41:28 by lbento            #+#    #+#             */
/*   Updated: 2025/08/05 18:13:08 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_printf(const char *format, ...);

static int	ft_convert_args(char func, va_list args);

int	ft_printf(const char *format, ...)
{
	size_t		i;
	va_list		args;
	int			total;

	i = 0;
	total = 0;
	if (!format)
		return (total);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			i++;
			total += ft_convert_args((char) format[i], args);
		}
		else
			total += ft_putchar_printf(format[i]);
		i++;
	}
	va_end(args);
	return (total);
}

static int	ft_convert_args(char func, va_list args)
{
	if (func == '%')
		return (ft_putchar_printf(func));
	else if (func == 'c')
		return (ft_putchar_printf(va_arg(args, int)));
	else if (func == 's')
		return (ft_putstr_printf(va_arg(args, char *)));
	else if (func == 'p')
		return (ft_pointerhex(va_arg(args, void *)));
	else if (func == 'd' || func == 'i')
		return (ft_putnbr_printf(va_arg(args, int)));
	else if (func == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	else if (func == 'x')
		return (1);
	else if (func == 'X')
		return (1);
	else
		return (0);
}
#include <stdio.h>

int	main(void)
{
	char	c;
	int		nbr;
	int		result;
	int		total_printf;
	void	*ptr;

	c = 'c';
	result = ft_printf("Teste ft (%%c) = %c", c);
	printf("\n --\n");
	total_printf = printf("Original (%%c) = %c", c);
	printf("\n --\n");
	printf("Total da ft_printf = %i", result);
	printf("\nTotal da printf (original) = %i", total_printf);
	printf("\n----------------------------------------------------\n");
	result = ft_printf("Teste (%%s) = %s", "teste");
	printf("\n --\n");
	total_printf = printf("Original (%%s) = %s", "teste");
	printf("\n --\n");
	printf("Total da ft_printf = %i", result);
	printf("\nTotal da printf (original) = %i", total_printf);
	printf("\n----------------------------------------------------\n");
	nbr = -42.254;
	result = ft_printf("Teste ft (%%d) = %d", nbr);
	printf("\n --\n");
	total_printf = printf("Original (%%d) = %d", nbr);
	printf("\n --\n");
	printf("Total da ft_printf = %i", result);
	printf("\nTotal da printf (original) = %i", total_printf);
	printf("\n-----------------------------------\n");
	nbr = -42121351.254;
	result = ft_printf("Teste ft (%%i) = %i", nbr);
	printf("\n --\n");
	total_printf = printf("Original (%%i) = %i", nbr);
	printf("\n --\n");
	printf("Total da ft_printf = %i", result);
	printf("\nTotal da printf (original) = %i", total_printf);
	printf("\n-----------------------------------\n");
	nbr = 42;
	result = ft_printf("Teste ft (%%u) = %u", nbr);
	printf("\n --\n");
	total_printf = printf("Original (%%u) = %u", nbr);
	printf("\n --\n");
	printf("Total da ft_printf = %i", result);
	printf("\nTotal da printf (original) = %i", total_printf);
	printf("\n----------------------------------------------------\n");
	ptr = &c;
	result = ft_printf("Teste ft (%%p) = %p", ptr);
	printf("\n --\n");
	total_printf = printf("Original (%%p) = %p", ptr);
	printf("\n --");
	printf("\nTotal da ft_printf = %i", result);
	printf("\nTotal da printf (original) = %i", total_printf);
	printf("\n----------------------------------------------------\n");
}
