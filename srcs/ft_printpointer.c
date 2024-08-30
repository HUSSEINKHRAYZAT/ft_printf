/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:36:36 by hkhrayza          #+#    #+#             */
/*   Updated: 2024/06/23 12:16:26 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	ft_print_hex(unsigned long n)
{
	int	count;

	count = 0;
	if (n / 16 > 0)
		count += ft_print_hex(n / 16);
	n = n % 16;
	if (n < 10)
		count += ft_print_char(n + '0');
	else
		count += ft_print_char(n - 10 + 'a');
	return (count);
}

int	printpointer(void *p)
{
	unsigned long	address;
	int				count;

	address = (unsigned long)p;
	if (p == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (ft_strlen("(nil)"));
	}
	count = 0;
	count += ft_print_char('0');
	count += ft_print_char('x');
	count += ft_print_hex(address);
	return (count);
}
