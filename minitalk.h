#ifndef MINITALK_H
#define MINITALK_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
int	ft_atoi(char *str);
void send_char_as_signals(int pid, char c);
int ft_putchar(char c);
int	ft_putnbr(long n);
void trait(int signal, siginfo_t *info, void *nl);

#endif