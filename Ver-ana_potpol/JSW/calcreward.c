#include <stdio.h>
#include "calcreward.h"

//예상수익 계산

int calcreward(Pmonthval mv, Pcdata cd, Pstat st, Pmcvar mc) {
	int reward;
	
	if (cd->coinvalue > cd->cointiming) {
		reward = (100 - cd->coinvalue)*(100 - cd->coinvalue + cd->cointiming)* (100 - cd->coinvalue + cd->cointiming)*(80 - 5 * cd->coincount) / 100000;
	}
	else if (cd->coinvalue <= cd->cointiming) {
		reward = (100 - cd->coinvalue)*(100 + cd->coinvalue - cd->cointiming) *(100 + cd->coinvalue - cd->cointiming) * (80 - 5 * cd->coincount) / 100000;  //이차함수+퍼센테이지 기본수익
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
	for (int v = mc->vpcount; v > 0; v--)
		reward = reward * 4 / 5;																//이때까지 알려준 변수로 수익 조정;통수는 안알려줌
	for (int v = mc->vmcount; v > 0; v--
		)
		reward = reward * 6 / 5;
	return reward;
}
