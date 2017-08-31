/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nocardoz <nocardoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 12:04:44 by nocardoz          #+#    #+#             */
/*   Updated: 2017/08/30 21:50:19 by jbrown           ###   ########.fr       */
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
# define GET_BIT(a, b) ((a & BIT(b)) == BIT(b) ? 1 : 0)
# define PREV_BYTE(a) (((a) == 8) ? ((a) / 8 - 1): ((a) / 8))
# define PREV_BIT(a) ((a + 1) == 8 ? (a = 0) : (a += 1))


typedef struct	s_map
{
	char	**data;
	int		i;
	int		j;
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

int				index_of(char c, t_map *m);

void			*ft_memcpy(void *dst, const void *src, unsigned int size);
char			*ft_realloc(char *ptr, unsigned int size);

void			print_map(t_map *map);
t_map			*map_init(int fd);

void			find_max_square(t_map *map, int i, int j, char c);

void			print_row(t_map *m, char *cur_r);
void			create_dp(t_map *m);
t_map			*map_new(void);
void			max_square(t_map *m, int bit);
int				set_row(t_map *m, char *line);

#endif
