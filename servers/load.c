/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 13:56:28 by ccorazza          #+#    #+#             */
/*   Updated: 2014/02/12 06:00:07 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void			loading(void)
{
	int			i;

	i = 0;
	ft_putstr("\n");
	while (i != 100)
	{
		i++;
		usleep(15000);
	}
}

char			*ft_realloc(char *str, int size)
{
	char		*tmp;

	tmp = str;
	str = (char *)malloc(sizeof(char) * (size + 1));
	ft_bzero(str, size + 1);
	ft_strcpy(str, tmp);
	free(tmp);
	return (str);
}

char			*ft_line(char c)
{
	static char	*message;
	static int	index = 0;
	static int	factor = 1;

	if (index == 0)
	{
		message = (char *)malloc(sizeof(char) * (MESSAGE_SIZE + 1));
		ft_bzero(message, MESSAGE_SIZE + 1);
	}
	message[index] = c;
	index++;
	if (index == (MESSAGE_SIZE * factor))
	{
		factor++;
		message = ft_realloc(message, (factor * MESSAGE_SIZE));
	}
	if (c == '\0')
	{
		factor = 1;
		index = 0;
	}
	return (message);
}
