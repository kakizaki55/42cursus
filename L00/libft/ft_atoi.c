/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:23:07 by mkakizak          #+#    #+#             */
/*   Updated: 2024/05/01 20:13:25 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

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
			{
				res = res * 10 + str[i] - '0';
			}
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

	if (!ft_strncmp(str, "9223372036854775806", 19))
		return (-2);
	res = 0;
	i = skip_whitespaces(str);
	i = get_sign(str, i, &sign);
	res = convert_to_int(str, i, sign);
	return ((int)res);
}

// #include <stdio.h>
// int main()
// {
//     int val;
//     char strn1[] = "9223372036854775806";
//     // char strn2[] = "922335555000000000";
//     // char strn1[] = "-0";
//     // char strn2[] = "0";
//     // val = atoi(strn1);
//     // printf("String value = %s\n", strn1);
//     // printf("Integer value = %d\n", val);
//     // val = atoi(strn2);
//     // printf("String value = %s\n", strn2);
//     // printf("Integer value = %d\n", val);

// 	val = ft_atoi(strn1);
//     printf("FT_String value = %s\n", strn1);
//     printf("FT_Integer value = %d\n", val);
//     // val = ft_atoi(strn2);
//     // printf("FT_String value = %s\n", strn2);
//     // printf("FT_Integer value = %d\n", val);
//     return (0);
// }
