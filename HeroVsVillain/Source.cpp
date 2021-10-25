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
	//Random seed for villain's roll
	std::srand(static_cast<unsigned>(time(nullptr)));
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
	while (player->getHealth() > 0 || villain->getHealth() > 0)//Loop the turn based game until one of the characters dies
	{
		if (player->getHealth() <= 0)//If you have died
		{
			std::cout << "\n\n  -- " + player->name + ", you have failed us, the danger of our kingdom was not stopped.\nMaybe you are not the chosen one..\n\n";
			std::cout << "\n\n *You have lost...\n\n";
			break;
		}
		if (villain->getHealth() <= 0)//If you killed villain
		{
			std::cout << "\n\n  -- " + player->name + ", you have proven yourself as a Stormblessed,\nyou are indeed, a chosen one..\n\n";
			std::cout << "\n\n *You have won, congratulations!\n\n";
			break;
		}
		if (player->getHealth() <= 0 && villain->getHealth() <= 0)//If draw
		{
			std::cout << "\n\n  -- " + player->name + " has fought till the end,\nhe made not just us,\nbut all Stormblessed proud..\n\n";
			std::cout << "\n\n *You have won, congratulations!\n\n";
			break;
		}
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
		story->halt();
		std::cout << "-- Weapon stats --\n";
		//#1 - Melee, #2 - Stab, #3 - Shield
		if (x == 1 || x == 2) //If it's a weapon, print weapon values
		{
			std::cout << "//Damage: " + std::to_string(m_values->damage) + "\n";
			story->halt();
			if (x == 1)
			{
				std::cout << player->name; story->narrator();
				player->attack();
				std::cout << "\n";
			}
			else
			{
				std::cout << player->name; story->narrator();
				player->stab();
				std::cout << "\n";
			}
			fight->damageDeduction(villain, player, m_values->damage, m_values->recoil, m_values->defence);
			std::cout << "\n\n*" + villain->name + "has " + std::to_string(villain->getHealth()) + " hitpoints left*\n\n";
			std::cout << "*" + player->name + " has " + std::to_string(player->getHealth()) + " hitpoints left*\n\n";
		}
		if (x == 3) //If it's a shield, print shield's values
		{
			std::cout << "\n";
			std::cout << player->name; story->narrator();
			player->shield();
			std::cout << "\n";
			std::cout << "//Defence: " + std::to_string(m_values->defence) + "\n";
			std::cout << "//Recoil: " + std::to_string(m_values->recoil) + "\n";
		}
		story->halt();

		//Villains turn
		std::cout << "\n*" + villain->name + " is taking his turn*\n";
		story->halt();
		int roll = (rand() % 3) + 1;
		m_values->chooseWeapon(roll); //Calls a function chooseWeapon and sends an argument roll
		if (roll == 1) // If it's melee, print melee icon
		{
			for (int i = 0; i < 5; i++)
			{
				std::cout << m_values->icon[i];
			}
		}
		if (roll == 2) // If it's stab, print stab icon
		{
			for (int i = 0; i < 5; i++)
			{
				std::cout << m_values->icon[i];
			}
		}
		if (roll == 3)//If it's block, print shield icon
		{
			for (int i = 0; i < 9; i++)
			{
				std::cout << m_values->icon[i];
			}
		}
		std::cout << "\n-" + villain->name + " has received a " + m_values->name + "\n";
		story->halt();
		std::cout << "-- Weapon stats --\n";
		//#1 - Melee, #2 - Stab, #3 - Shield
		if (roll == 1 || roll == 2) //If it's a weapon, print weapon values
		{
			std::cout << "//Damage: " + std::to_string(m_values->damage) + "\n";
			story->halt();
			if (roll == 1)
			{
				std::cout << villain->name; story->narrator();
				villain->attack();
				std::cout << "\n";
			}
			else
			{
				std::cout << villain->name; story->narrator();
				villain->stab();
				std::cout << "\n";
			}
			fight->damageDeduction(player, villain, m_values->damage, m_values->recoil, m_values->defence);
			if (player->getHealth() <= 0 || villain->getHealth() <= 0)
			{
				if (player->getHealth() <= 0)
				{
					std::cout << "\n\n*Oh dear," + player->name + " has died..\n";
				}
				if (villain->getHealth() <= 0)
				{
					std::cout << "\n\n*Oh dear," + villain->name + " has died..\n";
				}
			}
			else
			{
				std::cout << "\n\n*" + player->name + " has " + std::to_string(player->getHealth()) + " hitpoints left*\n\n";
				std::cout << "*" + villain->name + " has " + std::to_string(villain->getHealth()) + " hitpoints left*\n\n";
			}
		}
		if (roll == 3) //If it's a shield, print shield's values
		{
			std::cout << "\n";
			std::cout << villain->name; story->narrator();
			villain->shield();
			std::cout << "\n";
			std::cout << "//Defence: " + std::to_string(m_values->defence) + "\n";
			std::cout << "//Recoil: " + std::to_string(m_values->recoil) + "\n";
		}
		story->halt();
	}
}

