/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 10:15:47 by hkhrayza          #+#    #+#             */
/*   Updated: 2024/06/23 12:15:30 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const	char *tp, ...);
int	printint(int number);
int	printunint(unsigned int number);
int	printstring(char const *str);
int	printpointer(void *p);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	ft_print_char(char c);

#endif
