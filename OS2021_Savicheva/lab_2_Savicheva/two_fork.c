#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
int main (int argc, char *argv[]){
	struct tm *ptr;
	struct timeval tv;
	time_t lt;
	char str[30];
	pid_t pid;
	if ((pid=fork()) == 0) {
		gettimeofday(&tv, NULL);
		lt = tv.tv_sec;
		ptr = localtime(&lt);
		strftime(str, 30, "%T", ptr);
		printf("\nPid of first child process = %d, time %s:%ld\n", getpid(), str, tv.tv_usec);
		return 0;
	} 
	if ((pid=fork()) == 0) {
		gettimeofday(&tv, NULL);
		lt = tv.tv_sec;
		ptr = localtime(&lt);
		strftime(str, 30, "%T", ptr);
		printf("\nPid of second child process = %d,parent = %d,  time %s:%ld\n", getpid(), getppid(), str, tv.tv_usec);
		return 0;
	} 
	gettimeofday(&tv, NULL);
	lt = tv.tv_sec;
	ptr = localtime(&lt);
	strftime(str, 30, "%T", ptr);
	printf("\nPid of parent process = %d,parent = %d, time %s:%ld\n", getpid(), getppid(),str, tv.tv_usec);
	system("ps -x");
	return 0;
}
