/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:49:08 by mle-boud          #+#    #+#             */
/*   Updated: 2022/11/29 16:18:59 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_conversion(va_list arg, char format, int fd)
{
	if (format == 'c')
		return (ft_putchar_fd(va_arg(arg, int), fd));
	if (format == 's')
		return (ft_putstr_dprintf(va_arg(arg, char *), fd));
	if (format == 'p')
	{
		write(1, "0x", 2);
		return (ft_pb_dprtf(va_arg(arg, void *), "0123456789abcdef", fd) + 2);
	}
	if (format == 'd' || format == 'i')
		return (ft_putnbr_dprintf(va_arg(arg, int), fd));
	if (format == 'u')
		return (ft_putnbr_unsigned_dprintf(va_arg(arg, unsigned int), fd));
	if (format == 'x')
		return (ft_b_dprtf(va_arg(arg, unsigned int), "0123456789abcdef", fd));
	if (format == 'X')
		return (ft_b_dprtf(va_arg(arg, unsigned int), "0123456789ABCDEF", fd));
	else
		return (write(1, &format, 1));
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	arg;
	int		ret;
	int		i;

	if (!format)
		return (0);
	if (write(fd, NULL, 0) < 0)
		return (-1);
	va_start(arg, format);
	ret = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%' && !format[i + 1])
			break ;
		else if (format[i] == '%')
			ret += ft_conversion(arg, format[++i], fd);
		else
			ret += write(fd, &format[i], 1);
	}
	va_end(arg);
	return (ret);
}
