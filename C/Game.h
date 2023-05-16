/*
 * Game.h
 *
 *  Created on: 2022年12月28日
 *      Author: User
 */

#ifndef GAME_H_
#define GAME_H_
#include "Definitions.h"

void GetName(char name[]);
int WelcomeMessage();
int Face(int a);
void ShuffleCards(int cards[]);

Card MapCard(int value);

#endif /* GAME_H_ */
