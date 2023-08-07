#include <stdio.h>
#include <string.h>

#define MAXLEN 10000

int main(int argc, char *argv[]){
	char command[MAXLEN] = "";
	for(int i=1; i<argc; i++){
		strcat(command, argv[i]);
		strcat(command, " ");
	}
	puts(command);
	FILE *fp = popen(command, "r");
	
	int numLines=0;
	char buffer[MAXLEN];
	
	while (fgets(buffer, MAXLEN, fp))
		numLines++;
	pclose(fp);
	printf("%d\n", numLines);
}
