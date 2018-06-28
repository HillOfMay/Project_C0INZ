#include "calcreward.h"
#include "returnreward.h"
#include "countval.h"
#include <stdio.h>
#include "space.h"
#include "tuto_challenge.h"
#include <Windows.h>

//입찰시 일어나는 일

int	tuto_challenge(cdata cd, stat st, mcvar mc, Pmonthval pmv, Pcdata pcd, Pstat pst, Pmcvar pmc) {
	
	int ingmsel = 0,tuto_notlead=0;
	int v = 0, coincount = 0;
	char select=0;
	

	printf("%d개월 째입니다.\n==============================\n이번 달의 코인:%s                              처음 게임을 시작하면,당신의 코인이 눈에 띌 것입니다.\n==============================\n", 1,"튜토리얼 코인" );  
	printf("\n투자하시겠습니까?(현재 자금:%d c)\n1:투자(-400)  2:포기(-200)  3:도움말  4:종료\n", 3000);
	space();
	printf("%d개월 째입니다.\n==============================\n이번 달의 코인:%s\n==============================\n", 1, "튜토리얼 코인");
	printf("\n투자하시겠습니까?(현재 자금:%d c)\n1:투자(-400)  2:포기(-200)  3:도움말  4:종료                              시작 자금으로는 3000C가 주어지며,달마다 기본적으로 400원씩 소모됩니다.\n", 3000);				
	space();
	printf("%d개월 째입니다.\n==============================\n이번 달의 코인:%s\n==============================\n", 1, "튜토리얼 코인");
	printf("\n투자하시겠습니까?(현재 자금:%d c)\n1:투자(-400)  2:포기(-200)  3:도움말  4:종료                              물론,이 코인에 투자했다가 돈만 날릴 것 같으면 그 코인을 포기함으로서 200C를 지불하고 다음 코인으로 넘어갈 수 있습니다.\n", 3000);
	space();
	printf("%d개월 째입니다.\n==============================\n이번 달의 코인:%s\n==============================\n", 1, "튜토리얼 코인");
	printf("\n투자하시겠습니까?(현재 자금:%d c)\n1:투자(-400)  2:포기(-200)  3:도움말  4:종료\n\n안정적인 코인입니다.                              코인마다 각각 4가지의 특성 중 몇개를 보유하게 되는데,이 값이 투자 수익에 영향을 미칩니다.어떤 영향인지는 알아서 추리해보세요!", 3000);
	space();
	
	while (1) {
		ingmsel = 0;
		if (tuto_notlead > 3) {
			printf("오호라,도움말에 따르지 않는 용감한 플레이어시군요!\n그렇다면 그렇게 원하시는 대로,게임 방식은 게임을 하면서 배워보시죠!");
			Sleep(3000);
			system("cls");
			pst->braveplayer = 1;
			printf("%d", pst->braveplayer);
			return 0;

		}
		printf("%d개월 째입니다.\n==============================\n이번 달의 코인:%s\n==============================\n", 1, "튜토리얼 코인");
		printf("\n투자하시겠습니까?(현재 자금:%d c)\n1:투자(-400)  2:포기(-200)  3:도움말  4:종료                             그러면 투자 방법에 대해 설명하죠.1을 눌러보세요!\n\n", 3000);
		while (ingmsel > 4 || ingmsel < 1)
			scanf_s("%d", &ingmsel);
		if (ingmsel == 1) {
			printf("\n얼마 후에 체크해볼까요?(1~99):                             일단 투자하시면,코인의 가격이 뛰는 타이밍에 맞추어 되돌아봐야 합니다.대체로 같은 곡선이라도 나중에 오르는 것이 수익이 높죠.\n한번 입력해보세요!  :");
			scanf("%d", &pcd->cointiming);
			printf("\n%d번째 체크:코인의 가격은 %dC인 것 같습니다.\n돈을 회수할까요?(y,n):\n\n입력하신 타이밍에 거둘 수 있는 수익을 일단 알려드립니다.너무 낮은 것 같으면,다시 타이밍을 맞춰보세요!\n\n하지만 조심하세요...내가 돈을 넣은 코인의 전체적인 가격은 꾸준히 떨어질 것입니다.추가로 올라봤자 일시적일 것이고,추가로 떨어지면 망하는거죠!\n\n참고로 타이밍은 고정되어 있지 않고,시시각각 변한답니다.한번 판단해 보실래요? :", ++coincount, calcreward(pmv, pcd, pst, pmc));
			while (select != 'y'&& select != 'n')
				scanf("%c", &select);
			if (select == 'y') {                                                                                                                  //회수하고 다음으로
				v = returnreward(pmv, pcd, pst, pmc);
				printf("\n돈을 회수했습니다(+%d C)\n이번달의 득실:%d C\n\n돈을 회수하셨군요.좋은 판단인지는 컴퓨터만이 알겠죠.그리고 당신이 알지 못하는 변수는 더 많습니다...", v, v - 400);
				printf("\n튜토리얼은 끝났으니,이제 본 게임에서 한번 굴러 보시죠!\n");
				pst->braveplayer += 1;
				space();
				return 0;
			}
			else if (select == 'n') {                                                                                                         //싫으면 임의변수 재지정하고 다시 반복
				printf("\n코인의 가격이 떨어진 모양입니다.\n");
				printf("코인의 가치가 떨어진 모양입니다.\n");
				printf("\n코인의 가치가 너무 떨어져 당신은 돈을 회수할 수 밖에 없었습니다.(튜토리얼 상,바로 회수합니다)\n");
				v = returnreward(pmv, pcd, pst, pmc);
				printf("\n돈을 회수했습니다(+%d C)\n이번달의 득실:%d C\n", v, v - 400);
				printf("\n걸리셨군요! 너무 오래 시간을 끌면 바로 이렇게 된답니다.물론,이렇게 극단적인 엔딩은 나오지 않지요.\n보시다시피,다시 타이밍을 맞추다 보면 코인의 가격은 요동칠 수 있으니 참고하시고,이제 본 투자를 즐겨 보시죠!");
				pst->braveplayer += 1;
				space();
				return 0;
			}

		}
		else if (ingmsel == 2) {
			printf("전략적인 판단은 나중에 하시고,지금은 투자하는 법에 대해서나 배워봅시다.");
			tuto_notlead++;
			space();
		}
		else if (ingmsel == 3) {
			printf("튜토리얼은 지금 하고있으니,나중에 보도록 하시죠.");
			tuto_notlead++;
			space();
		}
		else if (ingmsel == 4) {
			printf("정말 종료하시려구요?");
			if (tuto_notlead > 5)
				return 0;
			tuto_notlead++;
			space();
		}
	}
	}

