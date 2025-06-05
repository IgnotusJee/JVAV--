#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int getInt(void) {
	int i;
	scanf("%d", &i);
	return i;
}

void print(const char* str) {
	printf("%s", str);
}

void println(const char* str) {
	printf("%s\n", str);
}

void printInt(int i) {
	printf("%d", i);
}

void printIntln(int i) {
	printf("%d\n", i);
}

char* toString(int i) {
	char* str = malloc(20);
	snprintf(str, 20, "%d%c", i, '\0');
	return str;
}