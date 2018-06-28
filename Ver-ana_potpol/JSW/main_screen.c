#include "main_screen.h"
int main_screen() {
	int out = 0;
	printf("=======================\n     \tC●INs     \t\n=======================\n\n\n");
	printf("1:게임을 시작합니다\n\n");
	printf("2:튜토리얼\n\n");
	printf("3:종료\n\n*전체화면 플레이를 권장합니다.화면을 꼭 늘려주세요!\n\n");
	while (out>3 || out<1)
		scanf_s("%d", &out);
	return out;
}
//게임 시작

