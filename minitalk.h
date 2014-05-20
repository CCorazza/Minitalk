/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 13:39:17 by ccorazza          #+#    #+#             */
/*   Updated: 2014/02/09 14:05:23 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

# include "libft/libft.h"

/* SERVER FUNCTIONS */

void	ft_decrypt(int bin);
void	sig(int sign);
void	ft_server_error(void);
int		print_server(void);

/* CLIENT FUNCTIONS */

int		ft_encrypt(int s_pid, char msg);
int		ft_client(char **argv);
void	sig(int sig);

#endif /* !MINITALK_H */
