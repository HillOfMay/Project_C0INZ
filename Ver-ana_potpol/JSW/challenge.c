#include "calcreward.h"
#include "returnreward.h"
#include "countval.h"
#include <stdio.h>
#include "space.h"

//������ �Ͼ�� ��

int challenge(cdata cd, stat st, mcvar mc, Pmonthval pmv, Pcdata pcd, Pstat pst, Pmcvar pmc) {
	int v = 0, coincount = 0;
	char select,bl[10];
	pst->money -= 400;                                         //�ڱ�--

	//printf("�ڱ� ��Ȳ:%d", pst->money); //������ڵ�
	for (pcd->coincount = pmv->prosvar == 1 ? 5 : 1; pcd->coincount <= 10; pcd->coincount++) {
		select = 0;

		//////////////////////////////////////////////////////////////////////////////////////////////////////�������̽� ����ϰ�//////////////////////////////////////////////////////////////////////////////////////////////////
		system("cls");	
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
			printf("�������� �����Դϴ�.\n");                                 
		}
		printf("\n�����Ͻðڽ��ϱ�?(���� �ڱ�:%d c)\n1:����(-400)  2:����(-200)  3:����  4:����\n1\n", st.money);
		//////////////////////////////////////////////////////////////////////////////////////////////////////�������̽� ����ϰ�//////////////////////////////////////////////////////////////////////////////////////////////////

		printf("\n�� �Ŀ� üũ�غ����?(1~99):");
		while (pcd->cointiming<1|| pcd->cointiming>99)
			scanf("%d", &pcd->cointiming);
		pcd->cointiming = 100 - pcd->cointiming;
		printf("\n%d��° üũ:������ ������ %dC�� �� �����ϴ�.\n���� ȸ���ұ��?(y,n):", ++coincount, calcreward(pmv, pcd, pst, pmc));        //�����Է¹ް� ������� ���
		while (select != 'y'&& select != 'n')                                         
			scanf("%c", &select);

		if (select == 'y') {                                                                                                                  //ȸ���ϰ� ��������
			v = returnreward(pmv, pcd, pst, pmc);
			printf("\n���� ȸ���߽��ϴ�(+%d C)\n�̹����� ���:%d C\n", v, v - 400);
			pst->money += v;
			printf("\n���� �޷� �Ѿ�ϴ�.\n");
			space();
			return 0;
		}
		else if (select == 'n') {                                                                                                         //������ ���Ǻ��� �������ϰ� �ٽ� �ݺ�
			countval(pmc);
			printf("\n");
			pcd->coinvalue = pcd->coinvalue + 5 - pmc->coinchange;
			if (pmv->prosvar == 1) {
				pcd->coinvalue = pcd->coinvalue + 5 - pmc->coinchange;
			}
			if (pmc->valpm == 1)
				printf("������ ������ ���� ����Դϴ�!\n");
			else if (pmc->valpm == 0)
				printf("������ ������ ������ ����Դϴ�.\n");
			if (pmc->countpm == 1) {
				printf("������ ��ġ�� ���� ����Դϴ�!\n");
				pcd->coincount--;
			}
			else if (pmc->countpm == 0) {
				printf("������ ��ġ�� ������ ����Դϴ�.\n");
				pcd->coincount++;
			}
			//printf("���� ����:%d\n", pcd->coinvalue);  //������ڵ�
			//printf("\n���ݿ���:%d ��ġ����:%d -ī����:%d +ī����:%d ���� ī����:%d ���� Ƚ��:%d\n", pmc->valpm, pmc->countpm, pmc->vmcount, pmc->vpcount, pcd->coincount, coincount); //������ڵ�


		}
		else {																										//����ó��
			printf("\n������ �߻��Ͽ�,�ڵ����� ���� ȸ���մϴ�.�˼��մϴ�.\n");
			v = returnreward(pmv, pcd, pst, pmc);
			printf("���� ȸ���߽��ϴ�(+%d C)\n�̹����� ���:%d C\n", v, v - 400);
			pst->money += v;
			printf("\n���͸� �Է��ϸ� ���� �޷� �Ѿ�ϴ�.\n");
			gets(bl);
			gets(bl);
			return 0;
		}
		if (pcd->coincount >= 10) {																					//üũī��Ʈ�� 10�� ������ �ڵ����� �����޷�
			printf("������ ��ġ�� �ʹ� ������ ����� ���� ȸ���� �� �ۿ� �������ϴ�.\n");
			pcd->coincount += 3;
			v = returnreward(pmv, pcd, pst, pmc);
			printf("\n���� ȸ���߽��ϴ�(+%d C)\n�̹����� ���:%d C\n", v, v - 400);
			pst->money += v;
			printf("\n���� �޷� �Ѿ�ϴ�.\n");
			space();
			return 0;
		}
	}
	return 0;
}

