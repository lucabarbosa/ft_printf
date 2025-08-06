/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:58:10 by lbento            #+#    #+#             */
/*   Updated: 2025/08/05 20:44:29 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putnbr_u(unsigned int nbr);

int	ft_putnbr_u(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr > 9)
	{
		i += ft_putnbr_printf(nbr / 10);
		i++;
	}
	write(1, &"0123456789"[nbr % 10], 1);
	return (i);
}
