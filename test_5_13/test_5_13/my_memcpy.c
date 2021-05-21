#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
struct stu {
	char name[20];
	int age;
};
void* memcpy(void* dest, const void* src, size_t count) {
	void* ret = dest;
	assert(dest);
	assert(src);
	while (count--) {
		*(char*)dest = *(char*)src;
		++(char*)dest;
		++(char*)src;
	}
	return ret;
}
int main() {
	int i = 0;
	struct stu arr1[] = { {"张三",20},{"李四",30} };
	struct stu arr2[2] = { 0 };
	memcpy(arr2, arr1, sizeof(arr1));
	for (i = 0; i < 2; i++) {
		printf("%s,%d\n", (arr2+i)->name, (arr2+i)->age);
	}
	return 0;
}