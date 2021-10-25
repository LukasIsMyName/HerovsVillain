#pragma once
//Enum class defining which number represents which weapon in the class Melee

#include <random> // srand
#include <iostream> // standard library
#include <string> // string
#include <time.h> // std::time

enum class Melee
{
	Broadsword,
	Longsword,
	Katana,
	Mace,
	Scimitar,
	twoHandedSword,
	Whip
};

//Enum class defining which number represents which weapon in the class Stab
enum class Stab
{
	Dagger,
	Knife,
	Needle,
	Rapier,
	Spear
};

//Enum class defining which number represents which shiled in the class Shield
enum class Shield
{
	BerserkerShield,
	DragonFireShield,
	RecoilShield
};


struct GameObject
{
public:
	GameObject() {};
	//Virtual functions
	virtual void attack() = 0;
	virtual void stab() = 0;
	virtual void shield() = 0;
	//Set/get functions
	virtual void setHealth(int t_health) { health = t_health; } //Sets health
	virtual void setDamage(int t_damage) { damage += t_damage; } //Adds damage of the weapon to the initial objects' damage
	virtual void setName(std::string t_name) { name = t_name; } //Changes the name depending on which character has been chosen
	virtual int getHealth() { return health; }; //Retrieves health


	//Data variables
	int health = 0;
	int damage = 0;
	std::string name = "";

};

/// <summary>
/// Structure of a subclass
/// </summary>
struct Hero : public GameObject
{
	//Default constructor
	Hero()
	{
		setHealth(health);
		setDamage(damage);
		setName(name);
	};
	//Default destructor
	~Hero()
	{};

	void attack() { std::cout << "- Taste the fiery of my weapon!\n"; }
	void stab() { std::cout << "- Try avoiding this!\n"; }
	void shield() { std::cout << "- You don't stand a chance against my mighty shield.\n"; }

	int health = 150;
	int damage = 10;
	std::string name = "Kaladin";
};

/// <summary>
/// Structure of the villain subclass
/// </summary>
struct Villain : public GameObject
{
	//Default constructor
	Villain()
	{
		setHealth(health);
		setDamage(damage);
		setName(name);
	};
	//Default destructor
	~Villain()
	{};

	void attack() { std::cout << "- Taste the fiery of my weapon!\n"; }
	void stab() { std::cout << "- Try avoiding this!\n"; }
	void shield() { std::cout << "- You don't stand a chance against my mighty shield.\n"; }

	int health = 175;
	int damage = 6;
	std::string name = "Taravangian";
};

/// <summary>
/// Structure of weaponDamage using enum class to set initial damage
/// </summary>
struct weaponValues
{
	weaponValues() {};
	~weaponValues() {};
	
	std::string name = "";
	int damage = 1;
	int defence = 1;
	int recoil = 1;

public:
	//Function that sets the initial values to weapons/shields
	void chooseWeapon(int t_value)
	{
		
		std::srand(static_cast<unsigned>(time(nullptr)));
		if (t_value == 1)
		{
			std::cout << "*User has chosen to attack*\n";
			std::cout << "*User has chosen attack style: Melee*\n";
			int random = (rand() % 7) + 1; // picks a random weapon from 1 to 7
			//Adding damage values to swords/melee weapons
			switch (random)
			{
			case 1:
				name = "Broadsword\n";
				damage = 15;
				break;
			case 2:
				name = "Longsword\n";
				damage = 12;
				break;
			case 3:
				name = "Katana\n";
				damage = 12;
				break;
			case 4:
				name = "Mace\n";
				damage = 15;
				break;
			case 5:
				name = "Scimitar\n";
				damage = 8;
				break;
			case 6:
				name = "2handed sword\n";
				damage = 18;
				break;
			case 7:
				name = "Whip\n";
				damage = 8;
				break;
			default:
				break;
			}
		}
		if (t_value == 2)
		{
			std::cout << "*User has chosen attack style: Stab*\n";
			int random = (rand() % 5) + 1; // picks a random weapon from 1 to 5
			//Adding damage values to daggers/stab weapons
			switch (random)
			{
			case 1:
				name = "Dagger\n";
				damage = 10;
				break;
			case 2:
				name = "Knife\n";
				damage = 7;
				break;
			case 3:
				name = "Needle\n";
				damage = 5;
				break;
			case 4:
				name = "Rapier\n";
				damage = 15;
				break;
			case 5:
				name = "Spear\n";
				damage = 20;
				break;
			default:
				break;
			}
		}
		if (t_value == 3)
		{
			int random = (rand() % 3) + 1; // picks a random weapon from 1 to 3
			//Adding recoil to shields as well as defence values
			std::cout << "*User has chosen to defend himself*\n";
			switch (random)
			{
			case 1:
				name = "Berserker Shield\n";
				recoil = 7;
				defence = 15;
				break;
			case 2:
				name = "Dragonfire Shield\n";
				recoil = 12;
				defence = 20;
				break;
			case 3:
				name = "Recoil Shield\n";
				recoil = 15;
				defence = 10;
				break;
			default:
				break;
			}
		}
	};
};


/// <summary>
/// Game class containing run function for the loop and GameObject structure instance pointers
/// </summary>
class Game
{
	//Pointers of the objects
	GameObject* player = new Hero();
	GameObject* villain = new Villain();
	weaponValues* m_values = new weaponValues(); //Values of the weapons
	//Function to run the game loop
public:
	void run();
};