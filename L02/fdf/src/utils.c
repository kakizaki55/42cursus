
#include <fdf.h>

void print_img(t_vars img)
{
	ft_printf("bits per pixel is: %d\n", img.bits_per_pixel);
	ft_printf("line length: %d\n", img.line_length);
	ft_printf("img: %p\n", img.img);
	ft_printf("addr: %p\n", img.addr);
}

void print_matrix(int **matrix, int col, int row)
{
	int i;
	int j;

	i = 0;
	j = 0;
    while (i < col) {
        ft_printf("i[%d] ", i);

        while(j < row) 
		{
			ft_printf("%d\n[%d]", j, matrix[i][j]);
			j++;
        }
        ft_printf("\n");
		i++;
    }
}

void	free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int get_color(int z_value)
{
	if(z_value > 0)
	{
		return (0x00FFCC66);
	} else if (z_value < 0)
	{
		return (0x00FFFF00);
	}
	return (0x00FF00DD);
}

int str_arr_length(char **array)
{
	int i;

	if(array == NULL || array[0] == NULL)
		return (NULL);

	i = 0;
	while(array[i])
	{
		i++;
	}
	return (i);
}

int int_arr_length(int *array)
{
	int i;

	if(array == NULL || array[0] == NULL)
		return (NULL);

	i = 0;
	while(array[i])
	{
		i++;
	}
	return (i);
}