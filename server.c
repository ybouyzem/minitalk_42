/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:34:01 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/03/21 07:51:06 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handle_signal(int signal)
{
    //(void)*uap
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i = i | (1 << bit);//00001010 << 00010100
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
}

// void ft_handle_signal(int signo) {
//     static int received_char = 0;
//     static int bit_position = 0;
//     char tmp;
//     if (signo == SIGUSR1) {

//         received_char |= (1 << bit_position);
//     }
//     bit_position++;
//     tmp = bit_position + '0';
//     write(1, &tmp, 1);
//     if (bit_position == 8) {
//         write(1, &received_char, 1); // Write the received character to stdout
//         received_char = 0; // Reset received_char for the next character
//         bit_position = 0; // Reset bit_position for the next character
//     }
// }

int main(void)
{
    int pid;

    pid = getpid();
    write(1, "PID -> \n", 7);
    ft_putnbr(pid);
    write(1, "\nwait for a message...\n", 24);
    while (1)
    {
        signal(SIGUSR1, ft_handle_signal);
        signal(SIGUSR2, ft_handle_signal);
        pause();
    }
    return (0);
}

