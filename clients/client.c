/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 13:45:16 by ccorazza          #+#    #+#             */
/*   Updated: 2014/02/09 14:21:56 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		ft_encrypt(int serv_pid, char data)
{
	char	c;

	c = 0;
	while (c < 8)
	{
		usleep(200);
		if (((data >> c) & 1) == 1)
		{
			if (kill(serv_pid, SIGUSR1) == -1)
			{
				ft_putstr("Error. Perhaps bad PID ?\n");
				exit(0);
			}
		}
		else
		{
			if (kill(serv_pid, SIGUSR2) == -1)
			{
				ft_putstr("Error. Perhaps bad PID ?\n");
				exit(0);
			}
		}
		c++;
	}
	return (0);
}

int		ft_client(char **argv)
{
	int		i;
	char	*data;
	int		serv_pid;

	data = argv[2];
	serv_pid = ft_atoi(argv[1]);
	i = 0;
	while (data[i] != '\0')
	{
		ft_encrypt(serv_pid, data[i]);
		i++;
	}
	ft_encrypt(serv_pid, data[i]);
	return (0);
}

void	sig(int sig)
{
	sig = sig;
}

int		main(int argc, char **argv)
{
	if (argc == 3)
	{
		if ((signal(SIGUSR1, sig) == SIG_ERR) ||
				(signal(SIGUSR2, sig) == SIG_ERR))
		{
			ft_putstr("Error - Signal.\n");
			exit(1);
		}
		ft_client(argv);
	}
	else
		ft_putstr("Usage : [./CLIENT] [PID_OF_SERVER] [MESSAGE]\n");
	return (0);
}
