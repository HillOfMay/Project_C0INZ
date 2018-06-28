#include <stdio.h>
#include "giveup.h"

int giveup(Pmonthval pmv, Pstat pst) {
	pst->money -= 200;
	printf("코인에 투자하지 않고 생활비로 200C을 소모하셨습니다.  ");
	if (pmv->afterplus == 0)
		printf("현명하신 판단이었습니다!\n");
	else if (pmv->afterplus == 1)
		printf("어리석으신 판단이었군요.\n");
	printf("당신의 자금:%d C", pst->money);
	return 0;
}
//포기시 수익-200,통수여부 출력