/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:51:44 by moelalj           #+#    #+#             */
/*   Updated: 2023/02/13 15:43:25 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_power(int pw)
{
	int	res;

	res = 1;
	if (pw == 0)
		return (1);
	while (pw >= 1)
	{
		res = res * 2;
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
	j = 7;
	pw = 0;
	while (pw <= 7)
	{
		save += arr[j] * ft_power(pw);
		pw++;
		j--;
	}
	return (save);
}

void	handler(int signal, siginfo_t *info, void *t)
{
	static int	*only_bin;
	static int	pid;
	static int	c;

	(void)t;
	if (info->si_pid != pid)
		c = 0;
	pid = info->si_pid;
	if (!c)
		only_bin = malloc(8 * sizeof(int));
	if (signal == SIGUSR1)
		only_bin[c++] = 0;
	else if (signal == SIGUSR2)
		only_bin[c++] = 1;
	if (c == 8)
	{
		ft_putchar_fd(bintodec(only_bin), 1);
		free(only_bin);
		c = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause ();
	return (0);
}
