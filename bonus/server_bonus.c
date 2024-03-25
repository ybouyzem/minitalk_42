/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:50:11 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/03/25 14:55:08 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_handle_signal(int signo, siginfo_t *info, void *s)
{
	static int	received_char;
	static int	bit_position ;
	static int	pid;

	s = NULL;
	if (!pid)
		pid = info->si_pid;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		received_char = 0;
		bit_position = 0;
	}
	if (signo == SIGUSR1)
		received_char |= (1 << bit_position);
	bit_position++;
	if (bit_position == 8)
	{
		if (received_char != '\0')
			write(1, &received_char, 1);
		else
			kill(info->si_pid, SIGUSR1);
		received_char = 0;
		bit_position = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = ft_handle_signal;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	write(1, "PID -> \n", 7);
	ft_putnbr(pid);
	write(1, "\nwait for a message...\n", 24);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
