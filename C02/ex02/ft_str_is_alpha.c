/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:35:23 by junykim           #+#    #+#             */
/*   Updated: 2022/02/08 19:40:36 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	index;
	int	flag;

	index = 0;
	flag = 1;
	while (*(str + index) != '\0')
	{
		if (('a' <= str[index] && str[index] <= 'z') \
				|| ('A' <= str[index] && str[index] <= 'Z'))
			flag = 1;
		else
		{
			flag = 0;
			break ;
		}
		index++;
	}
	return (flag);
}
