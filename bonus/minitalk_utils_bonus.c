/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:46:28 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/04/03 14:50:17 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_putnbr(int n)
{
	long	nb;
	char	tmp;

	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb <= 9)
	{
		tmp = nb + '0';
		write(1, &tmp, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

static int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
	{
		return (1);
	}
	return (0);
}

static int	ft_getdigit(const char *str, int *i, int *sign)
{
	long int	r;
	long int	tmp;

	tmp = 0;
	r = 0;
	while (ft_isdigit(str[*i]) && str[*i])
	{
		r = (str[*i] - 48) + tmp * 10;
		if (tmp > r && *sign == 1)
			return (-1);
		if (tmp > r && *sign == -1)
			return (0);
		*i = *i + 1;
		tmp = r;
	}
	return (r * *sign);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	r;
	long int	tmp;

	tmp = 0;
	r = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]) && str[i])
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i])
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	return (ft_getdigit(str, &i, &sign));
}
