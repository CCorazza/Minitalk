/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 13:40:44 by ccorazza          #+#    #+#             */
/*   Updated: 2014/02/09 14:06:31 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include "../libft/libft.h"

int		ft_encrypt(int serv_pid, char data);
int		ft_client(char **argv);
void	sig(int sig);

#endif /* !CLIENT_H */
