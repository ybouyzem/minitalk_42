/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 00:06:35 by ybouyzem          #+#    #+#             */
/*   Updated: 2024/03/09 05:41:16 by ybouyzem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
#include "signal.h"

int     ft_isdigit(int c);
int     ft_atoi(const char *str);
void    ft_putnbr(int n);
void	check_parssing(char *str);
