#include <stdio.h>
#include "giveup.h"

int giveup(Pmonthval pmv, Pstat pst) {
	pst->money -= 200;
	printf("���ο� �������� �ʰ� ��Ȱ��� 200C�� �Ҹ��ϼ̽��ϴ�.  ");
	if (pmv->afterplus == 0)
		printf("�����Ͻ� �Ǵ��̾����ϴ�!\n");
	else if (pmv->afterplus == 1)
		printf("������� �Ǵ��̾�����.\n");
	printf("����� �ڱ�:%d C", pst->money);
	return 0;
}
//����� ����-200,������� ���