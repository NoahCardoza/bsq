/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nocardoz <nocardoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 12:05:54 by nocardoz          #+#    #+#             */
/*   Updated: 2017/08/30 15:13:31 by nocardoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	print_row(t_map *m, char *cur_r)
{
	int	pos;

	pos = 7;
	m->j = 0;
	while (m->j < m->cols)
	{
		if (m->maxqlen
				&& m->i >= m->maxrow && m->i < m->maxrow + m->maxqlen
				&& m->j >= m->maxcol && m->j < m->maxcol + m->maxqlen)
			cur_r[m->j] = *(m->key + 2);
		else
			(m->data[m->i][m->j / 8] & BIT(pos)) ? (cur_r[m->j] = *(m->key + 1)) : (cur_r[m->j] = '.');
		(++m->j % 8) == 0 ? pos = 7 : --pos;
	}
	cur_r[m->j] = '\n';
	write(1, cur_r, (m->cols + 1));
	m->j = 0;
	m->i++;
}

int		*create_dp(t_map *map)
{
	int i;
	int *dp;

	i = 0;
	dp = malloc(sizeof(int*) * (map->cols + 1));
	while (i < map->cols)
	{
		dp[i] = 0;
		i++;
	}
	return (dp);
}

t_map	*map_new(void)
{
	t_map *m;

	m = malloc(sizeof(t_map));
	m->rows = 0;
	m->cols = 0;
	m->data = NULL;
	m->i = 0;
	m->j = 0;
	m->maxqlen = 0;
	m->maxrow = 0;
	m->maxcol = 0;
	m->dp = create_dp(m);
	m->key = NULL;

	return (m);
}

void	max_square(t_map *m, char *line)
{
	int temp;

	if (m->i > 0 && m->j > 0)
	{
		temp = m->dp[m->j];
		if (m->data[m->i - 1][m->j - 1] == *(m->key + 1))
		{
			if (m->maxqlen < (m->dp[m->j] = MIN(MIN(m->dp[m->j - 1], m->prev), m->dp[m->j]) + 1))
			{
				m->maxqlen = m->dp[m->j] + 1;
				m->maxrow = m->i - m->dp[m->j];
				m->maxcol = m->j - m->dp[m->j];
			}
		}
		else
		printf("%s\n", m->key);
			m->dp[m->j] = 0;
			m->prev = temp;
	}
	else if (line[m->j] == *m->key && m->maxqlen == 0)
	{	
		m->maxqlen = 1;
		m->maxcol = m->j;
	}
}


int		set_row(t_map *m, char *line)
{
	int		pos;

	m->data[m->i] = malloc(sizeof(char) * BYTES(m->cols));	
	printf("%d\n", BYTES(m->cols));
	printf("%s\n", line);
	pos = 7;
	while (m->j < m->cols)
	{
		printf("{%s}[%c]\n", m->key, line[m->j]);
		if (index_of(line[m->j], m->key) == -1)
		{
			printf("EROR 5 {%s}[%c] => %s\n", m->key, line[m->j], (line + m->j));
			return (0);
		}
		max_square(m, line);	
		if (line[m->j++] == *(m->key + 1))
			BIT_SET(m->data[m->i][(m->j - 1) / 8], BIT(pos));
		(m->j % 8) == 0 ? pos = 7 : --pos;

	}
	printf("\n");
	m->j = 0;
	m->i++;
	return (1);
}
