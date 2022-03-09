/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:20:30 by junykim           #+#    #+#             */
/*   Updated: 2022/02/22 20:12:20 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	flag;
	int	tmp;

	flag = 0;
	while (length-- > 1)
	{
		tmp = f(tab[length], tab[length - 1]);
		if (tmp == 0)
			continue ;
		if (flag == 0)
			flag = tmp;
		else if ((flag < 0 && tmp > 0) || (flag > 0 && tmp < 0))
			return (0);
	}
	return (1);
}
