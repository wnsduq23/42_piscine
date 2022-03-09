/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:58:45 by junykim           #+#    #+#             */
/*   Updated: 2022/02/10 17:16:02 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	char			*a;

	i = 0;
	a = dest;
	while (*a)
		a++;
	while (*src && i < nb)
	{
		*a = *src;
		a++;
		src++;
		i++;
	}
	*a = 0;
	return (dest);
}
