/*
Name: Pierre Vincent C. Hernandez
ID: 12043656
Section: S11B
*/

/*
Speifications:
This program was ran on a Windows 10 OS
Suggested screen width: at least 165 characters can fit on the screen
Suggested screen length: games output could extend from approximately 30 - 80 characters in length

This game contains flashing of lights and colors, so people that are sensitive to this type of visuals should be cautious or 
just avoid this game to avoid complications
*/


#include <dos.h> // delays
#include <stdio.h>	//standard input / output
#include <stdlib.h>	//for random numbers
#include <time.h> // time as a seed for the random number
#include <string.h> //string duplicating purpose

#define PHV 216 // parallel horizontal lines with single vertical line
#define R 214 // title top right design
#define PVH 215 // parallel vertical lines with single horizontal line
#define L 190 // title bottom leftdesign

#define V 186 // vertical lines for box
#define H 205 // horizontal lines for box
#define UR 187 // upper-right corner for box
#define LR 188 // lower-right corner for box
#define UL 201 // upper-left corner for box
#define LL 200 // lower-left corner for box
#define HD 196 // horizontal divider 
#define VD 179 // vertical divider 

#define S 36 // dollar sign
#define CM 176 // clear minds icon
#define C 177 // calming icon
#define EB 178 // energy booster icon
#define LEO 233 // lemon oil icon
#define LAO 235 // lavander oil icon
#define RO 229 // rosemary oil icon
#define MO 232 // mint oil icon
#define B 248 // bubble-like effect
#define T 46 //"." // twinkle twinkle little star

#define DIFFUSER_OIL_PREMIUM_RATE 15	//diff oil premium rate
#define LOAN_SHARK_RATE 10	//loan shark rate

//possible improvement/s: 
//instead of assigning a strings in every const char* variable in a function, it could be assigned as a constant(#define)
//instead of passing the character icons in the parameter of each function, it should be called in the function directly since it is a constant(#define)


// system("Color F3") - main game color


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: prints the cIcon every nSpacing characters from nStart to nEnd
Parameters: 
	nStart - the starting value of the increment
	nEnd - the ending value of the increment
	cIcon - type of character to be printed
	nSpacing - the interval of printing characters
