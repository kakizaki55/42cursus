/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:54:03 by mkakizak          #+#    #+#             */
/*   Updated: 2025/01/13 17:45:33 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	check_arg_count(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Invalid number of arguments:");
		printf("number_of_philosophers time_to_die time_to_eat time_to_sleep \
		[number_of_times_each_philosopher_must_eat]\n");
		return (true);
	}
	return (false);
}

bool	check_invalid_args(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (ft_atoi(argv[i]) <= 0)
		{
			printf("Invalid arguments: All args must be positive numbers\n");
			return (true);
		}
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("Invalid arguments: All ars must be valid numbers\n");
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}
