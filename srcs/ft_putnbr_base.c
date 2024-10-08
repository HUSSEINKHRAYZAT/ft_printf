/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 10:39:23 by hkhrayza          #+#    #+#             */
/*   Updated: 2024/06/23 11:54:07 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	ft_check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < 32 || base[i] > 126)
			return (0);
		z = i + 1;
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int	size_base;
	int	nbr_final[100];
	int	i;
	int	count;

	size_base = 0;
	i = 0;
	count = 0;
	if (ft_check_base(base))
	{
		while (base[size_base])
			size_base++;
		if (nbr == 0)
			return (ft_print_char(base[0]));
		while (nbr)
		{
			nbr_final[i++] = nbr % size_base;
			nbr = nbr / size_base;
		}
		while (i--)
			count += ft_print_char(base[nbr_final[i]]);
	}
	return (count);
}
