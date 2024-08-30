/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 09:40:12 by hkhrayza          #+#    #+#             */
/*   Updated: 2024/06/23 12:01:54 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	checktype(va_list args, char tp)
{
	if (tp == '%')
		return (write(1, "%", 1));
	else if (tp == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	else if (tp == 's')
		return (printstring(va_arg(args, char *)));
	else if (tp == 'p')
		return (printpointer(va_arg(args, void *)));
	else if (tp == 'd' || tp == 'i')
		return (printint(va_arg(args, int)));
	else if (tp == 'u')
		return (printunint(va_arg(args, unsigned int)));
	else if (tp == 'x')
		return (ft_putnbr_base(va_arg(args, ssize_t), "0123456789abcdef"));
	else if (tp == 'X')
		return (ft_putnbr_base(va_arg(args, ssize_t), "0123456789ABCDEF"));
	return (0);
}

int	ft_printf(const char *tp, ...)
{
	int			i;
	int			count;
	va_list		args;

	if (!tp)
		return (0);
	i = 0;
	count = 0;
	va_start (args, tp);
	while (tp[i] != '\0')
	{
		if (tp[i] != '%')
		{
			write(1, &tp[i], 1);
			count++;
		}
		else
		{
			count += checktype(args, tp[i + 1]);
			i++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
