
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#define BIT(x) 				(1 << (x))
#define BIT_SET(y, mask)	(y |= (mask))
#define BIT_CLEAR(y, mask)	(y &= ~(mask))
#define BIT_FLIP(y, mask)	(y ^= (mask))
#define BYTES(a) ((((a) % 8) == 0) ? (a) / 8 : ((a) / 8) + 1)
#define MIN(a, b) (((a) < (b)) ? a: b)
#define MAX(a, b) (((b) > (b)) ? a: b)

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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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
			cur_r[m->j] = 'x';
		else
			(m->data[m->i][m->j / 8] & BIT(pos)) ? (cur_r[m->j] = 'o') : (cur_r[m->j] = '.');
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

void	map_init(t_map *m)
{
	m->rows = 1;
	m->cols = 10;
	m->data = malloc(sizeof(char*) * m->rows);
	m->i = 0;
	m->j = 0;
	m->maxqlen = 0;
	m->maxrow = 0;
	m->maxcol = 0;
	m->dp = create_dp(m);
}

void	max_square(t_map *m, char *line)
{
	int temp;

	if (m->i > 0 && m->j > 0)
	{
		temp = m->dp[m->j];
		if (m->data[m->i - 1][m->j - 1] == 'o')
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
	else if (line[m->j] == '.' && m->maxqlen == 0)
	{	
		m->maxqlen = 1;
		m->maxcol = m->j;
	}
}


void	set_row(t_map *m, char *line)
{
	int		pos;

	m->data[m->i] = malloc(sizeof(char) * BYTES(m->cols));	
	printf("%d\n", BYTES(m->cols));
	pos = 7;
	while (m->j < m->cols)
	{
		max_square(m, line);
		if (line[m->j++] == 'o')
			BIT_SET(m->data[m->i][(m->j - 1) / 8], BIT(pos));
		(m->j % 8) == 0 ? pos = 7 : --pos;
	}
	m->j = 0;
	m->i++;
}

int		main(void)
{
	t_map *m;
	char	buf[11] = "o.o....o..";
	printf("%s\n", buf);
	m = malloc(sizeof(t_map));
	map_init(m);
	set_row(m, buf);
	m->i = 0;
	print_row(m, buf);
	printf("%d\n%d\n%d\n", m->maxqlen, m->maxrow, m->maxcol);
	return (0);
}
