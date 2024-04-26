/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:23:07 by mkakizak          #+#    #+#             */
/*   Updated: 2024/04/26 14:37:39 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_atoi(const char *str)
{
	// need to deal with lon ong values and cast them to int before returning them bask
	int i;
	int res;
	int sign;
	
	res = 0;
	i = 0;
	sign = 1;

	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')) {
        i++;
    }
    if (str[i] == '-') 
	{
        sign = -1;
        i++;
	} else if (str[i] == '+') {
        i++;
	}
	while(str[i] != '\0')
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			res = res * 10 + str[i] - '0';
		} else {
			return (res * sign);
		}
		i++;
	}
	return res * sign;
}

// int main()
// {
//     int val;
//     char strn1[] = "12546";
 
//     val = atoi(strn1);
//     printf("String value = %s\n", strn1);
//     printf("Integer value = %d\n", val);
 
//     char strn2[] = "       --3  f";
//     val = atoi(strn2);
//     printf("String value = %s\n", strn2);
//     printf("Integer value = %d\n", val);

// 	val = ft_atoi(strn1);
//     printf("FT_String value = %s\n", strn1);
//     printf("Integer value = %d\n", val);
 
//     val = ft_atoi(strn2);
//     printf("FT_String value = %s\n", strn2);
//     printf("Integer value = %d\n", val);
 
//     return (0);
// }