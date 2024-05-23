/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:18:03 by amezioun          #+#    #+#             */
/*   Updated: 2024/05/23 19:38:19 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_atoi(char *str)
{
	int	number;
	int	countminus;

	countminus = 0;
	number = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*(str + 1) == '-' || *(str + 1) == '+')
			return (0);
		if (*str == '-')
			countminus = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	if (countminus == 1)
		return (-number);
	return (number);
}

void	msgback(int vid)
{
	(void)vid;
	write(1, "All the text have been written", 30);
}

int	send_char_as_signals(int pid, char c)
{
	int	bit;
	int error = 0;

	bit = 0;
	while (bit < 8 && !error)
	{
		if ((c & (1 << bit)) != 0)
			error = kill(pid, SIGUSR1);
		else
			error = kill(pid, SIGUSR2);
		usleep(300);
		bit++;
	}
	return error;
}

int	main(int ac, char **av)
{
	int		j;
	char	*text;
	int		pid;

	if (ac != 3)
		write(1, "<./client_bonus>  <PID>  <MESSAGE>\n", 35);
	else
	{
		j = 0;
		text = av[2];
		pid = ft_atoi(av[1]);
		while (text[j])
		{
			if (send_char_as_signals(pid, text[j]) == -1)
			{
				write(1, "error\n", 6);
				return (1);
			}
			j++;
			if (text[j] == '\0')
			{
				send_char_as_signals(pid, '\0');
			}
			signal(SIGUSR2, msgback);
		}
		send_char_as_signals(pid, '\n');
	}
	return (0);
}
