#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != '\0')
	{
		ft_strnstr(envp[i], "PATH", 5);
		i++;
	}
	return (0);
}
