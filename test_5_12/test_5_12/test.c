#include<stdio.h>
int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* pb = arr;
	int(*pa)[10] = &arr;
	printf("%p\n", pb);
	printf("%p\n", pb + 1);
	printf("%p\n", pa);
	printf("%p", pa + 1);
	return 0;
}