#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "header.hpp"
void welcome(std::string jumble, std::string theWord, std::string theHint);

void game()
{
	enum fields
	{
		WORD ,HINT , NUM_FIELDS
	};//NUM_FIELDS =2

	const int NUM_WORDS = 5;
	const std::string WORDS[NUM_WORDS][NUM_FIELDS] = {
		{"wall", "Do you feel you’re banging your head against something?"},
		{"glasses", "These might help you see the answer."},
		{"labored", "Going slowly, is it?"},
		{"persistent", "Keep at it."},
		{"jumble", "It’s what the game is all about."}
	};

	srand(static_cast<unsigned int>(time(0)));
	int choice = rand() % NUM_WORDS;
	std::string theWORD = WORDS[choice][WORD];
	std::string theHint = WORDS[HINT][WORD];
	std::string jumble = theWORD;
	int length = jumble.length();
	for (int i{ 0 }; i < length; ++i)
	{
		int index1 = rand() % length;
		int index2 = rand() % length;
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;


	}
	welcome(jumble , theWORD , theHint);
}

void welcome(std::string jumble , std::string theWord , std::string theHint )
{
	using namespace std;
	cout << "\t\t\tWelcome to Word Jumble!\n\n";
	cout << "Unscramble the letters to make a word.\n";
	cout << "Enter ’hint’ for a hint.\n";
	cout << "Enter ’quit’ to quit the game.\n\n";
	cout << "The jumble is: " << jumble;
	string guess;
	cout << "\n\nYour guess: ";
	cin >> guess;

	while ((guess != theWord) && (guess != "quit"))
	{
		if (guess == "hint")
		{
			cout << theHint;
		}
		else
		{
			cout << "Sorry, that’s not it.";
		}
		cout << "\n\nYour guess: ";
		cin >> guess;
		if (guess == theWord)
		{
			cout << "\nThat’s it! You guessed it!\n";
		}
		cout << "\nThanks for playing.\n";
		
	
	}
}