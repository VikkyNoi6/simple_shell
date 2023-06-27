#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 100

void read_line(char *line)
{
	printf("shell> ");
	fgets(line, MAX_LINE_LENGTH, stdin);
	line[strcspn(line, "n")] = '0'; // Remove the newline character
}	

int split_line(char *line, char **args)
{
	int i = 0;
	char *token = strok(line, " ");
	while (token != NULL && i < MAX_ARGS)
	{
		args[i++] = token;
		token = strok(NULL, " ");
	}		
	args[i] = NULL;
	return i;
}
	
void execute(char **args)
{
	pid_t pid = fork();
	if (pid == 0)
	{
		execvp(args[0], args);
		printf("Command not found: %sn", args[0]);
		exit(1);
	} else if (pid < 0)
		{
			printf("Error forking child processn");
		} else
			{	
				int staus;
				waitpid(pid, &status, 0);
			}	
}
void loop() 
{
	char line[MAX_LINE_LENGTH];
	char *args[MAX_ARGS];
	int argc;
	while (1)
	{
		read_line(line);
		argc = split_line(line, args);
		if (args[0] != NULL) 
		{
			execute(args);
		}
	}
}

int main()
{
	loop();
	return 0;
}
