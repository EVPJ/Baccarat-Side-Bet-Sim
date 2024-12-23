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
const int NUMBER_OF_SIMULATED_SHOES = 1000000;

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
	return tempCard;
}
void shuffleShoe()
{
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
	int burning = getcard();
	if (burning == 0)
	{
		getcard();
		getcard();
		getcard();
		getcard();
		getcard();
		getcard();
		getcard();
		getcard();
		getcard();
		getcard();
	}
	else
	{
		for (int i = 0; i < burning; i++)
		{
			getcard();
		}
	}
}

string returnResult()
{

	if (playerTotal < bankerTotal)
	{
		return "Banker";
	}
	else if (playerTotal > bankerTotal)
	{
		return "Player";
	}
	else
	{
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

int main()
{
	srand(time(0));

	for (int i = 0; i < NUMBER_OF_SIMULATED_SHOES; i++)
	{
		while (cutCardStatus < 1)
		{
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
}
