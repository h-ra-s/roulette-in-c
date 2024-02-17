/*
Heather Slanec
Allows user to play a game of roulette repeatedly
Roulette Program
*/

#include<stdio.h>

//function prototypes
void showInstructions();
void makeBet(int *betPtr, int *betNumberPtr, char *oddEvenPtr, int *dozenPtr);
float getBetAmount();
int spinWheel();
float figureWinnings(int bet, int betNumber, int dozen, char oddEven, 
	float betMoney, int spinNumber, char *winLosePtr);

//main------------------------------------------------------------------------
int main()
{
	//declare variable
	float betMoney, postSpinMoney;
	int spinNumber, bet, betNumber, dozen;
	char oddEven, anotherBet, winLose;
	
	do{
		//function call - show instructions
		showInstructions();
		
		//function call - get bet type, send memory location of 'bet'
		makeBet(&bet, &betNumber, &oddEven, &dozen);

		//function call - get bet amount
		betMoney = getBetAmount();
	
		//function call - spin the wheel
		spinNumber = spinWheel();
		
		//function call - calculate money won/lost
		postSpinMoney = figureWinnings(bet, betNumber, dozen, oddEven, 
			betMoney, spinNumber, &winLose);
		
		
		
		//report total money won/lost:
		//if won
		if(winLose == 'W')
			printf("\nYou won $%.2f!", postSpinMoney);
		//if lost
		else	
			printf("\nYou lost $%.2f!", postSpinMoney);

			
			
		//ask if want to bet again
		printf("\nWould you like to play again? Enter Y for Yes or N for No: ");
		scanf("\n%c", &anotherBet);
		
		//validate input
		while(anotherBet != 'Y' && anotherBet != 'y' && anotherBet != 'N' && anotherBet != 'n')
		{
			//get user input:
			printf("\n\nError! Try again.");
			printf("\nWould you like to play again? Enter Y for Yes or N for No: ");
			scanf("\n%c", &anotherBet);
		}
		
		
	}while(anotherBet != 'N' && anotherBet != 'n');
	
	return 0;
}

//functions------------------------------------------------------------------
void showInstructions()
{
	//print instructions
	printf("\nRoulette Rules:");
	printf("\n\nThe roulette wheel has the numbers 0-36 on it. You can place your bet in one of three ways:");
	printf("\n\n1. Bet on a number (payout is 36 times the bet amount)");
	printf("\n2. Bet on an odd or even (payout is 2 times the bet)");
	printf("\n3. Bet on a dozen ~ first 1-12, second 13-24, third 25-36 (payout is 3 times the bet)");
	printf("\n\nNote: The number zero does not count for odd or even or dozen, but can count as a number bet.");
}

