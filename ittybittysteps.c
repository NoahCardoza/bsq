/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ittybittysteps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nocardoz <nocardoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 16:26:23 by nocardoz          #+#    #+#             */
/*   Updated: 2017/08/30 18:51:08 by nocardoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define BIT(n) ( 1<<(n) )
#define BYTES(a, b, c, d, e, f, g, h) (BIT(a * 1) | BIT(b * 2) | BIT(c * 3) | BIT(d * 4) | BIT(e * 5) | BIT(f * 5) | BIT(g * 6) | BIT(h * 7))

void ft_putbits(char c)
{
	int b;
	b = 7;
	while (b >= 0)
		printf("%d", !!(c & BIT(b--)));
	printf("\n");
}

int main(void)
{
	int b;

	b = 0;
	// ft_putbits(b);
	b <<= 5;
	// ft_putbits(b);
	ft_putbits(BYTES(1, 0, 1, 0, 0, 1, 1, 0));
	// ft_putbits(BIT(1) & BIT(1));
	// ft_putbits(BIT(1));
	// ft_putbits(BIT(2));
	// ft_putbits(BIT(3));
	// ft_putbits(BIT(4));
	// ft_putbits(BIT(5));
	// ft_putbits(BIT(6));
	// ft_putbits(BIT(7));
	// printf("%d\n", BIT(0) | BIT(7));
	// printf("%d\n", BIT(1));
	// printf("%d\n", BIT(2));
	// printf("%d\n", BIT(3));
	// printf("%d\n", BIT(4));
	// printf("%d\n", BIT(5));
	// printf("%d\n", BIT(6));
	// printf("%d\n", BIT(7));
	// printf("%d\n", b);
	// int oct = 128;
	// while (oct)
	// {
	// 	ft_putbits(oct);
	// 	printf("\n");
	// 	oct >>= 1;
	// }
	// printf("\n%c\n", 35);
	return (0);
}
