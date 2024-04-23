/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:18:03 by amezioun          #+#    #+#             */
/*   Updated: 2024/04/23 19:38:23 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

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
void msgback(int vid)
{
	(void)vid;
	write(1, "All the text have been written", 30);
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
		usleep(100);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int		j;
	char	*text;
	int		pid;

	if (ac != 3)
	{
		printf("./a.out pid text");
	}
	else
	{
		j = 0;
		text = av[2];
		pid = ft_atoi(av[1]);
		while (text[j])
		{
			send_char_as_signals(pid, text[j]);
			j++;
			if(text[j] == '\0')
			{
				send_char_as_signals(pid, '\0');
			}
			signal(SIGUSR2, msgback);
		}
		send_char_as_signals(pid, '\n');
	}
	return (0);
}
