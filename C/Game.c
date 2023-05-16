/*
 * Game.c
 *
 *  Created on: 2022年12月28日
 *      Author: User
 */
#ifndef GAME_C_
#define GAME_C_
#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <string.h>
#include "Definitions.h"



int WelcomeMessage()
{
    int choice;
	printf("Welcome to Poker Game my pale!\n");
	printf("Are you ready? (1)Yes (2)No\n");
	scanf("%d", &choice);
	while(choice != 1&&choice !=2)
	{

		printf ("wrong! Please enter 1 or 2!\n");
		fflush(stdin);
		scanf ("%d", &choice);
	}

	return choice;
}



void ShuffleCards(int cards[])
{
	for(int i=51; i>=0; i--)
	{

		int temp;
		int card = rand() %(i + 1);
		temp=cards[card];
		cards[card]=cards[i];
		cards[i]=temp;

	}

}

int Face(int num)
{
	if(num%13 == 0)
	{
		return 13;
	}
	else
	{
		return num%13;
	}
}


void GetName(char name[])
{
  char Last_name[10];
  char space[2]=" ";
  printf("Please input the player's first name (10 characters at most):\n");
  scanf("%10s",name);
  fflush(stdin);
  printf("Please input the player's last name (9 characters at most):\n");
  scanf("%9s",Last_name);
  strcat(name,space);
  strcat(name,Last_name);
  fflush(stdin);
}

Card MapCard(int value){
	Card card;
	card.face = Face(value);
	switch ((value-1)/13){
	case 0:card.suit='S';
	    break;
	case 1:card.suit='H';
	    break;
	case 2:card.suit='D';
	    break;
	case 3:card.suit='C';
	    break;
	}
	return card;
}

#endif /* GAME_C_ */


