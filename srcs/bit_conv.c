/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nocardoz <nocardoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 12:05:54 by nocardoz          #+#    #+#             */
/*   Updated: 2017/08/30 23:03:29 by jbrown           ###   ########.fr       */
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
}

void	create_dp(t_map *m)
{
	int i;

	i = 0;
	m->dp = malloc(sizeof(int) * (m->cols + 1));
	while (i < m->cols + 1)
	{
		*((m->dp) + i) = 0;
		i++;
	}
}

t_map	*map_new(void)
{
	t_map *m;

	m = malloc(sizeof(t_map));
	m->rows = 0;
	m->cols = 0;
	m->prev = 0;
	m->data = NULL;
	m->i = 0;
	m->j = 0;
	m->maxqlen = 0;
	m->maxrow = 0;
	m->maxcol = 0;
	m->dp = NULL;
	m->key = NULL;

	return (m);
}

void	max_square(t_map *m, int bit)
{
	int temp;

	if (m->i > 0 && m->j > 0)
	{
		temp = m->dp[m->j];
		PREV_BIT(bit);
		bit = GET_BIT(m->data[m->i - 1][PREV_BYTE(m->j)], bit);
		if (bit == 0)
		{
			if (m->maxqlen < (m->dp[m->j] = MIN(MIN(m->dp[m->j - 1], m->prev), m->dp[m->j]) + 1))
			{
				m->maxqlen = m->dp[m->j] + 1;
				m->maxrow = m->i - m->dp[m->j];
				m->maxcol = m->j - m->dp[m->j];
			}
		}
		else
			m->dp[m->j] = 0;
		m->prev = temp;
	}
}

int		set_row(t_map *m, char *line)
{
	int		pos;

	m->data[m->i] = malloc(sizeof(char) * BYTES(m->cols));	
	pos = 7;
	while (m->j < m->cols)
	{
		if (index_of(line[m->j], m) == -1)
			return (0);
		if (line[m->j] == *(m->key + 1))
			BIT_SET(m->data[m->i][(m->j - 1) / 8], BIT(pos));
		max_square(m, pos);
		(++(m->j) % 8) == 0 ? pos = 7 : --pos;
	}
	m->j = 0;
	m->i++;
	return (1);
}
