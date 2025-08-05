/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:51:08 by lbento            #+#    #+#             */
/*   Updated: 2025/08/05 16:16:39 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putnbr_printf(int nbr);

int	ft_putnbr_printf(int nbr)
{
	int	i;

	if (nbr < -2147483647)
	{
		write(1, "-2147483648", 10);
		return (10);
	}
	else if (nbr < 0)
	{	
		nbr = -nbr;
		write(1, "-", 1);
	}
	i = 1;
	if (nbr > 9)
	{
		ft_putnbr_printf(nbr / 10);
		i++;
	}
	write(1, &"0123456789"[nbr % 10], 1);
	return (i);
}
