#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "startval.h"

//월별변수지정
void startval(Pmonthval mv, Pcdata cd) {
	int v;

	srand(time(NULL));
	cd->coinvalue = rand() % 100; //코인값

	
		v = (rand() % 100) + 1;
		if (v >= 1 && v <= 30)
			mv->plusvar = 0;
		else if (v >= 31 && v <= 50)
			mv->plusvar = 1;
		else
			mv->plusvar = 2;  //부가가치값

		srand(time(NULL) + 1);
		v = (rand() % 100) + 1;
		if (v >= 1 && v <= 20)
			mv->prosvar = 0;
		else if (v >= 21 && v <= 40)
			mv->prosvar = 1;
		else
			mv->prosvar = 2; //전망값


		srand(time(NULL) + 2);
		mv->afterplus = (rand() % 100) + 1;
		if (v >= 1 && v <= 20)
			mv->afterplus = 0;
		else if (v >= 21 && v <= 40)
			mv->afterplus = 1;
		else
			mv->afterplus = 2;     //통수떡상락값

}

