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
	int x = 0;
	//Test
	std::cout << "'The heroes name is " + player->name + "'\n";
	std::cout << "'The villains name is " + villain->name + "'\n";
	std::cout << "'Choose a weapon'\n";
	std::cin >> x;
	m_values->chooseWeapon(x);
	std::cout << "-User has received a " + m_values->name + "\n";
	std::cout << "-- Weapon stats --\n";
	if (x == 1 || x == 2)
	{
		std::cout << "//Damage: " + std::to_string(m_values->damage) + "\n";
	}
	if (x == 3)
	{
		std::cout << "//Defence: " + std::to_string(m_values->defence) + "\n";
		std::cout << "//Recoil: " + std::to_string(m_values->recoil) + "\n";
	}
}

