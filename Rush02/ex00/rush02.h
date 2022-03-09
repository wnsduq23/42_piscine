/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhapa <chanhapa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:19:46 by chanhapa          #+#    #+#             */
/*   Updated: 2022/02/20 20:21:07 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H

# define RUSH02_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_info
{
	int			fd;
	int			size;
	int			len;
	char		buf[4096];
	char		**buf_split;
}				t_info;

void	dict_input(char *dict[2][101], struct s_info p1);
void	reading_r(char *nbr, char *dict[2][101]);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_putstr(char *str);
char	*ft_strndup(char *src, int n);
char	*ft_strdup(char *src);
int		_is_in(char c, char *src);
int		_malloc_size(char *str, char *charset);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_trim(char *str, int is_num);
char	**ft_split(char *str, char *charset);
int		num_return(int num);
void	ft_putstr_ns(char *str);
int		is_valid_argu(char *str);

#endif
