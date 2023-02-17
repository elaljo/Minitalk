/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:51:35 by moelalj           #+#    #+#             */
/*   Updated: 2023/02/13 15:41:49 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	*dectobinary(int nb)
{
	int	j;
	int	i;
	int	count;
	int	*var;

	i = 7;
	count = 0;
	j = 0;
	var = malloc (8 * sizeof(int));
	while (i >= 0)
	{
		j = nb >> i;
		i--;
		if (j & 1)
			var[count++] = 1;
		else
			var[count++] = 0;
	}
	return (var);
}

void	switch_dtob_and_sent(char **argv)
{
	int				pid;
	int				*dbin;
	int				dbin_counter;
	static int		i;

	pid = ft_atoi(argv[1]);
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
		free(dbin);
		dbin_counter = 0;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if ((argc == 3) && (ft_atoi(argv[1]) > 0))
		switch_dtob_and_sent(argv);
	else
		ft_putstr_fd("ATTENTION: <!> Something wrong with the arguments\n", 1);
	return (0);
}
