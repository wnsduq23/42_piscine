/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:43:43 by junykim           #+#    #+#             */
/*   Updated: 2022/02/08 19:50:15 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	flag;
	int	index;

	flag = 1;
	index = 0;
	while (*(str + index) != '\0')
	{
		if (str[index] < 'a' || str[index] > 'z')
		{
			flag = 0;
			break ;
		}
		index++;
	}
	return (flag);
}
