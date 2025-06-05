#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int getInt(void) {
	int i;
	scanf("%d", &i);
	return i;
}

void print(const char* str) {
	printf("%s\n", str);
}

void printInt(int i) {
	printf("%d", i);
}

char* toString(int i) {
	char* str = malloc(20);
	snprintf(str, 20, "%d", i);
	return str;
}