Return value: (void) prints a series of cIcon base on nStart, nEnd, and nSpacing
*/
void displayFloatingIcons(int nStart, int nEnd, char cIcon, int nSpacing)
{
	int x;
 	
 	for(x = nStart; x <= nEnd; x++)
 	{
 		if(x % nSpacing == 0)		//prints on and every nSpacing from the last printed character
 			printf("%c", cIcon);
 			
 		else 
 			printf(" ");
	}
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays a header underline
Parameters: none
Rerurn value: (void) prints an underline for the menu header
*/
void displayHeaderUnderline()
{
	printf("%63c", UR);
	displayFloatingIcons(1, 33, H, 1);
	printf("%c\n", UL);		//total: 35 characters	
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays a divider at the bottom part of the game when scanning a letter
Parameters: none
Rerurn value: (void) prints the divider for choosing a letter of action
*/
void displayLetterScanDivider()
{
	printf("\nEnter 0 to go back/cancel");
	printf("\n%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c",
		PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH); //15 characters w/ 3 spaces in between
	printf("%6c", LR);
	displayFloatingIcons(1, 27, H, 1);	//27 characters
	printf("%c", LL);
	printf("%6c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c\n",
		PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH);	//15 characters w/ 3 spaces in between
	printf("%91s", "Choose letter of action: ");
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays a divider at the bottom part of the game when scanning numbers
Parameters: none
Rerurn value: (void) prints the divider for money or number transaction
*/
void displayAmountScanDivider()
{
	printf("\nEnter 0 to go back/cancel");
	printf("\n%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c",
		PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH);
	printf("%6c", LR);
	displayFloatingIcons(1, 27, H, 1);	//27 characters
	printf("%c", LL);
	printf("%6c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c\n",
		PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH);
	printf("%80s", "Enter amount: ");
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the upper part of choice boxes in the game
Parameters: none
Rerurn value: (void) prints the upper choice box
*/
void displayUpperUniversalChoiceBox()
{
	printf("%40c", UR);
	displayFloatingIcons(1, 80, H, 1); //80 characters
	printf("%c\n", UL);	//total: 82 characters
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the lower part of choice boxes in the game
Parameters: none
Rerurn value: (void) prints the lower choice box
*/
void displayLowerUniversalChoiceBox()
{
	printf("%40c", LR);
	displayFloatingIcons(1, 80, H, 1); //80 characters
	printf("%c\n\n", LL);	//total: 82 characters
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays invalid input note for the user
Parameters: none
Rerurn value: (void) prints a notification of invalid input for the user 
*/
void displayInvalidInputNote()
{
	printf("\n%95s\n", "INVALID LETTER OR AMOUNT INPUT");
	printf("%91s\n", "PLEASE WAIT TO REFRESH");
	printf("\a");
	sleep(2);	// 2 sec delay
	system("CLS");
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/



/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the amount of money(nTypeOfMoney)
Parameters: 
	nTypeOfMoney - type of money such as cash, debt or loan
Rerurn value: (void) prints the nTypeOfMoney in a specific format
*/
void displayMoney(int nTypeOfMoney)
{
	if (nTypeOfMoney >= 1000)
		printf("%3d,%03d", nTypeOfMoney / 1000, nTypeOfMoney % 1000);	//7 characters 
	else
		printf("%7d", nTypeOfMoney);	//7 characters 
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the price(nPriceOfProduct) of essential and diffuser oils per bottle
Parameters: 
	nPriceOfProduct - price of an oil per bottle
Rerurn value: (void) prints the nPriceOfProduct in a specific format
*/
void displayPrice(int nPriceOfProduct)
{
	if (nPriceOfProduct >= 1000)
		printf("%3c%2d,%03d/btl", S, nPriceOfProduct / 1000, nPriceOfProduct % 1000);  // 13 characters
	else
		printf("%3c%6d/btl", S, nPriceOfProduct);	// 13 characters
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the price(nProductPrice) of city essential oils per drop
Parameters: 
	nProductPrice - price of a city essential oil per drop
Rerurn value: (void) prints the nProductPrice in a specific format
*/
void displayDropPrice(int nProductPrice)
 {
 	if (nProductPrice >= 1000)
		printf("(%c%d,%03d/drp)", S, nProductPrice / 1000, nProductPrice % 1000);   // 12 characters
	else
		printf("(%c%5d/drp)", S, nProductPrice);	// 12 characters
 }	//P
 
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the selling price(nPriceOfProduct) of essential oils per drop
Parameters: 
	nPriceOfProduct - selling price of an essential oil per drop
Rerurn value: (void) prints the nPriceOfProduct in a specific format
*/
void displayEssOilSellPrice(int nPriceOfProduct)
{
	if (nPriceOfProduct >= 1000)
		printf("%3c%2d,%03d/drp", S, nPriceOfProduct / 1000, nPriceOfProduct % 1000);  // 13 characters
	else
		printf("%3c%6d/drp", S, nPriceOfProduct);	// 13 characters
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: changes and updates the sales trip span by or to nNumberOfDays days
Parameters: 
	nNumberOfDays - the amount of the days the player entered for the new sales trip span
	*nNumOfTravelDays - the sales trip span and where the new sales trip span will be stored
Rerurn value: (void) updates the *nNumOfTravelDays by or to nNumberOfDays
*/
void displaySettingsMenu(int nNumberOfDays, int *nNumOfTravelDays)
{
	system("Color 0A");
	
	int nDaysAmount = 0;
	
	char cSettingsLetter;

	do
	{
		printf("\n\n\n\n%71c%13s%5c\n", PVH, "SETTINGS", PHV);	
		displayHeaderUnderline();
		printf("\n%85s%2d Days\n", "Sales Trip Span: ", *nNumOfTravelDays);
		printf("\n");
		printf("%90s\n%89s\n%89s\n\n\n", "FREEBIE CHANCE RATE:", "ESSENTIAL OIL - 40%", "DIFFUSER OIL - 30%");
		displayUpperUniversalChoiceBox();
		printf("%40c%52s%29c\n", V, "D. CHANGE SALES TRIP SPAN", V);
		displayLowerUniversalChoiceBox();
	
		displayLetterScanDivider();
		
		scanf(" %c", &cSettingsLetter);
		
		switch (cSettingsLetter)
		{
			case 'D' :
				displayAmountScanDivider();
		
				scanf("%d", &nDaysAmount);
			
				if (nDaysAmount <= nNumberOfDays && nDaysAmount != 0 || nDaysAmount > 30)	//if input is more than 30 days or a negative input
				{
					printf("\n%101s\n", "SALES TRIP CAN ONLY LAST UP TO 30 DAYS ONLY");
					displayInvalidInputNote();
				}
					
					
				else
				{
					if (nDaysAmount > nNumberOfDays)
					{
						*nNumOfTravelDays = nDaysAmount;	//changes sales trip span by entered input
						system("CLS");
					}
							
					if (nDaysAmount == 0)	//cancels the changing of sales trip span 
						system("CLS");
				}
				break;
				
			case '0' :
				system("CLS");	
				break;
				
			default:
				displayInvalidInputNote();
				break;
		}
	}
	while (cSettingsLetter != '0');	
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays a raining-like effect of dollar signs to notify that the player had a transcaction related to money
Parameters: none
Rerurn value: (void) prints series of dollar signs/characters
*/
void displayTransactTransition()
{
	system("CLS");
	
	system("Color 20");
	printf("\n");
	displayFloatingIcons(0, 160, S, 10);
	printf("\n\n\n");
	displayFloatingIcons(5, 160, S, 10);
	printf("\n\n\n");
	displayFloatingIcons(0, 160, S, 10);
	printf("\n\n\n");
	printf("\a");	//alert sound to notify that player made a transaction
	
	system("Color 0A");
	displayFloatingIcons(5, 160, S, 10);
	printf("\n\n\n");
	displayFloatingIcons(0, 160, S, 10);
	printf("\n\n\n");
	displayFloatingIcons(5, 160, S, 10);
	printf("\n\n\n");
		
	system("Color 20");
	displayFloatingIcons(0, 160, S, 10);
	printf("\n\n\n");
	displayFloatingIcons(5, 160, S, 10);
	printf("\n\n\n");
	displayFloatingIcons(0, 160, S, 10);
	printf("\n\n\n");
		
	system("Color 0A");
	displayFloatingIcons(5, 160, S, 10);
	printf("\n\n\n");
	displayFloatingIcons(0, 160, S, 10);
	printf("\n\n\n");
	displayFloatingIcons(5, 160, S, 10);
	printf("\n\n\n");
	
	system("CLS");
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the stock-on-hand count/inventory of the player's essential and diffuser oils
Parameters: 
	cOilIcon1 - character icon for lemon
	cOilIcon2 - character icon for lavender
	cOilIcon3 - character icon for rosemary
	cOilIcon4 - character icon for mint
	cClearMindOil - character icon for clear minds
	cCalmingOil - character icon for calming
	cEnergyBoosterOil - character icon for energy booster
	*ccOilName1 - string for lemon
	*ccOilName2 - string for lavender
	*ccOilName3 - string for rosemary
	*ccOilName4 - string for mint
	nHandDrops1 - drop count of lemon
	nHandDrops2 - drop count of lavender
	nHandDrops3 - drop count of rosemary
	nHandDrops4 - drop count of  mint
	nClearMindsBtls - bottle count for clear minds
	nCalmingBtls - bottle count for calming
	nEnergyBoosterBtls - bottle count for energy booster
Rerurn value: (void) prints the remaining stock-on-hand oils of the player
*/
void displayRemainingStockOnHand(char cOilIcon1, char cOilIcon2, char cOilIcon3, char cOilIcon4,
	char cClearMindOil, char cCalmingOil, char cEnergyBoosterOil,
	const char *ccOilName1, const char *ccOilName2, const char *ccOilName3, const char *ccOilName4, 
	int nHandDrops1, int nHandDrops2, int nHandDrops3, int nHandDrops4,
	int nClearMindsBtls, int nCalmingBtls, int nEnergyBoosterBtls)
{
	printf("%c", UR);
	displayFloatingIcons(1, 62, H, 1);
	printf("%c\n", UL);	//total: 64 characters
	
	printf("%c%2c%9s - [drp/s:%4d]", V, cOilIcon1, ccOilName1, nHandDrops1);	//26	//lemon
	printf("%7c%9s - [drp/s:%4d]%6c\n", cOilIcon2, ccOilName2, nHandDrops2, V);	//30	//lavender
	
	printf("%c%2c%9s - [drp/s:%4d]", V, cOilIcon3, ccOilName3, nHandDrops3);	//rosemary
	printf("%7c%9s - [drp/s:%4d]%6c\n", cOilIcon4, ccOilName4, nHandDrops4, V);		//mint
	
	printf("%c%2c%4s[btl/s:%4d]%5c%4s[btl/s:%4d]%5c%4s[btl/s:%4d]%3c\n",
		 V, cClearMindOil, "CMO:", nClearMindsBtls, cCalmingOil, "CO:", nCalmingBtls, cEnergyBoosterOil, "EBO:", nEnergyBoosterBtls, V);
	
	printf("%c", LR);
	displayFloatingIcons(1, 62, H, 1);
	printf("%c\n", LL);	//total: 64 characters
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/




/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: computes the maximum bottle buy count for essential oil base on stocks and player's cash
Parameters: 
	nCash - shows the cash of the player
	nAvailableOilStock - the available stock that can be bought
	nOilPrice - the price of the essential oil
Return value: (int) returns 0 if oil is unavailable; returns a positive integer depending on the player's capability to buy and city stocks
*/
int getMaxBuy(int nCash, int nAvailableOilStock, int nOilPrice)
{
	if (nAvailableOilStock == 0)		//if stock = 0
		return 0;
		
	else 
	{
		if (nCash / nOilPrice > nAvailableOilStock)		//if Max > Stock; Max = stock
			return nAvailableOilStock;
		
		else												
			return nCash / nOilPrice;		//Stock >= Max; Max = cash / oil price
	}
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: distributes the maximum oil buy count per types of essential oil
Paramaters:
	nCurrentCash - remaining cash of the player
	*nMaxOilBuy1 - where the maximum buy count of lemon will be stored
	nOilAvailableStock1 - available stock of lemon
	nOilPrice1 - buy price of lemon
	*nMaxOilBuy2 - where the maximum buy count of lavender will be stored
	nOilAvailableStock2 - available stock of lavender
	nOilPrice2 - buy price of lavender
	*nMaxOilBuy3 - where the maximum buy count of rosemary will be stored
	nOilAvailableStock3 - available stock of rosemary
	nOilPrice3 - buy price of rosemary
	*nMaxOilBuy4 - where the maximum buy count of mint will be stored
	nOilAvailableStock4 - available stock of mint
	nOilPrice4 - buy price of mint
Return value: (void) updates the *nMaxOilBuy1 - *nMaxOilBuy4 using the function getMaxBuy()
*/
void distributeMaximumOilBuyCount(int nCurrentCash, 	
	int *nMaxOilBuy1, int nOilAvailableStock1, int nOilPrice1,	
	int *nMaxOilBuy2, int nOilAvailableStock2, int nOilPrice2,
	int *nMaxOilBuy3, int nOilAvailableStock3, int nOilPrice3,
	int *nMaxOilBuy4, int nOilAvailableStock4, int nOilPrice4)
{
	*nMaxOilBuy1 = getMaxBuy(nCurrentCash, nOilAvailableStock1, nOilPrice1);
	
	*nMaxOilBuy2 = getMaxBuy(nCurrentCash, nOilAvailableStock2, nOilPrice2);
	
	*nMaxOilBuy3 = getMaxBuy(nCurrentCash, nOilAvailableStock3, nOilPrice3);
	
	*nMaxOilBuy4 = getMaxBuy(nCurrentCash, nOilAvailableStock4, nOilPrice4);
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: issues the effects of buying essential oil/s on the player's cash and stock-on-hand, and the city's stocks
Parameters:
	nBuyCount - number of bottles the player bought
	*nCash - cash will be deducted by how much was spent on the purcahse
	*nCityStock - stock count of the essential oil will be deducted by the nBuyCount
	nCityPrice - price of the essential oil per bottle that will be deducted on the player's cash
	nCityDropPrice - drop price of the essential oil that will be added to the player's stock-on-hand drop count
	*nHandDrops - number of drops the player has, and where the newly aquired drops will be stored
	*nHandTotalPrice - total price of all the purchased drops of oil; will be used for getting the average
	*nHandAverageDropPrice - average drop price of the stock-on-hand oil of the player
Return value: (void) updates the *nCash and *nCityStock by deducting the amount and price of the bought oil to it, and 
						updates the stock-on-hand status of the player with the newly aquired oil
*/
void issuePurchaseEffects(
	int nBuyCount, int *nCash, 
	int *nCityStock, int nCityPrice, int nCityDropPrice,
	int *nHandDrops, int *nHandTotalPrice, int *nHandAverageDropPrice)
{
	//drops purchased
	int nTotalBuyDropCount = nBuyCount * 10;
	
	//total purchased drop price
	int nTotalBuyDropPrice = nCityDropPrice * nTotalBuyDropCount;
	
	//total price of purchased bottle
	int nTotalBuyPrice = nCityPrice * nBuyCount;
	
	//update remaining city ess oil stock
	*nCityStock -= nBuyCount;
	
	//update ess oil drops stock-on-hand
	*nHandDrops += nTotalBuyDropCount;
	
	//update total price of ess oil stock-on-hand
	*nHandTotalPrice += nTotalBuyDropPrice;
	
	//update average drop price on-hand
	*nHandAverageDropPrice = *nHandTotalPrice / *nHandDrops;
	
	//subtract total price of purchased bottle to cash
	*nCash -= nTotalBuyPrice;
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: determines if the chosen oil is available/can be purchased, 
			if yes it asks for the amount of bottles to be bought and calls issuePurchaseEffects() function, 
			if not it will display an inavild note 
Parameters: 
	nEssOilMaxBuy - used to determine if player is capable of buying the oil
	*nCash - remaining cash of the player
	*nCityStock - available stock of the essential oil
	nCityPrice - city's essential oil price per bottle
	nCityDropPrice - city's essential oil drop price
	*nHandDrops - player's essential oil drop count
	*nHandTotalPrice - player's essential oil total price
	*nHandAverageDropPrice - player's essential oil average drop price
Return value: (void) if player is incapable of buying the chosen oil then it does nothing;
					if player is capable, it updates the city's remaining stock count, and the player's cash, and stock-on-hand status
*/
void executeBuyChoice(
	int nEssOilMaxBuy, int *nCash,
	int *nCityStock, int nCityPrice, int nCityDropPrice,
	int *nHandDrops, int *nHandTotalPrice, int *nHandAverageDropPrice)	
{
	int nPurchaseAmount = 0;
				
	if (nEssOilMaxBuy == 0)		//when player is incapable of buying due to insufficient cash / stock
		displayInvalidInputNote();
					
	else 
	{
		displayAmountScanDivider();
		scanf("%d", &nPurchaseAmount);
					
		if (nPurchaseAmount < 0 || nPurchaseAmount > nEssOilMaxBuy)	//when invalid input
				displayInvalidInputNote();
		
		else 
		{
			if (nPurchaseAmount > 0 && nPurchaseAmount <= nEssOilMaxBuy) //when valid input
			{
				issuePurchaseEffects(
					nPurchaseAmount, &*nCash,
					&*nCityStock, nCityPrice, nCityDropPrice,
					&*nHandDrops, &*nHandTotalPrice, &*nHandAverageDropPrice);
				
				displayTransactTransition();
			}
				
			else				//when canceling transaction
				system("CLS");
		}	
	}
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the avaiable buy choice for the player to choose and buy; makes it easy for the player which oils can be bought
Parameters: 
	cOilIcon - character icon of the essential oil
	*ccOilName - name of the essential oil
	nCityStockPrice - city price of the essential oil per bottle
	nCityDropPrice - city price of the essential oil per drop
	nCityStock - current stock count of the essential oil in the city
	nMaximumPurchBottle - maximum bottle count that the player could buy
	cLetter - designated letter of the essential oil; player will use the letters/characters for choosing action
Return value: (void) prints nothing if player is incapable of buying (nMaximumPurchBottle = 0);
					if capable, prints the specified letter for oil, name of oil, and its price and stock info
*/
void displayEssOilBuyProducts(char cOilIcon, const char *ccOilName, int nCityStockPrice, int nCityDropPrice, int nCityStock, 
	int nMaximumPurchBottle, char cLetter)
{
	if (nCityStock >= 1)
		{
			displayUpperUniversalChoiceBox();
			printf("%40c%2c. %2c%9s",  V, cLetter, cOilIcon, ccOilName);	//16characters
			displayPrice(nCityStockPrice);	//13 characters
			printf(" "); //1 character
			displayDropPrice(nCityDropPrice);	//12 characters
			printf(" [btls:%4d][10drps/btl] [max buy:%3d]%2c\n", nCityStock, nMaximumPurchBottle, V); 	//40 characters 
			displayLowerUniversalChoiceBox();
		}		// total: 82 characters			
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the buy choices/essential oils that the player could buy; passes the updated city stock count, and player's stock-on-hand status
Parameters: 
	*nCurrentCash - remaining cash of the player
	*ccLemonOil - string for lemon 
	*ccLavenderOil - string for lavender 
	*ccRosemaryOil - string for rosemary 
	*ccMintOil - string for mint  
	*ccClearMindsOil - string for clear minds 
	*ccCalmingOil - string for calming 
	*ccEnergyBoosterOil - string for energy booster 
	cLemonIcon - character icon for lemon
	cLavenderIcon - character icon for lavender
	cRosemaryIcon - character icon for rosemary
	cMintIcon - character icon for mint
	cCMIcon - character icon for clear minds
	cCIcon - character icon for calming
	cEBIcon - character icon for energy booster 
	*nLemonCityStock - city stock count of lemon
	nLemonCityPrice - city price per bottle of lemon
	nLemonCityDropPrice - city price per drop of lemon
	*nLemonHandDrops - stock-on-hand drops of lemon
	*nLemonAverageDropPriceOnHand - stock-on-hand average drop price of lemon
	*nLemonTotalHandPrice - stock-on-hand total price of lemon
	*nLavenderCityStock - city stock count of lavender
	nLavenderCityPrice - city price per bottle of lavender
	nLavenderCityDropPrice - city price per drop of lavender
	*nLavenderHandDrops - stock-on-hand drops of lavender
	*nLavenderAverageDropPriceOnHand - stock-on-hand average drop price of lavender
	*nLavenderTotalHandPrice - stock-on-hand total price of lavender
	*nRosemaryCityStock - city stock count of rosemary
	nRosemaryCityPrice - city price per bottle of rosemary
	nRosemaryCityDropPrice - city price per drop of rosemary
	*nRosemaryHandDrops - stock-on-hand drops of rosemary
	*nRosemaryAverageDropPriceOnHand - stock-on-hand average drop price of rosemary
	*nRosemaryTotalHandPrice - stock-on-hand total price of rosemary
	*nMintCityStock - city stock count of mint
	nMintCityPrice - city price per bottle of mint
	nMintCityDropPrice - city price per drop of mint
	*nMintHandDrops - stock-on-hand drops of mint
	*nMintAverageDropPriceOnHand - stock-on-hand average drop price of mint
	*nMintTotalHandPrice - stock-on-hand total price of mint
	nClearMindsStock - stock-on-hand bottle count of clear minds
	nCalmingStock - stock-on-hand bottle count of calming
	nEnergyBoosterStock - stock-on-hand bottle count of energy booster 
Return value: (void) updates the city's stocks, and the player's stock-on-hand status when player made a purchase or buy transaction
*/
void displayBuyMenu(
	int *nCurrentCash, 
	 
	const char *ccLemonOil, const char *ccLavenderOil, const char *ccRosemaryOil, const char *ccMintOil,	
	const char *ccClearMindsOil, const char *ccCalmingOil, const char *ccEnergyBoosterOil,
	
	char cLemonIcon, char cLavenderIcon, char cRosemaryIcon, char cMintIcon,
	char cCMIcon, char cCIcon, char cEBIcon,
	
	int *nLemonCityStock, int nLemonCityPrice, 
	int nLemonCityDropPrice,
	int *nLemonHandDrops, int *nLemonAverageDropPriceOnHand,
	int *nLemonTotalHandPrice,
	
	int *nLavenderCityStock, int nLavenderCityPrice, 
	int nLavenderCityDropPrice,
	int *nLavenderHandDrops, int *nLavenderAverageDropPriceOnHand,
	int *nLavenderTotalHandPrice,
	
	int *nRosemaryCityStock, int nRosemaryCityPrice, 
	int nRosemaryCityDropPrice, 
	int *nRosemaryHandDrops, int *nRosemaryAverageDropPriceOnHand,
	int *nRosemaryTotalHandPrice,
	
	int *nMintCityStock, int nMintCityPrice, 
	int nMintCityDropPrice,
	int *nMintHandDrops, int *nMintAverageDropPriceOnHand,
	int *nMintTotalHandPrice,
	
	int nClearMindsStock, int nCalmingStock, int nEnergyBoosterStock)		
{
	int nMaxBuyLemon = 0;		
	int nMaxBuyLavender = 0;
	int nMaxBuyRosemary = 0;
	int nMaxBuyMint = 0;
	
	int nCityTotalStockCount;
	int nTotalMaxBuyCount;
	
	char cBuyMenuLetter;
	
	do
	{
		system("Color F1");
		
		nCityTotalStockCount = *nLemonCityStock + *nLavenderCityStock + *nRosemaryCityStock + *nMintCityStock;
		
		//to comment out for insufficient cash
		distributeMaximumOilBuyCount(*nCurrentCash, 
			&nMaxBuyLemon, *nLemonCityStock, nLemonCityPrice,
			&nMaxBuyLavender, *nLavenderCityStock, nLavenderCityPrice,
			&nMaxBuyRosemary, *nRosemaryCityStock, nRosemaryCityPrice,
			&nMaxBuyMint, *nMintCityStock, nMintCityPrice);
			
		nTotalMaxBuyCount = nMaxBuyLemon + nMaxBuyLavender + nMaxBuyRosemary + nMaxBuyMint;
	
		displayRemainingStockOnHand(cLemonIcon, cLavenderIcon, cRosemaryIcon, cMintIcon, 
			cCMIcon, cCIcon, cEBIcon,
			ccLemonOil, ccLavenderOil, ccRosemaryOil, ccMintOil,
			*nLemonHandDrops, *nLavenderHandDrops, *nRosemaryHandDrops, *nMintHandDrops,
			nClearMindsStock, nCalmingStock, nEnergyBoosterStock);
	
		printf("\n%71c%10s%8c\n", PVH, "BUY", PHV);
		displayHeaderUnderline();
		printf("\n");
		printf("%78s%2c", "Cash:", S);
		displayMoney(*nCurrentCash);
		printf("\n\n");
		
		//if all essential oils are unavailable
		if(nCityTotalStockCount == 0)
			printf("\n\n%94s\n\n", "ESSENTIAL OILS NOT AVAILABLE");
		
		//if player is incapable of buying due to insufficient cash	
		if(nTotalMaxBuyCount == 0 && nCityTotalStockCount > 0)
			printf("\n\n%88s\n\n", "INSUFFICIENT CASH");
		
		//displays the oils that can be bought	
		else
		{
			//lemon
			displayEssOilBuyProducts(cLemonIcon, ccLemonOil, nLemonCityPrice, nLemonCityDropPrice, *nLemonCityStock, 
				nMaxBuyLemon, 'E');
			
			//lavender
			displayEssOilBuyProducts(cLavenderIcon, ccLavenderOil, nLavenderCityPrice, nLavenderCityDropPrice, *nLavenderCityStock, 
				nMaxBuyLavender, 'A');
			
			//rosemary
			displayEssOilBuyProducts(cRosemaryIcon, ccRosemaryOil, nRosemaryCityPrice, nRosemaryCityDropPrice, *nRosemaryCityStock, 
				nMaxBuyRosemary, 'R');
			
			//mint
			displayEssOilBuyProducts(cMintIcon, ccMintOil, nMintCityPrice, nMintCityDropPrice, *nMintCityStock, 
				nMaxBuyMint, 'M');
		}
		
		displayLetterScanDivider();
		
		scanf(" %c", &cBuyMenuLetter);
		
		switch (cBuyMenuLetter)
		{
			//lemon
			case 'E':	
				executeBuyChoice(
					nMaxBuyLemon, &*nCurrentCash, 
					&*nLemonCityStock, nLemonCityPrice, nLemonCityDropPrice,
					&*nLemonHandDrops, &*nLemonTotalHandPrice, &*nLemonAverageDropPriceOnHand);
				break;
			
			//lavender
			case 'A':	
				executeBuyChoice(
					nMaxBuyLavender, &*nCurrentCash, 
					&*nLavenderCityStock, nLavenderCityPrice, nLavenderCityDropPrice,
					&*nLavenderHandDrops, &*nLavenderTotalHandPrice, &*nLavenderAverageDropPriceOnHand);
				break;
			
			//rosemary	
			case 'R' :	
				executeBuyChoice(
					nMaxBuyRosemary, &*nCurrentCash,
					&*nRosemaryCityStock, nRosemaryCityPrice, nRosemaryCityDropPrice,
					&*nRosemaryHandDrops, &*nRosemaryTotalHandPrice, &*nRosemaryAverageDropPriceOnHand);
				break;
			
			//mint	
			case 'M' :	
				executeBuyChoice(
					nMaxBuyMint, &*nCurrentCash,
					&*nMintCityStock, nMintCityPrice, nMintCityDropPrice,
					&*nMintHandDrops, &*nMintTotalHandPrice, &*nMintAverageDropPriceOnHand);
				break;
			
			//exit / cancel
			case '0' :	
				system("CLS");
				break;
			
			//invalid input
			default:	
				displayInvalidInputNote();
				break;
		}
	}
	while (cBuyMenuLetter != '0');
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/



/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the stock-on-hand price and stock count information of an oil for selling
Parameters: 
	cOilIcon - character icon of the oil
	*ccOilName - string name of oil
	nOilStockOnHand - drops/bottle count of the oil
	nOilSellPrice - sell price of the oil base on the city's generated prices
	cOilLetter - letter designated for the oil
	bOilType - determines the type of format of the display(essential oil or diffuser oil)
Return value: (void) prints the stock-on-hand information with the designated format if stock is available;
					if not it does not display any information about the oil
*/
void displayOilSellProducts(char cOilIcon, const char *ccOilName, int nOilStockOnHand, int nOilSellPrice, char cOilLetter, char bOilType)
{
	if (nOilStockOnHand > 0)
		{
			displayUpperUniversalChoiceBox();
			printf("%40c%9c.%2c%15s", V, cOilLetter, cOilIcon, ccOilName);	//28 characters
			
			//price display for ess oil
			if (bOilType == 'M')
				displayEssOilSellPrice(nOilSellPrice);	//13 characters
			
			//price display for diff oil
			else
			{
				if (bOilType == 'N')
					displayPrice(nOilSellPrice);		//13 characters
			}
			
			printf(" [stock:%4d] [max sell:%4d]%12c\n", nOilStockOnHand, nOilStockOnHand, V); //41 characters
			displayLowerUniversalChoiceBox();
		}				//total: 82 characters		
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: issues the effects of selling oil/s on the player's cash, and stock-on-hand oils
Parameters: 
	nSellAmount - count of drops/bottle to be sold
	nCitySellPrice - sell price is the generated city price of oil
	*nCash - remaining cash of the player
	*nHandStock - remaining drops/bottles of oil
	*nTotalHandPrice - total price of the oil
	*nAverageHandPrice - average price of oil per drop/bottle
Return value: (void) updates the player's *nCash, *nHandStock, *nTotalHandPrice, and *nAverageHandPrice after selling the oil/s
*/
void issueSellEffects(
	int nSellAmount, int nCitySellPrice, 
	int *nCash, int *nHandStock, 
	int *nTotalHandPrice, int *nAverageHandPrice)
{
	//total sell price to be gained
	int nTotalSellPrice = nCitySellPrice * nSellAmount;
	
	//total price of sold stock-on-hand product to be subtracted from the total stock-on-hand price
	int nTotalStockOnHandsSoldPrice = *nAverageHandPrice * nSellAmount;
	
	//update remaining stock-on-hand
	*nHandStock -= nSellAmount;
	
	//update remaining total price of the stock-on-hand product
	*nTotalHandPrice -= nTotalStockOnHandsSoldPrice;
	
	//update new average price if stock is not equal to zero or greater than zero
	if (*nHandStock > 0 && *nHandStock != 0)
		*nAverageHandPrice = *nTotalHandPrice / *nHandStock;
	
	//total hand price and average price resets to 0 if stock is 0
	else
	{
		*nTotalHandPrice = 0;
		*nAverageHandPrice = 0;
	}
	
	//add the sell price gained to the cash of player
	*nCash += nTotalSellPrice;
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: determines if player could sell oil depending on the remaining stock-on-hand;
				if player could sell, it asks for the amount to be sold and calls issueSellEffects() function,
				if not it displays invalid input
Parameters:
	nOilMaxSell - maximum bottle/drop of oil could be sold / the stock-on-hand bottle/drop count 
	nOilCityPrice - sell price is the generated city price of oil
	*nCash - remaining cash of player
	*nOilHandStock - stock-on-hand drop/bottle count of oil
	*nOilTotalHandPrice - stock-on-hand total price of oil
	*nOilAveragePrice - stock-on-hand average drop/bottle price of oil
Return value: (void) updates the player's cash, stock-on-hand count and prices of the oil after selling a certain amount
*/
void executeOilSellChoice(
	int nOilMaxSell, int nOilCityPrice, 
	int *nCash, int *nOilHandStock, 
	int *nOilTotalHandPrice, int *nOilAveragePrice)	
{
	int nOilSellAmount = 0;
				
	if (nOilMaxSell == 0)	//chosen oil is unavailable
		displayInvalidInputNote();
					
	else 
	{
		displayAmountScanDivider();
		scanf("%d", &nOilSellAmount);
					
		if (nOilSellAmount < 0 || nOilSellAmount > nOilMaxSell)		//invalid input
			displayInvalidInputNote();
		
		else 
		{
			if (nOilSellAmount > 0 && nOilSellAmount <= nOilMaxSell)	//valid input
			{
				issueSellEffects(
					nOilSellAmount, nOilCityPrice,
					&*nCash, &*nOilHandStock, 
					&*nOilTotalHandPrice, &*nOilAveragePrice);
				
				displayTransactTransition();
			}
				
			else
				system("CLS");	//cancel transaction
		}	
	}
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the sell menu for essential oils, and the oil choices that could be sold; passes the updated cash, and stock-on-hand essential oil status
Parameters:
	*nCurrentCash - remaining cash of player
	*ccLemonOil - string of lemon
	*ccLavenderOil - string of lavender
	*ccRosemaryOil - string of rosemary
	*ccMintOil - string of mint
	*ccClearMindsOil - string of clear minds
	*ccCalmingOil - string of calming
	*ccEnergyBoosterOil - string of energy booster
	cLemonIcon - character icon of lemon
	cLavenderIcon - character icon of lavender
	cRosemaryIcon - character icon of rosemary
	cMintIcon - character icon of mint
	cCMIcon - character icon of clear minds
	cCIcon - character icon of calming
	cEBIcon - character icon of energy booster
	nLemonCityDropPrice - generated city drop price as sell price of lemon
	*nLemonHandDrops - remaining stock-on-hand drops of lemon
	*nLemonAverageDropPriceOnHand - stock-on-hand average drop price of lemon
	*nLemonTotalHandPrice - stock-on-hand total price of lemon
	nLavenderCityDropPrice - generated city drop price as sell price of lavender
	*nLavenderHandDrops - remaining stock-on-hand drops of lavender
	*nLavenderAverageDropPriceOnHand - stock-on-hand average drop price of lavender
	*nLavenderTotalHandPrice - stock-on-hand total price of lavender
	nRosemaryCityDropPrice - generated city drop price as sell price of rosemary
	*nRosemaryHandDrops - remaining stock-on-hand drops of rosemary
	*nRosemaryAverageDropPriceOnHand - stock-on-hand average drop price of rosemary
	*nRosemaryTotalHandPrice - stock-on-hand total price of rosemary
	nMintCityDropPrice - generated city drop price as sell price of mint
	*nMintHandDrops - remaining stock-on-hand drops of mint
	*nMintAverageDropPriceOnHand - stock-on-hand average drop price of mint
	*nMintTotalHandPrice - stock-on-hand total price of mint
	nClearMindsStock - remaining stock-on-hand bottles of clear minds
	nCalmingStock - remaining stock-on-hand bottles of calming
	nEnergyBoosterStock - remaining stock-on-hand bottles of energy booster
Return value: (void) updates the player's cash, and stock-on-hand essential oils after selling essential oil/s
*/
void displaySellEssOilMenu(
	int *nCurrentCash, 
	 
	const char *ccLemonOil, const char *ccLavenderOil, const char *ccRosemaryOil, const char *ccMintOil,	
	const char *ccClearMindsOil, const char *ccCalmingOil, const char *ccEnergyBoosterOil,
	
	char cLemonIcon, char cLavenderIcon, char cRosemaryIcon, char cMintIcon,
	char cCMIcon, char cCIcon, char cEBIcon,

	int nLemonCityDropPrice,
	int *nLemonHandDrops, int *nLemonAverageDropPriceOnHand,
	int *nLemonTotalHandPrice,
 
	int nLavenderCityDropPrice,
	int *nLavenderHandDrops, int *nLavenderAverageDropPriceOnHand,
	int *nLavenderTotalHandPrice,
 
	int nRosemaryCityDropPrice, 
	int *nRosemaryHandDrops, int *nRosemaryAverageDropPriceOnHand,
	int *nRosemaryTotalHandPrice,
 
	int nMintCityDropPrice,
	int *nMintHandDrops, int *nMintAverageDropPriceOnHand,
	int *nMintTotalHandPrice,
	
	int nClearMindsStock, int nCalmingStock, int nEnergyBoosterStock)	
{
	char cEssOilSellLetter;
	
	int nTotalEssOilHandDrops;
	
	do
	{	
		system("Color F2");
		
		nTotalEssOilHandDrops = *nLemonHandDrops + *nLavenderHandDrops + *nRosemaryHandDrops + *nMintHandDrops;
		
		displayRemainingStockOnHand(cLemonIcon, cLavenderIcon, cRosemaryIcon, cMintIcon, 
			cCMIcon, cCIcon, cEBIcon,
			ccLemonOil, ccLavenderOil, ccRosemaryOil, ccMintOil,
			*nLemonHandDrops, *nLavenderHandDrops, *nRosemaryHandDrops, *nMintHandDrops,
			nClearMindsStock, nCalmingStock, nEnergyBoosterStock);
	
		printf("\n%71c%11s%7c\n", PVH, "SELL", PHV);
		displayHeaderUnderline();
		printf("%87s\n\n", "ESSENTIAL OILS");
		printf("%78s%2c", "Cash:", S);
		displayMoney(*nCurrentCash);
		printf("\n\n");
		
		//player has no essential oils
		if(nTotalEssOilHandDrops == 0)
			printf("\n\n%97s\n\n", "NO ESSENTIAL OILS IN THE INVENTORY");
		
		else
		{
			//lemon
			displayOilSellProducts(
				cLemonIcon, ccLemonOil, *nLemonHandDrops, nLemonCityDropPrice, 'e', 'M');
			
			//lavender
			displayOilSellProducts(
				cLavenderIcon, ccLavenderOil, *nLavenderHandDrops, nLavenderCityDropPrice, 'a', 'M');
			
			//rosemary
			displayOilSellProducts(
				cRosemaryIcon, ccRosemaryOil, *nRosemaryHandDrops, nRosemaryCityDropPrice, 'r', 'M');
			
			//mint
			displayOilSellProducts(
				cMintIcon, ccMintOil, *nMintHandDrops, nMintCityDropPrice, 'm', 'M');
		}
		
		displayLetterScanDivider();
		
		scanf(" %c", &cEssOilSellLetter);
		
		switch (cEssOilSellLetter)
		{
			//lemon
			case 'e' :	
				executeOilSellChoice(
					*nLemonHandDrops, nLemonCityDropPrice,
					&*nCurrentCash, &*nLemonHandDrops, 
					&*nLemonTotalHandPrice, &*nLemonAverageDropPriceOnHand);
				break;
			
			//lavender	
			case 'a' :	
				executeOilSellChoice(
					*nLavenderHandDrops, nLavenderCityDropPrice,
					&*nCurrentCash, &*nLavenderHandDrops, 
					&*nLavenderTotalHandPrice, &*nLavenderAverageDropPriceOnHand);
				break;
			
			//rosemary
			case 'r' :	
				executeOilSellChoice(
					*nRosemaryHandDrops, nRosemaryCityDropPrice,
					&*nCurrentCash, &*nRosemaryHandDrops,
					&*nRosemaryTotalHandPrice, &*nRosemaryAverageDropPriceOnHand);
				break;
			
			//mint	
			case 'm' :	
				executeOilSellChoice(
					*nMintHandDrops, nMintCityDropPrice, 
					&*nCurrentCash, &*nMintHandDrops,
					&*nMintTotalHandPrice, &*nMintAverageDropPriceOnHand);
				break;
			
			//exit / cancel
			case '0' :	
				system("CLS");
				break;
			
			//invalid input
			default:	
				displayInvalidInputNote();
				break;
		}
	}
	while (cEssOilSellLetter != '0');
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the sell menu for diffuser oils, and the oil choices that could be sold; passes the updated cash, and stock-on-hand diffuser oil status
Parameters:
	*nCurrentCash - remaining cash of player
	*ccLemonOil - string of lemon
	*ccLavenderOil - string of lavender
	*ccRosemaryOil - string of rosemary
	*ccMintOil - string of mint
	*ccClearMindsOil - string of clear minds
	*ccCalmingOil - string of calming
	*ccEnergyBoosterOil - string of energy booster
	cLemonIcon - character icon of lemon
	cLavenderIcon - character icon of lavender
	cRosemaryIcon - character icon of rosemary
	cMintIcon - character icon of mint
	cCMIcon - character icon of clear minds
	cCIcon - character icon of calming
	cEBIcon - character icon of energy booster
	nLemonHandDrops -  - remaining stock-on-hand drops of lemon
	nLavenderHandDrops - remaining stock-on-hand drops of lavender
	nRosemaryHandDrops - remaining stock-on-hand drops of rosemary
	nMintHandDrops - remaining stock-on-hand drops of mint
	*nClearMindsStock - stock-on-hand bottle count of clear minds
	*nClearMindsAveragePrice - stock-on-hand average bottle price of clear minds
	nClearMindsSellPrice - generated city sell price of clear minds
	*nClearMindsTotalHandPrice - stock-on-hand total price of clear minds
	*nCalmingStock - stock-on-hand bottle count of calming
	*nCalmingAveragePrice - stock-on-hand average bottle price of calming
	nCalmingSellPrice - generated city sell price of calming
	*nCalmingTotalHandPrice - stock-on-hand total price of calming
	*nEnergyBoosterStock - stock-on-hand bottle count of energy booster
	*nEnergyBoosterAveragePrice - stock-on-hand average bottle price of energy booster
	nEnergyBoosterSellPrice - generated city sell price of energy booster
	*nEnergyBoosterTotalHandPrice - stock-on-hand total price of energy booster
Return value: (void) updates the player's cash, and stock-on-hand essential oils after selling diffuser oil/s
*/
void displaySellDiffOilMenu(
	int *nCurrentCash, 
	 
	const char *ccLemonOil, const char *ccLavenderOil, const char *ccRosemaryOil, const char *ccMintOil,	
	const char *ccClearMindsOil, const char *ccCalmingOil, const char *ccEnergyBoosterOil,
	
	char cLemonIcon, char cLavenderIcon, char cRosemaryIcon, char cMintIcon,
	char cCMIcon, char cCIcon, char cEBIcon,

	int nLemonHandDrops, int nLavenderHandDrops, 
	int nRosemaryHandDrops, int nMintHandDrops, 
	
	int *nClearMindsStock, int *nClearMindsAveragePrice,
	int nClearMindsSellPrice, int *nClearMindsTotalHandPrice,
	
	int *nCalmingStock, int *nCalmingAveragePrice,
	int nCalmingSellPrice, int *nCalmingTotalHandPrice,
	
	int *nEnergyBoosterStock, int *nEnergyBoosterAveragePrice,
	int nEnergyBoosterSellPrice, int *nEnergyBoosterTotalHandPrice)		
{
	char cDiffOilSellMenuLetter;
	
	int nTotalDiffOilBottles;

	do
	{
		system("Color F2");
		
		nTotalDiffOilBottles = *nClearMindsStock + *nCalmingStock + *nEnergyBoosterStock;
		
		displayRemainingStockOnHand(cLemonIcon, cLavenderIcon, cRosemaryIcon, cMintIcon, 
			cCMIcon, cCIcon, cEBIcon,
			ccLemonOil, ccLavenderOil, ccRosemaryOil, ccMintOil,
			nLemonHandDrops, nLavenderHandDrops, nRosemaryHandDrops, nMintHandDrops,
			*nClearMindsStock, *nCalmingStock, *nEnergyBoosterStock);
	
		printf("\n%71c%11s%7c\n", PVH, "SELL", PHV);
		displayHeaderUnderline();
		printf("%86s\n\n", "DIFFUSER OILS");
		printf("%78s%2c", "Cash:", S);
		displayMoney(*nCurrentCash);
		printf("\n\n");
		
		//player has no diffuser oils
		if(nTotalDiffOilBottles == 0)
			printf("\n\n%96s\n\n", "NO DIFFUSER OILS IN THE INVENTORY");
		
		else
		{
			//clear minds
			displayOilSellProducts(
				cCMIcon, ccClearMindsOil, *nClearMindsStock, nClearMindsSellPrice, 'x', 'N');
				
			//calming
			displayOilSellProducts(
				cCIcon, ccCalmingOil, *nCalmingStock, nCalmingSellPrice, 'y', 'N');
			
			//energy booster
			displayOilSellProducts(
				cEBIcon, ccEnergyBoosterOil, *nEnergyBoosterStock, nEnergyBoosterSellPrice, 'z', 'N');
		}
		
		displayLetterScanDivider();
		
		scanf(" %c", &cDiffOilSellMenuLetter);
		
		switch (cDiffOilSellMenuLetter)
		{
			//clear minds
			case 'x' :	
				executeOilSellChoice(
					*nClearMindsStock, nClearMindsSellPrice,
					&*nCurrentCash, &*nClearMindsStock,
					&*nClearMindsTotalHandPrice, &*nClearMindsAveragePrice);
				break;
			
			//calming	
			case 'y' :	
				executeOilSellChoice(
					*nCalmingStock, nCalmingSellPrice,
					&*nCurrentCash, &*nCalmingStock,
					&*nCalmingTotalHandPrice, &*nCalmingAveragePrice);
				break;
			
			//energy booster	
			case 'z' :	
				executeOilSellChoice(
					*nEnergyBoosterStock, nEnergyBoosterSellPrice,
					&*nCurrentCash, &*nEnergyBoosterStock, 
					&*nEnergyBoosterTotalHandPrice, &*nEnergyBoosterAveragePrice);
				break;
			
			//exit / cancel	
			case '0' :	
				system("CLS");
				break;
			
			//invalid input
			default:	
				displayInvalidInputNote();
				break;
		}
	}	
	while (cDiffOilSellMenuLetter != '0');
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays two choices of oils that the player could sold; sell main menu; passes the updated player's cash, and stock-on-hand oils status
Parameters:
	*nCurrentCash - remaining cash of player
	*ccLemonOil - string of lemon
	*ccLavenderOil - string of lavender
	*ccRosemaryOil - string of rosemary
	*ccMintOil - string of mint
	*ccClearMindsOil - string of clear minds
	*ccCalmingOil - string of calming
	*ccEnergyBoosterOil - string of energy booster
	cLemonIcon - character icon of lemon
	cLavenderIcon - character icon of lavender
	cRosemaryIcon - character icon of rosemary
	cMintIcon - character icon of mint
	cCMIcon - character icon of clear minds
	cCIcon - character icon of calming
	cEBIcon - character icon of energy booster
	nLemonCityDropPrice - generated city drop price as sell price of lemon
	*nLemonHandDrops - remaining stock-on-hand drops of lemon
	*nLemonAverageDropPriceOnHand - stock-on-hand average drop price of lemon
	*nLemonTotalHandPrice - stock-on-hand total price of lemon
	nLavenderCityDropPrice - generated city drop price as sell price of lavender
	*nLavenderHandDrops - remaining stock-on-hand drops of lavender
	*nLavenderAverageDropPriceOnHand - stock-on-hand average drop price of lavender
	*nLavenderTotalHandPrice - stock-on-hand total price of lavender
	nRosemaryCityDropPrice - generated city drop price as sell price of rosemary
	*nRosemaryHandDrops - remaining stock-on-hand drops of rosemary
	*nRosemaryAverageDropPriceOnHand - stock-on-hand average drop price of rosemary
	*nRosemaryTotalHandPrice - stock-on-hand total price of rosemary
	nMintCityDropPrice - generated city drop price as sell price of mint
	*nMintHandDrops - remaining stock-on-hand drops of mint
	*nMintAverageDropPriceOnHand - stock-on-hand average drop price of mint
	*nMintTotalHandPrice - stock-on-hand total price of mint
	*nClearMindsStock - stock-on-hand bottle count of clear minds
	*nClearMindsAveragePrice - stock-on-hand average bottle price of clear minds
	nClearMindsSellPrice - generated city sell price of clear minds
	*nClearMindsTotalHandPrice - stock-on-hand total price of clear minds
	*nCalmingStock - stock-on-hand bottle count of calming
	*nCalmingAveragePrice - stock-on-hand average bottle price of calming
	nCalmingSellPrice - generated city sell price of calming
	*nCalmingTotalHandPrice - stock-on-hand total price of calming
	*nEnergyBoosterStock - stock-on-hand bottle count of energy booster
	*nEnergyBoosterAveragePrice - stock-on-hand average bottle price of energy booster
	nEnergyBoosterSellPrice - generated city sell price of energy booster
	*nEnergyBoosterTotalHandPrice - stock-on-hand total price of energy booster
Return value: (void) updates the player's cash and stock-on-hand count and prices of different oils when player sold bottle/s or drop/s of various oils
*/
void displaySellMainMenu(
	int *nCurrentCash, 
	 
	const char *ccLemonOil, const char *ccLavenderOil, const char *ccRosemaryOil, const char *ccMintOil,	
	const char *ccClearMindsOil, const char *ccCalmingOil, const char *ccEnergyBoosterOil,
	
	char cLemonIcon, char cLavenderIcon, char cRosemaryIcon, char cMintIcon,
	char cCMIcon, char cCIcon, char cEBIcon,
	
	int nLemonCityDropPrice,
	int *nLemonHandDrops, int *nLemonAverageDropPriceOnHand,
	int *nLemonTotalHandPrice,
	
	int nLavenderCityDropPrice,
	int *nLavenderHandDrops, int *nLavenderAverageDropPriceOnHand,
	int *nLavenderTotalHandPrice,
	 
	int nRosemaryCityDropPrice, 
	int *nRosemaryHandDrops, int *nRosemaryAverageDropPriceOnHand,
	int *nRosemaryTotalHandPrice,
	 
	int nMintCityDropPrice,
	int *nMintHandDrops, int *nMintAverageDropPriceOnHand,
	int *nMintTotalHandPrice,
	
	int *nClearMindsStock, int *nClearMindsAveragePrice,
	int nClearMindsSellPrice, int *nClearMindsTotalHandPrice,
	
	int *nCalmingStock, int *nCalmingAveragePrice,
	int nCalmingSellPrice, int *nCalmingTotalHandPrice,
	
	int *nEnergyBoosterStock, int *nEnergyBoosterAveragePrice,
	int nEnergyBoosterSellPrice, int *nEnergyBoosterTotalHandPrice)
{
	system("Color F2");
	
	char cSellMainMenuLetter;

	do
	{
		printf("\n\n\n\n%71c%11s%7c\n", PVH, "SELL", PHV);
		displayHeaderUnderline();
		printf("\n\n\n");
		displayUpperUniversalChoiceBox();
		printf("%40c%48s%33c\n", V, "M. ESSENTIAL OILS", V);
		displayLowerUniversalChoiceBox();
		displayUpperUniversalChoiceBox();
		printf("%40c%47s%34c\n", V, "N. DIFFUSER OILS", V);
		displayLowerUniversalChoiceBox();
		
		displayLetterScanDivider();
		
		scanf(" %c", &cSellMainMenuLetter);
		
		switch (cSellMainMenuLetter)
		{
			//essential oil
			case 'M' :	
				system("CLS");
				displaySellEssOilMenu(
					&*nCurrentCash, 
					
					ccLemonOil, ccLavenderOil, ccRosemaryOil, ccMintOil,	
					ccClearMindsOil, ccCalmingOil, ccEnergyBoosterOil,
		
					cLemonIcon,cLavenderIcon, cRosemaryIcon, cMintIcon,
					cCMIcon, cCIcon, cEBIcon,
 
					nLemonCityDropPrice,
					&*nLemonHandDrops, &*nLemonAverageDropPriceOnHand,
					&*nLemonTotalHandPrice,

					nLavenderCityDropPrice,
					&*nLavenderHandDrops, &*nLavenderAverageDropPriceOnHand,
					&*nLavenderTotalHandPrice,

					nRosemaryCityDropPrice, 
					&*nRosemaryHandDrops, &*nRosemaryAverageDropPriceOnHand,
					&*nRosemaryTotalHandPrice,
 
					nMintCityDropPrice,
					&*nMintHandDrops, &*nMintAverageDropPriceOnHand,
					&*nMintTotalHandPrice,
	
					*nClearMindsStock, *nCalmingStock, *nEnergyBoosterStock);
				break;
			
			//diffuser oil
			case 'N' :	
				system("CLS");
				displaySellDiffOilMenu(
					&*nCurrentCash,
					
					ccLemonOil, ccLavenderOil, ccRosemaryOil, ccMintOil,	
					ccClearMindsOil, ccCalmingOil, ccEnergyBoosterOil,
		
					cLemonIcon,cLavenderIcon, cRosemaryIcon, cMintIcon,
					cCMIcon, cCIcon, cEBIcon,
		
					*nLemonHandDrops, *nLavenderHandDrops, 
					*nRosemaryHandDrops, *nMintHandDrops, 
	
					&*nClearMindsStock, &*nClearMindsAveragePrice,
					nClearMindsSellPrice, &*nClearMindsTotalHandPrice,
	
					&*nCalmingStock, &*nCalmingAveragePrice,
					nCalmingSellPrice, &*nCalmingTotalHandPrice,
		
					&*nEnergyBoosterStock, &*nEnergyBoosterAveragePrice,
					nEnergyBoosterSellPrice, &*nEnergyBoosterTotalHandPrice);
				break;
			
			//exit / cancel
			case '0' :
				system("CLS");
				break;
			
			//invalid input
			default:
				displayInvalidInputNote();
				break;
		}
	}
	while (cSellMainMenuLetter != '0');
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/



/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays a brewing-like effect for every diffuser oil make
Parameters: none
Return value: (void) prints brewing-like effect
*/
void displayDiffOilMaking()
{
	system("CLS");
	system("Color 7D");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	displayFloatingIcons(0, 160, EB, 10);
	printf("\n\n\n");
	displayFloatingIcons(5, 160, EB, 10);
	printf("\n\n\n");
	system("CLS");
	
	system("Color D6");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	displayFloatingIcons(0, 160, C, 10);
	printf("\n\n\n");
	displayFloatingIcons(5, 160, C, 10);
	printf("\n\n\n");
	displayFloatingIcons(0, 160, EB, 10);
	printf("\n\n\n");
	displayFloatingIcons(5, 160, EB, 10);
	printf("\n\n\n");
	system("CLS");
	
	system("Color B6");
	printf("\n\n\n\n\n\n\n\n");
	displayFloatingIcons(0, 160, CM, 10);
	printf("\n\n\n");
	displayFloatingIcons(5, 160, CM, 10);
	printf("\n\n\n");
	displayFloatingIcons(0, 160, C, 10);
	printf("\n\n\n");
	displayFloatingIcons(5, 160, C, 10);
	printf("\n\n\n");
	displayFloatingIcons(0, 160, EB, 10);
	printf("\n\n\n");
	displayFloatingIcons(5, 160, EB, 10);
	printf("\n\n\n");
	system("CLS");
	
	system("Color E7");
	printf("\n");
	displayFloatingIcons(0, 160, B, 10);
	printf("\n\n\n");
	displayFloatingIcons(5, 160, B, 10);
	printf("\n\n\n");
	displayFloatingIcons(0, 160, CM, 10);
	printf("\n\n\n");
	displayFloatingIcons(5, 160, CM, 10);
	printf("\n\n\n");
	displayFloatingIcons(0, 160, C, 10);
	printf("\n\n\n");
	displayFloatingIcons(5, 160, C, 10);
	printf("\n\n\n");
	displayFloatingIcons(0, 160, EB, 10);
	printf("\n\n\n");
	displayFloatingIcons(5, 160, EB, 10);
	printf("\n\n\n");
	printf("\a");
	
	system("CLS");
	
	system("Color F6");
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: computes for the make price of a diffuser oil base on the stock-on-hand average drop price of ingredients, and drop needed for each ingredient
Parameters:
	nIngredientHandDropPrice1 - stock-on-hand average drop price of 1st ingredient
	nIngredientDropCount1 - 1st ingredient drops needed
	nIngredientHandDropPrice2 - stock-on-hand average drop price of 2nd ingredient
	nIngredientDropCount2 - 2nd ingredient drops needed
	nIngredientHandDropPrice3 - stock-on-hand average drop price of 3rd ingredient
	nIngredientDropCount3 - 3rd ingredient drops needed
Return value: (int) returns the make price per bottle of a diffuser oil
*/
int computeMakePrice(
	int nIngredientHandDropPrice1, int nIngredientDropCount1,
	int nIngredientHandDropPrice2, int nIngredientDropCount2,
	int nIngredientHandDropPrice3, int nIngredientDropCount3)
{
	int nTotalIngPrice1 = nIngredientHandDropPrice1 * nIngredientDropCount1;
	int nTotalIngPrice2 = nIngredientHandDropPrice2 * nIngredientDropCount2;
	int nTotalIngPrice3 = nIngredientHandDropPrice3 * nIngredientDropCount3;
	
	return nTotalIngPrice1 + nTotalIngPrice2 + nTotalIngPrice3;
} //P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: distributes the make price of each diffuser oil using computeMakePrice() function
Parameters: 
	*ClearMindsMakePrice - make price for clear minds
	*CalmingMakePrice - make price for calming
	*EnergyBoosterMakePrice - make price for energy booster
	nLemonHandDropPrice - stock-on-hand average drop price of lemon
	nLavenderHandDropPrice - stock-on-hand average drop price of lavender
	nRosemaryHandDropPrice - stock-on-hand average drop price of rosemary
	nMintHandDropPrice - stock-on-hand average drop price of mint
Return value: (void) updates and passes the make prices(*ClearMindsMakePrice, *CalmingMakePrice, and *EnergyBoosterMakePrice) 
						of Clear minds, Calming, Energy booster oils
*/
void distributeDiffOilMakePrice(
	int *ClearMindsMakePrice, int *CalmingMakePrice, int *EnergyBoosterMakePrice,
	int nLemonHandDropPrice, int nLavenderHandDropPrice, int nRosemaryHandDropPrice, int nMintHandDropPrice)
{
	*ClearMindsMakePrice = computeMakePrice(
							nLemonHandDropPrice, 3,		//lemon drps: 3
							nRosemaryHandDropPrice, 2,	//rosemary drps: 2
							nMintHandDropPrice, 2);		//mint drps: 2
							
	*CalmingMakePrice = computeMakePrice(
							nLavenderHandDropPrice, 3,	//lavender drps: 3
							nRosemaryHandDropPrice, 2,	//rosemary drps: 2
							nLemonHandDropPrice, 1);	//lemon drps: 1
							
	*EnergyBoosterMakePrice = computeMakePrice(
							nRosemaryHandDropPrice, 1,	//rosemary drps: 1
							nMintHandDropPrice, 1,		//mint drps: 1
							nLemonHandDropPrice, 1);	//lemon drps: 1
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: computes the maximum bottle count of diffuser can be made from the stock-on-hand ingredient count
Paramenters:
	nOilIngredient1 - stock-on-hand drop count of 1st ingredient
	nOilCount1 - 1st ingredient drops needed for make
	nOilIngredient2 - stock-on-hand drop count of 2nd ingredient
	nOilCount2 - 2nd ingredient drops needed for make
	nOilIngredient3 - stock-on-hand drop count of 3rd ingredient
	nOilCount3 - 3rd ingredient drops needed for make
Return value: (int) returns 0 if ingredients are incomplete or insufficient; returns a positive integer if not
*/
int getMaxMakeFromIngredients(
	int nOilIngredient1, int nOilCount1,
	int nOilIngredient2, int nOilCount2,
	int nOilIngredient3, int nOilCount3)
{
	int j = 0;
	
	int nIngredient1 = nOilIngredient1;
	int nIngredient2 = nOilIngredient2;
	int nIngredient3 = nOilIngredient3;
	
	for(j = 0; nIngredient1 - nOilCount1 >= 0 && nIngredient2 - nOilCount2 >= 0 && nIngredient3 - nOilCount3 >= 0; j++)
	{
		nIngredient1 -= nOilCount1;
		nIngredient2 -= nOilCount2;
		nIngredient3 -= nOilCount3;
	}
	
	return j;
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: computes for the make make base from the player's cash, and the make count from the ingredients
Parameters:
	nCash - remaining cash of the player
	nCityCharge - charge of the current city
	nDiffOilMakePrice - make price per bottle of the oil
	nOilIngredient1 - stock-on-hand drop count of 1st ingredient
	nOilCount1 - 1st ingredient drops needed for make
	nOilIngredient2 - stock-on-hand drop count of 2nd ingredient
	nOilCount2 - 2nd ingredient drops needed for make
	nOilIngredient3 - stock-on-hand drop count of 3rd ingredient
	nOilCount3 - 3rd ingredient drops needed for make
Return value: (int) returns 0 if cash or ingredient is unsufficient; returns nMaxMakeFromIng if player has sufficient cash / limited ingredient;
					returns nMaxMakeFromBudget if player's cash is limited
*/
int getMaxMake(
	int nCash, int nCityCharge, int nDiffOilMakePrice,
	int nOilIngredient1, int nOilCount1,
	int nOilIngredient2, int nOilCount2,
	int nOilIngredient3, int nOilCount3)
{							
	int nMaxMakeFromBudget;
	
	int nMaxMakeFromIng;
		
	if(nOilIngredient1 > 0 && nOilIngredient2 > 0 && nOilIngredient3 > 0)
	{
		nMaxMakeFromBudget = (nCash - nCityCharge) / nDiffOilMakePrice;
	
		nMaxMakeFromIng = getMaxMakeFromIngredients(
							nOilIngredient1, nOilCount1,
							nOilIngredient2, nOilCount2,
							nOilIngredient3, nOilCount3);
							
		if (nMaxMakeFromBudget >= nMaxMakeFromIng)	//limited ingredients
			return nMaxMakeFromIng;
			
		else 							//limited cash
			return nMaxMakeFromBudget;
	}
	
	else			//insufficient cash / ingredients
		return 0;
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: distributes the maximum bottle count of each diffuser oil that can be made
Paramters:
	*nClearMindsMax - maximum bottle make count of clear minds 
	*nCalmingMax - maximum bottle make count of calming
	*nEnergyBoosterMax - maximum bottle make count of energy booster
	nClearMindsMakePrice - make price per bottle of clear minds 
	nCalmingMakePrice - make price per bottle of calming
	nEnergyBoosterMakePrice - make price per bottle of energy booster
	nLemonDropCount - stock-on-hand drop count of lemon
	nLavenderDropCount - stock-on-hand drop count of lavender
	nRosemaryDropCount - stock-on-hand drop count of rosemary
	nMintDropCount - stock-on-hand drop count of mint
	nCash - remaining cash of player
	nCharge - charge in the current city for every make
Return value: (void) updates and passes the max make counts to *nClearMindsMax, *nCalmingMax, and *nEnergyBoosterMax
*/
void distributeMaxDiffOilMake(
	int *nClearMindsMax, int *nCalmingMax, int *nEnergyBoosterMax,
	int nClearMindsMakePrice, int nCalmingMakePrice, int nEnergyBoosterMakePrice,
	int nLemonDropCount, int nLavenderDropCount, int nRosemaryDropCount, int nMintDropCount,
	int nCash, int nCharge)
{
	*nClearMindsMax = getMaxMake(
						nCash, nCharge, nClearMindsMakePrice,
						nLemonDropCount, 3,		//lemon drps: 3
						nRosemaryDropCount, 2,	//rosemary drps: 2
						nMintDropCount, 2);		//mint drps: 2
						
	*nCalmingMax = getMaxMake(
						nCash, nCharge, nCalmingMakePrice,
						nLavenderDropCount, 3,	//lavender drps: 3
						nRosemaryDropCount, 2,	//rosemary drps: 2
						nLemonDropCount, 1);	//lemod drps: 1
						
	*nEnergyBoosterMax = getMaxMake(
						nCash, nCharge, nEnergyBoosterMakePrice,
						nRosemaryDropCount, 1,	//rosemary drps: 1
						nMintDropCount, 1,		//mint drps: 1
						nLemonDropCount, 1);	//lemod drps: 1
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: computes and distributes the total and average drop price of stock-on-hand essential oils after making diffuser oil/s
Parameters:
	nOilStock - number of essential oil drops left
	*nTotalPrice - stock-on-hand total price of essential oil
	*nAveragePrice - stock-on-hand average drop price of essential oil
Return value: (void) updates and passes 0 to *nTotalPrice, and *nAveragePrice if nOilStock = 0;
					if not it updates and passes a positve integer to *nTotalPrice, and *nAveragePrice
*/
void distributeTotalAndAverageDropPrice(int nOilStock, int *nTotalPrice, int *nAveragePrice)
{
	//avoids dividing total price by zero that could flag an error
	if (nOilStock > 0 || nOilStock != 0)				
		*nAveragePrice = *nTotalPrice / nOilStock;
	
	//resets total and average drop price to 0
	else
	{
		*nTotalPrice = 0;
		*nAveragePrice = 0;
	}
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: issues the effects of making a diffuser oil on player's cash, and stock-on-hand status
Parameters:
	nMakeAmount - number of bottles to make
	nDiffOilMakePrice - make price per bottle of diffuser oil
	nCharge - charge in the current city for every batch of make
	nCash - remaining cash of player
	*nDiffOilStock - stock-on-hand bottle count of diffuser oil
	*nDiffOilTotalHandPrice - stock-on-hand total price of diffuser oil
	*nDiffOilAverageHandPrice - stock-on-hand average price per bottle of diffuser oil
	*nOilHandDrops1 - remaining stock-on-hand drop count of 1st ingredient
	*nOilAverageDropPrice1 - stock-on-hand average price per drop of 1st
	*nOilTotalHandPrice1 - stock-on-hand total price of 1st
	nDropNeedForMake1 - drops needed from 1st ingredient
	*nOilHandDrops2 - remaining stock-on-hand drop count of 2nd ingredient
	*nOilAverageDropPrice2 - stock-on-hand average price per drop of 2nd
	*nOilTotalHandPrice2 - stock-on-hand total price of 2nd
	nDropNeedForMake2 - drops needed from 2nd ingredient
	*nOilHandDrops3 - remaining stock-on-hand drop count of 3rd ingredient
	*nOilAverageDropPrice3 - stock-on-hand average price per drop of 3rd
	*nOilTotalHandPrice3 - stock-on-hand total price of 3rd
	nDropNeedForMake3 - drops needed from 3rd ingredient
Return value: (void) updates and passes player's cash, and stock-on-hand count and prices after making diffuser oil/s 
*/
void issueMakeEffects(
	int nMakeAmount, int nDiffOilMakePrice, int nCharge, 
	int *nCash, int *nDiffOilStock, int *nDiffOilTotalHandPrice, int *nDiffOilAverageHandPrice,
	int *nOilHandDrops1, int *nOilAverageDropPrice1, int *nOilTotalHandPrice1, int nDropNeedForMake1,
	int *nOilHandDrops2, int *nOilAverageDropPrice2, int *nOilTotalHandPrice2, int nDropNeedForMake2,
	int *nOilHandDrops3, int *nOilAverageDropPrice3, int *nOilTotalHandPrice3, int nDropNeedForMake3)
{
	//computes total make price without city charge
	int nTotalMakePrice = nDiffOilMakePrice * nMakeAmount;
	//computes total make price with city charge
	int nTotalMakeWithCharge = nTotalMakePrice + nCharge;
	
	//totals the drops of oil used per type of oil
	int nOilUsed1 = nDropNeedForMake1 * nMakeAmount;
	int nOilUsed2 = nDropNeedForMake2 * nMakeAmount;
	int nOilUsed3 = nDropNeedForMake3 * nMakeAmount;
	
	//totals the price of drops used per type of oil
	int nTotalOilUsedPrice1 = *nOilAverageDropPrice1 * nOilUsed1;
	int nTotalOilUsedPrice2 = *nOilAverageDropPrice2 * nOilUsed2;
	int nTotalOilUsedPrice3 = *nOilAverageDropPrice3 * nOilUsed3;
	
	//subtracts the total make price with charge from the cash of the player
	*nCash -= nTotalMakeWithCharge;
	
	//updates remaining drops on hand per type of oil
	*nOilHandDrops1 -= nOilUsed1;
	*nOilHandDrops2 -= nOilUsed2;
	*nOilHandDrops3 -= nOilUsed3;
	
	//updates total price of remaining drops per type of oil
	*nOilTotalHandPrice1 -= nTotalOilUsedPrice1;
	*nOilTotalHandPrice2 -= nTotalOilUsedPrice2;
	*nOilTotalHandPrice3 -= nTotalOilUsedPrice3;
	
	//updates average drop price per type of oil if drops is not 0, 
	//and resets the total and average price per type of oil to 0 is drops left is 0
	distributeTotalAndAverageDropPrice(*nOilHandDrops1, &*nOilTotalHandPrice1, &*nOilAverageDropPrice1);
	distributeTotalAndAverageDropPrice(*nOilHandDrops2, &*nOilTotalHandPrice2, &*nOilAverageDropPrice2);
	distributeTotalAndAverageDropPrice(*nOilHandDrops3, &*nOilTotalHandPrice3, &*nOilAverageDropPrice3);
	
	//updates diff oil stock
	*nDiffOilStock += nMakeAmount;
	
	//updates total diff oil hand price
	*nDiffOilTotalHandPrice += nTotalMakeWithCharge;
	
	//updates diff oil average price
	*nDiffOilAverageHandPrice = *nDiffOilTotalHandPrice / *nDiffOilStock;
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: determines if player could make oil depending on the remaining stock-on-hand and cash;
				if player could make, it asks for the amount to be made and calls issueMakeEffects() function,
				if not it displays invalid input
Parameters:
	nMaxMake - maximum bottle count of diffuser that can be made
	nDiffOilMakePrice - make price per bottle of diffuser oil
	nCharge - make charge of the current city 
	*nCash - remaining cash
	*nDiffOilStock - stock-on-hand bottle count of diffuser oil
	*nDiffOilTotalHandPrice- stock-on-hand total price of diffuser oil
	*nDiffOilAverageHandPrice- stock-on-hand average price of diffuser oil
	*nOilHandDrops1 - remaining stock-on-hand drop count of 1st ingredient
	*nOilAverageDropPrice1 - stock-on-hand average drop price of 1st ingredient
	*nOilTotalHandPrice1 - stock-on-hand total price of 1st ingredient
	nDropNeedForMake1 - drops needed per bottle from 1st ingredient
	*nOilHandDrops2 - remaining stock-on-hand drop count of 2nd ingredient
	*nOilAverageDropPrice2 - stock-on-hand average drop price of 2nd ingredient
	*nOilTotalHandPrice2 - stock-on-hand total price of 2nd ingredient
	nDropNeedForMake2 - drops needed per bottle from 2nd ingredient
	*nOilHandDrops3 - remaining stock-on-hand drop count of 3rd ingredient
	*nOilAverageDropPrice3 - stock-on-hand average drop price of 3rd ingredient
	*nOilTotalHandPrice3 - stock-on-hand total price of 3rd ingredient
	nDropNeedForMake3 - drops needed per bottle from 3rd ingredient
Return value: (void) updates and passes the player's cash, stock-on-hand count and prices of the oil after making a certain amount
*/
void executeMakeChoice(
	int nMaxMake, int nDiffOilMakePrice, int nCharge, 
	int *nCash, int *nDiffOilStock, int *nDiffOilTotalHandPrice, int *nDiffOilAverageHandPrice,
	int *nOilHandDrops1, int *nOilAverageDropPrice1, int *nOilTotalHandPrice1, int nDropNeedForMake1,
	int *nOilHandDrops2, int *nOilAverageDropPrice2, int *nOilTotalHandPrice2, int nDropNeedForMake2,
	int *nOilHandDrops3, int *nOilAverageDropPrice3, int *nOilTotalHandPrice3, int nDropNeedForMake3)	
{
	int nMakeAmount = 0;
				
	if (nMaxMake == 0)		//diff oil not craftable
		displayInvalidInputNote();
					
	else 
	{
		displayAmountScanDivider();
		scanf("%d", &nMakeAmount);
					
		if (nMakeAmount < 0 || nMakeAmount > nMaxMake)	//invalid input
			displayInvalidInputNote();
		
		else 
		{
			if (nMakeAmount > 0 && nMakeAmount <= nMaxMake)		//valid input
			{
				issueMakeEffects(
					nMakeAmount, nDiffOilMakePrice, nCharge,
					&*nCash, &*nDiffOilStock, &*nDiffOilTotalHandPrice, &*nDiffOilAverageHandPrice,
					&*nOilHandDrops1, &*nOilAverageDropPrice1, &*nOilTotalHandPrice1, nDropNeedForMake1,
					&*nOilHandDrops2, &*nOilAverageDropPrice2, &*nOilTotalHandPrice2, nDropNeedForMake2,
					&*nOilHandDrops3, &*nOilAverageDropPrice3, &*nOilTotalHandPrice3, nDropNeedForMake3);
				
				displayDiffOilMaking();
			}
				
			else		//cancel transaction
				system("CLS");
		}	
	}
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the make price, and make count of the diffuser oil
Parameters:	
	*ccDiffOilName - string name of diffuser oil
	cDiffOilIcon - character icon of diffuser oil
	nDiffOilMakePrice - make price per bottle of diffuser oil
	nDiffOilMaxMake - max bottle of diffuser oil that can be made
	cOilIngredientIcon1 - character icon of 1st ingredient
	cOilIngredientIcon2 - character icon of 2nd ingredient
	cOilIngredientIcon3 - character icon of 3rd ingredient
	nIngredientCount1 - drops needed per make from 1st ingredient
	nIngredientCount2 - drops needed per make from 2nd ingredient
	nIngredientCount3 - drops needed per make from 3rd ingredient
	cDiffOilMakeLetter - desiignated letter character of diffuser oil
Return value: (void) prints the make price, and make count of the diffuser oil if craftable; if not, no print/display
*/
void displayAvailableDiffOilMake(
	const char *ccDiffOilName, char cDiffOilIcon, int nDiffOilMakePrice, int nDiffOilMaxMake,
	char cOilIngredientIcon1, char cOilIngredientIcon2, char cOilIngredientIcon3, 
	int nIngredientCount1, int nIngredientCount2, int nIngredientCount3, 
	char cDiffOilMakeLetter)
{
	if (nDiffOilMaxMake > 0)
		{
			displayUpperUniversalChoiceBox();
			printf("%40c%9c.%2c%15s", V, cDiffOilMakeLetter, cDiffOilIcon, ccDiffOilName);	//28 characters
			displayPrice(nDiffOilMakePrice);		//13 characters
			printf(" [%c/%c/%c: %d/%d/%d] [max make:%4d]%10c\n", cOilIngredientIcon1, cOilIngredientIcon2, cOilIngredientIcon3, 
				nIngredientCount1, nIngredientCount2, nIngredientCount3, nDiffOilMaxMake, V); //41 characters
			displayLowerUniversalChoiceBox();
		}							//total: 82 characters
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the choices of diffuser oil that the player can make
Parameters:
	nCurrentCharge - charge of the current city per batch of make
	*nCurrentCash - remaining cash of player
	*ccLemonOil - string name for lemon
	*ccLavenderOil - string name for lavender
	*ccRosemaryOil - string name for rosemary
	*ccMintOil - string name for mint
	*ccClearMindsOil - string name for clear minds
	*ccCalmingOil - string name for calming
	*ccEnergyBoosterOil - string name for energy booster
	cLemonIcon - character icon of lemon
	cLavenderIcon - character icon of lavender
	cRosemaryIcon - character icon of rosemary
	cMintIcon - character icon of mint
	cCMIcon - character icon of clear minds
	cCIcon - character icon of calming
	cEBIcon - character icon of energy booster
	*nLemonHandDrops - remaining stock-on-hand drops of lemon
	*nLemonAverageDropPriceOnHand - stock-on-hand average drop price of lemon
	*nLemonTotalHandPrice - stock-on-hand total price of lemon
	*nLavenderHandDrops - remaining stock-on-hand drops of lavender
	*nLavenderAverageDropPriceOnHand - stock-on-hand average drop price of lavender
	*nLavenderTotalHandPrice - stock-on-hand total price of lavender
	*nRosemaryHandDrops - remaining stock-on-hand drops of rosemary
	*nRosemaryAverageDropPriceOnHand - stock-on-hand average drop price of rosemary
	*nRosemaryTotalHandPrice - stock-on-hand total price of rosemary
	*nMintHandDrops - remaining stock-on-hand drops of mint
	*nMintAverageDropPriceOnHand - stock-on-hand average drop price of mint
	*nMintTotalHandPrice - stock-on-hand total price of mint
	*nClearMindsStock - stock-on-hand bottles of clear minds
	*nClearMindsAveragePrice - stock-on-hand average price of clear minds
	*nClearMindsTotalHandPrice - stock-on-hand total price of clear minds
	*nCalmingStock - stock-on-hand bottles of calming
	*nCalmingAveragePrice - stock-on-hand average price of calming
	*nCalmingTotalHandPrice - stock-on-hand total price of calming
	*nEnergyBoosterStock - stock-on-hand bottles of energy booster
	*nEnergyBoosterAveragePrice - stock-on-hand average price of energy booster
	*nEnergyBoosterTotalHandPrice - stock-on-hand total price of energy booster
Return value: (void) updates and passes the stock-on-hand count, and prices of oils of the player after making diffuser oil/s
*/
void displayMakeMenu(
	int nCurrentCharge, int *nCurrentCash, 
	 
	const char *ccLemonOil, const char *ccLavenderOil, const char *ccRosemaryOil, const char *ccMintOil,	
	const char *ccClearMindsOil, const char *ccCalmingOil, const char *ccEnergyBoosterOil,
	
	char cLemonIcon, char cLavenderIcon, char cRosemaryIcon, char cMintIcon,
	char cCMIcon, char cCIcon, char cEBIcon,
	
	int *nLemonHandDrops, int *nLemonAverageDropPriceOnHand,
	int *nLemonTotalHandPrice,
	
	int *nLavenderHandDrops, int *nLavenderAverageDropPriceOnHand,
	int *nLavenderTotalHandPrice,

	int *nRosemaryHandDrops, int *nRosemaryAverageDropPriceOnHand,
	int *nRosemaryTotalHandPrice,

	int *nMintHandDrops, int *nMintAverageDropPriceOnHand,
	int *nMintTotalHandPrice,
	
	int *nClearMindsStock, int *nClearMindsAveragePrice,
	int *nClearMindsTotalHandPrice,
	
	int *nCalmingStock, int *nCalmingAveragePrice,
	int *nCalmingTotalHandPrice,
	
	int *nEnergyBoosterStock, int *nEnergyBoosterAveragePrice,
	int *nEnergyBoosterTotalHandPrice)
{
	int nClearMindsMakePrice;		// = 100
	int nCalmingMakePrice;			// = 0
	int nEnergyBoosterMakePrice;	// = 50
	
	int nClearMindsMaxMake = 0;
	int nCalmingMaxMake = 0;
	int nEnergyBoosterMaxMake = 0;
	
	char cMakeMenuLetter;
	
	int nTotalMaxMake;
	
	do
	{
		system("Color F6");
		
		//to comment out for max make
		distributeDiffOilMakePrice(
			&nClearMindsMakePrice, &nCalmingMakePrice, &nEnergyBoosterMakePrice, 
			*nLemonAverageDropPriceOnHand, *nLavenderAverageDropPriceOnHand, *nRosemaryAverageDropPriceOnHand, *nMintAverageDropPriceOnHand);
			
		distributeMaxDiffOilMake(
			&nClearMindsMaxMake, &nCalmingMaxMake, &nEnergyBoosterMaxMake, 
			nClearMindsMakePrice, nCalmingMakePrice, nEnergyBoosterMakePrice,
			*nLemonHandDrops, *nLavenderHandDrops, *nRosemaryHandDrops, *nMintHandDrops,
			*nCurrentCash, nCurrentCharge);
			
		nTotalMaxMake = nClearMindsMaxMake + nCalmingMaxMake + nEnergyBoosterMaxMake;
		
		displayRemainingStockOnHand(cLemonIcon, cLavenderIcon, cRosemaryIcon, cMintIcon, 
			cCMIcon, cCIcon, cEBIcon,
			ccLemonOil, ccLavenderOil, ccRosemaryOil, ccMintOil,
			*nLemonHandDrops, *nLavenderHandDrops, *nRosemaryHandDrops, *nMintHandDrops,
			*nClearMindsStock, *nCalmingStock, *nEnergyBoosterStock);
		
		printf("\n%71c%11s%7c\n", PVH, "MAKE", PHV);
		displayHeaderUnderline();
		printf("\n");
		printf("%78s%2c", "Cash:", S);
		displayMoney(*nCurrentCash);		//7 characters
		printf("\n\n%89s%c%4d", "Charge per make batch: ", S, nCurrentCharge);
		printf("\n\n");
		
		if(nTotalMaxMake == 0)
			printf("\n\n%95s\n\n", "INSUFFICIENT INGREDIENTS / CASH");
			
		else
		{
			//clear minds
			displayAvailableDiffOilMake(
				ccClearMindsOil, CM, nClearMindsMakePrice, nClearMindsMaxMake,
				LEO, RO, MO,
				3, 2, 2,
				'X');
			
			//calming
			displayAvailableDiffOilMake(
				ccCalmingOil, C, nCalmingMakePrice, nCalmingMaxMake,
				LAO, RO, LEO,
				3, 2, 1,
				'Y');
			
			//energy booster
			displayAvailableDiffOilMake(
				ccEnergyBoosterOil, EB, nEnergyBoosterMakePrice, nEnergyBoosterMaxMake,
				RO, MO, LEO,
				1, 1, 1,
				'Z');
		}
		
		displayLetterScanDivider();
		
		scanf(" %c", &cMakeMenuLetter);
	
		switch (cMakeMenuLetter)
		{
			//clear minds
			case 'X' :	
				executeMakeChoice(
					nClearMindsMaxMake, nClearMindsMakePrice, nCurrentCharge,
					&*nCurrentCash, &*nClearMindsStock, &*nClearMindsTotalHandPrice, &*nClearMindsAveragePrice,
					&*nLemonHandDrops, &*nLemonAverageDropPriceOnHand, &*nLemonTotalHandPrice, 3,
					&*nRosemaryHandDrops, &*nRosemaryAverageDropPriceOnHand, &*nRosemaryTotalHandPrice, 2,
					&*nMintHandDrops, &*nMintAverageDropPriceOnHand, &*nMintTotalHandPrice, 2);
				break;
			
			//calming	
			case 'Y' :	
				executeMakeChoice(
					nCalmingMaxMake, nCalmingMakePrice, nCurrentCharge,
					&*nCurrentCash, &*nCalmingStock,  &*nCalmingTotalHandPrice, &*nCalmingAveragePrice,
					&*nLavenderHandDrops, &*nLavenderAverageDropPriceOnHand, &*nLavenderTotalHandPrice, 3,
					&*nRosemaryHandDrops, &*nRosemaryAverageDropPriceOnHand, &*nRosemaryTotalHandPrice, 2,
					&*nLemonHandDrops, &*nLemonAverageDropPriceOnHand, &*nLemonTotalHandPrice, 1);
				break;
			
			//energy booster
			case 'Z' :	
				executeMakeChoice(
					nEnergyBoosterMaxMake, nEnergyBoosterMakePrice, nCurrentCharge,
					&*nCurrentCash, &*nEnergyBoosterStock,  &*nEnergyBoosterTotalHandPrice, &*nEnergyBoosterAveragePrice,
					&*nRosemaryHandDrops, &*nRosemaryAverageDropPriceOnHand, &*nRosemaryTotalHandPrice, 1,
					&*nMintHandDrops, &*nMintAverageDropPriceOnHand, &*nMintTotalHandPrice, 1,
					&*nLemonHandDrops, &*nLemonAverageDropPriceOnHand, &*nLemonTotalHandPrice, 1);
				break;
			
			//exit / cancel		
			case '0' :	
				system("CLS");
				break;
			
			//invalid input
			default:	
				displayInvalidInputNote();
				break;
		}
	}
	while (cMakeMenuLetter != '0');
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the summary of the player's cash, debt, and loan; deducts the payment amount to the player's debt and cash
Parameters:
	*nCurrentCash - remaining cash of player
	*nCurrentDebt - remaining debt of player
	nCurrentLoan - total loaned money by player
Return value: (void) updates and passes the player's subtracted cash(*nCurrentCash), and debt(*nCurrentDebt) after paying his/her debt
*/
void displayPayDebtMenu(
	int *nCurrentCash, int *nCurrentDebt, int nCurrentLoan)
{
	int nPayDebtAmount = 0;
	
	do
	{
		system("Color F4");
		
		printf("\n\n\n\n%71c%13s%5c\n", PVH, "PAY DEBT", PHV);
		displayHeaderUnderline();
		printf("\n");
		
		printf("%78s%2c", "Cash:", S);
		displayMoney(*nCurrentCash);		//7 characters
		printf("\n\n");
		
		printf("%78s%2c", "Debt:", S);
		displayMoney(*nCurrentDebt);		//7 characters
		printf("\n\n");
	
		printf("%78s%2c", "Total Loan:", S);
		displayMoney(nCurrentLoan);		//7 characters
		printf("\n\n");
	
		displayAmountScanDivider();
		
		scanf("%d", &nPayDebtAmount);
		
		if (nPayDebtAmount < 0 || nPayDebtAmount > *nCurrentDebt || nPayDebtAmount > *nCurrentCash)	//invalid input
			displayInvalidInputNote();
			
		else
		{
			if (nPayDebtAmount > 0 && nPayDebtAmount <= *nCurrentDebt)	//valid input
			{
				*nCurrentCash -= nPayDebtAmount;
				*nCurrentDebt -= nPayDebtAmount;
				displayTransactTransition();
			}
		}
	}
	while (nPayDebtAmount !=  0);
	
	system("CLS");
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the summary of the player's cash, debt, and loan; adds the loan amount to player's cash, debt and laon
Parameters:
	*nCurrentCash - remaining cash of player
	*nCurrentDebt - remaining debt of player
	nCurrentLoan - total loaned money by player
Return value: (void) updates and passes the player'scash(*nCurrentCash), debt(*nCurrentDebt), and loan(*nCurrentLoan) after loaning money
*/
void displayLoanMenu(
	int *nCurrentCash, int *nCurrentDebt, int *nCurrentLoan)
{	
	int nLoanAmount = 0;
	
	do
	{
		system("Color F4");
		
		printf("\n\n\n\n%71c%11s%7c\n", PVH, "LOAN", PHV);
		displayHeaderUnderline();
		printf("\n");
	
		printf("%78s%2c", "Cash:", S);
		displayMoney(*nCurrentCash);		//7 characters
		printf("\n\n");
	
		printf("%78s%2c", "Debt:", S);
		displayMoney(*nCurrentDebt);		//7 characters
		printf("\n\n");
	
		printf("%78s%2c", "Total Loan:", S);
		displayMoney(*nCurrentLoan);		//7 characters
		printf("\n\n");
	
		displayAmountScanDivider();
		
		scanf("%d", &nLoanAmount);
		
		if (nLoanAmount < 0)	//invalid input
			displayInvalidInputNote();
		
		else 
		{
			if(nLoanAmount > 0)	//valid input
			{
				*nCurrentCash += nLoanAmount;
				*nCurrentDebt += nLoanAmount;
				*nCurrentLoan += nLoanAmount;
				displayTransactTransition();
			}
		}
			
		/*{
			if (nLoanAmount > 0 && nLoanAmount <= 4000)
				issueLoanEffects(nLoanAmount, &*nCurrentCash, &*nCurrentDebt, &*nCurrentLoan);
			
			else if (nLoanAmount > 4000)
			{
				printf("\n%88s %c4,000\a", "YOU CAN'T LOAN MORE THAN", S);
				sleep(2);
				system("CLS");
			}	
		}*/
	}
	while (nLoanAmount != 0);
		
	system("CLS");	
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/



/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays dusk to dawn transition
Parameters: none
Return value: (void) prints dusk to dawn transition
*/
void displayTraveling()
{
	system("CLS");
	system("Color 16");
	printf("\n\n");
	displayFloatingIcons(0, 160, B, 10);
	printf("\n\n\n");
	displayFloatingIcons(3, 160, T, 10);
	printf("\n\n\n");
	displayFloatingIcons(0, 160, B, 10);
	printf("\n\n\n");
	displayFloatingIcons(3, 160, T, 10);
	printf("\n\n\n");
	printf("\a");
	sleep(1);
	system("CLS");
	
	system("Color 0E");
	printf("\n\n");
	displayFloatingIcons(3, 160, T, 10);
	printf("\n\n\n");
	displayFloatingIcons(0, 160, B, 10);
	printf("\n\n\n");
	displayFloatingIcons(3, 160, T, 10);
	printf("\n\n\n");
	displayFloatingIcons(0, 160, B, 10);
	printf("\n\n\n\n\n\n\n\n");
	printf("\tTRAVELING ");
	displayFloatingIcons(1, 6, CM, 1);
	printf("\a");
	sleep(1);
	system("CLS");
	
	printf("\n\n");
	displayFloatingIcons(0, 160, B, 10);
	printf("\n\n\n");
	displayFloatingIcons(3, 160, T, 10);
	printf("\n\n%61s\n", "\\");
	displayFloatingIcons(0, 60, B, 10); 
	printf("\\");
	displayFloatingIcons(1, 80, B, 10);
	printf("\n\n\n");
	displayFloatingIcons(3, 160, T, 10);
	printf("\n\n\n\n\n\n\n\n");
	printf("\tTRAVELING ");
	displayFloatingIcons(1, 6, CM, 1);
	displayFloatingIcons(1, 6, C, 1);
	printf("\a");
	sleep(1);
	system("CLS");
	
	printf("\n\n");
	displayFloatingIcons(3, 160, T, 10);
	printf("\n\n\n");
	displayFloatingIcons(0, 160, B, 10);
	printf("\n\n\n");
	displayFloatingIcons(3, 160, T, 10);
	printf("\n\n\n");
	displayFloatingIcons(0, 160, B, 10);
	printf("\n\n\n\n\n\n\n\n");
	printf("\tTRAVELING ");
	displayFloatingIcons(1, 6, CM, 1);
	displayFloatingIcons(1, 6, C, 1);
	displayFloatingIcons(1, 6, EB, 1);
	printf("\a");
	sleep(1);
	system("CLS");
	
	system("Color 9F");
	printf("\n\n");
	displayFloatingIcons(0, 160, B, 10);
	printf("\n\n\n");
	displayFloatingIcons(3, 160, T, 10);
	printf("\n\n\n");
	displayFloatingIcons(0, 160, B, 10);
	printf("\n\n\n");
	displayFloatingIcons(3, 160, T, 10);
	printf("\n\n\n");
	printf("\a");
	system("CLS");
	
	system("Color F3");
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: generates a random number base on the given range
Parameters:
	nMinRangeMinus1 - min range minus 1; since there is a plus one
	nMaxRange - max range  
Return value: (int) returns the generated number base on the given range
*/
int getRandomAmount(int nMinRangeMinus1, int nMaxRange)
{
	int nRandomAmount;
	do
	{
		nRandomAmount = rand() % nMaxRange + 1; // generates random numbers, and cuts it down to  a certain range
	}
	while (nRandomAmount <= nMinRangeMinus1 || nRandomAmount > nMaxRange); //loops until desired number within specific range aquired
	return nRandomAmount;
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: generates the new price of an essential oil per day or city
Parameters:
	nEssOilMinRange - min of the price range of essential oil
	nEssOilMaxRange - max of the price range of essential oil
	nCityCharge - charge of the current city
Return value: (int) returns the price of the essential oil base from its price range; either retained, added or subtracted by city charge, 
					or multiplied to a generated factor 
*/
int generateEssOilPrice(int nEssOilMinRange, int nEssOilMaxRange, int nCityCharge)
{
	int nGeneratedPrice;
	int nChanceRate;
	int nPrice;
	float fFactor;
	
	//randomize factor value (value must be between 101 and 200)
	fFactor = getRandomAmount(101, 199);
	//compute factor
	fFactor /= 100.0;
	
	do
	{
		//get product original price range per bottle
		nGeneratedPrice = getRandomAmount(nEssOilMinRange, nEssOilMaxRange);
	
		//get chance rate, and its effect on the price per bottle
		nChanceRate = getRandomAmount(0, 100);
	
		//retain generated price
		if (nChanceRate >= 1 && nChanceRate <= 10)
			nPrice = nGeneratedPrice;
		
		//add city charge to product's price
		if (nChanceRate >= 11 && nChanceRate <= 45)
			nPrice = nGeneratedPrice + nCityCharge;
		
		//subtract city charge to product's price
		if (nChanceRate >= 46 && nChanceRate <= 80)
			nPrice = nGeneratedPrice - nCityCharge;
	
		//multiply by a factor
		if (nChanceRate >= 81 && nChanceRate <= 100)
			nPrice = nGeneratedPrice * fFactor;
	}
	while (nPrice <= 0);
	
	return nPrice;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: generates the new stock count, price, and drop price of essential oil per day or city
Parameters:
Return value: (void) updates and passes the new *nEssOilCityStock count, *nEssOilCityPrice, and *nEssOilCityDropPrice for the day or city
*/
void generateCityEssOil(
	int *nEssOilCityStock, int *nEssOilCityPrice, int *nEssOilCityDropPrice, 
	int nEssOilMinRange, int nEssOilMaxRange, int nCityCharge)
{
	//randomize city stock count
	*nEssOilCityStock = getRandomAmount(0, 99); //make sures that the stocks doesn't get too high
	//alternative
	//*nEssOilCityStock = rand() % 100;
	
	//generate essential oil city price
	*nEssOilCityPrice = generateEssOilPrice(nEssOilMinRange, nEssOilMaxRange, nCityCharge);
		
	//generate essential oil city drop price base from its generated city price
	*nEssOilCityDropPrice = *nEssOilCityPrice / 10;		//10 drops per bottle
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: distributes the new and updated city stock count, and prices for the day or city
Parameters:
	*nLemonStock - new city bottle count of lemon
	*nLemonPrice - new city price per bottle of lemon
	*nLemonDropPrice - new city price per drop of lemon
	*nLavenderStock - new city bottle count of lavender
	*nLavenderPrice - new city price per bottle of lavender
	*nLavenderDropPrice - new city price per drop of lavender
	*nRosemaryStock - new city bottle count of rosemary
	*nRosemaryPrice - new city price per bottle of rosemary
	*nRosemaryDropPrice - new city price per drop of rosemary
	*nMintStock - new city bottle count of mint
	*nMintPrice - new city price per bottle of mint
	*nMintDropPrice - new city price per drop of mint
	nCityCharge - charge of the current city
Return value: (void) updates, and passes the values of the new city stock count and prices per essential oil for the day or city
*/
void distributeEssOilCityStocksAndPrices(
	int *nLemonStock, int *nLemonPrice, int *nLemonDropPrice,
	int *nLavenderStock, int *nLavenderPrice, int *nLavenderDropPrice,
	int *nRosemaryStock, int *nRosemaryPrice, int *nRosemaryDropPrice,
	int *nMintStock, int *nMintPrice, int *nMintDropPrice,
	int nCityCharge)
{
	//lemon stocks, city price, drop price
	generateCityEssOil(
		&*nLemonStock, &*nLemonPrice, &*nLemonDropPrice,		
		99, 150, nCityCharge);		//lemon price range: 100-150
	
	//lavender stocks, city price, drop price
	generateCityEssOil(
		&*nLavenderStock, &*nLavenderPrice, &*nLavenderDropPrice,
		19, 60, nCityCharge);		//lavender price range: 20-60
	
	//rosemary stocks, city price, drop price
	generateCityEssOil(
		&*nRosemaryStock, &*nRosemaryPrice, &*nRosemaryDropPrice,
		69, 100, nCityCharge);		//rosemary price range: 70-100
	
	//mint stocks, city price, drop price
	generateCityEssOil(
		&*nMintStock, &*nMintPrice, &*nMintDropPrice,
		129, 200, nCityCharge);		//mint price range: 130-200
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: generates the new sell price of the diffuser oil for the day or city
Parameters:
	nIngredientDropPrice1 - new generated city drop price of 1st ingredient
	nIngNumDrops1 - drops needed per oil from 1st ingredient
	nIngredientDropPrice2 - new generated city drop price of 2nd ingredient
	nIngNumDrops2 - drops needed per oil from 2nd ingredient
	nIngredientDropPrice3 - new generated city drop price of 3rd ingredient
	nIngNumDrops3 - drops needed per oil from 3rd ingredient
Return value: (int) returns the price of the diffuser oil base from the drop prices of the ingredients in the city times the premium rate of 15%
*/
int generateCityDiffOilPrice(
	int nIngredientDropPrice1, int nIngNumDrops1,
	int nIngredientDropPrice2, int nIngNumDrops2,
	int nIngredientDropPrice3, int nIngNumDrops3)
{
	float fDiffOilPremiumRate;
	fDiffOilPremiumRate = 1.0 + DIFFUSER_OIL_PREMIUM_RATE / 100.0;
	
	return fDiffOilPremiumRate * (nIngredientDropPrice1 * nIngNumDrops1 + nIngredientDropPrice2 * nIngNumDrops2 + nIngredientDropPrice3 * nIngNumDrops3);
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: distributes the new generated sell price of each diffuser oil for the day or city
Parameters:
	nLemonDropPrice - current city drop price of lemon
	nLavenderDropPrice - current city drop price of lavender
	nRosemaryDropPrice - current city drop price of rosemary
	nMintDropPrice - current city drop price of mint
	*nClearMindsSellPrice - new sell price of clear minds
	*nCalmingSellPrice - new sell price of calming
	*nEnergyBoosterSellPrice - new sell price of energy booster
Return value: (void) updates and passes the new generated sell prices of eah diffuser oils for the day or city
*/
void distributeDiffOilSellPrices(
	int nLemonDropPrice, int nLavenderDropPrice, int nRosemaryDropPrice, int nMintDropPrice,	//city drop prices
	int *nClearMindsSellPrice, int *nCalmingSellPrice, int *nEnergyBoosterSellPrice)
{
	//clear minds sell price, and ingredients
	*nClearMindsSellPrice = generateCityDiffOilPrice(
		nLemonDropPrice, 3,		//lemon drops: 3
		nRosemaryDropPrice, 2,	//rosemary drops: 2
		nMintDropPrice, 2);		//mint drops: 2
	
	//calming sell price, and ingredients
	*nCalmingSellPrice = generateCityDiffOilPrice(
		nLavenderDropPrice, 3,	//lavender drops: 3
		nRosemaryDropPrice, 2,	//rosemary drops: 2
		nLemonDropPrice, 1);	//lemon drops: 1
	
	//energy booster sell price, and ingredients
	*nEnergyBoosterSellPrice = generateCityDiffOilPrice(
		nRosemaryDropPrice, 1,	//rosemary drops: 1
		nMintDropPrice, 1,		//mint drops: 1
		nLemonDropPrice, 1);	//lemon drops: 1
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: generates and issues the freebie of essential oil to the player's stock-on-hand essential oil drop, and prices
Parameters: 
	*nEssOilHandDrops - current stock-on-hand drop count of ess oil
	*nEssOilTotalHandPrice - current stock-on-hand total price of ess oil
	*nEssOilAverageDropPrice - current stock-on-hand average drop price of ess oil
	nEssOilCityDropPrice - new generated city drop price of oil
Return value: (void) updates and passes the freebie essential oil drops and price from the city to the player's stock-on-hand essential oil drops, and prices
*/
void generateEssOilFreebie(
	int *nEssOilHandDrops, int *nEssOilTotalHandPrice, int *nEssOilAverageDropPrice,
	int nEssOilCityDropPrice)					//free 1 botttle of ess oil / 10 drops of ess oil
{
	int nTotalFreebieDropPrice = nEssOilCityDropPrice * 10;
	
	*nEssOilHandDrops += 10;
	
	*nEssOilTotalHandPrice += nTotalFreebieDropPrice;
	
	*nEssOilAverageDropPrice = *nEssOilTotalHandPrice / *nEssOilHandDrops;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: generates and issues the freebie of essential oil to the player's stock-on-hand diffuser oil bottles, and prices
Parameters: 
	nIngredientDropPrice1 - new city drop price of 1st ingredient
	nIngredientDropCount1 - drops needed per bottle from 1st ingredient
	nIngredientDropPrice2 - new city drop price of 2nd ingredient
	nIngredientDropCount2 - drops needed per bottle from 2nd ingredient
	nIngredientDropPrice3 - new city drop price of 3rd ingredient
	nIngredientDropCount3 - drops needed per bottle from 3rd ingredient
	*nDiffOilStock - current stock-on-hand bottle count of diff oil
	*nDiffOilTotalPrice - current stock-on-hand total price of diff oil
	*nDiffOilAveragePrice - current stock-on-hand average price per bottle of diff oil
Return value: (void) updates and passes the freebie diffuser oil bottle and sell price from the city to the player's stock-on-hand diffuser oil bottles, and prices
*/
void generateDiffOilFreebie(
	int nIngredientDropPrice1, int nIngredientDropCount1,
	int nIngredientDropPrice2, int nIngredientDropCount2,
	int nIngredientDropPrice3, int nIngredientDropCount3,
	int *nDiffOilStock, int *nDiffOilTotalPrice, int *nDiffOilAveragePrice)
{
	int nTotalFreebieDiffOilPrice;
	
	//assuming that the freebie price has no added premium rate with it(raw price)
	//int nTotalIngredientPrice1 = nIngredientDropPrice1 * nIngredientDropCount1;
	//int nTotalIngredientPrice2 = nIngredientDropPrice2 * nIngredientDropCount2;
	//int nTotalIngredientPrice3 = nIngredientDropPrice3 * nIngredientDropCount3;
	//int nTotalFreebieDiffOilPrice = nTotalIngredientPrice1 + nTotalIngredientPrice2 + nTotalIngredientPrice3;
	
	//freebie price is base on the sell price of the diffuser oil with premium rate in the city
	nTotalFreebieDiffOilPrice = generateCityDiffOilPrice(
		nIngredientDropPrice1, nIngredientDropCount1,
		nIngredientDropPrice2, nIngredientDropCount2,
		nIngredientDropPrice3, nIngredientDropCount3);
	
	*nDiffOilStock += 1;
	
	*nDiffOilTotalPrice += nTotalFreebieDiffOilPrice;
	
	*nDiffOilAveragePrice = *nDiffOilTotalPrice / *nDiffOilStock;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: issues the freebie oils by generating a random number; 
			the condition that will fit the generated number will be the free oil to be given to the player
Parameters:
Return value: (void) updates and passes the stock-on-hand stock count and prices of an oil if random number sufficed a certain condition;
						if not, then it does nothing 
*/
void issueFreebie(
	int *nLemonHandDrops, int *nLemonTotalHandPrice, int *nLemonAveDropPrice,
	int *nLavenderHandDrops, int *nLavenderTotalHandPrice, int *nLavenderAveDropPrice,
	int *nRosemaryHandDrops, int *nRosemaryTotalHandPrice, int *nRosemaryAveDropPrice,
	int *nMintHandDrops, int *nMintTotalHandPrice, int *nMintAveDropPrice,
	
	int *nClearMindsStock, int *nClearMindsTotalPrice, int *nClearMindsAveragePrice,
	int *nCalmingStock, int *nCalmingTotalPrice, int *nCalmingAveragePrice,
	int *nEnergyBoosterStock, int *nEnergyBoosterTotalPrice, int *nEnergyBoosterAveragePrice,
	
	int nLemonCityDrpPrice, int nLavenderCityDrpPrice, int nRosemaryCityDrpPrice, int nMintCityDrpPrice)
{
	int bFreebieChanceRate = getRandomAmount(0, 100);
	
	//Ess Oil Freebie
	
	//lemon oil freebie
	if (bFreebieChanceRate > 50 && bFreebieChanceRate <= 60)
		generateEssOilFreebie(&*nLemonHandDrops, &*nLemonTotalHandPrice, &*nLemonAveDropPrice, nLemonCityDrpPrice);
	
	//lavender oil freebie
	if (bFreebieChanceRate > 60 && bFreebieChanceRate <= 70)
		generateEssOilFreebie(&*nLavenderHandDrops, &*nLavenderTotalHandPrice, &*nLavenderAveDropPrice, nLavenderCityDrpPrice);
	
	//rosemary oil freebie
	if (bFreebieChanceRate > 70 && bFreebieChanceRate <= 80)
		generateEssOilFreebie(&*nRosemaryHandDrops, &*nRosemaryTotalHandPrice, &*nRosemaryAveDropPrice, nRosemaryCityDrpPrice);
	
	//min toil freebie
	if (bFreebieChanceRate > 80 && bFreebieChanceRate <= 90)
		generateEssOilFreebie(&*nMintHandDrops, &*nMintTotalHandPrice, &*nMintAveDropPrice, nMintCityDrpPrice);
	
	
	//Diff Oil Freebie
	
	//clear minds oil freebie
	if (bFreebieChanceRate > 10 && bFreebieChanceRate <= 20)
		generateDiffOilFreebie(
			nLemonCityDrpPrice, 3,
			nRosemaryCityDrpPrice, 2,
			nMintCityDrpPrice, 2,
			&*nClearMindsStock, &*nClearMindsTotalPrice, &*nClearMindsAveragePrice);
	
	//calming oil freebie
	if (bFreebieChanceRate > 20 && bFreebieChanceRate <= 30)
		generateDiffOilFreebie(
			nLavenderCityDrpPrice, 3,
			nRosemaryCityDrpPrice, 2,
			nLemonCityDrpPrice, 1,
			&*nCalmingStock, &*nCalmingTotalPrice, &*nCalmingAveragePrice);
	
	//energy booster oil freebie
	if (bFreebieChanceRate > 30 && bFreebieChanceRate <= 40)
		generateDiffOilFreebie(
			nRosemaryCityDrpPrice, 1,
			nMintCityDrpPrice, 1,
			nLemonCityDrpPrice, 1,
			&*nEnergyBoosterStock, &*nEnergyBoosterTotalPrice, &*nEnergyBoosterAveragePrice);
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: determines if player travels to his/her current location; diplays an invalid input if yes;
				calls the functions distributeEssOilCityStocksAndPrices(), distributeDiffOilSellPrices(), and issueFreebie() if no,
				it also changes the charge base on where the player is going to travel, and charges the player's debt by 10%
Parameters: 
	*bBooleanChecker - boolean for exiting the loop in travel menu
	*bLocation - boolean to check the current location of player
	bLocNum - location boolean where the player wants to travel
	*nCharge - new charge of the current city/traveled city
	nMinChargeMinus1 - min range of the city's charge minus 1
	nMaxCharge - max range of the city's charge
	*nLemonStock - bottle count of the city for lemon
	*nLemonPrice - city price per bottle of lemon
	*nLemonCityDropPrice - city price per drop of lemon
	*nLemonHandDrops - stock-on-hand drops of lemon
	*nLemonTotalHandPrice - stock-on-hand total price of lemon
	*nLemonAveDropPrice - stock-on-hand average price per drop of lemon
	*nLavenderStock - bottle count of the city for lavender
	*nLavenderPrice - city price per bottle of lavender
	*nLavenderCityDropPrice - city price per drop of lavender
	*nLavenderHandDrops - stock-on-hand drops of lavender
	*nLavenderTotalHandPrice - stock-on-hand total price of lavender
	*nLavenderAveDropPrice - stock-on-hand average price per drop of lavender
	*nRosemaryStock - bottle count of the city for rosemary
	*nRosemaryPrice - city price per bottle of rosemary
	*nRosemaryCityDropPrice - city price per drop of rosemary
	*nRosemaryHandDrops - stock-on-hand drops of rosemary
	*nRosemaryTotalHandPrice - stock-on-hand total price of rosemary
	*nRosemaryAveDropPrice - stock-on-hand average price per drop of rosemary
	*nMintStock - bottle count of the city for mint
	*nMintPrice - city price per bottle of mint
	*nMintCityDropPrice - city price per drop of mint
	*nMintHandDrops - stock-on-hand drops of mint
	*nMintTotalHandPrice - stock-on-hand total price of mint
	*nMintAveDropPrice - stock-on-hand average price per drop of mint
	*nClearMindsSellPrice - city sell price for clear minds
	*nClearMindsStock - stock-on-hand bottle count for clear minds
	*nClearMindsTotalPrice - stock-on-hand total price for clear minds
	*nClearMindsAveragePrice - stock-on-hand average price for clear minds
	*nCalmingSellPrice - city sell price for calming
	*nCalmingStock - stock-on-hand bottle count for calming
	*nCalmingTotalPrice - stock-on-hand total price for calming
	*nCalmingAveragePrice - stock-on-hand average price for calming
	*nEnergyBoosterSellPrice - city sell price for energy booster
	*nEnergyBoosterStock - stock-on-hand bottle count for energy booster
	*nEnergyBoosterTotalPrice - stock-on-hand total price for energy booster
	*nEnergyBoosterAveragePrice - stock-on-hand average price for energy booster
	*nDebt - current debt of player
Return value: (void) updates and passes the player's debt, and the city's new generated oil prices and stock count;
						updates and passes the player's stock-on-hand oil prices and stocks if ever got a freebie
*/
void executeTravelChoice(
	int *bBooleanChecker, int *bLocation, int bLocNum,
	int *nCharge, int nMinChargeMinus1, int nMaxCharge,
	
	int *nLemonStock, int *nLemonPrice, int *nLemonCityDropPrice,
	int *nLemonHandDrops, int *nLemonTotalHandPrice, int *nLemonAveDropPrice,
	
	int *nLavenderStock, int *nLavenderPrice, int *nLavenderCityDropPrice,
	int *nLavenderHandDrops, int *nLavenderTotalHandPrice, int *nLavenderAveDropPrice,
	
	int *nRosemaryStock, int *nRosemaryPrice, int *nRosemaryCityDropPrice,
	int *nRosemaryHandDrops, int *nRosemaryTotalHandPrice, int *nRosemaryAveDropPrice,
	
	int *nMintStock, int *nMintPrice, int *nMintCityDropPrice,
	int *nMintHandDrops, int *nMintTotalHandPrice, int *nMintAveDropPrice,

	int *nClearMindsSellPrice, 
	int *nClearMindsStock, int *nClearMindsTotalPrice, int *nClearMindsAveragePrice,
	
	int *nCalmingSellPrice, 
	int *nCalmingStock, int *nCalmingTotalPrice, int *nCalmingAveragePrice,
	
	int *nEnergyBoosterSellPrice,
	int *nEnergyBoosterStock, int *nEnergyBoosterTotalPrice, int *nEnergyBoosterAveragePrice,
	
	int *nDebt)
{
	float fLoanInterest = LOAN_SHARK_RATE / 100.0 + 1.0;
	
	//executes to make sure that player wouldn't be able to travel again to its current city
	if (*bLocation == bLocNum)
		displayInvalidInputNote();
	
	//executes when chosen city is not the current city
	else
	{
		*bBooleanChecker = 0;
		*bLocation = bLocNum;
		*nDebt *= fLoanInterest;
		
		displayTraveling();
			
		*nCharge = getRandomAmount(nMinChargeMinus1, nMaxCharge);
			
		distributeEssOilCityStocksAndPrices(
			&*nLemonStock, &*nLemonPrice, &*nLemonCityDropPrice,
			&*nLavenderStock, &*nLavenderPrice, &*nLavenderCityDropPrice,
			&*nRosemaryStock, &*nRosemaryPrice, &*nRosemaryCityDropPrice,
			&*nMintStock, &*nMintPrice, &*nMintCityDropPrice,
			*nCharge);
					
		distributeDiffOilSellPrices(
			*nLemonCityDropPrice, *nLavenderCityDropPrice, *nRosemaryCityDropPrice, *nMintCityDropPrice,
			&*nClearMindsSellPrice, &*nCalmingSellPrice, &*nEnergyBoosterSellPrice);
			
		issueFreebie(
			&*nLemonHandDrops, &*nLemonTotalHandPrice, &*nLemonAveDropPrice,
			&*nLavenderHandDrops, &*nLavenderTotalHandPrice, &*nLavenderAveDropPrice,
			&*nRosemaryHandDrops, &*nRosemaryTotalHandPrice, &*nRosemaryAveDropPrice,
			&*nMintHandDrops, &*nMintTotalHandPrice, &*nMintAveDropPrice,
		
			&*nClearMindsStock, &*nClearMindsTotalPrice, &*nClearMindsAveragePrice,
			&*nCalmingStock, &*nCalmingTotalPrice, &*nCalmingAveragePrice,
			&*nEnergyBoosterStock, &*nEnergyBoosterTotalPrice, &*nEnergyBoosterAveragePrice,
				
			*nLemonCityDropPrice, *nLavenderCityDropPrice, *nRosemaryCityDropPrice, *nMintCityDropPrice);
		
		system("CLS");
	}
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the valid locations that the player could travel to except player's current location by checking the boolean for the location number
Parameters: 
	bPlace - boolean for player's current location number
Return value: (void) prints the city travel choices except player's current location
*/
void displayTravelChoices(int bPlace)
{
	if (bPlace != 1)
		{
			displayUpperUniversalChoiceBox();
			printf("%40c%44s%37c\n", V, "F. MANILA", V);
			displayLowerUniversalChoiceBox();
		}
	
	if (bPlace != 2)
		{
			displayUpperUniversalChoiceBox();
			printf("%40c%44s%37c\n", V, "G. MAKATI", V);
			displayLowerUniversalChoiceBox();
		}
	
	if (bPlace != 3)
		{
			displayUpperUniversalChoiceBox();
			printf("%40c%45s%36c\n", V, "H. ALABANG", V);
			displayLowerUniversalChoiceBox();
		}
	
	if (bPlace != 4)
		{
			displayUpperUniversalChoiceBox();
			printf("%40c%47s%34c\n", V, "I. QUEZON CITY", V);
			displayLowerUniversalChoiceBox();
		}
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the city choices that the player could travel to, and passes the generated new city charge, stocks, and prices, 
			and player's stocks and prices when there's a freebie
Parameters: 
	*ccManila - string for Manila
	*ccMakati - string for Makati
	*ccAlabang - string for Alabang
	*ccQuezonCity - string for Quezon City
	*cCurrentLocation - player's current location string
	nCurrentCash - player's cash
	*nCurrentCharge - charge per city
	*nCurrentDebt - player's debt
	nNumberOfDays - number of days the player has traveled
	nNumOfTravelDays - sales trip span
	*nLemonCityStock - city bottle count for lemon
	*nLemonCityPrice - city price per bottle for lemon
	*nLemonCityDropPrice - city price per drop for lemon
	*nLemonHandDrops - stock-on-hand drop count for lemon
	*nLemonAverageDropPriceOnHand - stock-on-hand average price per drop for lemon
	*nLemonTotalHandPrice - stock-on-hand total price for lemon
	*nLavenderCityStock - city bottle count for lavender
	*nLavenderCityPrice - city price per bottle for lavender
	*nLavenderCityDropPrice - city price per drop for lavender
	*nLavenderHandDrops - stock-on-hand drop count for lavender
	*nLavenderAverageDropPriceOnHand - stock-on-hand average price per drop for lavender
	*nLavenderTotalHandPrice - stock-on-hand total price for lavender
	*nRosemaryCityStock - city bottle count for rosemary
	*nRosemaryCityPrice - city price per bottle for rosemary
	*nRosemaryCityDropPrice - city price per drop for rosemary
	*nRosemaryHandDrops - stock-on-hand drop count for rosemary
	*nRosemaryAverageDropPriceOnHand - stock-on-hand average price per drop for rosemary
	*nRosemaryTotalHandPrice - stock-on-hand total price for rosemary
	*nMintCityStock - city bottle count for mint
	*nMintCityPrice - city price per bottle for mint
	*nMintCityDropPrice - city price per drop for mint
	*nMintHandDrops - stock-on-hand drop count for mint
	*nMintAverageDropPriceOnHand - stock-on-hand average price per drop for mint
	*nMintTotalHandPrice - stock-on-hand total price for mint
	*nClearMindsStock - stock-on-hand bottle count for clear minds
	*nClearMindsAveragePrice - stock-on-hand average price per bottle for clear minds
	*nClearMindsSellPrice - city sell price per bottle for clear minds
	*nClearMindsTotalHandPrice - stock-on-hand total price for clear minds
	*nCalmingStock - stock-on-hand bottle count for calming
	*nCalmingAveragePrice  - stock-on-hand average price per bottle for calming
	*nCalmingSellPrice - city sell price per bottle for calming
	*nCalmingTotalHandPrice - stock-on-hand total price for calming
	*nEnergyBoosterStock - stock-on-hand bottle count for energy booster
	*nEnergyBoosterAveragePrice  - stock-on-hand average price per bottle for energy booster
	*nEnergyBoosterSellPrice - city sell price per bottle for energy booster
	*nEnergyBoosterTotalHandPrice - stock-on-hand total price for energy booster
	*bLocationChecker
Return value: (void) updates and passes the generated new city charge, stocks, and prices, 
					and player's stocks and prices when there's a freebie by calling the function executeTravelChoice();
					displays invalid input if player tried to travel in his/her current location
*/
void displayTravelMenu(
	const char *ccManila, const char *ccMakati, const char *ccAlabang, const char *ccQuezonCity,
	char* cCurrentLocation,
	
	int nCurrentCash, int *nCurrentCharge, int *nCurrentDebt, 
	int nNumberOfDays, int nNumOfTravelDays,
	
	int *nLemonCityStock, int *nLemonCityPrice, 
	int *nLemonCityDropPrice,
	int *nLemonHandDrops, int *nLemonAverageDropPriceOnHand,
	int *nLemonTotalHandPrice,
	
	int *nLavenderCityStock, int *nLavenderCityPrice, 
	int *nLavenderCityDropPrice,
	int *nLavenderHandDrops, int *nLavenderAverageDropPriceOnHand,
	int *nLavenderTotalHandPrice,
	
	int *nRosemaryCityStock, int *nRosemaryCityPrice, 
	int *nRosemaryCityDropPrice, 
	int *nRosemaryHandDrops, int *nRosemaryAverageDropPriceOnHand,
	int *nRosemaryTotalHandPrice,
	
	int *nMintCityStock, int *nMintCityPrice, 
	int *nMintCityDropPrice,
	int *nMintHandDrops, int *nMintAverageDropPriceOnHand,
	int *nMintTotalHandPrice,
	
	int *nClearMindsStock, int *nClearMindsAveragePrice,
	int *nClearMindsSellPrice, int *nClearMindsTotalHandPrice,
	
	int *nCalmingStock, int *nCalmingAveragePrice,
	int *nCalmingSellPrice, int *nCalmingTotalHandPrice,
	
	int *nEnergyBoosterStock, int *nEnergyBoosterAveragePrice,
	int *nEnergyBoosterSellPrice, int *nEnergyBoosterTotalHandPrice,
	
	int *bLocationChecker)		
{
	system("Color F5");
	
	char cTravelMenuLetter;
	
	int bTravelChoiceChecker;
		
	if(nNumberOfDays < nNumOfTravelDays)
	{
		do
		{	
			bTravelChoiceChecker = 1;
			
			printf("\n\n\n\n%71c%12s%6c\n", PVH, "TRAVEL", PHV);
			displayHeaderUnderline();
			printf("\n\n\n");
			
			displayTravelChoices(*bLocationChecker);
			
			displayLetterScanDivider();
			
			
			scanf(" %c", &cTravelMenuLetter);
			
			
			switch (cTravelMenuLetter)
			{
				//Manila
				case 'F':			
					executeTravelChoice(
						&bTravelChoiceChecker, &*bLocationChecker, 1,
						&*nCurrentCharge, 19, 30,
						
						&*nLemonCityStock, &*nLemonCityPrice, &*nLemonCityDropPrice,
						&*nLemonHandDrops, &*nLemonTotalHandPrice, &*nLemonAverageDropPriceOnHand,
						
						&*nLavenderCityStock, &*nLavenderCityPrice, &*nLavenderCityDropPrice,
						&*nLavenderHandDrops, &*nLavenderTotalHandPrice, &*nLavenderAverageDropPriceOnHand,
						
						&*nRosemaryCityStock, &*nRosemaryCityPrice, &*nRosemaryCityDropPrice, 
						&*nRosemaryHandDrops, &*nRosemaryTotalHandPrice, &*nRosemaryAverageDropPriceOnHand,
						
						&*nMintCityStock, &*nMintCityPrice, &*nMintCityDropPrice,
						&*nMintHandDrops, &*nMintTotalHandPrice, &*nMintAverageDropPriceOnHand,
						
						&*nClearMindsSellPrice, 
						&*nClearMindsStock, &*nClearMindsTotalHandPrice, &*nClearMindsAveragePrice,
						
						&*nCalmingSellPrice, 
						&*nCalmingStock, &*nCalmingTotalHandPrice, &*nCalmingAveragePrice,
						
						&*nEnergyBoosterSellPrice, 
						&*nEnergyBoosterStock, &*nEnergyBoosterTotalHandPrice, &*nEnergyBoosterAveragePrice,
						
						&*nCurrentDebt);
						if(*bLocationChecker == 1)
							strcpy(cCurrentLocation, ccManila);
					break;
				
				//Makati	
				case 'G' :			
					executeTravelChoice(
						&bTravelChoiceChecker, &*bLocationChecker, 2,
						&*nCurrentCharge, 79, 100,
						
						&*nLemonCityStock, &*nLemonCityPrice, &*nLemonCityDropPrice,
						&*nLemonHandDrops, &*nLemonTotalHandPrice, &*nLemonAverageDropPriceOnHand,
						
						&*nLavenderCityStock, &*nLavenderCityPrice, &*nLavenderCityDropPrice,
						&*nLavenderHandDrops, &*nLavenderTotalHandPrice, &*nLavenderAverageDropPriceOnHand,
						
						&*nRosemaryCityStock, &*nRosemaryCityPrice, &*nRosemaryCityDropPrice, 
						&*nRosemaryHandDrops, &*nRosemaryTotalHandPrice, &*nRosemaryAverageDropPriceOnHand,
						
						&*nMintCityStock, &*nMintCityPrice, &*nMintCityDropPrice,
						&*nMintHandDrops, &*nMintTotalHandPrice, &*nMintAverageDropPriceOnHand,
						
						&*nClearMindsSellPrice, 
						&*nClearMindsStock, &*nClearMindsTotalHandPrice, &*nClearMindsAveragePrice,
						
						&*nCalmingSellPrice, 
						&*nCalmingStock, &*nCalmingTotalHandPrice, &*nCalmingAveragePrice,
						
						&*nEnergyBoosterSellPrice, 
						&*nEnergyBoosterStock, &*nEnergyBoosterTotalHandPrice, &*nEnergyBoosterAveragePrice,
						
						&*nCurrentDebt);
						if(*bLocationChecker == 2)
							strcpy(cCurrentLocation, ccMakati);
					break;
				
				//Alabang
				case 'H' :			
					executeTravelChoice(
						&bTravelChoiceChecker, &*bLocationChecker, 3,
						&*nCurrentCharge, 69, 90,
						
						&*nLemonCityStock, &*nLemonCityPrice, &*nLemonCityDropPrice,
						&*nLemonHandDrops, &*nLemonTotalHandPrice, &*nLemonAverageDropPriceOnHand,
						
						&*nLavenderCityStock, &*nLavenderCityPrice, &*nLavenderCityDropPrice,
						&*nLavenderHandDrops, &*nLavenderTotalHandPrice, &*nLavenderAverageDropPriceOnHand,
						
						&*nRosemaryCityStock, &*nRosemaryCityPrice, &*nRosemaryCityDropPrice, 
						&*nRosemaryHandDrops, &*nRosemaryTotalHandPrice, &*nRosemaryAverageDropPriceOnHand,
						
						&*nMintCityStock, &*nMintCityPrice, &*nMintCityDropPrice,
						&*nMintHandDrops, &*nMintTotalHandPrice, &*nMintAverageDropPriceOnHand,
						
						&*nClearMindsSellPrice, 
						&*nClearMindsStock, &*nClearMindsTotalHandPrice, &*nClearMindsAveragePrice,
						
						&*nCalmingSellPrice, 
						&*nCalmingStock, &*nCalmingTotalHandPrice, &*nCalmingAveragePrice,
						
						&*nEnergyBoosterSellPrice, 
						&*nEnergyBoosterStock, &*nEnergyBoosterTotalHandPrice, &*nEnergyBoosterAveragePrice,
						
						&*nCurrentDebt);
						if(*bLocationChecker == 3)
							strcpy(cCurrentLocation, ccAlabang);
					break;
				
				//Quezon City
				case 'I' :			
					executeTravelChoice(
						&bTravelChoiceChecker, &*bLocationChecker, 4,
						&*nCurrentCharge, 39, 60,
						
						&*nLemonCityStock, &*nLemonCityPrice, &*nLemonCityDropPrice,
						&*nLemonHandDrops, &*nLemonTotalHandPrice, &*nLemonAverageDropPriceOnHand,
						
						&*nLavenderCityStock, &*nLavenderCityPrice, &*nLavenderCityDropPrice,
						&*nLavenderHandDrops, &*nLavenderTotalHandPrice, &*nLavenderAverageDropPriceOnHand,
						
						&*nRosemaryCityStock, &*nRosemaryCityPrice, &*nRosemaryCityDropPrice, 
						&*nRosemaryHandDrops, &*nRosemaryTotalHandPrice, &*nRosemaryAverageDropPriceOnHand,
						
						&*nMintCityStock, &*nMintCityPrice, &*nMintCityDropPrice,
						&*nMintHandDrops, &*nMintTotalHandPrice, &*nMintAverageDropPriceOnHand,
						
						&*nClearMindsSellPrice, 
						&*nClearMindsStock, &*nClearMindsTotalHandPrice, &*nClearMindsAveragePrice,
						
						&*nCalmingSellPrice, 
						&*nCalmingStock, &*nCalmingTotalHandPrice, &*nCalmingAveragePrice,
						
						&*nEnergyBoosterSellPrice, 
						&*nEnergyBoosterStock, &*nEnergyBoosterTotalHandPrice, &*nEnergyBoosterAveragePrice,
						
						&*nCurrentDebt);
						if(*bLocationChecker == 4)
							strcpy(cCurrentLocation, ccQuezonCity);
					break;
				
				//exit / cancel
				case '0' :
					system("CLS");
					break;
				
				//invalid input
				default:
					displayInvalidInputNote();
					break;
			}
		}
		while (bTravelChoiceChecker && cTravelMenuLetter != '0');
	}
	
	else
		*bLocationChecker = 0;
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/



/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays a loading bar for aesthetics and game feel
Parameters: none
Return value: (void) prints the loading bar
*/
void displayLoadingGame()
{
	system("Color 0D");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tLoading ");
	
	system("Color 0E");
	printf("%c%c%c%c%c%c%c%c", EB, EB, EB, EB, EB, EB, EB, EB);
		
	system("Color 0B");
	printf("%c%c%c%c%c%c%c%c", C, C, C, C, C, C, C, C);
	
	system("Color 09");
	printf("%c%c%c%c%c%c%c%c", CM, CM, CM, CM, CM, CM, CM, CM);
	printf("\a");
	system("CLS");
	
	system("Color F3");
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the upper part of the status box
Parameters: none
Return value: (void) prints the upper part of the status box
*/
void displayUpperStatusBox()
{
	printf("%c", UR);
	displayFloatingIcons(1, 86, H, 1); //86 characters
	printf("%c%c", UL, UR);
	displayFloatingIcons(1, 13, H, 1);	//13 characters
	printf("%c%c", UL, UR);
	displayFloatingIcons(1, 57, H, 1);	//57 characters
	printf("%c\n", UL);				//total: 162 characters
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the settings option in day 1 for the player to be able to tweak his/her sales trip
				but after day 1 it it won't be available and visible as one of the choices of action
Parameters: 
	nNumberOfDays - current day of the player's sales trip
Return value: (void) displays the settings option in day 1, and no display if not day 1
*/
void displaySettingsBoxAvailability(int nNumberOfDays)
{
	if (nNumberOfDays > 1)
		printf("%c%14c%c%28s%3d%%%26c\n", V, V, V, "DIFFUSER OIL PREMIUM RATE: ", DIFFUSER_OIL_PREMIUM_RATE, V);		
	else 
		printf("%c%12s%2c%c%28s%3d%%%26c\n", V, "Q. SETTINGS", V, V, "DIFFUSER OIL PREMIUM RATE: ", DIFFUSER_OIL_PREMIUM_RATE, V);
}	//P						

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the player's current location/city, city's charge, player's cash, debt, loan, 
			current day, sales trip span, loan shark rate, and diffuser premium rate
Parameters:
	*cCurrentLocation - string of player's current location
	nNumberOfDays - number of days since start of sales trip
	nCurrentCharge - city charge
	nCurrentCash - player's cash
	nCurrentDebt - player's debt
	nCurrentLoan - player's loan
	nNumOfTravelDays - sales trip span
Return value: (void) displays the player's current location/city, city's charge, player's cash, debt, loan, 
			current day, sales trip span, loan shark rate, and diffuser premium rate
*/
void displayStatusAndSettingsBox(char* cCurrentLocation, int nNumberOfDays, int nCurrentCharge, int nCurrentCash, int nCurrentDebt, int nCurrentLoan,
	int nNumOfTravelDays)
{
	printf("%c CURRENT LOCATION: %11s%25s%c%3d%17s%2d%9c%c%14c%c%16s%15d%27c\n%c%87c", V, cCurrentLocation, "CITY CHARGE: ",
		S, nCurrentCharge, "DAY: ", nNumberOfDays, V, V, V, V, "DAYS OF TRAVEL:", nNumOfTravelDays, V, V, V);		
	displaySettingsBoxAvailability(nNumberOfDays);
	printf("%c CASH: %c", V, S);
	displayMoney(nCurrentCash);
	printf("%33s%c", "DEBT: ", S);
	displayMoney(nCurrentDebt);
	printf("%21s%c", "LOAN: ", S);
	displayMoney(nCurrentLoan);
	printf("%2c%c%14c%c%18s%13d%%%26c\n", V, V, V, V, "LOAN SHARK RATE: ", LOAN_SHARK_RATE, V);						
}  //P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the lower part of the status box 
Parameter: none
Return value: (void) displays the lower part of the status box 
*/
void displayLowerStatusBox()
{
	
	printf("%c", LR);
	displayFloatingIcons(1, 86, H, 1); //86 characters
	printf("%c%c", LL, LR);
	displayFloatingIcons(1, 13, H, 1);	//13 characters
	printf("%c%c", LL, LR);
	displayFloatingIcons(1, 57, H, 1);	//57 characters
	printf("%c\n", LL);				//total: 162 characters
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the upper portion of the stocks box
Parameters: none
Return value: (void) displays the upper portion of the stocks box
*/
void displayUpperStocksBox()
{
	printf("%c", UR);
	displayFloatingIcons(1, 78, H, 1);	//78 characters
	printf("%c%c", UL, UR);
	displayFloatingIcons(1, 80, H, 1);	//80 characters
	printf("%c\n", UL);			//total: 162 characters
	
	printf("%c%45s%34c%c%47s%34c\n", V, "CITY STOCKS", V, V, "STOCK-ON-HAND", V);
	printf("%c%34c", V, HD);
	displayFloatingIcons(1, 12, HD, 1);	//hori dividers for City Stocks
	printf("%33c%c%34c", V, V, HD);
	displayFloatingIcons(1, 14, HD, 1);	//hori dividers for Stock-On-Hand
	printf("%33c\n", V);
	
	printf("%c%31s%17c%21s%10c%c%26s%12c%27s%16c\n", V, "ESSENTIAL OILS", VD, "DIFFUSER OILS", V, V, "ESSENTIAL OILS", VD, "DIFFUSER OILS", V);
	printf("%c%48c%31c%c%38c%43c\n", V, VD, V, V, VD, V);
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the city prices, and stock number of an essential oil
Parameters: 
	*ccTypeOfEssentialOil - string for essential oil name
	nEOCityStock - city bottle count of ess oil
	nEOCityPrice - city price per bottle of ess oil
	nCityDropPrice - city price per drop of ess oil
	cEssOilIcon - character icon of ess oil
Return value: (void) displays the city prices, and stock number of an essential oil
*/
void displayEssentialOilCityStocks(const char *ccTypeOfEssentialOil, int nEOCityStock,
	int nEOCityPrice, int nCityDropPrice, char cEssOilIcon)
{
	if (nEOCityStock >= 1)
		{
			printf("%c%2c%9s",  V, cEssOilIcon, ccTypeOfEssentialOil);	//13 characters
			displayPrice(nEOCityPrice);	//13 characters
			displayDropPrice(nCityDropPrice);	//12 characters	
			printf("[btl/s:%3d]%c", nEOCityStock, VD); 	//12 characters 
		}
	else
		printf("%c%2c%9s%24s%13c",  V, cEssOilIcon, ccTypeOfEssentialOil, "NOT AVAILABLE", VD);		//Total: 49 characters			
		//printf("%c%48c", V, VD);	    	
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the city sell price of a diffuser oil
Parameters: 
	*ccDiffuserOil - string name of diff oil
	cDiffOilIcon - character icon of diff oil
	nDiffOilSellPrice - city sell price per bottle of diff oil
Return value: (void) displays the city sell price of a diffuser oil
*/
void displayDiffuserOilCitySellPrice(const char *ccDiffuserOil, char cDiffOilIcon, int nDiffOilSellPrice)
{
	printf("%2c%15s", cDiffOilIcon, ccDiffuserOil);		//17 characters
	displayPrice(nDiffOilSellPrice);	//13 characters
	printf("%c", V); 	//1 characters			//total: 31 characters
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the stock-on-hand price, and stock number of an essential oil
Parameters: 
	cEssOilIcon - character icon for ess oil
	*ccEssentialOil - string name of ess oil
	nAverageEssOilDropPrice - stock-on-hand average price per drop of ess oil
	nEssOilDropsOnHand - stock-on-hand drop count of ess oil
Return value: (void) displays the stock-on-hand price, and stock number of an essential oil
*/
void displayAvailableEssentialOilStockOnHand(
	char cEssOilIcon, const char *ccEssentialOil, int nAverageEssOilDropPrice, int nEssOilDropsOnHand)
{
	if (nEssOilDropsOnHand >= 1)
		{
			printf("%c%2c%9s  ", V, cEssOilIcon, ccEssentialOil); //14 characters
			displayDropPrice(nAverageEssOilDropPrice);	//12 characters
			printf("[drp/s:%4d]%c", nEssOilDropsOnHand, VD);	//13 characters
		}
	else
		{
			printf("%c%38c", V, VD);
		}							//total: 39 characters
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the stock-on-hand price, and stock number of a diffuser oil
Parameters: 
	ccTypeOfDiffuserOil - string name of diff oil
	nStockDiffuserOil - stock-on-hand bottle count of diff oil
	nDiffuserOilAveragePrice - stock-on-hand average price per bottle of diff oil
	cIcon2
Return value: (void) displays the stock-on-hand price, and stock number of a diffuser oil
*/
void displayAvailableDiffuserOilStockOnHand(const char *ccTypeOfDiffuserOil, int nStockDiffuserOil, int nDiffuserOilAveragePrice, char cIcon2)
{
	if (nStockDiffuserOil >= 1)
		{
			printf("%2c%15s", cIcon2, ccTypeOfDiffuserOil);	//17 characters
			displayPrice(nDiffuserOilAveragePrice);	//13 characters
			printf("[btl/s:%4d]%c\n", nStockDiffuserOil, V); 	//13 characters
		}	
	else
		printf("%43c\n", V);		//total:43 characters
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the sell prices of diff oil and the available oils in the city and in the player's stock-on-hand
Parameters:
	*ccLemonOil - string name of lemon
	*ccLavenderOil - string name of lavender
	*ccRosemaryOil - string name of rosemary
	*ccMintOil - string name of mint
	*ccClearMindsOil - string name of clear minds
	*ccCalmingOil - string name of calming
	*ccEnergyBoosterOil - string name of energy booster
	cLemonIcon - character icon of lemon
	cLavenderIcon - character icon of lavender
	cRosemaryIcon - character icon of rosemary
	cMintIcon - character icon of mint
	cCMIcon - character icon of clear minds
	cCIcon - character icon of calming
	cEBIcon - character icon of energy booster
	nLemonCityStock - city bottle count of lemon
	nLemonCityPrice - city price per bottle of lemon
	nLemonCityDropPrice - city price per drop of lemon
	nLemonHandDrops - stock-on-hand drop count of lemon
	nLemonAverageDropPriceOnHand - stock-on-hand average price per drop of lemon
	nLemonTotalHandPrice - stock-on-hand total price of lemon
	nLavenderCityStock - city bottle count of lavender
	nLavenderCityPrice - city price per bottle of lavender
	nLavenderCityDropPrice - city price per drop of lavender
	nLavenderHandDrops - stock-on-hand drop count of lavender
	nLavenderAverageDropPriceOnHand - stock-on-hand average price per drop of lavender
	nLavenderTotalHandPrice - stock-on-hand total price of lavender
	nRosemaryCityStock - city bottle count of rosemary
	nRosemaryCityPrice - city price per bottle of rosemary
	nRosemaryCityDropPrice - city price per drop of rosemary
	nRosemaryHandDrops - stock-on-hand drop count of rosemary
	nRosemaryAverageDropPriceOnHand - stock-on-hand average price per drop of rosemary
	nRosemaryTotalHandPrice - stock-on-hand total price of rosemary
	nMintCityStock - city bottle count of mint
	nMintCityPrice - city price per bottle of mint
	nMintCityDropPrice - city price per drop of mint
	nMintHandDrops - stock-on-hand drop count of mint
	nMintAverageDropPriceOnHand - stock-on-hand average price per drop of mint
	nMintTotalHandPrice - stock-on-hand total price of mint
	nClearMindsStock - stock-on-hand bottle count of clear minds
	nClearMindsAveragePrice - stock-on-hand average price per bottle of clear minds
	nClearMindsSellPrice - city sell price per bottle of clear minds
	nClearMindsTotalHandPrice - stock-on-hand total price of clear minds
	nCalmingStock - stock-on-hand bottle count of calming
	nCalmingAveragePrice - stock-on-hand average price per bottle of calming
	nCalmingSellPrice - city sell price per bottle of calming
	nCalmingTotalHandPrice - stock-on-hand total price of calming
	nEnergyBoosterStock - stock-on-hand bottle count of energy booster
	nEnergyBoosterAveragePrice - stock-on-hand average price per bottle of energy booster
	nEnergyBoosterSellPrice - city sell price per bottle of energy booster
	nEnergyBoosterTotalHandPrice - stock-on-hand total price of energy booster
Return value: (void) displays the sell prices of diff oil and the available oils in the city and in the player's stock-on-hand
*/
void displayStocksBox(
	const char *ccLemonOil, const char *ccLavenderOil, const char *ccRosemaryOil, const char *ccMintOil,	//from displayStocksBox()
	const char *ccClearMindsOil, const char *ccCalmingOil, const char *ccEnergyBoosterOil,
	
	char cLemonIcon, char cLavenderIcon, char cRosemaryIcon, char cMintIcon,
	char cCMIcon, char cCIcon, char cEBIcon,
	
	int nLemonCityStock, int nLemonCityPrice, 
	int nLemonCityDropPrice,
	int nLemonHandDrops, int nLemonAverageDropPriceOnHand,
	int nLemonTotalHandPrice,
	
	int nLavenderCityStock, int nLavenderCityPrice, 
	int nLavenderCityDropPrice,
	int nLavenderHandDrops, int nLavenderAverageDropPriceOnHand,
	int nLavenderTotalHandPrice,
	
	int nRosemaryCityStock, int nRosemaryCityPrice, 
	int nRosemaryCityDropPrice, 
	int nRosemaryHandDrops, int nRosemaryAverageDropPriceOnHand,
	int nRosemaryTotalHandPrice,
	
	int nMintCityStock, int nMintCityPrice, 
	int nMintCityDropPrice,
	int nMintHandDrops, int nMintAverageDropPriceOnHand,
	int nMintTotalHandPrice,
	
	int nClearMindsStock, int nClearMindsAveragePrice,
	int nClearMindsSellPrice, int nClearMindsTotalHandPrice,
	
	int nCalmingStock, int nCalmingAveragePrice,
	int nCalmingSellPrice, int nCalmingTotalHandPrice,
	
	int nEnergyBoosterStock, int nEnergyBoosterAveragePrice,
	int nEnergyBoosterSellPrice, int nEnergyBoosterTotalHandPrice)
{
	displayEssentialOilCityStocks(ccLemonOil, nLemonCityStock, nLemonCityPrice, nLemonCityDropPrice, cLemonIcon);
	displayDiffuserOilCitySellPrice(ccClearMindsOil, cCMIcon, nClearMindsSellPrice);
	displayAvailableEssentialOilStockOnHand(cLemonIcon, ccLemonOil, nLemonAverageDropPriceOnHand, nLemonHandDrops);
	displayAvailableDiffuserOilStockOnHand(ccClearMindsOil, nClearMindsStock, nClearMindsAveragePrice, cCMIcon);
	printf("%c%48c%31c%c%38c%43c\n", V, VD, V, V, VD, V);
	
	displayEssentialOilCityStocks(ccLavenderOil, nLavenderCityStock, nLavenderCityPrice, nLavenderCityDropPrice, cLavenderIcon);
	displayDiffuserOilCitySellPrice(ccCalmingOil, cCIcon, nCalmingSellPrice);
	displayAvailableEssentialOilStockOnHand(cLavenderIcon, ccLavenderOil, nLavenderAverageDropPriceOnHand,  nLavenderHandDrops);
	displayAvailableDiffuserOilStockOnHand(ccCalmingOil, nCalmingStock, nCalmingAveragePrice, cCIcon);
	printf("%c%48c%31c%c%38c%43c\n", V, VD, V, V, VD, V);
	
	displayEssentialOilCityStocks(ccRosemaryOil, nRosemaryCityStock, nRosemaryCityPrice, nRosemaryCityDropPrice, cRosemaryIcon);
	displayDiffuserOilCitySellPrice(ccEnergyBoosterOil, cEBIcon, nEnergyBoosterSellPrice);
	displayAvailableEssentialOilStockOnHand(cRosemaryIcon, ccRosemaryOil, nRosemaryAverageDropPriceOnHand, nRosemaryHandDrops);
	displayAvailableDiffuserOilStockOnHand(ccEnergyBoosterOil, nEnergyBoosterStock, nEnergyBoosterAveragePrice, cEBIcon);
	printf("%c%48c%31c%c%38c%43c\n", V, VD, V, V, VD, V);
	
	displayEssentialOilCityStocks(ccMintOil, nMintCityStock, nMintCityPrice, nMintCityDropPrice, cMintIcon);
	printf("%31c", V);
	displayAvailableEssentialOilStockOnHand(cMintIcon, ccMintOil, nMintAverageDropPriceOnHand, nMintHandDrops);
	printf("%43c\n", V);
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the lower portion of the stock box
Parameters: none
Return value: (void) displays the lower portion of the stock box
*/
void displayLowerStocksBox()  
{
	printf("%c", LR);
	displayFloatingIcons(1, 78, H, 1);	//78 characters
	printf("%c%c", LL, LR);
	displayFloatingIcons(1, 80, H, 1);	//80 characters
	printf("%c\n", LL);			//total: 162 characters
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the upper portion of the choice box
Parameters: none
Return value: (void) displays the upper portion of the choice box
*/
void displayGameMenuChoicesUpperBox()
{
	printf("%c", UR);
	displayFloatingIcons(1, 160, H, 1);
	printf("%c\n", UL);
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the action choices that the player could do
Parameter: none
Return value: (void) displays the action choices that the player could do
*/
void displayGameMenuChoices()
{
	printf("%c%23s%23s%23s%27s%23s%25s%17c\n", V, "b. Buy", "s. Sell", "m. Make", "p. Pay Debt", "l. Loan", "t. Travel", V);
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the lower portion of the choice box
Parameters: none
Return value: (void) displays the lower portion of the choice box
*/
void displayGameMenuChoicesLowerBox()
{
	printf("%c", LR);
	displayFloatingIcons(1, 160, H, 1);
	printf("%c\n", LL);
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the divider at the bottom part of the game menu 
Parameters: none 
Return value: (void) displays the divider at the bottom part of the game menu 
*/
void displayScanDividerForGameMenu()
{
	printf("\n%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c",
		PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH);	//12 characters w/ 4 spaces in between
	printf("%7c", LR);
	displayFloatingIcons(1, 27, H, 1);	//27 characters
	printf("%c", LL);
	printf("%7c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c%5c\n",
		PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV);	//12 characters w/ 4 spaces in between
	printf("%92s", "Choose letter of action: ");
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the game menu; this is where the whole game will play around until the end of the sales trip
Parameters: 
	*nRemainingCash - player's remaining cash
	*nRemainingDebt - player's remaining debt
	*nRemainingLemon - player's remaining lemon drops
	*nLemonTotalPrice - player's remaining total price of lemon
	*nRemainingLavender - player's remaining lavender drops
	*nLavenderTotalPrice - player's remaining total price of lavender
	*nRemainingRosemary - player's remaining rosemary drops
	*nRosemaryTotalPrice - player's remaining total price of rosemary
	*nRemainingMint - player's remaining mint drops
	*nMintTotalPrice - player's remaining total price of mint
	*nRemainingClearMinds - player's remaining clear minds bottles
	*nClearMindsTotalPrice - player's remaining total price of clear minds
	*nRemainingCalming - player's remaining calming bottles
	*nCalmingTotalPrice - player's remaining total price of calming
	*nRemainingEnergyBooster - player's remaining energy booster bottles
	*nEnergyBoosterTotalPrice - player's remaining total price of energy booster
	*nRemainingBalance - player's remaining balance
	*bLocationChecker - boolean for player's current location, and boolean for top 10 place identifier
Return value: (void) updates and passes the remaining stocks, stock prices, debt, cash, and balance of the player every after the sales trip
*/
void displayGameMenu(
	int *nRemainingCash, int *nRemainingDebt,
	int *nRemainingLemon, int *nLemonTotalPrice,
	int *nRemainingLavender, int *nLavenderTotalPrice,
	int *nRemainingRosemary, int *nRosemaryTotalPrice,
	int *nRemainingMint, int *nMintTotalPrice,
	int *nRemainingClearMinds, int *nClearMindsTotalPrice,
	int *nRemainingCalming, int *nCalmingTotalPrice,
	int *nRemainingEnergyBooster, int *nEnergyBoosterTotalPrice,
	int *nRemainingBalance,
	
	int *bLocationChecker)
{
	const char *ccManila = "Manila";
	const char *ccMakati = "Makati";
	const char *ccAlabang = "Alabang";
	const char *ccQuezonCity = "Quezon City";
	//cCurrentLocation supports 11 visible characters
	char cCurrentLocation[12];
	strcpy(cCurrentLocation, ccManila);
	int nNumberOfDays;
	int nCurrentCharge = 25;
	int nCurrentCash = 5500;	//200
	int nCurrentDebt = 4000;	//10000
	int nCurrentLoan = 4000;
	int nNumOfTravelDays = 15;	
	
	const char *ccLemonOil = "Lemon";
	const char *ccLavenderOil = "Lavender"; 
	const char *ccRosemaryOil = "Rosemary"; 
	const char *ccMintOil = "Mint";
	const char *ccClearMindsOil = "Clear Minds"; 
	const char *ccCalmingOil = "Calming";
	const char *ccEnergyBoosterOil = "Energy Booster";
	
	int nLemonCityStock = 0;		//2 - B
	int nLemonCityPrice = 0;		//50 - B
	int nLemonCityDropPrice = 0;	//5 - B
	int nLemonHandDrops = 0;				//10 - S
	int nLemonAverageDropPriceOnHand = 0;	//10 - S
	int nLemonTotalHandPrice = 0;			//100 - S
	
	int nLavenderCityStock = 0;		//20 - B
	int nLavenderCityPrice = 0;		//20 - B
	int nLavenderCityDropPrice = 0;	//2 - B
	int nLavenderHandDrops = 0;
	int nLavenderAverageDropPriceOnHand = 0;
	int nLavenderTotalHandPrice = 0;
	
	int nRosemaryCityStock = 0;		
	int nRosemaryCityPrice = 0;		
	int nRosemaryCityDropPrice = 0;	
	int nRosemaryHandDrops = 0;					//10 - S
	int nRosemaryAverageDropPriceOnHand = 0;	//7 - S
	int nRosemaryTotalHandPrice = 0;			//70 - S
	
	int nMintCityStock = 0;		//5 - B
	int nMintCityPrice = 0;		//250 - B
	int nMintCityDropPrice = 0;	//25 - B
	int nMintHandDrops = 0;					//10 - S
	int nMintAverageDropPriceOnHand = 0;	//12 - S
	int nMintTotalHandPrice = 0;			//120 - S
	
	int nClearMindsStock = 0;
	int nClearMindsAveragePrice = 0;
	int nClearMindsSellPrice = 0;
	int nClearMindsTotalHandPrice = 0;
	
	int nCalmingStock = 0;
	int nCalmingAveragePrice = 0;
	int nCalmingSellPrice = 0;
	int nCalmingTotalHandPrice = 0;
	
	int nEnergyBoosterStock = 0;
	int nEnergyBoosterAveragePrice = 0;
	int nEnergyBoosterSellPrice = 0;
	int nEnergyBoosterTotalHandPrice = 0;
	
	int bTravelChecker;
	
	char cGameMenuLetter;
	
	displayLoadingGame();
		
	nCurrentCharge = getRandomAmount(20, 30);
		
	distributeEssOilCityStocksAndPrices(
		&nLemonCityStock, &nLemonCityPrice, &nLemonCityDropPrice,
		&nLavenderCityStock, &nLavenderCityPrice, &nLavenderCityDropPrice,
		&nRosemaryCityStock, &nRosemaryCityPrice, &nRosemaryCityDropPrice,
		&nMintCityStock, &nMintCityPrice, &nMintCityDropPrice,
		nCurrentCharge);
		
	distributeDiffOilSellPrices(
		nLemonCityDropPrice, nLavenderCityDropPrice, nRosemaryCityDropPrice, nMintCityDropPrice,
		&nClearMindsSellPrice, &nCalmingSellPrice, &nEnergyBoosterSellPrice);
		
	issueFreebie(
		&nLemonHandDrops, &nLemonTotalHandPrice, &nLemonAverageDropPriceOnHand,
		&nLavenderHandDrops, &nLavenderTotalHandPrice, &nLavenderAverageDropPriceOnHand,
		&nRosemaryHandDrops, &nRosemaryTotalHandPrice, &nRosemaryAverageDropPriceOnHand,
		&nMintHandDrops, &nMintTotalHandPrice, &nMintAverageDropPriceOnHand,

		&nClearMindsStock, &nClearMindsTotalHandPrice, &nClearMindsAveragePrice,
		&nCalmingStock, &nCalmingTotalHandPrice, &nCalmingAveragePrice,
		&nEnergyBoosterStock, &nEnergyBoosterTotalHandPrice, &nEnergyBoosterAveragePrice,
			
		nLemonCityDropPrice, nLavenderCityDropPrice, nRosemaryCityDropPrice, nMintCityDropPrice);
	
	*bLocationChecker = 1;	
	
	for(nNumberOfDays = 1; nNumberOfDays <= nNumOfTravelDays; nNumberOfDays++)
	{
		bTravelChecker = *bLocationChecker;
		
		while (bTravelChecker == *bLocationChecker)
		{
			system("Color F3");
			
			displayUpperStatusBox();
			displayStatusAndSettingsBox(
				cCurrentLocation, nNumberOfDays, nCurrentCharge, nCurrentCash, nCurrentDebt, nCurrentLoan, nNumOfTravelDays);
			displayLowerStatusBox();
	
			displayUpperStocksBox();
			displayStocksBox(
				ccLemonOil, ccLavenderOil, ccRosemaryOil, ccMintOil,	
				ccClearMindsOil, ccCalmingOil, ccEnergyBoosterOil,
		
				LEO, LAO, RO, MO,
				CM, C, EB,
			
				nLemonCityStock, nLemonCityPrice, 
				nLemonCityDropPrice,
				nLemonHandDrops, nLemonAverageDropPriceOnHand,
				nLemonTotalHandPrice,
			
				nLavenderCityStock, nLavenderCityPrice, 
				nLavenderCityDropPrice,
				nLavenderHandDrops, nLavenderAverageDropPriceOnHand,
				nLavenderTotalHandPrice,
				
				nRosemaryCityStock, nRosemaryCityPrice, 
				nRosemaryCityDropPrice, 
				nRosemaryHandDrops, nRosemaryAverageDropPriceOnHand,
				nRosemaryTotalHandPrice,
			
				nMintCityStock, nMintCityPrice, 
				nMintCityDropPrice,
				nMintHandDrops, nMintAverageDropPriceOnHand,
				nMintTotalHandPrice,
			
				nClearMindsStock, nClearMindsAveragePrice,
				nClearMindsSellPrice, nClearMindsTotalHandPrice,
			
				nCalmingStock, nCalmingAveragePrice,
				nCalmingSellPrice, nCalmingTotalHandPrice,
			
				nEnergyBoosterStock, nEnergyBoosterAveragePrice,
				nEnergyBoosterSellPrice, nEnergyBoosterTotalHandPrice);
			displayLowerStocksBox();
			
			displayGameMenuChoicesUpperBox();
			displayGameMenuChoices();
			displayGameMenuChoicesLowerBox();
			
			displayScanDividerForGameMenu();
		
			scanf(" %c", &cGameMenuLetter);
			
			switch (cGameMenuLetter)
			{
				//settings
				case 'Q':	
					if (nNumberOfDays != 1)
						displayInvalidInputNote();
				
					else
					{
						system("CLS");
						displaySettingsMenu(nNumberOfDays,  &nNumOfTravelDays);
					}
					break;
				
				//buy 
				case 'b':
					system("CLS");
					displayBuyMenu(
						&nCurrentCash,
						
						ccLemonOil, ccLavenderOil, ccRosemaryOil, ccMintOil,	
						ccClearMindsOil, ccCalmingOil, ccEnergyBoosterOil,
			
						LEO, LAO, RO, MO,
						CM, C, EB,
			
						&nLemonCityStock, nLemonCityPrice, 
						nLemonCityDropPrice,
						&nLemonHandDrops, &nLemonAverageDropPriceOnHand,
						&nLemonTotalHandPrice,
		
						&nLavenderCityStock, nLavenderCityPrice, 
						nLavenderCityDropPrice,
						&nLavenderHandDrops, &nLavenderAverageDropPriceOnHand,
						&nLavenderTotalHandPrice,
			
						&nRosemaryCityStock, nRosemaryCityPrice, 
						nRosemaryCityDropPrice, 
						&nRosemaryHandDrops, &nRosemaryAverageDropPriceOnHand,
						&nRosemaryTotalHandPrice,
		
						&nMintCityStock, nMintCityPrice, 
						nMintCityDropPrice,
						&nMintHandDrops, &nMintAverageDropPriceOnHand,
						&nMintTotalHandPrice,
				
						nClearMindsStock, nCalmingStock, nEnergyBoosterStock);
					break;
				
				//sell
				case 's':
					system("CLS");
					displaySellMainMenu(
						&nCurrentCash, 
						
						ccLemonOil, ccLavenderOil, ccRosemaryOil, ccMintOil,
						ccClearMindsOil, ccCalmingOil, ccEnergyBoosterOil,
					
						LEO, LAO, RO, MO,
						CM, C, EB,
		 
						nLemonCityDropPrice,
						&nLemonHandDrops, &nLemonAverageDropPriceOnHand,
						&nLemonTotalHandPrice,
		 		
						nLavenderCityDropPrice,
						&nLavenderHandDrops, &nLavenderAverageDropPriceOnHand,
						&nLavenderTotalHandPrice,
		 		
						nRosemaryCityDropPrice, 
						&nRosemaryHandDrops, &nRosemaryAverageDropPriceOnHand,
						&nRosemaryTotalHandPrice,
		 		
						nMintCityDropPrice,
						&nMintHandDrops, &nMintAverageDropPriceOnHand,
						&nMintTotalHandPrice,
				
						&nClearMindsStock, &nClearMindsAveragePrice,
						nClearMindsSellPrice, &nClearMindsTotalHandPrice,
					
						&nCalmingStock, &nCalmingAveragePrice,
						nCalmingSellPrice, &nCalmingTotalHandPrice,
				
						&nEnergyBoosterStock, &nEnergyBoosterAveragePrice,
						nEnergyBoosterSellPrice, &nEnergyBoosterTotalHandPrice);
					break;
				
				//make
				case 'm':
					system("CLS");
					displayMakeMenu(
						nCurrentCharge, &nCurrentCash, 
					
						ccLemonOil, ccLavenderOil, ccRosemaryOil, ccMintOil,	
						ccClearMindsOil, ccCalmingOil, ccEnergyBoosterOil,
					
						LEO, LAO, RO, MO,
						CM, C, EB,
			
						&nLemonHandDrops, &nLemonAverageDropPriceOnHand,
						&nLemonTotalHandPrice,
				
						&nLavenderHandDrops, &nLavenderAverageDropPriceOnHand,
						&nLavenderTotalHandPrice,
				
						&nRosemaryHandDrops, &nRosemaryAverageDropPriceOnHand,
						&nRosemaryTotalHandPrice,
				
						&nMintHandDrops, &nMintAverageDropPriceOnHand,
						&nMintTotalHandPrice,
				
						&nClearMindsStock, &nClearMindsAveragePrice,
						&nClearMindsTotalHandPrice,
				
						&nCalmingStock, &nCalmingAveragePrice,
						&nCalmingTotalHandPrice,
					
						&nEnergyBoosterStock, &nEnergyBoosterAveragePrice,
						&nEnergyBoosterTotalHandPrice);
					break;
				
				//pay debt
				case 'p':
					system("CLS");
					displayPayDebtMenu(
						&nCurrentCash, &nCurrentDebt, nCurrentLoan);
					break;
				
				//loan
				case 'l':
					system("CLS");
					displayLoanMenu(
						&nCurrentCash, &nCurrentDebt, &nCurrentLoan);
					break;
				
				//travel
				case 't':
					system("CLS");
					displayTravelMenu(
						ccManila, ccMakati, ccAlabang, ccQuezonCity,
						cCurrentLocation,
						
						nCurrentCash, &nCurrentCharge,  	
						&nCurrentDebt, nNumberOfDays, nNumOfTravelDays,
				
						&nLemonCityStock, &nLemonCityPrice, 
						&nLemonCityDropPrice,
						&nLemonHandDrops, &nLemonAverageDropPriceOnHand,
						&nLemonTotalHandPrice,
					
						&nLavenderCityStock, &nLavenderCityPrice, 
						&nLavenderCityDropPrice,
						&nLavenderHandDrops, &nLavenderAverageDropPriceOnHand,
						&nLavenderTotalHandPrice,
					
						&nRosemaryCityStock, &nRosemaryCityPrice, 
						&nRosemaryCityDropPrice, 
						&nRosemaryHandDrops, &nRosemaryAverageDropPriceOnHand,
						&nRosemaryTotalHandPrice,
					
						&nMintCityStock, &nMintCityPrice, 
						&nMintCityDropPrice,
						&nMintHandDrops, &nMintAverageDropPriceOnHand,
						&nMintTotalHandPrice,
				
						&nClearMindsStock, &nClearMindsAveragePrice,
						&nClearMindsSellPrice, &nClearMindsTotalHandPrice,
					
						&nCalmingStock, &nCalmingAveragePrice,
						&nCalmingSellPrice, &nCalmingTotalHandPrice,
					
						&nEnergyBoosterStock, &nEnergyBoosterAveragePrice,
						&nEnergyBoosterSellPrice, &nEnergyBoosterTotalHandPrice,
					
						&*bLocationChecker);
					break;
				
				//invalid input
				default:
					displayInvalidInputNote();
					break;
			}
		}
	}
		
	*nRemainingCash = nCurrentCash; 
	*nRemainingDebt = nCurrentDebt;
	
	*nRemainingLemon = nLemonHandDrops;
	*nLemonTotalPrice = nLemonTotalHandPrice;
	
	*nRemainingLavender = nLavenderHandDrops;
	*nLavenderTotalPrice = nLavenderTotalHandPrice;
	
	*nRemainingRosemary = nRosemaryHandDrops;
	*nRosemaryTotalPrice = nRosemaryTotalHandPrice;
	
	*nRemainingMint = nMintHandDrops;
	*nMintTotalPrice = nMintTotalHandPrice;
	
	*nRemainingClearMinds = nClearMindsStock; 
	*nClearMindsTotalPrice = nClearMindsTotalHandPrice;
	
	*nRemainingCalming = nCalmingStock;
	*nCalmingTotalPrice = nCalmingTotalHandPrice;
	
	*nRemainingEnergyBooster = nEnergyBoosterStock;
	*nEnergyBoosterTotalPrice = nEnergyBoosterTotalHandPrice;
	
	*nRemainingBalance = nCurrentCash + nLemonTotalHandPrice + nLavenderTotalHandPrice + nRosemaryTotalHandPrice + nMintTotalHandPrice + nClearMindsTotalHandPrice + nCalmingTotalHandPrice + nEnergyBoosterTotalHandPrice - nCurrentDebt;
	//*nRemainingBalance = 100;		//not top 10 lister
	//*nRemainingBalance = 1600;	//3rd place
	
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the summary of sales trip of the top oilbularyo
Parameters: 
	*cTopOilbularyoName - string name of top oilbularyo
	nTopOilbularyoCash - remaining cash of top oilbularyo
	nTopOilbularyoBalance - remaining balance of top oilbularyo
	nTopPlaceNum - top place number of top oilbularyo
Return value: (void) displays the summary of sales trip of the top oilbularyo
*/
void displayTopOilbularyoInfoSummary(
	char *cTopOilbularyoName, int nTopOilbularyoCash, int nTopOilbularyoBalance,
	int nTopPlaceNum)
{
	if (nTopOilbularyoCash > 0 || nTopOilbularyoBalance > 0)
	{
		printf("%60d. %s - ", nTopPlaceNum, cTopOilbularyoName);
		printf("%c Balance: %c", V, S);	
		displayMoney(nTopOilbularyoBalance);	// 7 characters
		printf(" %c", V);
		printf("%c Cash: %c", V, S);	
		displayMoney(nTopOilbularyoCash);	// 7 characters
		printf(" %c\n\n", V);
	}
	
	else 
		printf("%60d.\n\n", nTopPlaceNum);
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the leaderboard of the top 10 oilbularyos
Parameters: 
	*cNameTop1 - string name of top 1 oilbularyo
	*cNameTop2 - string name of top 2 oilbularyo
	*cNameTop3 - string name of top 3 oilbularyo
	*cNameTop4 - string name of top 4 oilbularyo
	*cNameTop5 - string name of top 5 oilbularyo
	*cNameTop6 - string name of top 6 oilbularyo
	*cNameTop7 - string name of top 7 oilbularyo
	*cNameTop8 - string name of top 8 oilbularyo
	*cNameTop9 - string name of top 9 oilbularyo
	*cNameTop10 - string name of top 10 oilbularyo
	nCashTop1 - remaining cash of top 1 oilbularyo
	nCashTop2 - remaining cash of top 2 oilbularyo
	nCashTop3 - remaining cash of top 3 oilbularyo
	nCashTop4 - remaining cash of top 4 oilbularyo
	nCashTop5 - remaining cash of top 5 oilbularyo
	nCashTop6 - remaining cash of top 6 oilbularyo
	nCashTop7 - remaining cash of top 7 oilbularyo
	nCashTop8 - remaining cash of top 8 oilbularyo
	nCashTop9 - remaining cash of top 9 oilbularyo
	nCashTop10 - remaining cash of top 10 oilbularyo
	nBalanceTop1 - remaining balance of top 1 oilbularyo
	nBalanceTop2 - remaining balance of top 2 oilbularyo
	nBalanceTop3 - remaining balance of top 3 oilbularyo
	nBalanceTop4 - remaining balance of top 4 oilbularyo
	nBalanceTop5 - remaining balance of top 5 oilbularyo
	nBalanceTop6 - remaining balance of top 6 oilbularyo
	nBalanceTop7 - remaining balance of top 7 oilbularyo
	nBalanceTop8 - remaining balance of top 8 oilbularyo
	nBalanceTop9 - remaining balance of top 9 oilbularyo
	nBalanceTop10 - remaining balance of top 10 oilbularyo
Return value: (void) displays the leaderboard of the top 10 oilbularyos
*/
void displayTopTenList(
	char* cNameTop1, char* cNameTop2, char* cNameTop3, char* cNameTop4, char* cNameTop5, 	
	char* cNameTop6, char* cNameTop7, char* cNameTop8, char* cNameTop9, char* cNameTop10, 
	
	int nCashTop1, int nCashTop2, int nCashTop3, int nCashTop4, int nCashTop5, 
	int nCashTop6, int nCashTop7, int nCashTop8, int nCashTop9, int nCashTop10, 
	
	int nBalanceTop1, int nBalanceTop2, int nBalanceTop3, int nBalanceTop4, int nBalanceTop5, 
	int nBalanceTop6, int nBalanceTop7, int nBalanceTop8, int nBalanceTop9, int nBalanceTop10)
{
	char cTop10Letter;
	
	do
	{
		system("Color 0D");
		
		printf("\n\n%88s\n", "TOP OIL-BULARYOS");
		displayHeaderUnderline();
		printf("\n\n");
		
		displayTopOilbularyoInfoSummary(
			cNameTop1, nCashTop1, nBalanceTop1,
			1);
			
		displayTopOilbularyoInfoSummary(
			cNameTop2, nCashTop2, nBalanceTop2,
			2);
		
		displayTopOilbularyoInfoSummary(
			cNameTop3, nCashTop3, nBalanceTop3,
			3);
		
		displayTopOilbularyoInfoSummary(
			cNameTop4, nCashTop4, nBalanceTop4,
			4);
		
		displayTopOilbularyoInfoSummary(
			cNameTop5, nCashTop5, nBalanceTop5,
			5);
			
		displayTopOilbularyoInfoSummary(
			cNameTop6, nCashTop6, nBalanceTop6,
			6);
			
		displayTopOilbularyoInfoSummary(
			cNameTop7, nCashTop7, nBalanceTop7,
			7);
			
		displayTopOilbularyoInfoSummary(
			cNameTop8, nCashTop8, nBalanceTop8,
			8);
			
		displayTopOilbularyoInfoSummary(
			cNameTop9, nCashTop9, nBalanceTop9,
			9);
			
		displayTopOilbularyoInfoSummary(
			cNameTop10, nCashTop10, nBalanceTop10,
			10);
	
		displayLetterScanDivider();
		
		scanf(" %c", &cTop10Letter);
		
		switch(cTop10Letter)
		{
			case '0' :
				system("CLS");
				break;
			
			default:
				displayInvalidInputNote();
				break;
		}
	}
	while(cTop10Letter != '0');
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/



/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: determines if the recent player is one of the top 10 by comparing the recent player's remaining balance with the top 10
Parameters:
	nPlayerCash - recent player's cash
	nPlayerBalance - recent player's balance
	*nCash1 - remaining cash of top 1 oilbularyo
	*nCash2 - remaining cash of top 2 oilbularyo
	*nCash3 - remaining cash of top 3 oilbularyo
	*nCash4 - remaining cash of top 4 oilbularyo
	*nCash5 - remaining cash of top 5 oilbularyo
	*nCash6 - remaining cash of top 6 oilbularyo
	*nCash7 - remaining cash of top 7 oilbularyo
	*nCash8 - remaining cash of top 8 oilbularyo
	*nCash9 - remaining cash of top 9 oilbularyo
	*nCash10 - remaining cash of top 10 oilbularyo
	*nBalance1 - remaining balance of top 1 oilbularyo
	*nBalance2 - remaining balance of top 2 oilbularyo
	*nBalance3 - remaining balance of top 3 oilbularyo
	*nBalance4 - remaining balance of top 4 oilbularyo
	*nBalance5 - remaining balance of top 5 oilbularyo
	*nBalance6 - remaining balance of top 6 oilbularyo
	*nBalance7 - remaining balance of top 7 oilbularyo
	*nBalance8 - remaining balance of top 8 oilbularyo
	*nBalance9 - remaining balance of top 9 oilbularyo
	*nBalance10 - remaining balance of top 10 oilbularyo
	*nTop10Checker - boolean for the recent player's standing
Return value: (void) updates and passes the top oilbularyos standing if recent player got into the top 10 
					by moving all the records and giving *nTop10Checker a boolean number for the standing of the recent player
*/
void determineIfTop10Lister(
	int nPlayerCash, int nPlayerBalance,
	
	int *nCash1, int *nCash2, int *nCash3, int *nCash4, int *nCash5, 
	int *nCash6, int *nCash7, int *nCash8, int *nCash9, int *nCash10, 
	
	int *nBalance1, int *nBalance2, int *nBalance3, int *nBalance4, int *nBalance5, 
	int *nBalance6, int *nBalance7, int *nBalance8, int *nBalance9, int *nBalance10, 
	
	int *nTop10Checker)
{
	if (nPlayerBalance >= *nBalance1)
	{
		*nCash10 = *nCash9;
		*nCash9 = *nCash8;
		*nCash8 = *nCash7;
		*nCash7 = *nCash6;
		*nCash6 = *nCash5;
		*nCash5 = *nCash4;
		*nCash4 = *nCash3;
		*nCash3 = *nCash2;
		*nCash2 = *nCash1;
		*nCash1 = nPlayerCash;
		
		*nBalance10 = *nBalance9;
		*nBalance9 = *nBalance8;
		*nBalance8 = *nBalance7;
		*nBalance7 = *nBalance6;
		*nBalance6 = *nBalance5;
		*nBalance5 = *nBalance4;
		*nBalance4 = *nBalance3;
		*nBalance3 = *nBalance2;
		*nBalance2 = *nBalance1;
		*nBalance1 = nPlayerBalance;
		
		*nTop10Checker = 1;
	}
	
	if (nPlayerBalance >= *nBalance2 && nPlayerBalance < *nBalance1)
	{
		*nCash10 = *nCash9;
		*nCash9 = *nCash8;
		*nCash8 = *nCash7;
		*nCash7 = *nCash6;
		*nCash6 = *nCash5;
		*nCash5 = *nCash4;
		*nCash4 = *nCash3;
		*nCash3 = *nCash2;
		*nCash2 = nPlayerCash;
		
		*nBalance10 = *nBalance9;
		*nBalance9 = *nBalance8;
		*nBalance8 = *nBalance7;
		*nBalance7 = *nBalance6;
		*nBalance6 = *nBalance5;
		*nBalance5 = *nBalance4;
		*nBalance4 = *nBalance3;
		*nBalance3 = *nBalance2;
		*nBalance2 = nPlayerBalance;
		
		*nTop10Checker = 2;
	}
	
	if (nPlayerBalance >= *nBalance3 && nPlayerBalance < *nBalance2)
	{
		*nCash10 = *nCash9;
		*nCash9 = *nCash8;
		*nCash8 = *nCash7;
		*nCash7 = *nCash6;
		*nCash6 = *nCash5;
		*nCash5 = *nCash4;
		*nCash4 = *nCash3;
		*nCash3 = nPlayerCash;
		
		*nBalance10 = *nBalance9;
		*nBalance9 = *nBalance8;
		*nBalance8 = *nBalance7;
		*nBalance7 = *nBalance6;
		*nBalance6 = *nBalance5;
		*nBalance5 = *nBalance4;
		*nBalance4 = *nBalance3;
		*nBalance3 = nPlayerBalance;
		
		*nTop10Checker = 3;
	}
	
	if (nPlayerBalance >= *nBalance4 && nPlayerBalance < *nBalance3)
	{
		*nCash10 = *nCash9;
		*nCash9 = *nCash8;
		*nCash8 = *nCash7;
		*nCash7 = *nCash6;
		*nCash6 = *nCash5;
		*nCash5 = *nCash4;
		*nCash4 = nPlayerCash;
		
		*nBalance10 = *nBalance9;
		*nBalance9 = *nBalance8;
		*nBalance8 = *nBalance7;
		*nBalance7 = *nBalance6;
		*nBalance6 = *nBalance5;
		*nBalance5 = *nBalance4;
		*nBalance4 = nPlayerBalance;
		
		*nTop10Checker = 4;
	}
	
	if (nPlayerBalance >= *nBalance5 && nPlayerBalance < *nBalance4)
	{
		*nCash10 = *nCash9;
		*nCash9 = *nCash8;
		*nCash8 = *nCash7;
		*nCash7 = *nCash6;
		*nCash6 = *nCash5;
		*nCash5 = nPlayerCash;
		
		*nBalance10 = *nBalance9;
		*nBalance9 = *nBalance8;
		*nBalance8 = *nBalance7;
		*nBalance7 = *nBalance6;
		*nBalance6 = *nBalance5;
		*nBalance5 = nPlayerBalance;
		
		*nTop10Checker = 5;
	}
	
	if (nPlayerBalance >= *nBalance6 && nPlayerBalance < *nBalance5)
	{
		*nCash10 = *nCash9;
		*nCash9 = *nCash8;
		*nCash8 = *nCash7;
		*nCash7 = *nCash6;
		*nCash6 = nPlayerCash;
		
		*nBalance10 = *nBalance9;
		*nBalance9 = *nBalance8;
		*nBalance8 = *nBalance7;
		*nBalance7 = *nBalance6;
		*nBalance6 = nPlayerBalance;
		
		*nTop10Checker = 6;
	}
	
	if (nPlayerBalance >= *nBalance7 && nPlayerBalance < *nBalance6)
	{
		*nCash10 = *nCash9;
		*nCash9 = *nCash8;
		*nCash8 = *nCash7;
		*nCash7 = nPlayerCash;
		
		*nBalance10 = *nBalance9;
		*nBalance9 = *nBalance8;
		*nBalance8 = *nBalance7;
		*nBalance7 = nPlayerBalance;
		
		*nTop10Checker = 7;
	}
	
	if (nPlayerBalance >= *nBalance8 && nPlayerBalance < *nBalance7)
	{
		*nCash10 = *nCash9;
		*nCash9 = *nCash8;
		*nCash8 = nPlayerCash;
		
		*nBalance10 = *nBalance9;
		*nBalance9 = *nBalance8;
		*nBalance8 = nPlayerBalance;
		
		*nTop10Checker = 8;
	}
	 
	if (nPlayerBalance >= *nBalance9 && nPlayerBalance < *nBalance8)
	{
		*nCash10 = *nCash9;
		*nCash9 = nPlayerCash;
		
		*nBalance10 = *nBalance9;
		*nBalance9 = nPlayerBalance;
		
		*nTop10Checker = 9;
	}
	 
	if (nPlayerBalance >= *nBalance10 && nPlayerBalance < *nBalance9)
	{
		*nCash10 = nPlayerCash;
		
		*nBalance10 = nPlayerBalance;
		
		*nTop10Checker = 10;
	}
	
	if (nPlayerBalance < *nBalance10)
		*nTop10Checker = 0;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: gets the name of the recent player, and moves the name records/placement if recent player is one of the top 10;
			if not it only asks for the user to input any character to go back to the main menu/starting menu
Parameter:
	*cNameTop1 - string name of top 1
	*cNameTop2 - string name of top 2
	*cNameTop3 - string name of top 3
	*cNameTop4 - string name of top 4
	*cNameTop5 - string name of top 5
	*cNameTop6 - string name of top 6
	*cNameTop7 - string name of top 7
	*cNameTop8 - string name of top 8
	*cNameTop9 - string name of top 9
	*cNameTop10 - string name of top 10
	bTopChecker - boolean for checking the latest player's standing
Return value: (void) updates and passes the updated chronological order of the names after confirming if recent player is a top 10 lister
*/
void getTopOilbularyoName(
	char *cNameTop1, char *cNameTop2, char *cNameTop3, char *cNameTop4, char *cNameTop5,
	char *cNameTop6, char *cNameTop7, char *cNameTop8, char *cNameTop9, char *cNameTop10,
	int bTopChecker)
{
	char cPlayerName[31];
	char cConfirmLetter;
	
	if (bTopChecker >= 1 && bTopChecker <= 10)
	{
		printf("\n\n\n%99s\n%77s", "You are now one of the top Oilbularyos", "Enter thy name: ");
		scanf(" %[^\n]%*c", cPlayerName);
						
		if(bTopChecker == 1)
		{
			strcpy(cNameTop10, cNameTop9);
			strcpy(cNameTop9, cNameTop8);
			strcpy(cNameTop8, cNameTop7);
			strcpy(cNameTop7, cNameTop6);
			strcpy(cNameTop6, cNameTop5);
			strcpy(cNameTop5, cNameTop4);
			strcpy(cNameTop4, cNameTop3);
			strcpy(cNameTop3, cNameTop2);
			strcpy(cNameTop2, cNameTop1);
			strcpy(cNameTop1, cPlayerName);
		}
						
		if(bTopChecker == 2)
		{
			strcpy(cNameTop10, cNameTop9);
			strcpy(cNameTop9, cNameTop8);
			strcpy(cNameTop8, cNameTop7);
			strcpy(cNameTop7, cNameTop6);
			strcpy(cNameTop6, cNameTop5);
			strcpy(cNameTop5, cNameTop4);
			strcpy(cNameTop4, cNameTop3);
			strcpy(cNameTop3, cNameTop2);
			strcpy(cNameTop2, cPlayerName);
		}
						
		if(bTopChecker == 3)
		{
			strcpy(cNameTop10, cNameTop9);
			strcpy(cNameTop9, cNameTop8);
			strcpy(cNameTop8, cNameTop7);
			strcpy(cNameTop7, cNameTop6);
			strcpy(cNameTop6, cNameTop5);
			strcpy(cNameTop5, cNameTop4);
			strcpy(cNameTop4, cNameTop3);
			strcpy(cNameTop3, cPlayerName);
		}
			
		if(bTopChecker == 4)
		{
			strcpy(cNameTop10, cNameTop9);
			strcpy(cNameTop9, cNameTop8);
			strcpy(cNameTop8, cNameTop7);
			strcpy(cNameTop7, cNameTop6);
			strcpy(cNameTop6, cNameTop5);
			strcpy(cNameTop5, cNameTop4);
			strcpy(cNameTop4, cPlayerName);
		}
						
		if(bTopChecker == 5)
		{
			strcpy(cNameTop10, cNameTop9);
			strcpy(cNameTop9, cNameTop8);
			strcpy(cNameTop8, cNameTop7);
			strcpy(cNameTop7, cNameTop6);
			strcpy(cNameTop6, cNameTop5);
			strcpy(cNameTop5, cPlayerName);
		}
						
		if(bTopChecker == 6)
		{
			strcpy(cNameTop10, cNameTop9);
			strcpy(cNameTop9, cNameTop8);
			strcpy(cNameTop8, cNameTop7);
			strcpy(cNameTop7, cNameTop6);
			strcpy(cNameTop6, cPlayerName);
		}
						
		if(bTopChecker == 7)
		{
			strcpy(cNameTop10, cNameTop9);
			strcpy(cNameTop9, cNameTop8);
			strcpy(cNameTop8, cNameTop7);
			strcpy(cNameTop7, cPlayerName);
		}
						
		if(bTopChecker == 8)
		{
			strcpy(cNameTop10, cNameTop9);
			strcpy(cNameTop9, cNameTop8);
			strcpy(cNameTop8, cPlayerName);
		}
						
		if(bTopChecker == 9)
		{
			strcpy(cNameTop10, cNameTop9);
			strcpy(cNameTop9, cPlayerName);
		}
						
		if(bTopChecker == 10)
		{
			strcpy(cNameTop10, cPlayerName);
		}
	}
				
	else
	{
		printf("\n\n\n%90s", "Enter any character: ");
		scanf(" %c", &cConfirmLetter);
	}
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays the summary of the remaining stocks count, prices, cash, debt, loan, and balance of the player after every sales trip;
				it also determines if latest player is a top 10 lister by calling the function determineIfTop10Lister()
Parameters:
	nOilbularyoCash - player's remaining cash
	nOilbularyoDebt - player's remaining debt
	nOilbularyoLemon - player's remaining drops of lemon
	nLemonPrice - player's remaining total price of lemon
	nOilbularyoLavender - player's remaining drops of lavender
	nLavenderPrice - player's remaining total price of lavender
	nOilbularyoRosemary - player's remaining drops of rosemary
	nRosemaryPrice - player's remaining total price of rosemary
	nOilbularyoMint - player's remaining drops of mint
	int nMintPrice - player's remaining total price of mint
	nOilbularyoClearMinds - player's remaining bottles of clear minds
	nClearMindsPrice - player's remaining total price of clear minds
	nOilbularyoCalming - player's remaining bottles of calming
	nCalmingPrice - player's remaining total price of calming
	nOilbularyoEnergyBooster - player's remaining bottles of energy booster
	nEnergyBoosterPrice - player's remaining total price of energy booster
	nOilbularyoBalance - player's remaining balance
	*nCash1 - remaining cash of top 1 oilbularyo
	*nCash2 - remaining cash of top 2 oilbularyo
	*nCash3 - remaining cash of top 3 oilbularyo
	*nCash4 - remaining cash of top 4 oilbularyo
	*nCash5 - remaining cash of top 5 oilbularyo
	*nCash6 - remaining cash of top 6 oilbularyo
	*nCash7 - remaining cash of top 7 oilbularyo
	*nCash8 - remaining cash of top 8 oilbularyo
	*nCash9 - remaining cash of top 9 oilbularyo
	*nCash10 - remaining cash of top 10 oilbularyo
	*nBalance1 - remaining balance of top 1 oilbularyo
	*nBalance2 - remaining balance of top 2 oilbularyo
	*nBalance3 - remaining balance of top 3 oilbularyo
	*nBalance4 - remaining balance of top 4 oilbularyo
	*nBalance5 - remaining balance of top 5 oilbularyo
	*nBalance6 - remaining balance of top 6 oilbularyo
	*nBalance7 - remaining balance of top 7 oilbularyo
	*nBalance8 - remaining balance of top 8 oilbularyo
	*nBalance9 - remaining balance of top 9 oilbularyo
	*nBalance10 - remaining balance of top 10 oilbularyo
	*nTop10Checker - boolean for latest player's top standing
Return value: (void) updates and passes the latest player's cash, and balance to the top 10 oilbularyos' cash and balance;
					updates a new chronological order of top oilbularyos' cash and balance; passes a standing if player is a top 10 lister
*/
void displayOilbularyoInfoSummary(
	int nOilbularyoCash, int nOilbularyoDebt, 
	int nOilbularyoLemon, int nLemonPrice,
	int nOilbularyoLavender, int nLavenderPrice,
	int nOilbularyoRosemary, int nRosemaryPrice,
	int nOilbularyoMint, int nMintPrice,
	int nOilbularyoClearMinds, int nClearMindsPrice, 
	int nOilbularyoCalming, int nCalmingPrice,
	int nOilbularyoEnergyBooster, int nEnergyBoosterPrice,
	int nOilbularyoBalance,
	
	int *nCash1, int *nCash2, int *nCash3, int *nCash4, int *nCash5, 
	int *nCash6, int *nCash7, int *nCash8, int *nCash9, int *nCash10, 
	
	int *nBalance1, int *nBalance2, int *nBalance3, int *nBalance4, int *nBalance5, 
	int *nBalance6, int *nBalance7, int *nBalance8, int *nBalance9, int *nBalance10, 
	
	int *nTop10Checker)
{
	system("Color 0D");
	
	//char *nOilbularyoName[31];
	
	printf("\n\n\n\n%98s\n\n", "Oilbularyo traveled back home with...");
	
	//fincancial summary
	printf("%80s %c ", "Cash:", S);	// 7 characters
	displayMoney(nOilbularyoCash);	// 7 characters
	
	printf("\n\n");
	printf("%80s %c ", "Debt:", S);	// 7 characters
	displayMoney(nOilbularyoDebt);	// 7 characters
	printf("\n\n");
	
	//essential oils summary
	printf("%87s\n", "ESSENTIAL OILS");
	printf("%80s %c ", "Lemon:", S);
	displayMoney(nLemonPrice);
	printf(" (drp/s: %4d)\n", nOilbularyoLemon);
	printf("%80s %c ", "Lavender:", S);
	displayMoney(nLavenderPrice);
	printf(" (drp/s: %4d)\n", nOilbularyoLavender);
	printf("%80s %c ", "Rosemary:", S);
	displayMoney(nRosemaryPrice);
	printf(" (drp/s: %4d)\n", nOilbularyoRosemary);
	printf("%80s %c ", "Mint:", S);
	displayMoney(nMintPrice);
	printf(" (drp/s: %4d)\n\n", nOilbularyoMint);
	
	//diffuser oils summary
	printf("%86s\n", "DIFFUSER OILS");
	printf("%80s %c ", "Clear Minds:", S);
	displayMoney(nClearMindsPrice);
	printf(" (btl/s: %4d)\n", nOilbularyoClearMinds);
	printf("%80s %c ", "Calming:", S);
	displayMoney(nCalmingPrice);
	printf(" (btl/s: %4d)\n", nOilbularyoCalming);
	printf("%80s %c ", "Energy Booster:", S);
	displayMoney(nEnergyBoosterPrice);
	printf(" (btl/s: %4d)\n\n", nOilbularyoEnergyBooster);
	
	//balance
	printf("%80s %c ", "BALANCE:", S);
	displayMoney(nOilbularyoBalance);
	printf("\n\n\n");
	
		
	determineIfTop10Lister(
		nOilbularyoCash, nOilbularyoBalance, 
		
		&*nCash1, &*nCash2, &*nCash3, &*nCash4, &*nCash5, 
		&*nCash6, &*nCash7, &*nCash8, &*nCash9, &*nCash10, 
	
		&*nBalance1, &*nBalance2, &*nBalance3, &*nBalance4, &*nBalance5, 
		&*nBalance6, &*nBalance7, &*nBalance8, &*nBalance9, &*nBalance10, 
		
		&*nTop10Checker);
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: displays a divider at the bottom of the main/starting menu
Parameters: none 
Return value: (void) displays a divider at the bottom of the main/starting menu
*/
void displayMainMenuScanDivider()
{
	printf("\n\n%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c",
		PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH); //15 characters w/ 3 spaces in between
	printf("%6c", LR);
	displayFloatingIcons(1, 27, H, 1);	//27 characters
	printf("%c", LL);
	printf("%6c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c%4c\n",
		PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH, PHV, PVH);	//15 characters w/ 3 spaces in between
	printf("%91s", "Choose letter of action: ");
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Definition: displays the 3 choices that the player could do, start the game, view the tp 10, and exit the game
Parameters: none
Return value: (void) displays the 3 choices that the player could do, start the game, view the tp 10, and exit the game
*/
void displayMainMenuChoices()
{
	printf("\n\n%14c%23c%20c%15c%4c%c%c%c%9c%10c%21c%22c\n\n", C, LAO, B, R, H, H, H, H, PVH, CM, T, B);
	printf("%10c%23c%19c%20c%13s\n%84s%4c%21c%18c%22\n\n", B, EB, MO, VD, "Oil-bularyo", "ON THE GO", V, B, C, RO);
	printf("%5c%21c%19c%27c%9c%c%c%c%4c\n%120c%23c\n\n", RO, B, T, PHV, HD, HD, HD, HD, L, T, B);
	
	printf("%11c%20c%17c%18c", CM, LAO, B, UR);
	displayFloatingIcons(1, 27, H, 1);	//27 characters
	printf("%c\n", UL);
	printf("%66c%24s%4c%19c%21c%18c\n", V, "o. Start a Sales Trip", V, B, LEO, MO);
	printf("%66c", LR);
	displayFloatingIcons(1, 27, H, 1);	//27 characters
	printf("%c\n%4c%15c%17c\n", LL, B, T, C);
	
	printf("%66c", UR);
	displayFloatingIcons(1, 27, H, 1);	//27 characters
	printf("%c\n", UL);
	printf("%66c%26s%2c%14c%16c%19c\n", V, "v. View the Top Ten List", V, EB, LAO, RO);
	printf("%66c", LR);
	displayFloatingIcons(1, 27, H, 1);	//27 characters
	printf("%c\n%12c%20c%18c\n", LL, LEO, MO, RO);
	
	printf("%66c", UR);
	displayFloatingIcons(1, 27, H, 1);	//27 characters
	printf("%c\n", UL);
	printf("%66c%22s%6c%18c%16c%22c\n", V, "x. Exit the Game", V, MO, B, CM);
	printf("%6c%18c%20c%22c", EB, B, T, LR);
	displayFloatingIcons(1, 27, H, 1);	//27 characters
	printf("%c\n%117c%20c\n", LL, RO, T);
}	//P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
Description: the starting point of the game, it calls specific functions for the game to cycle around until player decides to exit the game
Parameter: none
Return value: (void)
*/
void executeOilbularyoGame()
{
	int nRemainingCash;
	int nRemainingDebt;
	int nRemainingLemon, nLemonTotalPrice;
	int nRemainingLavender, nLavenderTotalPrice;
	int nRemainingRosemary, nRosemaryTotalPrice;
	int nRemainingMint, nMintTotalPrice;
	int nRemainingClearMinds, nClearMindsTotalPrice;
	int nRemainingCalming, nCalmingTotalPrice;
	int nRemainingEnergyBooster, nEnergyBoosterTotalPrice;
	int nRemainingBalance;
	
	//names could support 30 visible characters
	char cNameTop1[31];	// = {'a', 'L', 'f', '4', ' ', '0', '1', '\0'}
	char cNameTop2[31];	// = {'D', 'R', '4', '6', '0', 'N', '\0'}
	char cNameTop3[31];	// = {'!', 's', 'u', 'p', 'a', '\0'}
	char cNameTop4[31];	// = {'~', ' ', 'U', ' ', '~', '\0'}
	char cNameTop5[31];	// = {'|', '*', '_', '*', '|', '\0'}
	char cNameTop6[31];	// = {'L', '0', 'L', '\0'}
	char cNameTop7[31];	// = {'!', ' ', 'n', 'a', 'n', 'i', ' ', '!', '\0'}
	char cNameTop8[31];	// = {'h', 'a', 'k', 'd', 'o', 'g', '\0'}
	char cNameTop9[31];	// = {'O', 'N', 'O', '\0'}
	char cNameTop10[31];// = {'Y', '\0'}
	
	int nCashTop1 = 0;	//5000
	int nCashTop2 = 0;	//4500
	int nCashTop3 = 0;	//4000
	int nCashTop4 = 0;	//3500
	int nCashTop5 = 0;	//3000
	int nCashTop6 = 0;	//2500
	int nCashTop7 = 0;	//2000
	int nCashTop8 = 0;	//2400
	int nCashTop9 = 0;	//3900
	int nCashTop10 = 0;	//1800
	
	int nBalanceTop1 = 0;	//2000
	int nBalanceTop2 = 0;	//1750
	int nBalanceTop3 = 0;	//1500
	int nBalanceTop4 = 0;	//1250
	int nBalanceTop5 = 0;	//1000
	int nBalanceTop6 = 0;	//900
	int nBalanceTop7 = 0;	//750
	int nBalanceTop8 = 0;	//600
	int nBalanceTop9 = 0;	//400
	int nBalanceTop10 = 0;	//150
	
	char cMainMenuLetter;
	
	int bTopChecker;
	
	do
	{
		system("Color 0B");
	
		printf("%2c%27c%30c%37c%29c%21c", T, B, LEO, MO, B, EB);
		
		displayMainMenuChoices();
	
		displayMainMenuScanDivider();
	
		scanf(" %c", &cMainMenuLetter);
	
		switch (cMainMenuLetter)
		{
			case 'o':
				system("CLS");
				displayGameMenu(
					&nRemainingCash, &nRemainingDebt,
					&nRemainingLemon, &nLemonTotalPrice,
					&nRemainingLavender, &nLavenderTotalPrice,
					&nRemainingRosemary, &nRosemaryTotalPrice,
					&nRemainingMint, &nMintTotalPrice,
					&nRemainingClearMinds, &nClearMindsTotalPrice,
					&nRemainingCalming, &nCalmingTotalPrice,
					&nRemainingEnergyBooster, &nEnergyBoosterTotalPrice,
					&nRemainingBalance, 
						
					&bTopChecker); 
					
				displayOilbularyoInfoSummary(
					nRemainingCash, nRemainingDebt,
					nRemainingLemon, nLemonTotalPrice,
					nRemainingLavender, nLavenderTotalPrice,
					nRemainingRosemary, nRosemaryTotalPrice,
					nRemainingMint, nMintTotalPrice,
					nRemainingClearMinds, nClearMindsTotalPrice,
					nRemainingCalming, nCalmingTotalPrice,
					nRemainingEnergyBooster, nEnergyBoosterTotalPrice,
					nRemainingBalance, 
					
					&nCashTop1, &nCashTop2, &nCashTop3, &nCashTop4, &nCashTop5, 
					&nCashTop6, &nCashTop7, &nCashTop8, &nCashTop9, &nCashTop10, 
					
					&nBalanceTop1, &nBalanceTop2, &nBalanceTop3, &nBalanceTop4, &nBalanceTop5, 
					&nBalanceTop6, &nBalanceTop7, &nBalanceTop8, &nBalanceTop9, &nBalanceTop10, 
					
					&bTopChecker);
				
				getTopOilbularyoName(
					cNameTop1, cNameTop2, cNameTop3, cNameTop4, cNameTop5,
					cNameTop6, cNameTop7, cNameTop8, cNameTop9, cNameTop10,
					bTopChecker);
				
				system("CLS");
				break;
			
			case 'v':
				system("CLS");
				displayTopTenList(
					cNameTop1, cNameTop2, cNameTop3, cNameTop4, cNameTop5, 	// from displayTopTenList()
					cNameTop6, cNameTop7, cNameTop8, cNameTop9, cNameTop10, 
	
					nCashTop1, nCashTop2, nCashTop3, nCashTop4, nCashTop5, 
					nCashTop6, nCashTop7, nCashTop8, nCashTop9, nCashTop10, 
				
					nBalanceTop1, nBalanceTop2, nBalanceTop3, nBalanceTop4, nBalanceTop5, 
					nBalanceTop6, nBalanceTop7, nBalanceTop8, nBalanceTop9, nBalanceTop10);
				break;
			
			case 'x' :
				system("CLS");
				break;
			
			default:
				displayInvalidInputNote();
				break;
		}
	}
	while(cMainMenuLetter != 'x');
}	// P

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/





int main ()
{	
	srand(time(0));
	
	executeOilbularyoGame();
	
	return 0;
}



// width - 160 characters ; length - 30-100 characters
/*
<color ID> - <color>
1 - Blue
2 - Green
3 - Aqua
4 - Red
5 - Purple
6 - Yellow
7 - White/light gray
8 - Gray
9 - Light blue
0 - Black
A - Light green
B - Light aqua
C - Light red
D - Light purple
E - Light yellow
F - Bright white 
*/
