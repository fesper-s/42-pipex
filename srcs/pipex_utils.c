#include "pipex.h"

char	**ft_trim(char **cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
	{
		cmds[i] = ft_strtrim(cmds[i], "'\"");
		i++;
	}
	return (cmds);
}
