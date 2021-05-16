#include <stdio.h>
#include <assert.h>
//模拟实现库函数 :strcpy
char* my_strcpy(char* dst, const char* src) {
	char* cp = dst;
	assert(dst && src);
	while (*dst++ = *src++)
		;
	return cp;
}
void test1() {
	char arr1[] = "I love  you      ";
	char arr2[] = "I not love you ";
	printf("%s\n", my_strcpy(arr1, arr2));

}
int main() {
	test1();
	system("pause");
	return 0;
}