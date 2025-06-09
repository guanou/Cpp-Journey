#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <list>
#include "header.hpp"



void for_loop_comprehension()
{
	/*int rows{};
	int colums{};

	std::cout << "Rows : " << std::endl;
	std::cin >> rows;

	std::cout << "Colums : " << std::endl;
	std::cin >> colums;
	*/

	//Triangle
	std::cout << "---Triangle---" << std::endl;
	for (int i{ 3 }; i >= 0; --i)
	{
		for (int j{ 0 }; j <= 3 - i; j++)
		{
			std::cout << "*";
		}

		std::cout << std::endl;
	}
	//Carre
	std::cout << "---Carre---" << std::endl;

	for (int i{ 0 }; i <= 3; i++)
	{
		for (int j{ 0 }; j <= 3; j++)
		{
			std::cout << "#";
		}
		std::cout << std::endl;
	}
}

void list_comprehension()
{
	const int MAX_ITEMS = 10;
	std::string list[MAX_ITEMS];

	int nums_items = 0;
	list[nums_items++] = "Shield";
	list[nums_items++] = "Sword";
	list[nums_items++] = "Arrow";

	for (std::string liste : list)
	{
		std::cout << liste << std::endl;
	}


	//C-style
	char phrase[] = "James";
	std::cout << "Phrase en C-style" << phrase << std::endl;
}

void multi_list()
{
	const int rows{ 3 };
	const int colums{ 3 };
	char board[rows][colums] = { {'X' ,'O','X'},
							{ '0' ,'X','O'},
							{'X' ,'O','X'} };
	//std::cout << board[0][1] << std::endl;
	for (int i{ 0 }; i < rows; ++i)
	{
		for (int j{ 0 }; j < colums; ++j)
		{
			std::cout << board[i][j];

		}
		std::cout << std::endl;
	}
}

void vector_comprehension()
{
	/*std::vector<std::string> myInventory;

	myInventory.push_back("Sword");
	myInventory.push_back("Katana");
	myInventory.push_back("Fruit");
	std::vector<std::string>::const_iterator iter;
	std::vector<std::string>::iterator MyIter;
	MyIter = myInventory.begin();
	*MyIter = "Chocolat";
	myInventory.push_back(*MyIter);
	for (iter = myInventory.begin(); iter != myInventory.end(); iter++)
	{
		std::cout << *iter << std::endl;
	}

	*/
		/*std::vector<int> nombres = {1, 2, 3, 4, 5, 6};

		auto iter = nombres.begin();
		for (; iter!= nombres.end();++iter) {
			if (*iter % 2 == 0)
			{
				std::cout << (*iter)*2 << " ";
			}
			else
				std::cout << *iter << " ";
		}
		std::cout << std::endl;
		*/

	std::list<int> valeurs = { 1, 2, 3, 4, 5, 6 };

	// À compléter : supprimer les éléments impairs avec un itérateur


	auto iter = valeurs.begin();
	for (; iter != valeurs.end(); ++iter) {
		if (*iter % 2 != 0)
		{
			iter = valeurs.erase(iter);
		}
		
	}
	std::cout << std::endl;


	for (int n : valeurs) {
		std::cout << n << " ";
	}
	std::cout << std::endl;


}
/// <summary>
/// faire un classement des meilleurs jeux selon l utilisateur
/// </summary>
void game_list()
{
	std::vector<std::string>user_game_list;
	std::vector<std::string>::iterator ite;
	
	std::string user_input;
	char end_list='n';
	char other_game = 'y';

	std::cout << "What is your favorite game: ";
	std::cin >> user_input;
	user_game_list.push_back(user_input);
	while (end_list != 'y' && end_list != 'Y')
	{
		
		
		do
		{
			std::cout << "Game?: ";
			std::cin >> user_input;
			user_game_list.push_back(user_input);
			std::cout << "Others game?(n/y):  ";
			std::cin >> other_game;
			
			
			
		}while (other_game != 'n' && other_game != 'N');

		
		




		break;
		//std::cout << "Have you finish?(y/n) : ";
		//std::cin >> end_list;
	}
	for (auto ite = user_game_list.begin(); ite != user_game_list.end(); ++ite)
	{
		std::cout << "It is your favorite game:" << std::endl;
		std::cout << *ite << std::endl;
	}
}


inline float radiation(int health)
{
	return(health / 2);
}
void game_inline_comprehension()
{
	float health = 100;
	
	for (int i{ 0 }; i <= 5; ++i)
	{
		health = radiation(health);
		std::cout << health << std::endl;
	}
}

void display(const std::vector < std::string>& v)
{
	std::vector<std::string>::const_iterator ite = v.begin();
	for (; ite != v.end(); ++ite)
	{
		std::cout << *ite << std::endl;
	}
}
void reference()
{
	using namespace std;

	std::vector<string>inventory;
	inventory.push_back("Sword");
	inventory.push_back("Ammo");
	inventory.push_back("Kaatan");

	display(inventory);


}

inline std::string& ref_to_element(std::vector<std::string>& v, int i)
{
	return v[i];
}


void hero_inventory()
{
	using namespace std;
	std::vector<std::string>inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");
	std::string& rString = ref_to_element(inventory, 2);
	std::string st = ref_to_element(inventory, 1);
	cout << "Ton premiere objet: " <<endl<< ref_to_element(inventory, 0)<<endl;
	cout << "Ton deuxieme objet: "<<endl << ref_to_element(inventory, 1) << endl;
	cout << "Ton troiseme objet: " << endl << ref_to_element(inventory, 2) << endl;
	cout << "---------" << endl;

	for (auto& t : inventory)
	{
		cout << t << endl;
	}
	cout << "---------" << endl;

	cout << endl;
	cout << "Tu as ramasser une potion mais il faut que tu jette un objet" << endl;
	cout << "Tu as jeter le shield" << endl;
	cout << endl;
	cout << "---------" << endl;
	rString = "Potion de vie";
	st = "James";
	cout << "Ton troiseme objet: " << endl << ref_to_element(inventory, 2) << endl;
	cout << "ne fais pas de ref " << ref_to_element(inventory, 1) << endl;
	cout << endl;
	cout << "---------" << endl;
	for (auto& t : inventory)
	{
		cout << t << endl;
	}
}