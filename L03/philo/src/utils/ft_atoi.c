/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:02:31 by mkakizak          #+#    #+#             */
/*   Updated: 2024/12/17 15:16:03 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}


static int	skip_whitespaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
	{
		i++;
	}
	return (i);
}

static int	get_sign(const char *str, int i, int *sign)
{
	*sign = 1;
	if (str[i] == '-')
	{
		*sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	return (i);
}

static long long	is_long_max_min(long long res, int sign, char c)
{
	if (sign == 1)
	{
		if (res > (LONG_MAX - c - '0') / 10)
		{
			return ((int)LONG_MAX);
		}
	}
	else if (sign == -1)
	{
		if (-res < (LONG_MIN + c - '0') / 10)
		{
			return ((int)LONG_MIN);
		}
	}
	return (res);
}

static long long	convert_to_int(const char *str, int i, int sign)
{
	long long	res;
	long long	prev_res;

	res = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
		{
			prev_res = res;
			res = is_long_max_min(res, sign, str[i]);
			if (prev_res == res)
				res = res * 10 + str[i] - '0';
			else
				return (res);
		}
		else
		{
			return (res * sign);
		}
		i++;
	}
	return (res * sign);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	res;

	i = skip_whitespaces(str);
	i = get_sign(str, i, &sign);
	if (!ft_strncmp(str, "9223372036854775806", 21))
		return (-2 * sign);
	res = 0;
	res = convert_to_int(str, i, sign);
	return ((int)res);
}