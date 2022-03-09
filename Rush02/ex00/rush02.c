/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhapa <chanhapa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:02:13 by chanhapa          #+#    #+#             */
/*   Updated: 2022/02/20 20:22:02 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	main(int argc, char *argv[])
{
	char			*dict[2][101];
	struct s_info	p1;

	if (argc > 2)
	{
		write(1, "error\n", 1);
		return (0);
	}
	p1.size = 0;
	dict_input(dict, p1);
	if (!is_valid_argu(argv[1]))
		return (0);
	if (*argv[1] == '0' && ft_strlen(argv[1]) == 1)
	{
		ft_putstr_ns(dict[0][0]);
		write(1, "\n", 1);
		return (0);
	}
	reading_r(argv[1], dict);
	write(1, "\n", 1);
	return (0);
}

void	dict_input(char *dict[2][101], struct s_info p1)
{
	p1.size = 0;
	p1.fd = open("numbers.dict", O_RDWR);
	while (1)
	{
		p1.len = read(p1.fd, p1.buf + p1.size, 4096 - p1.size);
		if (p1.len > 0)
			p1.size += p1.len;
		else if (p1.len == 0)
			break ;
		else if (p1.len < 0 || p1.fd < 0)
			return ;
	}
	p1.buf_split = ft_split(p1.buf, ":\n");
	while (*p1.buf_split && *(p1.buf_split + 1))
	{
		p1.len = ft_strlen(*p1.buf_split);
		if (p1.len > 3)
			dict[1][(p1.len - 1) / 3 - 1] = ft_strdup(*(p1.buf_split + 1));
		else
			dict[0][ft_atoi(*p1.buf_split)] = ft_strdup(*(p1.buf_split + 1));
		p1.buf_split += 2;
	}
	close(p1.fd);
}

void	ft_for_more_nbrlen(char *nbr, char *dict[2][101])
{
	char	*block;
	int		len;

	len = ft_strlen(nbr);
	block = 0;
	if (len % 3 == 1)
	{
		ft_putstr(dict[0][nbr[0] - '0']);
		ft_putstr(dict[1][(len - 1) / 3 - 1]);
		reading_r(nbr + 1, dict);
		return ;
	}
	else if (len % 3 == 0)
		block = ft_strndup(nbr, 3);
	else
		block = ft_strndup(nbr, 2);
	len -= num_return(len % 3);
	nbr += num_return(len % 3);
	reading_r(block, dict);
	free(block);
	write(1, " ", 1);
	ft_putstr(dict[1][len / 3 - 1]);
	reading_r(nbr, dict);
}

void	reading_r(char *nbr, char *dict[2][101])
{
	if (*nbr == '0')
	{
		if (*(nbr + 1))
			reading_r(nbr + 1, dict);
	}
	else if (ft_strlen(nbr) == 1)
		ft_putstr_ns(dict[0][ft_atoi(nbr)]);
	else if (ft_strlen(nbr) == 2 && nbr[0] == '1')
		ft_putstr_ns(dict[0][ft_atoi(nbr)]);
	else if (ft_strlen(nbr) == 2)
	{
		ft_putstr_ns(10 * dict[0][(nbr[0] - '0')]);
		if (nbr[1] && nbr[1] != '0')
			write(1, " ", 1);
		reading_r(nbr + 1, dict);
	}
	else if (ft_strlen(nbr) == 3)
	{
		ft_putstr(dict[0][nbr[0] - '0']);
		ft_putstr(dict[0][100]);
		reading_r(nbr + 1, dict);
	}
	else
		ft_for_more_nbrlen(nbr, dict);
}

int	num_return(int num)
{
	if (num)
		return (2);
	return (3);
}
