/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 13:56:41 by ccorazza          #+#    #+#             */
/*   Updated: 2014/02/12 05:28:38 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_decrypt(int bin)
{
	static char	c;
	static int	i;
	char		*str;

	c += (bin << i++);
	if (i > 7)
	{
		str = ft_line(c);
		if (c == '\0')
		{
			write(1, str, ft_strlen(str));
			write(1, "\n", 1);
		}
		c = 0;
		i = 0;
	}
}

void	sig(int sign)
{
	if (sign == SIGUSR1)
		ft_decrypt(1);
	if (sign == SIGUSR2)
		ft_decrypt(0);
}

void	ft_server_error(void)
{
	usleep(200);
	if ((signal(SIGUSR1, sig) == SIG_ERR) || (signal(SIGUSR2, sig) == SIG_ERR))
	{
		ft_putstr("Something went wrong\n");
		exit(0);
	}
}

int		print_serv(void)
{
	ft_putstr("---- [Server initialization] ----");
	loading();
	ft_putstr("---- [Loading the PID] ----");
	loading();
	ft_putchar('\n');
	ft_putstr("SERVEUR [ON] - PID : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	return (0);
}

int		main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_putstr("Just launch the server... without any arguments.\n");
		exit(0);
	}
	ft_server_error();
	print_serv();
	while (42)
		pause();
}
