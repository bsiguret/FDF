/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 04:06:41 by bsiguret          #+#    #+#             */
/*   Updated: 2017/11/09 05:55:13 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	aft_intlen(int nb)
{
	int	len;

	len = 0;
	if (nb < 0)
		++len;
	while (nb)
	{
		++len;
		nb = nb / 10;
	}
	return (len);
}

static char	*aft_intmax(void)
{
	char	*str;

	str = ft_strnew(aft_intlen(-2147483648) + 1);
	ft_strcpy(str, "-2147483648");
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == -2147483648)
		return (aft_intmax());
	str = ft_strnew(aft_intlen(n + 1));
	i = aft_intlen(n) - 1;
	if (str)
	{
		if (n < 0)
		{
			str[0] = '-';
			n = -n;
		}
		if (n == 0)
			*str = '0';
		while (n > 0)
		{
			str[i] = '0' + (n % 10);
			n = n / 10;
			--i;
		}
	}
	return (str);
}
