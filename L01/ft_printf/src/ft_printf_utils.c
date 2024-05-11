/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minokakakizaki <minokakakizaki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:51:29 by mkakizak          #+#    #+#             */
/*   Updated: 2024/05/11 11:54:27 by minokakakiz      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

int print_char(char c)
{
	if(write(1, &c, 1) != -1)
	{
		return (1);
	}
	return (0);
}


int print_str(char * str)
{
	int i;
	
	i = 0;
	while(str[i])
	{
		if(write(1, &str[i], 1) != -1)
		{
			i++;
		} 
		else
		{
			return (0);
		}
	}
	return(i);
}

int	print_unsigned_dec(unsigned int n)
{
	return (ft_putnbr_long(n));
}

int print_lower_hex(unsigned int nbr)
{	
	return(ft_putnbr_base(nbr, "0123456789abcdef"));
}

int print_upper_hex(unsigned int nbr)
{
	return(ft_putnbr_base(nbr, "0123456789ABCDEF"));
}


int print_address(void *ptr) {

    uintptr_t addr = (uintptr_t)ptr;
    char output[19];
    output[18] = '\0';
    int start;
	int i;

	// if(ptr < (uintptr_t)0)
	// {
	// 	start = 19;
	// }
	// else 
	// {
	// 	start = 16;
	// }
	start = 16;

    // Find the starting position for non-zero digits
    int found_nonzero = 0;
    for (int i = 0; i < 16; i += 4) {
        unsigned char nibble = (addr >> i) & 0xF;
        if (nibble != 0) {
            found_nonzero = 1;
            start = start - i;
            break;
        }
    }

	// 0x1086833a0


	i = start - 2;
    // Convert pointer value to hexadecimal
    while (i >= 0) 
	{
        unsigned char nibble = (addr >> (((start - i) * 4) - 8)) & 0xF;
        output[i] = (nibble < 10) ? nibble + '0' : nibble - 10 + 'a';
		i--;
    }
	// 0x119d383a0
	// printf("i is %d\n", start);

    // Add '0x' and terminating \0 char 
    output[0] = '0';
    output[1] = 'x';
	output[start] = '\0';
	
    ft_putstr(output);

	return(ft_strlen(output));
}

