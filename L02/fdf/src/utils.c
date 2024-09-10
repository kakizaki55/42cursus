
#include <fdf.h>

void print_img(t_data img)
{
	ft_printf("bits per pixel is: %d\n", img.bits_per_pixel);
	ft_printf("line length: %d\n", img.line_length);
	ft_printf("img: %p\n", img.img);
	ft_printf("addr: %p\n", img.addr);
}

//make sure i need to delet change this in to a while loop

void print_matrix(int **matrix, int col, int row)
{

    for (int i = 0; i < col; i++) {
        ft_printf("[%d] ", i);

        for (int j = 0; j < row; j++) {
				ft_printf("[%d]", matrix[i][j]);
        }
        ft_printf("\n");
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