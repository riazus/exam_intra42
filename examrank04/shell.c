#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void exit_fatal()
{
	write(2, "error: fatal\n", 14);
	exit(1);
}

int ft_cd()
{
	return 0;
}

int ft_linelen(char **argv)
{
	int i = 0;

	while(argv[i])
		i++;

	return i;
}

int ft_strlen(char *line)
{
	int i = 0;

	while(line[i])
		i++;

	return i;
}

int main(int argc, char **argv, char **env)
{
	int j, i = 1;
	int pipefd[2];
	int filefd0 = dup(0);
	int filefd1 = dup(1);
	char **line;
	int len;
	int opened_pipe = 0;
	pid_t pid;

	while (i < argc)
	{
		if (!strcmp(argv[i], "|") || !strcmp(argv[i], ";"))
			i++;
		else
		{
			len = ft_linelen(argv);
			if (!(line = (char **)malloc(sizeof *) * len + 1))
				exit_fatal();
			line[len] = NULL;
			j = i;
			while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			{
				line[i-j] = argv[i];
				i++;
			}
			if (opened_pipe)
			{
				dup2(pipefd[0], 0);
				close(pipefd[0]);
			}
			if (argv[i] && !strcmp(argv[i], "|"))
			{
				dup2(pipefd[1], 1);
				close(pipefd[1]);
			}
			if (!strcmp(line[0], "cd"))
				ft_cd(line);
			else
			{
				pid = pipe(pipefd);
				if (pid == 0)
				{
					write(2, "error: cannot execute ", 22);
					write(2, line[0], ft_strlen(line[0]));
					write(2, "\n", 2);
					free(line);
					return(0);
				}
				if (pid < 0)
				{

				}
				waitpid(line, &j, 0)
			}
			if (opened_pipe)
			{
				dup2(filefd0, 0);
				opened_pipe = 0;
			}
			if (argv[i] && !strcmp(argv[i], "|"))
			{
				dup2(filefd1, 1);
				opened_pipe = 1;
			}
		}
		free(line);
	}
	return (0);
}

