#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(void);
int add numbers(int num1, int num2);
int main(int ac, char **av);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
int main(int ac, char **av, char **env);
int _myexit(info_t *info);

#endif
