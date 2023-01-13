#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    int NUMBER_OF_TRUNCATION=3;
    char HOME[]="~";

void stringmod(char* original,char* replacement, int index) {
    int len = strlen(original);
    int len_r = strlen(replacement);
    int i;
    if (index < len) {
        for (i = 0; i < len_r; i++) {
            original[i] = replacement[i];
        }
        for (i = len_r; i < len; i++) {
            original[i] = original[i + (index - len_r)];
        }
        original[i] = '\0';
    }
}

int main() {
    int count = 0;
    int i, j, k, l;
    char cwd[1024];
    char div[1024];
    char test[1024];
    getcwd(cwd,sizeof(cwd));
    char* user = getenv("USER");

    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd() error");
        return 1;
    }
    if (!user){
	perror("getenv() error");
        return 1;
    }
    for (i = 0; i < strlen(cwd); i++) {
	if (cwd[i] == '/') {
		count++;
	}

	if (count==1){
		l=i+2;
	}

	if (count==3 ) {
		k=i;
		strncpy(div, cwd+l,strlen(user));
		if (strcmp(div,user)==0){
			stringmod(cwd,HOME,i);
		}
		break;
	}
}
    printf("%s\n", cwd);
    return 0;
}
