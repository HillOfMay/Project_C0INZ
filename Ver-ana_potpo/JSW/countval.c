#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "countval.h"

//임의변수지정
void countval(Pmcvar pmc) { 
	int v;

	srand(time(NULL));

	v = (rand() % 100) + 1;
	if (v >= 1 && v <= 20) {
		pmc->valpm = 1;
		pmc->vpcount++;       //가격 상승
	}
	else if (v >= 21 && v <= 50) {
		pmc->valpm = 0;
		pmc->vmcount++;      //가격 하락
	}
	else
		pmc->valpm = 2;

	v = (rand() % 100) + 1;
	if (v >= 1 && v <= 15)
		pmc->countpm = 1;       //가치 상승:시간따른 증감폭 완화
	else if (v >= 15 && v <= 35)
		pmc->countpm = 0;       //가치 하락:시간따른 증감폭 심화
	else
		pmc->countpm = 2;

	v = (rand() % 10) + 1;
	pmc->coinchange = v;       //시시각각 조금씩 바뀌는 최고가타이밍
}

