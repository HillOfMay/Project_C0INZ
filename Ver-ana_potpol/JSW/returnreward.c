#include <stdio.h>
#include "returnreward.h"

//실수익계산
int returnreward(Pmonthval mv, Pcdata cd, Pstat st, Pmcvar mc) {
	int reward;
	if (cd->coinvalue > cd->cointiming) {
		reward = (100 - cd->coinvalue)*(100 - cd->coinvalue + cd->cointiming)* (100 - cd->coinvalue + cd->cointiming)*(80 - 5 * (cd->coincount-1)) / 100000;
	}
	else if (cd->coinvalue <= cd->cointiming) {
		reward = (100 - cd->coinvalue)*(100 + cd->coinvalue - cd->cointiming) *(100 + cd->coinvalue - cd->cointiming) * (80 - 5 * (cd->coincount-1)) / 100000;  //복잡한 수식을 통해 2차함수 기본수익 계산
	}
	if (mv->prosvar == 0)
		reward += 100;
	if (mv->plusvar == 1)
		reward *= 2;
	else if (mv->plusvar == 0)
		reward = reward * 3 / 4;
	if (mv->prosvar == 1)
		reward *= 3;
	else if (mv->prosvar == 0)
		reward /= 2;
	for (mc->vpcount; mc->vpcount > 0; mc->vpcount--)
		reward = reward * 4 / 5;
	for (mc->vmcount; mc->vmcount > 0; mc->vmcount--)         //월별/임시변수에 따른 값 조정
		reward = reward * 6 / 5;
	if (cd->coinvalue == cd->cointiming) {
		printf("\n정확한 타이밍에 큰 이득을 챙겼습니다!\n");
		reward = reward * 3 / 2;
	}
	else if (mv->afterplus == 0) {
		printf("\n코인의 가격이 떡락했습니다...\n");
		reward /= 2;
	}
	else if (mv->afterplus == 1) {
		printf("\n코인의 가격이 떡상했습니다!\n");         //통수변수에 따른 값 조정
		reward *= 2;
	}
	return reward;
}