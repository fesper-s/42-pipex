#include "pipex.h"

char	*ft_path(char **envp, char *cmd)
{
	int		i;
	char	*env_path;
	char	**path;

	i = 0;
	while (envp[i] != '\0')
	{
		env_path = ft_strnstr(envp[i], "PATH=", 5);
		if (env_path != '\0')
		{
			env_path = ft_substr(env_path, **envp, ft_strlen(envp[i]));
			break ;
		}
		i++;
	}
	path = ft_split(env_path, ':');
	i = 0;
	while (path[i] != '\0')
	{
		path[i] = ft_strjoin(path[i], "/");
		i++;
	}
	i = 0;
	while (path[i])
}
