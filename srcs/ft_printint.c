/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:20:08 by hkhrayza          #+#    #+#             */
/*   Updated: 2024/06/23 12:02:31 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	ft_number_len(int number)
{
	int	len;

	len = 0;
	if (number <= 0)
		len++;
	while (number != 0)
	{
		number /= 10;
		len++;
	}
	return (len);
}

int	printint(int number)
{
	ft_putnbr_fd(number, 1);
	return (ft_number_len(number));
}
