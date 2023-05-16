/*
 * PlayPoker.c
 *
 *  Created on: 2022年12月28日
 *      Author: User
 */

#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "SingleComparison.h"
#include <string.h>
#include "Definitions.h"


int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
    Card dcard;
    Card pcard;

	int choice = WelcomeMessage();
	char name[21];
    int position=0,dealer, player;

	if(choice ==1)
	{

		GetName(name);
		printf("Hello %s\n", name);
		fflush(stdin);
		puts ("Let's  started!\n please select A, B, or C:");
		char selection ='A';
        int cards[52];
        for (int i=0;i<52;++i){
        	cards[i]=i+1;
        }
		while (selection!='C'){
		MenuSelection(&selection);
		switch(selection)
		{

			case 'A':
				printf("Card shuffled!\n");
				position=0;

				for(int i=0; i<=51; ++i)
				{
					cards[i]=i+1;
				}

				ShuffleCards(cards);
				for(int j=0;j<=51; j++)
				{
					if((j+1)%13==0)
					{
						printf("%d(%d)\n", cards[j], Face(cards[j]));
					}
					else
					{
						printf("%d(%d) ", cards[j], Face(cards[j]));
					}
				}
				break;
			case 'B':
				printf("Deal cards!\n");
			    Deal1Card( cards,&position, &dealer,&player);

				printf("Deal card!");
				printf("The dealer's card is %d(%d)\n",dealer, Face(dealer));
				printf("The player's card is %d(%d)\n",player, Face(player));
                printf("%d cards left.",52-position);
                fflush(stdin);
                if(position==52)
                   position=0;
                dcard = MapCard(dealer);
                pcard = MapCard(player);
                int k = Winner(dcard,pcard);
                if(k==0){
                	printf("%s lose\n",name);
                }
                else{
                	printf("%s win\n",name);
                }
				break;

			case 'C':
				printf("See you next time!\n");
				break;
			default:
				printf("Wrong selection!\n");
				break;
		}
		}
	}
	else if(choice ==2){
		puts ("end\n");
	}
	return 0;
}

