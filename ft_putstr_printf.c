/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:40:57 by lbento            #+#    #+#             */
/*   Updated: 2025/08/05 20:23:31 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putstr_printf(char *str);

int	ft_putstr_printf(char *str)
{
	int	i;

	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}
