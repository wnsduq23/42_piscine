/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:11:06 by junykim           #+#    #+#             */
/*   Updated: 2022/02/08 20:15:57 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	index;

	index = 0;
	while (*(str + index) != '\0')
	{
		if ('A' <= str[index] && str[index] <= 'Z')
		{
			str[index] = str[index] - 'A' + 'a';
		}
		index++;
	}
	return (str);
}
