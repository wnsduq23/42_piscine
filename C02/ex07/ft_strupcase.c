/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:46:01 by junykim           #+#    #+#             */
/*   Updated: 2022/02/10 17:26:09 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	index;

	index = 0;
	while (*(str + index) != '\0')
	{
		if ('a' <= str[index] && str[index] <= 'z')
		{
			str[index] = str[index] - 'a' + 'A';
		}
		index++;
	}
	return (str);
}
