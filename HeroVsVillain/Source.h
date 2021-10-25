//Name: Lukas Sumkauskas
//ID: C00263149
//
//Date: 2021 October

#pragma once


#include <random> // srand
#include <iostream> // standard library
#include <string> // string
#include <time.h> // std::time



struct GameObject
{
public:
	GameObject() {};
	//Virtual functions
	virtual void attack() = 0;
	virtual void stab() = 0;
	virtual void shield() = 0;
	virtual void say() = 0;
	//Set/get functions
	virtual void setHealth(int t_health) { health = t_health; } //Sets the initial health
	virtual void takeHealth(int t_multiplier) { health -= t_multiplier; }//Takes away from health using the argument
	virtual void setDamage(int t_damage) { damage = t_damage; } //Sets the initial damage
	virtual void setDefence(int t_defence) { defence = t_defence; } //Sets the initial defence
	virtual void setName(std::string t_name) { name = t_name; } //Function that sets a name by passing an argument
	virtual int getHealth() { return health; } //Retrieves health
	virtual int getDamage() { return damage; } //Retrieves damage
	virtual int getDefence() { return defence; } //Retrieves defence


	//Data variables
	int health = 0;
	int damage = 0;
	int defence = 0;
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
		setDefence(defence);
	};
	//Default destructor
	~Hero()
	{};

	//Heroes public functions
	void attack() { std::cout << "- Taste the fiery of my weapon!\n"; }
	void stab() { std::cout << "- Try avoiding this!\n"; }
	void shield() { std::cout << "- You don't stand a chance against my mighty shield.\n"; }
	void say() { std::cout << " - Kingdoms enemy, is my enemy.\nI shall obliterate everyone\nwho is in the way of the Kingdom.\n"; }

	//Local data members
	int health = 150;
	int damage = 10;
	int defence = 55;
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
		setDefence(defence);
	};
	//Default destructor
	~Villain()
	{};
	//Villain public functions
	void attack() { std::cout << " - You shall know darkness, by tasting my sword!\n"; }
	void stab() { std::cout << " - Do you bleed?\n"; }
	void shield() { std::cout << " - Fool, you are too weak to penetrate my shield\n"; }
	void say() { std::cout << " - Stormblessed or not, you don't stand a chance against me!\n"; }

	//Villain local data members
	int health = 175;
	int damage = 4;
	int defence = 65;
	std::string name = "Taravangian";
};

/// <summary>
/// Structure of weaponDamage using enum class to set initial damage
/// </summary>
struct weaponValues
{	//Constructor and destructor
	weaponValues() {};
	~weaponValues() {};
	
	//Local data members
	std::string name = "";
	std::string icon[9]; //String for ASCII art to represent style
	int damage = 1;
	int defence = 1;
	int recoil = 1;

public:
	//Function that sets the initial values to weapons/shields
	void chooseWeapon(int t_value)
	{
		if (t_value == 1) //If it's melee, set icon as sword
		{
			icon[0] = "                      O\n";
			icon[1] = "	   	      {____________________________________\n";
			icon[2] = "	@XXXXXXXXXXXXXX___________________________________.>\n";
			icon[3] = "	              {\n";
			icon[4] = "                      O\n";		
		}
		if (t_value == 2)//If it's stab, set icon as a rapier
		{
			icon[0] = "       |\n";
			icon[1] = "       /~\\\n";
			icon[2] = "Oxxxxx|  (|=========================-\n";
			icon[3] = " \\____/\\_/\n";
			icon[4] = "       |\n";
		}
		if (t_value == 3)//If it's a block, set icon as a shield
		{
			icon[0] = "|`-._/\\_.-`|\n";
			icon[1] = "|    ||    |\n";
			icon[2] = "|___o()o___|\n";
			icon[3] = "|__((<>))__|\n";
			icon[4] = "\\   o\\/o   /\n";
			icon[5] = " \\   ||   /\n"; 
			icon[6] = "  \\  ||  /\n";
			icon[7] = "   '.||.'\n";
			icon[8] = "     ``\n";
		}
		//Randomizer seed
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
			std::cout << "*User has chosen to attack*\n";
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
				defence = 12;
				break;
			case 2:
				name = "Dragonfire Shield\n";
				recoil = 5;
				defence = 20;
				break;
			case 3:
				name = "Recoil Shield\n";
				recoil = 20;
				defence = 7;
				break;
			default:
				break;
			}
		}
	};
};

/// <summary>
/// Structure responsible for battles, deduction of health
/// </summary>
struct battle
{
	//Default constructor and destructor
	battle() {};
	~battle() {};
public:  
	void damageDeduction(GameObject* t_defender,GameObject* t_attacker, int t_weaponDamage, int t_defenderRecoil, int t_shieldDefence)
	{
		//Complex formula to calculate the damage dealt depending on defenders defence
		float damageDealt = (t_weaponDamage + t_attacker->getDamage())*(100.0/(100.0 + ((double)t_defender->defence + t_shieldDefence))); 
		std::cout << "*" + t_defender->name + " took " + std::to_string((int)damageDealt) + " damage*\n";
		t_defender->takeHealth((int)damageDealt);
		if (t_defenderRecoil != 0)
		{
			t_attacker->takeHealth(t_defenderRecoil);
			std::cout << "*" + t_attacker->name + " has taken " + std::to_string(t_defenderRecoil) + " damage due to the recoil of the shield*\n";
		}
	}
};

/// <summary>
/// A structure build of lore that contains the story, conversations, etc
/// </summary>
struct lore
{
	//Constructor and destructor
	lore() {};
	~lore() {};
	std::string welcome = "  - Welcome aboard player, you have been chosen to represent the Stormblesseds,\nyour goal is to defeat the villain and defend the kingdom!\n Are you up for the challenge?\n";
public:
	//Function that halts the processes in the game for more aesthetic look in the console
	void halt() { std::cout << "\n*Press <ENTER> to continue*\n"; std::cin.ignore(); }
	void narrator() { std::cout << " says:\n"; } //For using functions as say(), attack() and such that outputs a text


};


/// <summary>
/// Game class containing run function for the loop and GameObject structure instance pointers
/// </summary>
class Game
{
	//Pointers of the objects
	GameObject* player = new Hero(); //Gameobject pointer which points to the hero
	GameObject* villain = new Villain(); //Gameobject pointer which points to the villain
	weaponValues* m_values = new weaponValues(); //Points to the values of the weapons
	lore* story = new lore(); //Lore object pointer
	battle* fight = new battle(); //Battle object pointer
	//Function to run the game loop
public:
	void run();
};