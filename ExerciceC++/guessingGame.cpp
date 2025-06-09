#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "header.hpp"

//int min_number(int player_number);


/*

-void guessing_Game():
		- c est une fonction qui permet a l utilisateur de jouer et de chercher un nombre generer
			aleatoirement par l ordinateur


- void computer_guess():
		- c est le jeu ou l ordinateur devine le nombre

-la fonction search_algorithm<2>(int player_number, int computer_number, int count)
		- player_number : c est un nombre que l utilisateur a choisis
		- count : permet de compter le nombre de fois que l ordinateur a pris pour chercher le nombre
		- computer_number : c est l ordinateur qui choisis aleatoirement un nombre et faut l
			utilise comme ++i car comme ca permet de changer a chaque fois le nombre chercher

*/



void searching_algorithm(int player_number, int computer_number, int count);
void searching_algorithm2(int player_number, int computer_number, int count);

void guessing_Game()
{
	//Player
	srand(static_cast<unsigned int>(time(0)));
	int player_input;
	bool game_loop = true;
	int random_number = rand() % 101;
	short count = 0;
	std::cout << "Guess my number" << std::endl;
	while (game_loop)
	{
		std::cout << "Answer " << random_number << std::endl;
		std::cout << "Count " << count << std::endl;


		std::cin >> player_input;
		if (isdigit(player_input))
		{


			if (player_input == random_number)
			{
				std::cout << "You find it " << std::endl;
				game_loop = false;
			}
			else if (player_input < random_number)
			{
				if (player_input < 0) {
					std::cout << "You are out of range" << std::endl;

				}
				std::cout << "The number is greater , seek you can find it" << std::endl;

				++count;
			}
			else if (player_input > random_number)
			{
				if (player_input > 100) {
					std::cout << "You are out of range" << std::endl;

				}
				std::cout << "The number is lesser than your " << std::endl;

				++count;
			}


			if (count == 3)
			{
				std::cout << "You want help? Y/N" << std::endl;
				char answer_count;
				std::cin >> answer_count;
				if (answer_count == 'Y' || answer_count == 'y')
				{
					if (random_number <= 10)
						std::cout << "The number is in a range of " << 0 << " - " << random_number + 10 << std::endl;
					else
						std::cout << "The number is in a range of " << random_number - 10 << " - " << random_number + 10 << std::endl;
				}
				else
				{
					std::cout << "You can do it alone " << std::endl;
					continue;
				}
				if (player_input == random_number)
					game_loop = false;
			}

		}
		else
		{
			std::cout << "I want an integer" << std::endl;
			break;
		}
		if (!game_loop)
		{
			std::cout << "Thank you and bye" << std::endl;
			break;
		}

	}
}

void computer_to_guess()
{
	//Variable
	srand(static_cast<unsigned>(time(0)));
	
	int player_number;
	int count = 0;
	
	std::cout << "\t\t----------Hello in this programs----------"  <<
		"\n----------You will propose to computer to guess your number----------" << std::endl;
	std::cout << "Choose a number: ";

	std::cin >> player_number;

	
	int player_number_Max{ player_number + 20 };
	int computer_number{ rand() % player_number_Max };
	
	
	searching_algorithm2(player_number, computer_number , count);

}


void searching_algorithm(int player_number ,  int computer_number , int count )
{
	int player_number_Max = player_number + 20;
	
	while (player_number != computer_number)
	{
		if (computer_number == player_number)
		{

			std::cout << "He finds it " << std::endl;
			break;
		}

		
		computer_number = rand() % player_number_Max + 1;
		++count;
		

	}
	std::cout << "Count: " << count << std::endl;
	std::cout << "Computer: " << computer_number << std::endl;
}


void searching_algorithm2(int player_number, int computer_number, int count)
{
	int player_number_Max = player_number + 20;

	for (int i{ 0 }; i <= player_number_Max; i++)
	{
		if (computer_number == player_number)
		{
			std::cout << "He finds it " << std::endl;
			break;
		}

		computer_number = rand() % player_number_Max + 1;
		++count;
	}
	
	std::cout << "Count: " << count << std::endl;
	std::cout << "Computer: " << computer_number << std::endl;
}


