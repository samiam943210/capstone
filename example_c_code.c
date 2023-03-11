//Author: Sam Dubuc
//This code takes integer input from the user and prints whether or not the number is even

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]) {
	if(argc != 2) {
		printf("Error: incorrect number of arguments\n");
		return 1;
	}
	int num = atoi(argv[1]);
	printf("Your number is: %d\n", num);
	if(num%2 == 0) {
		printf("Your number is even\n");
	} else {
		printf("Your number is odd\n");
	}
	
	return 0;
}
