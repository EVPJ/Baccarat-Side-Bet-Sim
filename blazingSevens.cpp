// this includes a cut card at 14 cards and plays through the whole shoe
#include <iostream>
#include <cstdlib> //for rand and srand
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

void shuffle(vector<int> array, int length);

// declare consts
const int NUMBER_OF_SIMULATED_SHOES = 100000;
int bankroll = 75000;
int runningCount = 0;
int placedBetBlazing7 = 0;
int burning = 0;
double trueCount = 0;
bool wentBroke = false;

//"Ace", "Two", "Three", "Four","Five", "Six", "Seven", "Eight", "Nine", "Zero"
std::vector<int> shoeCards = {
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	0,
	0,
	0,
	0,
};

int cutCardStatus = 0; // can be either 0"Inside", 1"Outside", 2"Complete"
int bankerWins = 0;
int playerWins = 0;
int tieWins = 0;
int firsttimerun = true;
int wtf = 0;

int playerCardOne = 0;
int playerCardTwo = 0;
int bankerCardOne = 0;
int bankerCardTwo = 0;
int bankerCardThree = -1;
int playerCardThree = -1;
// define starting 2 card totals
int playerTotal = 0;
int bankerTotal = 0;

// return a random card and remove it from the shoe
//
//---------------------DEFAULT--------------
//

// function to return sum of elements
// in an array of size n

int shoeSize()
{
	return shoeCards.size();
}

// return a random card and remove it from the shoe
//
//---------------------DEFAULT--------------
//
int getcard()
{
	int tempCard = shoeCards.front();
	shoeCards.erase(shoeCards.begin());
	if (tempCard < 2)
	{
		runningCount++;
	}
	else if (tempCard > 7)
	{
		runningCount += 2;
	}
	else if (tempCard == 7)
	{
		runningCount -= 6;
	}
	else if (tempCard == 3 || tempCard == 4 || tempCard == 5)
	{
		runningCount--;
	}

	return tempCard;
}
void shuffleShoe()
{
	runningCount = 0;
	shoeCards = {
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		0,
		0,
		0,
		0,

	};
	// srand(time(NULL));

	// for each element in the array, randomly swap it with an element in the
	// array, possibly even itself (it's possible when shuffling a deck of cards
	// that a card ends up in the same spot it started in)

	std::random_shuffle(shoeCards.begin(), shoeCards.end());
	cutCardStatus = 0;
	burning = getcard();
	if (burning == 0)
	{
		burning = 10;
	}

	for (int i = 0; i < burning; i++)
	{
		getcard();
	}
	runningCount = 0;
	if (burning < 2)
	{
		runningCount++;
	}
	else if (burning > 7)
	{
		runningCount += 2;
	}
	else if (burning == 7)
	{
		runningCount -= 6;
	}
	else if (burning == 3 || burning == 4 || burning == 5)
	{
		runningCount--;
	}
}

string returnResult()
{
	if (placedBetBlazing7 > 0)
	{
		if (playerTotal == 7 && bankerTotal == 7 && playerCardThree == -1 && bankerCardThree == -1)
		{
			bankroll += (2525);
		}
		else if (playerTotal == 7 && bankerTotal == 7 && playerCardThree > -1 && bankerCardThree > -1)
		{
			bankroll += (199 * placedBetBlazing7);
		}
	}
	if (playerTotal < bankerTotal)
	{
		playerCardThree = -1;
		bankerCardThree = -1;
		placedBetBlazing7 = 0;
		return "Banker";
	}
	else if (playerTotal > bankerTotal)
	{
		playerCardThree = -1;
		bankerCardThree = -1;
		placedBetBlazing7 = 0;
		return "Player";
	}
	else
	{
		playerCardThree = -1;
		bankerCardThree = -1;
		placedBetBlazing7 = 0;
		return "Tie";
	}

	/*
		cout << "player1: " << playerCardOne;
		cout << "player2: " << playerCardTwo;
		cout << "banker1: " << bankerCardOne;
		cout << "banker2: " << bankerCardTwo;

		cout << "player3: " << playerCardThree;
		cout << "banker3: " << bankerCardThree;
	*/
}

