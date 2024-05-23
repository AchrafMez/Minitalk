/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:32:27 by amezioun          #+#    #+#             */
/*   Updated: 2024/05/23 18:49:38 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putnbr(long n)
{
	char	*str;
	int		count;

	str = "0123456789";
	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	count += write(1, &str[n % 10], 1);
	return (count);
}

void	trait(int signal, siginfo_t *info, void *nl)
{
	static char	res = 0;
	static int	bit = 0;
	static int	pid = 0;

	nl = NULL;
	if (info->si_pid != pid)
	{
		res = 0;
		bit = 0;
	}
	if (signal == SIGUSR1)
		res = res | (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &res, 1);
		bit = 0;
		res = 0;
	}
	pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	act;

	ft_putnbr(getpid());
	ft_putchar('\n');
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &trait;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
