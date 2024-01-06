#include <stdio.h>
#include <string.h>
#include <unistd.h>

char HOME[] = "~";
#define MAX_LEN 2

int main() {
  char path[1024];
  char login[256];
  getcwd(path, sizeof(path));

  char *splited[1024];
  char *token = strtok(path, "/");
  int i = 0;
  while (token != NULL) {
    splited[i++] = token;
    token = strtok(NULL, "/");
  }

  if (i < 2) {
    printf("%s", path);
    return 0;
  }
  getlogin_r(login, sizeof(login));
  if (strcmp(login, splited[1]) == 0) {
    splited[1] = HOME;
    for (int j = 2; j < i - 1; j++) {
      splited[j][MAX_LEN] = '\0';
    }

    for (int j = 1; j < i - 1; j++) {
      printf("%s/", splited[j]);
    }
    printf("%s\n", splited[i - 1]);
    return 0;

  } else {

    printf("/");
    for (int j = 0; j < i - 1; j++) {
      if (strlen(splited[j]) > 3)
        splited[j][MAX_LEN] = '\0';
      printf("%s/", splited[j]);
    }
    printf("%s\n", splited[i - 1]);

    return 0;
  }
}
