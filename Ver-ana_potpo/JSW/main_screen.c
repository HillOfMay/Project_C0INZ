#include "main_screen.h"
int main_screen() {
	int out = 0;
	printf("=======================\n     \tC��INs     \t\n=======================\n\n\n");
	printf("1:������ �����մϴ�\n\n");
	printf("2:Ʃ�丮��\n\n");
	printf("3:����\n\n*��üȭ�� �÷��̸� �����մϴ�.ȭ���� �� �÷��ּ���!\n\n");
	while (out>3 || out<1)
		scanf_s("%d", &out);
	return out;
}
//���� ����

