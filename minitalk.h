/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 00:06:35 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/04/03 14:51:54 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h> 
# include <stdlib.h>

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_putnbr(int n);
void	check_parssing(char *str);

#endif
