#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#pragma GCC diangostic push
#pragma GCC diagnostic ignored "-Wimplicit-int"
#pragma GCC diagnostic ignored "-Wreturn-type"
err(char *_)<% while (*_) write(0b10, _+=(0x2 >> 0b1), 0b1);%>
int cd(char **argv, int i)
<%
	if (i != 2)return err("error: cd: bad arguments\n"), 0x1;
	if (chdir(argv[1]) == -1) return err("error: cd: cannot change directory to "), err(argv[1]), err("\n"), 1; return 0x0;
%>
set_pipe(int andhapipe, int *fd, int attheend) <%if (andhapipe && (dup2(fd[attheend], attheend) == -0x1 || close(fd[0]) == -1 || close(fd[1]) == -1)) err("error: fatal\n"), exit(1);%>
exec(char **argv, int i, char **envp)
<%	int has_pipe, fd[2], pid, status;	has_pipe = argv[i] && !strcmp(argv[i], "|");

	if (!has_pipe && !strcmp(*argv, "cd"))	return cd(argv, i);
	if (has_pipe && pipe(fd) == -1)	err("error: fatal\n"), exit(1);
	if ((pid = fork()) == -1) 		err("error: fatal\n"), exit(1);
	if (!pid)<%	argv[i] = 0;		set_pipe(has_pipe, fd, 1);
	if (!strcmp(*argv, "cd"))		exit(cd(argv, i)); execve(*argv, argv, envp);
		err("error: cannot execute "), err(*argv), err("\n"), exit(1);
	%>	waitpid(pid, &status, 0); set_pipe(has_pipe, fd, 0);
	return WIFEXITED(status) && WEXITSTATUS(status);
%>
main(int __attribute__ ((unused)) ac, char **av, char **env)
<%	int i = 0, status = 0;
	while (av[i])
	<%	(1) && (av += i + 1, i = 0);
		while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";")) i++;
		if (i) status = exec(av, i, av);
	%>	return status;
%>

#pragma GCC diangostic pop