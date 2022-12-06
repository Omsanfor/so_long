/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omsanfor <omsanfor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:19:58 by omsanfor          #+#    #+#             */
/*   Updated: 2022/04/05 13:19:59 by omsanfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_plus_int(int n, int len)
{
	char	*number;

	number = (char *)malloc(sizeof(char) * (len + 1));
	if (number)
	{
		number[len] = '\0';
		len--;
		while (len >= 0)
		{
			number[len] = ((n % 10) + '0');
			n = n / 10;
			len--;
		}
		return (number);
	}
	return (NULL);
}

static char	*ft_minus_int(int n, int len)
{
	char	*number;

	number = (char *)malloc(sizeof(*number) * (len + 2));
	if (number)
	{
		number[0] = '-';
		len++;
		number[len] = '\0';
		len--;
		while (len > 0)
		{
			number[len] = ((n % 10) + '0');
			n = n / 10;
			len--;
		}
		return (number);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	int		len;
	int		num;

	len = 0;
	num = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	if (num >= 0)
		return (ft_plus_int(num, len));
	return (ft_minus_int((num * -1), len));
}
