/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fft_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:05:12 by omanie            #+#    #+#             */
/*   Updated: 2022/02/17 15:35:28 by omanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	ft_atoi_help(char next, long res, int cnt, int odd)
{
	if (cnt <= 17)
		return ((long)(next - '0') + res * 10);
	else if (cnt == 18 && res > 922337203685477580L && odd)
		return (-9223372036854775807L - 1L);
	else if (cnt == 18 && res > 922337203685477580)
		return (9223372036854775807L);
	else if (cnt == 18 && res < 922337203685477580L)
		return ((long)(next - '0') + res * 10);
	else if (cnt == 18 && next <= '7')
		return ((long)(next - '0') + res * 10);
	else if (cnt == 18 && next == '8' && odd)
		return (-9223372036854775807L - 1L);
	else if (odd)
		return (-9223372036854775807L - 1L);
	else
		return (9223372036854775807L);
}

static int	one_line_code(int odd, long res)
{
	if (odd && res != -9223372036854775807L - 1L)
		return (res * -1);
	return (res);
}

int	ft_atoi(const char *str)
{
	long	res;
	int		i;
	int		odd;
	int		cnt;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	odd = 0;
	if (str[i] == '-')
		odd = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	res = 0;
	cnt = 0;
	while (48 <= (char)(str[i]) && (char)(str[i]) <= 57 && cnt <= 19)
	{
		res = ft_atoi_help((char)(str[i]), res, cnt, odd);
		i++;
		if (res > 0 || cnt)
			cnt++;
	}
	res = one_line_code(odd, res);
	return ((int) res);
}
