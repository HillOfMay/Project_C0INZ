#define _CRT_SECURE_NO_WARNINGS
#include "monthloof.h"
#include "endcheck.h"
#include "startval.h"
#include "main_screen.h"
#include "tuto_challenge.h"
#include "space.h"
#include <Windows.h>








int main(){
	
	stat st = { 0, };
	int finish_game=0;
	while (finish_game==0) {

		monthval mv = { 2, };
		cdata cd = { 0, };
		mcvar mc = { 0, };
		st.money = 0;
		st.ifend = 0;
		Pmonthval pmv;
		Pcdata pcd;
		Pstat pst;
		Pmcvar pmc;

		pst = &st;
		pmc = &mc;
		pcd = &cd;
		pmv = &mv;

		
		
		int stsel=0;
		char ift = 0;                    //���� ��� �־����
		
		if (pst->braveplayer) {
			stsel = 1;
			ift = 'n';
		}
		else          
			stsel = main_screen();


		if (stsel == 1) {
			printf("Ʃ�丮���� �����ұ��?(y,n)");
			while (ift != 'y'&& ift != 'n')
				scanf("%c", &ift);
			if (ift == 'y') {
				system("cls"); getchar();
				printf("coins�� �÷��� ���ּż� �����մϴ�!");
				space();
				printf("coins�� �÷��� ���ּż� �����մϴ�!\n\n�� ������ ���� ���忡 ��� ���� ����ڴ� ���ΰ��� �̾߱��̸�,����� �� ���ΰ��� ��Ե� ���ڰ� �� �� �ֵ��� �����ּž� �մϴ�.");
				space();
				printf("coins�� �÷��� ���ּż� �����մϴ�!\n\n�� ������ ���� ���忡 ��� ���� ����ڴ� ���ΰ��� �̾߱��̸�,����� �� ���ΰ��� ��Ե� ���ڰ� �� �� �ֵ��� �����ּž� �մϴ�.\n\n�����ϼ���...������ ������ ���Ӿ��� �ٲ� ���̰�,�ַ� ���Ӿ��� ������ ���Դϴ�.");
				space();
				tuto_challenge(cd, st, mc, pmv, pcd, pst, pmc);
			}
			//����    

			st.money += 3000;

			for (cd.coinmonth = 1; cd.coinmonth <= 100; cd.coinmonth++) {
				system("cls");
				startval(&mv, &cd);
				monthloof(cd, st, mc, pmv, pcd, pst, pmc);
				endcheck(cd, st, pst);
				if (st.ifend == 1) {
					pst->braveplayer = 0;
					system("cls");
					break;
				}
				else if (st.ifend == 2) {
					printf("\n�ٽ� �����Ͻðڽ��ϱ�?(y=1,n=2)\n");
					while (st.ifend != 1 && st.ifend != 2) {
						scanf("%d", &pst->ifend);
					}
					if (st.ifend == 2) {
						finish_game = 1;
						break;
					}
						
					else if (st.ifend == 1) {
						pst->braveplayer = 0;
						system("cls");
						break;
					}
				}
				else if (st.ifend == 3) {
					if (st.clearcount == 1)
						printf("�����մϴ�,������ �������̽ÿ�.������ �ٽ� �����Ͽ�,�̹� ������ ������ �ƴ��� �����Ͻðڽ��ϱ�?\n(y=1,n=2)");
					else if (st.clearcount >= 2)
						printf("�����մϴ�,%d���� �λ��� �����ڷ� �̲� ������ �������̽ÿ�.������ �ٽ� �����Ͽ�,����� �̸��� �θ� ���� �ֽʽÿ�.\n(y=1,n=2):", st.clearcount);
					while (st.ifend != 2 && st.ifend != 1) {
						scanf("%d", &st.ifend);
					}
					if (st.ifend == 2) {
						finish_game = 1;
						break;
					}
					else if (st.ifend == 1) {
						pst->braveplayer = 0;
						system("cls");
						break;
					}
				}
			}
		}                                                                                                   //���Ⱑ ���ӽ���
		if (stsel == 2) {
			system("cls"); getchar();
			printf("coins�� �÷��� ���ּż� �����մϴ�!");
			space();
			printf("coins�� �÷��� ���ּż� �����մϴ�!\n\n�� ������ ���� ���忡 ��� ���� ����ڴ� ���ΰ��� �̾߱��̸�,����� �� ���ΰ��� ��Ե� ���ڰ� �� �� �ֵ��� �����ּž� �մϴ�.");
			space();
			printf("coins�� �÷��� ���ּż� �����մϴ�!\n\n�� ������ ���� ���忡 ��� ���� ����ڴ� ���ΰ��� �̾߱��̸�,����� �� ���ΰ��� ��Ե� ���ڰ� �� �� �ֵ��� �����ּž� �մϴ�.\n\n�����ϼ���...������ ������ ���Ӿ��� �ٲ� ���̰�,�ַ� ���Ӿ��� ������ ���Դϴ�.");
			space();
			tuto_challenge(cd, st, mc, pmv, pcd, pst, pmc);
		}
		if (stsel == 3) {
			printf("������ �����Ͻðڽ��ϱ�?(y=1,n=2):");
			while (st.ifend != 1 && st.ifend != 2) {
				scanf("%d", &st.ifend);
			}
			if (st.ifend == 1) {
				finish_game = 1;
				break;
			}
			else if (st.ifend == 2) {
				pst->braveplayer = 0;
				system("cls");
			}
		}
	}
}







//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






