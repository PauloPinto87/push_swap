#include <stdio.h>


void	ft_atoi(char *str)
{
	long	result;
	int		char_convert;

	result = 0;
	if (*str != '\0')
	{
		char_convert = *str - '0';
		result = (result * 10) + char_convert;
		printf("%ld\n", result);
		str++;
		ft_atoi(str);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;


	i = 1;
	while (i < argc)
	{
		ft_atoi(argv[i]);
		j = 0;
		while (argv[i][j])
		{
			//printf("%d\n", argv[i][j] - 48);
			j++;
		}
		//printf("Argc = %d, argv = %s\n", i, argv[i]);
		i++;
	}
}