#include "calcreward.h"
#include "returnreward.h"
#include "countval.h"
#include <stdio.h>
#include "space.h"

//입찰시 일어나는 일

int challenge(cdata cd, stat st, mcvar mc, Pmonthval pmv, Pcdata pcd, Pstat pst, Pmcvar pmc) {
	int v = 0, coincount = 0;
	char select,bl[10];
	pst->money -= 400;                                         //자금--

	//printf("자금 현황:%d", pst->money); //디버깅코드
	for (pcd->coincount = pmv->prosvar == 1 ? 5 : 1; pcd->coincount <= 10; pcd->coincount++) {
		select = 0;

		//////////////////////////////////////////////////////////////////////////////////////////////////////인터페이스 깔끔하게//////////////////////////////////////////////////////////////////////////////////////////////////
		system("cls");	
		printf("%d개월 째입니다.\n==============================\n이번 달의 코인:%s\n==============================\n", cd.coinmonth, cd.coin_name);
		if (pmv->plusvar == 0) {
			printf("투자 적정기의 코인입니다.\n");
		}
		else if (pmv->plusvar == 1) {
			printf("끝물인 코인입니다.\n");
		}
		if (pmv->prosvar == 1) {
			printf("가격이 요동치는 코인입니다.\n");
		}
		else if (pmv->prosvar == 0) {
			printf("안정적인 코인입니다.\n");                                 
		}
		printf("\n투자하시겠습니까?(현재 자금:%d c)\n1:투자(-400)  2:포기(-200)  3:도움말  4:종료\n1\n", st.money);
		//////////////////////////////////////////////////////////////////////////////////////////////////////인터페이스 깔끔하게//////////////////////////////////////////////////////////////////////////////////////////////////

		printf("\n얼마 후에 체크해볼까요?(1~99):");
		while (pcd->cointiming<1|| pcd->cointiming>99)
			scanf("%d", &pcd->cointiming);
		pcd->cointiming = 100 - pcd->cointiming;
		printf("\n%d번째 체크:코인의 가격은 %dC인 것 같습니다.\n돈을 회수할까요?(y,n):", ++coincount, calcreward(pmv, pcd, pst, pmc));        //예상값입력받고 예상수익 계산
		while (select != 'y'&& select != 'n')                                         
			scanf("%c", &select);

		if (select == 'y') {                                                                                                                  //회수하고 다음으로
			v = returnreward(pmv, pcd, pst, pmc);
			printf("\n돈을 회수했습니다(+%d C)\n이번달의 득실:%d C\n", v, v - 400);
			pst->money += v;
			printf("\n다음 달로 넘어갑니다.\n");
			space();
			return 0;
		}
		else if (select == 'n') {                                                                                                         //싫으면 임의변수 재지정하고 다시 반복
			countval(pmc);
			printf("\n");
			pcd->coinvalue = pcd->coinvalue + 5 - pmc->coinchange;
			if (pmv->prosvar == 1) {
				pcd->coinvalue = pcd->coinvalue + 5 - pmc->coinchange;
			}
			if (pmc->valpm == 1)
				printf("코인의 가격이 오른 모양입니다!\n");
			else if (pmc->valpm == 0)
				printf("코인의 가격이 떨어진 모양입니다.\n");
			if (pmc->countpm == 1) {
				printf("코인의 가치가 오른 모양입니다!\n");
				pcd->coincount--;
			}
			else if (pmc->countpm == 0) {
				printf("코인의 가치가 떨어진 모양입니다.\n");
				pcd->coincount++;
			}
			//printf("코인 가격:%d\n", pcd->coinvalue);  //디버깅코드
			//printf("\n가격여부:%d 가치여부:%d -카운터:%d +카운터:%d 투자 카운터:%d 투자 횟수:%d\n", pmc->valpm, pmc->countpm, pmc->vmcount, pmc->vpcount, pcd->coincount, coincount); //디버깅코드


		}
		else {																										//예외처리
			printf("\n오류가 발생하여,자동으로 돈을 회수합니다.죄송합니다.\n");
			v = returnreward(pmv, pcd, pst, pmc);
			printf("돈을 회수했습니다(+%d C)\n이번달의 득실:%d C\n", v, v - 400);
			pst->money += v;
			printf("\n엔터를 입력하면 다음 달로 넘어갑니다.\n");
			gets(bl);
			gets(bl);
			return 0;
		}
		if (pcd->coincount >= 10) {																					//체크카운트가 10을 넘으면 자동으로 다음달로
			printf("코인의 가치가 너무 떨어져 당신은 돈을 회수할 수 밖에 없었습니다.\n");
			pcd->coincount += 3;
			v = returnreward(pmv, pcd, pst, pmc);
			printf("\n돈을 회수했습니다(+%d C)\n이번달의 득실:%d C\n", v, v - 400);
			pst->money += v;
			printf("\n다음 달로 넘어갑니다.\n");
			space();
			return 0;
		}
	}
	return 0;
}

