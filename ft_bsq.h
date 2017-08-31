/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nocardoz <nocardoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 12:04:44 by nocardoz          #+#    #+#             */
/*   Updated: 2017/08/30 15:55:19 by nocardoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define BIT(x) 				(1 << (x))
# define BIT_SET(y, mask)	(y |= (mask))
# define BIT_CLEAR(y, mask)	(y &= ~(mask))
# define BIT_FLIP(y, mask)	(y ^= (mask))
# define BYTES(a) ((((a) % 8) == 0) ? (a) / 8 : ((a) / 8) + 1)
# define MIN(a, b) (((a) < (b)) ? a: b)
# define MAX(a, b) (((b) > (b)) ? a: b)

typedef struct	s_map
{
	char	**data;
	char	i;
	char	j;
	int		rows;
	int		cols;
	int		maxqlen;
	int		maxrow;
	int		maxcol;
	int		*dp;
	int		prev;
	char	*key;

}				t_map;

int				ft_get_line_buff(int fd, char **buf, int buf_size);

int				ft_atoi(char **expr);

int				ft_strlen(char *str);

int				ft_get_line(int fd, char **line, int buf_size);

int				index_of(char c, char *str);

void			*ft_memcpy(void *dst, const void *src, unsigned int size);
char			*ft_realloc(char *ptr, unsigned int size);

void			map_print(t_map *map);
t_map			*map_init(int fd);

void			find_max_square(t_map *map, int i, int j, char c);

void			print_row(t_map *m, char *cur_r);
int				*create_dp(t_map *map);
t_map			*map_new(void);
void			max_square(t_map *m, char *line);
int				set_row(t_map *m, char *line);

#endif
