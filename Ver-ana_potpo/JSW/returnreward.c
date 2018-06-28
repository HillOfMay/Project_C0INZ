#include <stdio.h>
#include "returnreward.h"

//�Ǽ��Ͱ��
int returnreward(Pmonthval mv, Pcdata cd, Pstat st, Pmcvar mc) {
	int reward;
	if (cd->coinvalue > cd->cointiming) {
		reward = (100 - cd->coinvalue)*(100 - cd->coinvalue + cd->cointiming)* (100 - cd->coinvalue + cd->cointiming)*(80 - 5 * (cd->coincount-1)) / 100000;
	}
	else if (cd->coinvalue <= cd->cointiming) {
		reward = (100 - cd->coinvalue)*(100 + cd->coinvalue - cd->cointiming) *(100 + cd->coinvalue - cd->cointiming) * (80 - 5 * (cd->coincount-1)) / 100000;  //������ ������ ���� 2���Լ� �⺻���� ���
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
	for (mc->vmcount; mc->vmcount > 0; mc->vmcount--)         //����/�ӽú����� ���� �� ����
		reward = reward * 6 / 5;
	if (cd->coinvalue == cd->cointiming) {
		printf("\n��Ȯ�� Ÿ�ֿ̹� ū �̵��� ì����ϴ�!\n");
		reward = reward * 3 / 2;
	}
	else if (mv->afterplus == 0) {
		printf("\n������ ������ �����߽��ϴ�...\n");
		reward /= 2;
	}
	else if (mv->afterplus == 1) {
		printf("\n������ ������ �����߽��ϴ�!\n");         //��������� ���� �� ����
		reward *= 2;
	}
	return reward;
}