/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:10:02 by altikka           #+#    #+#             */
/*   Updated: 2021/12/22 14:16:23 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n <= 2147483647 || n > -2147483648)
	{
		if (n < 0)
		{
			if (n == -2147483648)
			{
				ft_putchar('-');
				ft_putchar('2');
				ft_putnbr(147483648);
			}
			else
			{
				ft_putchar('-');
				ft_putnbr(-n);
			}
		}
		else if (n >= 10)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
		else
			ft_putchar((char )(n + '0'));
	}
}
