#include <string.h>
#include "challenge.h"
#include "giveup.h"


//1�������� �ݺ�
int monthloof(cdata cd, stat st, mcvar mc, Pmonthval pmv, Pcdata pcd, Pstat pst, Pmcvar pmc) {
	int name;
	srand(time(NULL));
	name = (rand() % 7) + 1;
	switch (name) {
	case 1:strcpy(cd.coin_name, "��Ʈ����"); break;
	case 2:strcpy(cd.coin_name, "��������"); break;
	case 3:strcpy(cd.coin_name, "����Ʈ����"); break;
	case 4:strcpy(cd.coin_name, "����"); break;
	case 5:strcpy(cd.coin_name, "���ν��ڶ�"); break;
	case 6:strcpy(cd.coin_name, "��Ʈ���� ĳ��"); break;
	case 7:strcpy(cd.coin_name, "�������� Ŭ����"); break;                //�����̸�����
	}
	int ingmsel = 0;
	//printf("\n�����ڿ���:%d ��������:%d\n", pmv->plusvar, pmv->prosvar); //������ڵ�
	printf("%d���� °�Դϴ�.\n==============================\n�̹� ���� ����:%s\n==============================\n", cd.coinmonth, cd.coin_name);
	if (pmv->plusvar == 0) {
		printf("���� �������� �����Դϴ�.\n");
	}
	else if (pmv->plusvar == 1) {
		printf("������ �����Դϴ�.\n");
	}
	if (pmv->prosvar == 1) {
		printf("������ �䵿ġ�� �����Դϴ�.\n");
	}
	else if (pmv->prosvar == 0) {
		printf("�������� �����Դϴ�.\n");                                 //�������� �˸�
	}
	printf("\n�����Ͻðڽ��ϱ�?(���� �ڱ�:%d c)\n1:����(-400)  2:����(-200)  3:����  4:����\n", st.money);
	while (ingmsel>4 || ingmsel<1)
		scanf_s("%d", &ingmsel);
	if (ingmsel == 1) {
		challenge(cd, st, mc, pmv, pcd, pst, pmc);                       //�����Ѵٸ� �����ڵ�;
	}
	else if (ingmsel == 2) {  
		giveup(pmv, pst);                                               //�����ϸ� �����ڵ�;
	}
	else if (ingmsel == 3) {
		printf("������ ���� �غ���� �ʾҽ��ϴ٤���;");  //���߿� �ٽý����
		getchar(); space();
	}
	else if (ingmsel == 4) {
		pst->ifend = 1;
		pst->braveplayer = 0;
	}                                               //�����ϸ� ����ȭ��
	return 0;
}

