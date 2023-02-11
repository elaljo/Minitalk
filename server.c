/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:26:24 by moelalj           #+#    #+#             */
/*   Updated: 2023/02/11 18:08:33 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_power(int pw)
{
	int	res;
	int	nb;

	nb = 2;
	res = 1;
	if (pw == 0)
		return (1);
	while (pw >= 1)
	{
		res = res * nb;
		pw--;
	}
	return (res);
}

int	bintodec(int *arr)
{
	int	pw;
	int	j;
	int	save;

	save = 0;
	pw = 0;
	j = 7;
	while (pw <= 7)
	{
		save += arr[j] * ft_power(pw);
		pw++;
		j--;
	}
	return (save);
}

void	handler_helper(int signal)
{
	static int	*only_bin;
	static int	e;

	if (!e)
	{
		e = 0;
		only_bin = malloc(8 * sizeof(int));
	}
	if (signal == SIGUSR1)
	{
		only_bin[e] = 0;
		e++;
	}
	else if (signal == SIGUSR2)
	{
		only_bin[e] = 1;
		e++;
	}
	if (e == 8)
	{
		ft_putchar_fd(bintodec(only_bin), 1);
		free(only_bin);
		e = 0;
	}
}

void	handler(int signal, siginfo_t *info, void *t)
{
	static int	counter_e;
	static int	pid;

	(void)t;
	if (info->si_pid != pid)
	counter_e = 0;
	handler_helper(signal);
	pid = info->si_pid;
}

int	main(void)
{
	int					pid;
	struct sigaction	action;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	action.sa_sigaction = handler;
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
