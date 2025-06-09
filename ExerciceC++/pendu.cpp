#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <list>
#include <algorithm>
#include "header.hpp"
#include <cctype>
/// <summary>
///		bcp de bug j aime pas
///		peu mieux faire et aussi a ete fias grace au livre mais j ai 
///		appris bcp
///
/// </summary>

void pendu_game()
{

	//Variable
	std::vector<std::string> mots;
	std::vector<std::string>::iterator ite;
	mots.push_back("CHAT");
	mots.push_back("CANARD");
	mots.push_back("ELIEL");
	mots.push_back("HELICOPTERE");
	srand(static_cast<unsigned int>(time(0)));
	
	int mots_rand = rand() % mots.size();
	std::string mot_a_deviner = mots[mots_rand];
	
	int erreur = 0;
	int max_erreur = mot_a_deviner.length();
	std::string pendu(mots.size(), '-');
	std::string utilise = "";
	
	//Message
	std::cout << "\t\t-----PENDU-----" << std::endl;
	//std::cout << "Vous voulez les regles ?Y/n:  ";
	//rule(rules);
	
	while (pendu != mot_a_deviner)
	{
		char guess;
		std::cout << pendu << std::endl;
		std::cout << "Entre ta lettre: ";
		std::cin >> guess;
		guess = std::toupper(guess);

		while (utilise.find(guess) != std::string::npos)
		{
			std::cin >> guess;
			guess = std::toupper(guess);
			std::cout << "Tu as juste la lettre " << guess << " est dans le mots" << std::endl;
			std::cout << pendu << std::endl;
		}
		utilise += guess;
		if (mot_a_deviner.find(guess) != std::string::npos)
		{

			std::cout << "Tu as juste la lettre " << guess << " est dans le mots" << std::endl;
			for (int i = 0; i < mot_a_deviner.length(); ++i)
			{
				if (mot_a_deviner[i] == guess)
				{
					pendu[i] = guess;
				}
			}


		}
		else
		{
			std::cout << "Mauvaise devinetter " <<guess<<" ne fait pas partie du mots"<< std::endl;

		}
		
	}
	std::cout << pendu << std::endl;

}