//--------------------------------------------------------------------------
void makeBet(int *betPtr, int *betNumberPtr, char *oddEvenPtr, int *dozenPtr)
{
	//variable to hold user input
	int bet;
	
	//get user input:
	printf("\n\nWhat type of bet would you like to make? Enter 1, 2, or 3: ");
	scanf("%d", &bet);
	
	//validate user input
	while(bet != 1 && bet != 2 && bet != 3)
	{
		//get user input:
		printf("\n\nError! Try again.");
		printf("\nWhat type of bet would you like to make? Enter 1, 2, or 3: ");
		scanf("%d", &bet);
	}
	
	//use pointer to return value of function's 'bet' to the 'bet' declared in main
	*betPtr = bet;
	
	
	//if user does bet #1:
	if(bet == 1)
	{
		//declare variable
		int betNumber;
		
		//user input
		printf("\nWhat number would you like to bet on? Choose a number between 0-36: ");
		scanf("%d", &betNumber);
		
		//validate user input
		while(betNumber < 0 || betNumber > 36)
		{
			//get user input:
			printf("\n\nError! Try again.");
			printf("\nWhat number would you like to bet on? Choose a number between 0-36: ");
			scanf("%d", &betNumber);
		}
		
		//use pointer to return value of function's 'bet' to the 'bet' declared in main
		*betNumberPtr = betNumber;
	}
	
	//if user does bet #2
	if(bet == 2)
	{
		//declare variable
		char oddEven;
		
		//user input
		printf("\nWould you like to bet on an even or odd? Enter the letter E for Even, or the letter O for Odd: ");
		scanf("\n%c", &oddEven);
		
		//validate user input
		while(oddEven != 'E' && oddEven != 'e' && oddEven != 'O' && oddEven != 'o')
		{
			//get user input:
			printf("\n\nError! Try again.");
			printf("\nWould you like to bet on an even or odd? Enter the letter E for Even, or the letter O for Odd: ");
			scanf("\n%c", &oddEven);
		}
		
		//use pointer to return value of function's 'bet' to the 'bet' declared in main
		*oddEvenPtr = oddEven;
	}
	
	//if user does bet #3
	if(bet == 3)
	{
		//declare variable
		int dozen;
		
		//user input
		printf("\nWould you like to bet on 1) 1-12, 2) 13-24, or 3) 25-36? Enter 1, 2, or 3: ");
		scanf("%d", &dozen);
		
		//validate user input
		while(dozen != 1 && dozen != 2 && dozen != 3)
		{
			//get user input:
			printf("\n\nError! Try again.");
			printf("\nWould you like to bet on 1) 1-12, 2) 13-24, or 3) 25-36? Enter 1, 2, or 3: ");
			scanf("%d", &dozen);
		}
		
		//use pointer to return value of function's 'bet' to the 'bet' declared in main
		*dozenPtr = dozen;
	}
}

//--------------------------------------------------------------------------
float getBetAmount()
{
	//declare variable
	float betMoney;
	
	//get user input
	printf("\nEnter the amount of money you would like to bet: $");
	scanf("%f", &betMoney);
	
	return betMoney;
}

//-----------------------------------------------------------------------------
int spinWheel()
{
	//declare variable
	int spinNumber;
	
	//starter value for rand
	srand(time(0));
	
	//use rand to generate number 0-36
	//spinNumber = ( rand() % (36 - 0 + 1) ) + 0
	spinNumber = (rand() % 37) + 0;
	
	return spinNumber;	
}

//--------------------------------------------------------------------------
float figureWinnings(int bet, int betNumber, int dozen, char oddEven, 
	float betMoney, int spinNumber, char *winLosePtr)
{
	//initialize variable
	float postSpinMoney = 0;
	
	//if bet type #1 was chosen
	if(bet == 1)
	{
		if(betNumber == spinNumber)
		{
			//if won
			postSpinMoney = betMoney * 36;
			*winLosePtr = 'W';
		}
		else
		{
			//if lost
			postSpinMoney = betMoney;
			*winLosePtr = 'L';
		}
	}
	
	//if bet type #2 was chosen
	else if(bet == 2 ) 
	{
		if ((betNumber%2==0 && spinNumber%2==0) || (betNumber%2==1 && spinNumber%2==1))
		{	//if won using evens or odds
			postSpinMoney = betMoney * 2;
			*winLosePtr = 'W';
		}
		else
		{
			//if lost
			postSpinMoney = betMoney;
			*winLosePtr = 'L';
		}
	}
	
	//if bet type #3 was chosen
	else if(bet==3)
	{
		if(betNumber>=1 && betNumber<=12 && spinNumber>=1 && spinNumber<=12)
		{
			//if won on first 12
			postSpinMoney = betMoney * 3;
			*winLosePtr = 'W';
		}
		else if(betNumber>=13 && betNumber<=24 && spinNumber>=13 && spinNumber<=24)
		{
			//if won on second 12
			postSpinMoney = betMoney * 3;
			*winLosePtr = 'W';
		}
		else if(betNumber>=25 && betNumber<=36 && spinNumber>=25 && spinNumber<=36)
		{
			//if won on third 12
			postSpinMoney = betMoney * 3;
			*winLosePtr = 'W';
		}
		else
		{
			//if lost
			postSpinMoney = betMoney;
			*winLosePtr = 'L';
		}
	}
	
	return postSpinMoney;
}

