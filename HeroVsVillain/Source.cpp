//Name: Lukas Sumkauskas
//ID: C00263149
//
//Date: 2021 October

#include "Source.h"


/// <summary>
/// Run function
/// </summary>
void Game::run()
{
	//Local variable for input
	int x = 0;
	std::cout << "                 ====)------------- Hero versus Villain -------------(====\n\n";
	story->halt();
	std::cout << story->welcome;
	story->halt();
	std::cout << "'You have been reincarnated as " + player->name + ", the Stormblessed'\n";
	std::cout << player->name; story->narrator();
	player->say();
	story->halt();
	std::cout << "\n - - Base Stats - - \n";
	std::cout << "\n//Health: " + std::to_string(player->getHealth()) << std::endl;
	std::cout << "//Damage: " + std::to_string(player->getDamage()) << std::endl;
	std::cout << "//Defence: " + std::to_string(player->getDefence()) << std::endl;
	story->halt();
	std::cout << "'The foe you are fighting against is " + villain->name + "'\n";
	std::cout << villain->name; story->narrator();
	villain->say();
	std::cout << "\n - -Base Stats - -\n";
	std::cout << "\n//Health: " + std::to_string(villain->getHealth()) << std::endl;
	std::cout << "//Damage: " + std::to_string(villain->getDamage()) << std::endl;
	std::cout << "//Defence: " + std::to_string(villain->getDefence()) << std::endl;
	story->halt();
	std::cout << "'What do you wish to do?'\n";
	std::cout << " -----------------------\n";
	std::cout << " #Enter 1 to use Melee\n #Enter 2 to use Stab\n #Enter 3 to block an Attack\n";
	std::cin >> x;
	if (x > 3 || x < 1) //Simple error checking if the values are in the range
	{
		do 
		{
			std::cout << "$Error, the number is out of range$\n-Please enter a valid value\n";
			std::cin >> x;
		} while (x > 3 || x < 1);//Loops until the statement is false
	}
	m_values->chooseWeapon(x); //Calls a function chooseWeapon and sends an argument x
	if (x == 1) // If it's melee, print melee icon
	{
		for (int i = 0; i < 5; i++)
		{
			std::cout << m_values->icon[i];
		}
	}
	if (x == 2) // If it's stab, print stab icon
	{
		for (int i = 0; i < 5; i++)
		{
			std::cout << m_values->icon[i];
		}
	}
	if (x == 3)//If it's block, print shield icon
	{
		for (int i = 0; i < 9; i++)
		{
			std::cout << m_values->icon[i];
		}
	}
	std::cout << "\n-" + player->name + " has received a " + m_values->name + "\n";
	std::cout << "-- Weapon stats --\n";
	//#1 - Melee, #2 - Stab, #3 - Shield
	if (x == 1 || x == 2) //If it's a weapon, print weapon values
	{
		std::cout << "//Damage: " + std::to_string(m_values->damage) + "\n";
		story->attackConfirm();
	}
	if (x == 3) //If it's a shield, print shield's values
	{
		std::cout << "//Defence: " + std::to_string(m_values->defence) + "\n";
		std::cout << "//Recoil: " + std::to_string(m_values->recoil) + "\n";
		story->attackConfirm();
	}
}

