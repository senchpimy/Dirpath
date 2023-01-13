#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    char path[1024];
    char login[256];
    getcwd(path, sizeof(path));
    if (strlen(path)==1) {
	printf("/\n");
	return 0;
    }

    char *splited[1024];
    char *token = strtok(path, "/");
    int i = 0;
    while (token != NULL) {
        splited[i++] = token;
        token = strtok(NULL, "/");
    }

    getlogin_r(login, sizeof(login));

    if (strcmp(login, splited[1]) == 0) {
        splited[0] = "~";
    }

    for (int j = 1; j < i-1; j++) {
        splited[j][2] = '\0';
    }

    for (int j = 0; j < i - 1 ; j++) {
        printf("%s/", splited[j]);
    }
    printf("%s\n", splited[i - 1]);
    return 0;
}

