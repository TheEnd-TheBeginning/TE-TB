#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main (int argc, char *argv[]) {
	pid_t pid;
	printf("One process");
	pid = fork();
	printf("Two processes");
	pid = fork();
	printf("Three processes");
	return system("ps -x");
}
