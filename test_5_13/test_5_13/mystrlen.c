#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int my_strlen(const char* str) {
	if (*str == '\0') {
		return 0;
	}
	else
		return 1 + my_strlen(str + 1);
}
//≤‚ ‘
int main1() {
	char arr[] = "abcdefg";
	printf("%d\n", my_strlen(arr));
	return 0;
}