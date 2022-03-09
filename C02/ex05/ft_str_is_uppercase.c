/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:44:26 by junykim           #+#    #+#             */
/*   Updated: 2022/02/08 19:52:35 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	flag;
	int	index;

	index = 0;
	flag = 1;
	while (*(str + index) != '\0')
	{
		if (str[index] < 'A' || str[index] > 'Z')
		{
			flag = 0;
			break ;
		}
		index++;
	}
	return (flag);
}
