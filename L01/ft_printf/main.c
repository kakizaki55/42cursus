/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkakizak <mkakizak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:50:39 by mkakizak          #+#    #+#             */
/*   Updated: 2024/05/06 15:50:06 by mkakizak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// • %c Prints a single character.
// • %s Prints a string (as defined by the common C convention).
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number.
// • %i Prints an integer in base 10.
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.
// • %% Prints a percent sign.

//--------------------------------------------
//----------------PRINTF TEST-----------------
//--------------------------------------------


#include "libft.h"
#include "libftprintf.h"

int	main(void)
{
	int len;

	// GENERAL TEST (UNCOMMENT SECTION BELOW)
	//--------------------------------------------
	// ft_printf();
	// printf("%zu\n", ft_strlen("123"));
	// char c = 'c';
	// char ce = '\0';
	// char s[14] = "Hello there!!";
	// char *se = "";
	// void *p;
	// int d = -34578654; // need to handle min max pos neg
	// int	i = -42; 
	// unsigned u = 1234567; //no negatives (larger max)
	// int X = 98765432; //BC614E //NOTE: does not need to handle negatives
	// int x = 12345678; //BC614E
	//--------------------------------------------
	// NULL VALUES TEST (UNCOMMENT SECTION BELOW)
	//--------------------------------------------
	// char c = '\0';
	// char ce = '\0';
	// char *s = NULL;
	// char *se = NULL;
	// void *p = NULL;
	// int d = 0; // need to handle min max pos neg
	// int	i = 0; 
	// unsigned u = 0; //no negatives (larger max: 4294967295)
	// int X = INT_MIN; //BC614E //NOTE: does not need to handle negatives
	// int x = INT_MIN; //BC614E
	//--------------------------------------------
	// MAX/MIN VALUES TEST (UNCOMMENT SECTION BELOW)
	//--------------------------------------------
	// char c = '\0';
	// char ce = '\0';
	// char *s = NULL;
	// char *se = NULL;
	// void *p = NULL;
	// int d = INT_MAX; // need to handle min max pos neg
	// int	i = INT_MIN; 
	// unsigned u = UINT_MAX; //no negatives (larger max: 4294967295)
	// int X = INT_MAX; //BC614E //NOTE: does not need to handle negatives
	// int x = INT_MAX; //BC614E

	// printf("---------------------------------------------\n");
	// printf("-----------------PRINTF TEST-----------------\n");
	// printf("------------------cspdiuxX%%------------------\n");
	// printf("   Empty string test:");
	// len = printf("");
	// printf("      len: %d\n", len);
	// printf("Empty ft string test:");
	// len = ft_printf("");
	// printf("   ft_len: %d\n", len);

	// printf("\n------CHAR------\n");
	// len = printf("   printf: %c (char)\n", c);
	// printf("      len: %d\n", len);
	// len = ft_printf("ft_printf: %c (char)\n", c);
	// printf("   ft_len: %d\n", len);

	// printf("\n-----EMPTY CHAR-------\n");
	// len = printf("   printf: %c (empty char)\n", ce);
	// printf("      len: %d\n", len);
	// len = ft_printf("ft_printf: %c (empty char)\n\0", ce);
	// printf("   ft_len: %d\n", len);

	// printf("\n-----STRING-------\n");
	// len = printf("   printf: %s (string)\n", s);
	// printf("      len: %d\n", len);
	// len = ft_printf("ft_printf: %s (string)\n\0", s);
	// printf("   ft_len: %d\n", len);
	
	// printf("\n------EMPTY STRING------\n");
	// len = printf("   printf: %s (empty string)\n", se);
	// printf("      len: %d\n", len);
	// len = ft_printf("ft_printf: %s (empty string)\n", se);
	// printf("   ft_len: %d\n", len);
	
	// printf("\n------VOID POINTER------\n");
	// len = printf("   printf: %p (void pointer)\n", p);
	// printf("      len: %d\n", len);
	// len = ft_printf("ft_printf: %p (void pointer)\n", p);
	// printf("   ft_len: %d\n", len);
	
	// printf("\n------DECIMAL NUMBER------\n");
	// len = printf("   printf: %d (decimal number - d)\n", d);
	// printf("      len: %d\n", len);
	// len = ft_printf("ft_printf: %d (decimal number - d)\n", d);
	// printf("   ft_len: %d\n", len);
	
	// printf("\n------INTEGER------\n");
	// len = printf("   printf: %i (integer)\n", i);
	// printf("      len: %d\n", len);
	//  len = ft_printf("ft_printf: %i (integer)\n", i);
	//  printf("   ft_len: %d\n", len);
	
	// printf("\n------UNSIGNED DECIMAL------\n");
	// len = printf("   printf: %u (unsigned decimal)\n", u);
	// printf("      len: %d\n", len);
	// len = ft_printf("ft_printf: %u (unsigned decimal)\n", u);
	// printf("   ft_len: %d\n", len);
	
	// printf("\n-----lowercase HEX-------\n");
	// len = printf("   printf: %x (lowercase hex, from int)\n", x);
	// printf("      len: %d\n", len);
	// len = ft_printf("ft_printf: %x (lowercase hex, from int)\n", x);
	// printf("   ft_len: %d\n", len);
	
	// printf("\n------UPPERCASE HEX------\n");
	// len = printf("   printf: %X (uppercase HEX from int)\n", X);
	// printf("      len: %d\n", len);
	// len = ft_printf("ft_printf: %X (uppercase HEX from int)\n", X);
	// printf("   ft_len: %d\n", len);
	
	
	// printf("\n------%%%%%% TEST------\n");
	// len = printf("   printf: %%%%%%\n");
	// printf("      len: %d\n", len);
	// len = ft_printf("ft_printf: %%%%%%\n", X);
	// printf("   ft_len: %d\n", len);
	
	// printf("\n------MIXED ARG TYPE TEST------\n");
	// len = printf("   printf: %c , %s, %p, %d, %i, %u, %x, %X %% (multi_test)\n", c,s,p,d,i,u,x,X);
	// printf("      len: %d\n", len);
	// len = ft_printf("ft_printf: %c , %s, %p, %d, %i, %u, %x, %X %% (multi_test)\n\0", c,s,p,d,i,u,x,X);
	// printf("   ft_len: %d\n", len);

	// printf("\n------------------END TEST-------------------\n");
	// printf("\n---------------------------------------------\n");
	//printf("sum_variadic: %d\n", sum_variadic(5,1,2,3,4,5));
	return (0);
}