#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
void* mymemmove(void* dest, const void* src, size_t count) {
	void* ret = dest;
	assert(dest);
	assert(src);
	if(dest < src) {
		//从前往后拷贝(小端)
		while (count--) {
			*(char*)dest = *(char*)src;
			++(char*)dest;
			++(char*)src;

		}
	}
	else {
		while (count--) {
			//从后往前拷贝
			*((char*)dest + count) = *((char*)src + count);

		}
	}
	return ret;
}
int main() {
	int i = 0;
	int arr1[] = { 1,2,3,4,5,6,7,8,9 };
	mymemmove(arr1+1, arr1, 8);
	for (i = 0; i < 9; i++) {
		printf("%d ", arr1[i]);
	}
	return 0;
}