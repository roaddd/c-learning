#include<stdio.h>
//���������ֽ����С���ֽ���ĸ�����һ��С�������жϵ�ǰ�������ֽ���
int check_sys() {
	int i = 1;
	return *((char*)&i);

}
int main() {
	if (check_sys()) {
		printf("С��\n");
	}
	else {
		printf("���\n");
	}
	return 0;
}