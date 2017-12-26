/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:07:01 by bsiguret          #+#    #+#             */
/*   Updated: 2017/12/15 14:35:41 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_good(char c)
{
	int	nbr;

	if (c >= '0' && c <= '9')
		nbr = c - '0';
	else if (c >= 'a' && c <= 'z')
		nbr = c - 'a' + 10;
	else if (c >= 'A' && c <= 'Z')
		nbr = c - 'A' + 10;
	else
		nbr = -1;
	return (nbr);
}

int				ft_atoi_base(const char *str, int str_base)
{
	int	nbr;
	int	testbase;
	int	neg;

	nbr = 0;
	while ((*str >= 7 && *str <= 13) || *str == ' ')
		str++;
	neg = (*str == '-' ? -1 : 1);
	if (*str == '-' || *str == '+')
		str++;
	testbase = ft_good(*str);
	while (testbase >= 0 && testbase < str_base)
	{
		nbr = nbr * str_base + testbase;
		str++;
		testbase = ft_good(*str);
	}
	return (nbr * neg);
}
