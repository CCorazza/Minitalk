/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 13:41:39 by ccorazza          #+#    #+#             */
/*   Updated: 2014/02/12 05:49:39 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include "../libft/libft.h"

# define MESSAGE_SIZE 10000

/* LOADING */
void	loading(void);
char	*ft_realloc(char *str, int size);
char	*ft_line(char c);

/* SERVER */
void	ft_decrypt(int bin);
void	sig(int sign);
int		print_serv(void);
void	ft_server_error(void);

#endif /* !SERVER_H */
