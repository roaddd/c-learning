#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct stu {
	char name[20];
	int age;
};
//比较整形
int int_cmp(const int* p1, const int* p2) {
	return *p1 - *p2;
}
//比较浮点型
int float_cmp(const float* p1, const float* p2) {
	if (*p1 > *p2) {
		return 1;
	}
	else {
		return -1;
	}
}
//比较结构体类型(按姓名排)
int struct_cmp_name(const struct stu* p1, const struct stu* p2) {
	return strcmp(p1->name, p2->name);
}
void _swap(char* buf1, char* buf2) {
	int width = (int)(buf2 - buf1);
	int i = 0;
	for (i = 0; i < width; i++) {
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}
void bubble_sort(void* base, int count, int size, int (*cmp)(void* e1, void* e2)) {
	int i=0, j = 0;
	for (i=0; i < count - 1; i++) {
		for (j = 0; j < count - 1 - i; j++) {
			//比较相邻元素大小
			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size)>0) {
				//交换元素
				_swap((char*)base + j * size, (char*)base + (j + 1) * size);
			}
		}
	}
}
void test01() {
	int arr[] = { 1,5,3,2,9 };
	int i = 0;
	bubble_sort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), int_cmp);
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("%d\n", arr[i]);
	}
}
void test02() {
	float arr1[] = { 0.1,0.2,0.9,0.6,0.3 };
	int i = 0;
	bubble_sort(arr1, sizeof(arr1) / sizeof(arr1[0]), sizeof(arr1[0]), float_cmp);
	for (i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++) {
		printf("%f\n", arr1[i]);
	}
}
void test03() {
	struct stu s[3] = { {"zhangsan",30},{"lisi",50},{"wangwu",40} };
	int i = 0;
	int j = 0;
	bubble_sort(s, sizeof(s) / sizeof(s[0]), sizeof(s[0]), struct_cmp_name);
	for (i = 0; i < sizeof(s) / sizeof(s[0]); i++) {
		for (j = 0; j < sizeof(s[i].name); j++) {
			printf("%c", s[i].name[j]);
		}
		printf(" %d\n", s[i].age);
	}
}
int main() {
	//test01();
	//test02();
	//test03();
	char arr[] = "abcdef";
	printf("%d\n", strlen(arr));
	return 0;
}