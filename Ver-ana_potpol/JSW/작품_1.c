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
		char ift = 0;                    //점수 기록 넣어야함
		
		if (pst->braveplayer) {
			stsel = 1;
			ift = 'n';
		}
		else          
			stsel = main_screen();


		if (stsel == 1) {
			printf("튜토리얼을 진행할까요?(y,n)");
			while (ift != 'y'&& ift != 'n')
				scanf("%c", &ift);
			if (ift == 'y') {
				system("cls"); getchar();
				printf("coins를 플레이 해주셔서 감사합니다!");
				space();
				printf("coins를 플레이 해주셔서 감사합니다!\n\n이 게임은 코인 시장에 모든 돈을 꼬라박는 주인공의 이야기이며,당신은 이 주인공이 어떻게든 부자가 될 수 있도록 도와주셔야 합니다.");
				space();
				printf("coins를 플레이 해주셔서 감사합니다!\n\n이 게임은 코인 시장에 모든 돈을 꼬라박는 주인공의 이야기이며,당신은 이 주인공이 어떻게든 부자가 될 수 있도록 도와주셔야 합니다.\n\n조심하세요...코인의 가격은 끊임없이 바뀔 것이고,주로 끊임없이 떨어질 것입니다.");
				space();
				tuto_challenge(cd, st, mc, pmv, pcd, pst, pmc);
			}
			//시작    

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
					printf("\n다시 시작하시겠습니까?(y=1,n=2)\n");
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
						printf("축하합니다,위대한 투자자이시여.여정을 다시 시작하여,이번 성공이 요행이 아님을 증명하시겠습니까?\n(y=1,n=2)");
					else if (st.clearcount >= 2)
						printf("축하합니다,%d명을 인생의 성공자로 이끈 위대한 투자자이시여.여정을 다시 시작하여,당신의 이름을 널리 떨쳐 주십시오.\n(y=1,n=2):", st.clearcount);
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
		}                                                                                                   //여기가 게임시작
		if (stsel == 2) {
			system("cls"); getchar();
			printf("coins를 플레이 해주셔서 감사합니다!");
			space();
			printf("coins를 플레이 해주셔서 감사합니다!\n\n이 게임은 코인 시장에 모든 돈을 꼬라박는 주인공의 이야기이며,당신은 이 주인공이 어떻게든 부자가 될 수 있도록 도와주셔야 합니다.");
			space();
			printf("coins를 플레이 해주셔서 감사합니다!\n\n이 게임은 코인 시장에 모든 돈을 꼬라박는 주인공의 이야기이며,당신은 이 주인공이 어떻게든 부자가 될 수 있도록 도와주셔야 합니다.\n\n조심하세요...코인의 가격은 끊임없이 바뀔 것이고,주로 끊임없이 떨어질 것입니다.");
			space();
			tuto_challenge(cd, st, mc, pmv, pcd, pst, pmc);
		}
		if (stsel == 3) {
			printf("정말로 종료하시겠습니까?(y=1,n=2):");
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






