/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:09:20 by amezioun          #+#    #+#             */
/*   Updated: 2024/05/23 18:01:55 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

int		ft_atoi(char *str);
void	send_char_as_signals(int pid, char c);
void	ft_putchar(char c);
int		ft_putnbr(long n);
void	trait(int signal, siginfo_t *info, void *nl);
void	msgback(int vid);

#endif