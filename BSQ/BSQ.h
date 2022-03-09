/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSQ.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:42:25 by junykim           #+#    #+#             */
/*   Updated: 2022/02/23 20:42:45 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		g_row;
int		g_col;
int		g_pos;
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_min(int a, int b, int c);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		verify_chars(char *argv);
int		verify_columns(char *argv);
int		verify_returns(char *argv);
int		verify_map(char *argv);
int		get_next_cols(char *argv, int fd);
int		get_file_size(char *argv);
int		get_number_cols(char *argv);
int		get_number_rows(char *argv);
void	skip_first_row(int fd);
char	**read_file(char *argv);
void	buf_init(int fd, char **buf);
int		**malloc_map(void);
int		get_max_length(char **map, int **c_map, char obst, int max_length);
int		find_square_position(int **c_map, int max_length);
char	**fill_map(char **map, char *cell_types);
void	print_solution(int i, char **argv);
void	free_int_map(int **map);
void	free_char_map(char **map);
char	get_cell_type(char *argv, int type);
int		verify_cell_type(char type[3]);
#endif
