/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:32:20 by amezioun          #+#    #+#             */
/*   Updated: 2024/05/23 18:51:15 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	send_char_as_signals(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(300);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int		j;
	char	*message;
	int		pid;

	if (ac != 3)
		write(1, "<./client>  <PID>  <MESSAGE>\n", 29);
	else
	{
		j = 0;
		message = av[2];
		pid = ft_atoi(av[1]);
		while (message[j] != '\0')
		{
			send_char_as_signals(pid, message[j]);
			j++;
			usleep(300);
		}
		send_char_as_signals(pid, '\n');
	}
	return (0);
}
