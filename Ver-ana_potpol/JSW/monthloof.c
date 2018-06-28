#include <string.h>
#include "challenge.h"
#include "giveup.h"


//1스테이지 반복
int monthloof(cdata cd, stat st, mcvar mc, Pmonthval pmv, Pcdata pcd, Pstat pst, Pmcvar pmc) {
	int name;
	srand(time(NULL));
	name = (rand() % 7) + 1;
	switch (name) {
	case 1:strcpy(cd.coin_name, "배트코인"); break;
	case 2:strcpy(cd.coin_name, "엘더리움"); break;
	case 3:strcpy(cd.coin_name, "나이트코인"); break;
	case 4:strcpy(cd.coin_name, "니플"); break;
	case 5:strcpy(cd.coin_name, "코인스텔라"); break;
	case 6:strcpy(cd.coin_name, "배트코인 캐시"); break;
	case 7:strcpy(cd.coin_name, "엘더리움 클래식"); break;                //코인이름지정
	}
	int ingmsel = 0;
	//printf("\n굿투자여부:%d 전망여부:%d\n", pmv->plusvar, pmv->prosvar); //디버깅코드
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
		printf("안정적인 코인입니다.\n");                                 //월별변수 알림
	}
	printf("\n투자하시겠습니까?(현재 자금:%d c)\n1:투자(-400)  2:포기(-200)  3:도움말  4:종료\n", st.money);
	while (ingmsel>4 || ingmsel<1)
		scanf_s("%d", &ingmsel);
	if (ingmsel == 1) {
		challenge(cd, st, mc, pmv, pcd, pst, pmc);                       //투자한다면 투자코드;
	}
	else if (ingmsel == 2) {  
		giveup(pmv, pst);                                               //포기하면 포기코드;
	}
	else if (ingmsel == 3) {
		printf("도움말은 아직 준비되지 않았습니다ㅎㅎ;");  //나중에 다시써야지
		getchar(); space();
	}
	else if (ingmsel == 4) {
		pst->ifend = 1;
		pst->braveplayer = 0;
	}                                               //종료하면 메인화면
	return 0;
}

