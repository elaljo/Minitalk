/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:26:04 by moelalj           #+#    #+#             */
/*   Updated: 2023/02/11 22:26:05 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

int		ft_power(int pw);
int		bintodec(int *arr);
void	handler(int signal, siginfo_t *info, void *t);
int		*dectobinary(int nb);
void	switch_bin(char **argv);
size_t	ft_strlen(const char *s);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);

#endif
