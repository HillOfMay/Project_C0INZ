#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "countval.h"

//���Ǻ�������
void countval(Pmcvar pmc) { 
	int v;

	srand(time(NULL));

	v = (rand() % 100) + 1;
	if (v >= 1 && v <= 20) {
		pmc->valpm = 1;
		pmc->vpcount++;       //���� ���
	}
	else if (v >= 21 && v <= 50) {
		pmc->valpm = 0;
		pmc->vmcount++;      //���� �϶�
	}
	else
		pmc->valpm = 2;

	v = (rand() % 100) + 1;
	if (v >= 1 && v <= 15)
		pmc->countpm = 1;       //��ġ ���:�ð����� ������ ��ȭ
	else if (v >= 15 && v <= 35)
		pmc->countpm = 0;       //��ġ �϶�:�ð����� ������ ��ȭ
	else
		pmc->countpm = 2;

	v = (rand() % 10) + 1;
	pmc->coinchange = v;       //�ýð��� ���ݾ� �ٲ�� �ְ�Ÿ�̹�
}

