/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:58:52 by moelalj           #+#    #+#             */
/*   Updated: 2023/02/11 18:01:00 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	*dectobinary(int nb)
{
	int	i;
	int	j;
	int	count;
	int	*var;

	count = 0;
	var = malloc(8 * sizeof(int));
	i = 7;
	while (i >= 0)
	{
		j = nb >> i;
		i--;
		if (j & 1)
			var[count] = 1;
		else
			var[count] = 0;
		count++;
	}
	return (var);
}

void	switch_bin(char **argv)
{
	int	pid;
	int	i;
	int	*dbin;
	int	dbin_counter;

	pid = ft_atoi(argv[1]);
	i = 0;
	dbin_counter = 0;
	while (argv[2][i] != '\0')
	{
		dbin = dectobinary(argv[2][i]);
		while (dbin_counter <= 7)
		{
			if (dbin[dbin_counter] == 0)
				kill(pid, SIGUSR1);
			else if (dbin[dbin_counter] == 1)
				kill(pid, SIGUSR2);
			usleep(500);
			dbin_counter++;
		}
		dbin_counter = 0;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		switch_bin(argv);
	else
		ft_putstr_fd("<^Eroor^>", 1);
	return (0);
}
