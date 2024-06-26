/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:44:19 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/04/03 14:55:29 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_sent(int signal)
{
	if (signal == SIGUSR1)
		write(1, "Message sent successfuly!\n", 26);
}

void	ft_error(char *pid)
{
	int	i;

	i = 0;
	write(2, "illegal pid: ", 13);
	while (pid[i])
	{
		write(2, &pid[i], 1);
		i++;
	}
	write(2, "\n", 1);
	exit(1);
}

void	check_parssing(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	else if ((!ft_isdigit(str[i]) || str[i] == '+'))
		ft_error(str);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error(str);
		i++;
	}
}

void	ft_send_char(char *p, char c)
{
	int	i;
	int	pid;

	i = 0;
	pid = ft_atoi(p);
	while (i < 8)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error(p);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error(p);
		}
		usleep(450);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		check_parssing(argv[1]);
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
			ft_error(argv[1]);
		signal(SIGUSR1, ft_sent);
		while (argv[2][i] != 0)
		{
			ft_send_char(argv[1], argv[2][i]);
			i++;
		}
		ft_send_char(argv[1], '\n');
		ft_send_char(argv[1], '\0');
	}
	else
		write(1, "ERROR\n", 6);
	return (0);
}
