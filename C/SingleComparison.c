/*
 * SingleComparison.c
 *
 *  Created on: 2022年12月28日
 *      Author: User
 */
#ifndef SINGLECOMPARISION_C_
#define SINGLECOMPARISION_C_
#include <stdio.h>
#include <stdlib.h>
#include "SingleComparison.h"
#include "Definitions.h"

void MenuSelection(char *select){
	printf("Select your choice!\n");
	printf("A) shuffle Cards\n");
	printf("B) play Game\n");
	printf("c)Exit Game\n");
	fflush(stdin);
	*select = getchar();
}
void Deal1Card(const int * const cards,int *position, int *dealer, int *player)
{
*dealer=cards[*position];
*player=cards[*position+1];
*position+=2;
}
int Winner(Card dcard,Card pcard)
{
	if(pcard.face ==1)
	{
		if(dcard.face!=1)
		{
			return 1;
		}
		else
		{
			if(dcard.suit>pcard.suit)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
	}
	else if(dcard.face==1)
	{
		if(pcard.face!=1)
		{
		return 0;
		}
		else
		{
			if(dcard.suit>pcard.suit)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
	}
	else{
	if(dcard.face>pcard.face){
		return 0;
	}
	if(dcard.face<pcard.face){
		return 1;
	}
	else{
		if(dcard.suit>pcard.suit)
			return 0;
		else
		return 1;
	}
  }
}
#endif /*SINGLECOMPARISION_C_*/

