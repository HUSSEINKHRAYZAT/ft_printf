/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:33:13 by hkhrayza          #+#    #+#             */
/*   Updated: 2024/06/23 12:02:47 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	ft_unsigned_len(unsigned int number)
{
	int	len;

	len = 0;
	if (number == 0)
	{
		return (1);
	}
	while (number != 0)
	{
		number /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr_fd_unsigned(unsigned int n, int fd)
{
	char	c;

	if (n / 10)
	{
		ft_putnbr_fd_unsigned(n / 10, fd);
	}
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

int	printunint(unsigned int number)
{
	ft_putnbr_fd_unsigned(number, 1);
	return (ft_unsigned_len(number));
}
