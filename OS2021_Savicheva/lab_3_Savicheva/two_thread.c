#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<errno.h>
#include<unistd.h>
#include<time.h>
#include<sys/time.h>
void * start_routime(void *arg) {
	struct tm *ptr;
	struct timeval tv;
	time_t lt;
	char str[30];
	int loc_id = * (int *)arg;

	gettimeofday(&tv, NULL);
	lt = tv.tv_sec;
	ptr = localtime(&lt);
	strftime(str, 30, "%T", ptr);
	printf("\nPid of parent process = %d, id current tread = %ld, time %s:%ld\n", getpid(), pthread_self(), str, tv.tv_usec);
		return 0;
}
int main (int argc, char *argv[]) {
	int id1, id2, result;
	struct tm *ptr;
	struct timeval tv;
	time_t lt;
	char str[30];
	pthread_t thread1, thread2;
	id1 = 1;
	result = pthread_create(&thread1, NULL, start_routime, &id1);
	if ( result!= 0 ) {
		perror("First thread");
		return EXIT_FAILURE;
	}
	id1 = 2;
	result = pthread_create(&thread2, NULL, start_routime, &id2);
	if ( result!= 0 ) {
		perror("Second thread");
		return EXIT_FAILURE;
	}
	result = pthread_join(thread1, NULL);
	if ( result!=0 ) {
		perror("Join first thread");
		return EXIT_FAILURE;
	}

	result = pthread_join(thread2, NULL);
	if ( result!=0 ) {
		perror("Join second thread");
		return EXIT_FAILURE;
	}
	gettimeofday(&tv, NULL);
	lt = tv.tv_sec;
	ptr = localtime(&lt);
	strftime(str, 30, "%T", ptr);
	printf("\nPid of parent process = %d, time %s:%ld\n", getpid(), str, tv.tv_usec);
//	system("ps -x");
	return 0;
}