string drawHand()
{
	// define starting 4 cards
	playerCardOne = getcard();
	playerCardTwo = getcard();
	bankerCardOne = getcard();
	bankerCardTwo = getcard();
	// define starting 2 card totals

	playerTotal = ((playerCardOne + playerCardTwo) % 10);
	bankerTotal = ((bankerCardOne + bankerCardTwo) % 10);
	// define return statement

	// check for natural
	if (playerTotal >= 8 || bankerTotal >= 8)
	{
		return (returnResult());
	}
	// continue play if player stands
	else if (playerTotal > 5)
	{
		if (bankerTotal < 6)
		{
			bankerCardThree = getcard();
			bankerTotal = (bankerTotal + bankerCardThree) % 10;
			return (returnResult());
		}
		else
		{
			return (returnResult());
		}
	}
	// continue play if player draws
	else
	{
		playerCardThree = getcard();
		playerTotal = (playerTotal + playerCardThree) % 10;
		if (bankerTotal < 3)
		{
			bankerCardThree = getcard();
			bankerTotal = (bankerTotal + bankerCardThree) % 10;
			return (returnResult());
		}
		else if (bankerTotal == 3)
		{
			if (playerCardThree != 8)
			{
				bankerCardThree = getcard();
				bankerTotal = (bankerTotal + bankerCardThree) % 10;
				return (returnResult());
			}
			else
			{
				return (returnResult());
			}
		}
		else if (bankerTotal == 4)
		{
			if (playerCardThree > 1 && playerCardThree < 8)
			{
				bankerCardThree = getcard();
				bankerTotal = (bankerTotal + bankerCardThree) % 10;
				return (returnResult());
			}
			else
			{
				return (returnResult());
			}
		}
		else if (bankerTotal == 5)
		{
			if (playerCardThree > 3 && playerCardThree < 8)
			{
				bankerCardThree = getcard();
				bankerTotal = (bankerTotal + bankerCardThree) % 10;
				return (returnResult());
			}
			else
			{
				return (returnResult());
			}
		}
		else if (bankerTotal == 6)
		{
			if (playerCardThree > 5 && playerCardThree < 8)
			{
				bankerCardThree = getcard();
				bankerTotal = (bankerTotal + bankerCardThree) % 10;
				return (returnResult());
			}
			else
			{
				return (returnResult());
			}
		}
		else
		{
			return (returnResult());
		}
	}
}
void placeSideBet_blazing7()
{
	if (bankroll < 0)
	{
		wentBroke = true;
	}
	if (runningCount > 0)
	{
		if ((shoeCards.size() / 52) < 1)
		{
			if (runningCount > 5)
			{
				bankroll -= 50;
				placedBetBlazing7 = 50;
			}
		}
		else
		{
			if ((runningCount / (shoeCards.size() / 52)) > 5)
			{
				bankroll -= 50;
				placedBetBlazing7 = 50;
			}
		}
	}
}

int main()
{

	srand(time(0));

	for (int i = 0; i < NUMBER_OF_SIMULATED_SHOES; i++)
	{
		while (cutCardStatus < 1)
		{
			placeSideBet_blazing7();
			string drawnHandForCycle = drawHand();

			if (drawnHandForCycle == "Banker")
			{
				bankerWins++;
			}
			else if (drawnHandForCycle == "Player")
			{
				playerWins++;
			}
			else if (drawnHandForCycle == "Tie")
			{
				tieWins++;
			}
			else
			{
				wtf++;
			}

			if (shoeSize() < 14)
			{

				cutCardStatus++;
			}

			/* cout << "\nplayer1: " << playerCardOne;
			cout << "\nplayer2: " << playerCardTwo;
			cout << "\nbanker1: " << bankerCardOne;
			cout << "\nbanker2: " << bankerCardTwo;

			cout << "\nplayer3: " << playerCardThree;
			cout << "\nbanker3: " << bankerCardThree; */
		}

		shuffleShoe();
	}

	/* 	string drawnHandForCycle = drawHand();
		if (drawnHandForCycle == "Banker")
		{
			bankerWins++;
		}
		else if (drawnHandForCycle == "Player")
		{
			playerWins++;
		}
		else if (drawnHandForCycle == "Tie")
		{
			tieWins++;
		}
		else
		{
			wtf++;
		}
		if (shoeSize() < 14)
		{
			cutCardStatus++;
		}

		cout << "\nplayer1: " << playerCardOne;
		cout << "\nplayer2: " << playerCardTwo;
		cout << "\nbanker1: " << bankerCardOne;
		cout << "\nbanker2: " << bankerCardTwo;

		cout << "\nplayer3: " << playerCardThree;
		cout << "\nbanker3: " << bankerCardThree; */

	cout << "\n banker wins: " << bankerWins;
	cout << "\n player wins: " << playerWins;
	cout << "\n tie wins: " << tieWins;
	cout << "\n wtf: " << wtf;
	cout << "\n total: " << bankerWins + playerWins + tieWins;
	cout << "\n bankroll: " << bankroll;
	cout << "\n went broke: " << wentBroke;
}
