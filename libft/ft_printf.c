/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:37:54 by fesper-s          #+#    #+#             */
/*   Updated: 2022/07/05 09:56:21 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_selection(va_list ap, const char *format, int i)
{
	int	len;

	len = 0;
	if (format[i] == 'c')
		len += ft_printf_c(va_arg(ap, int));
	else if (format[i] == 's')
		len += ft_printf_s(va_arg(ap, char *));
	else if (format[i] == 'p')
		len += ft_printf_s("0x") + ft_printf_x(va_arg(ap, unsigned long));
	else if (format[i] == 'd')
		len += ft_printf_d(va_arg(ap, int));
	else if (format[i] == 'i')
		len += ft_printf_i(va_arg(ap, int));
	else if (format[i] == 'u')
		len += ft_printf_ud(va_arg(ap, unsigned int));
	else if (format[i] == 'x')
		len += ft_printf_x(va_arg(ap, unsigned int));
	else if (format[i] == 'X')
		len += ft_printf_xu(va_arg(ap, unsigned int));
	else if (format[i] == '%')
		len += ft_printf_c('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	ap;

	va_start(ap, format);
	len = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			len += ft_printf_selection(ap, format, i + 1);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			len++;
		}
		i++;
	}
	return (len);
}
