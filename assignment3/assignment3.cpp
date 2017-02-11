/*
 * Demo code for assignment 3 written by Zachary Halpern
 * © 2017 for deomonstration purposes only
 * http://github.com/ZeldaZach
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

void attack(int &);
void heal(int &, int &, int &);
void spell(int &, int &);
void move(int &, int &, int &, int &, int &, char);

int main(int argc, char** argv)
{
	// If we don't have exactly 3 args (really 4)
	if (argc != 4)
		std::exit(1);
	
	int user_max_health, user_max_spells, user_max_potions;
	int user1_health, user1_spells, user1_potions;
	int user2_health, user2_spells, user2_potions;
	char game_action;

	// Set all variables to inputs; argv = ["./assignment3", "max_health", "max_spells", "max_potions"]
	user1_health = user2_health = user_max_health = atoi(argv[1]);
	user1_spells = user2_spells = user_max_spells = atoi(argv[2]);
	user1_potions = user2_potions = user_max_potions = atoi(argv[3]);
	
	srand(static_cast<unsigned>(time(NULL)));
	
	// While both users are still alive
	while (user1_health && user2_health)
	{
		/* Player 1's turn will begin here */
		TRY_AGAIN_1: // This is a label, try not to use them unless you know what you're doing!
		std::cout << "Enter a command for player 1" << std::endl;
		std::cout << "(Health: " << user1_health << "/" << user_max_health
			<< " - Fireballs: " << user1_spells << "/" << user_max_spells
			<< " - Healing Potions: " << user1_potions << "/" << user_max_potions << ")" << std::endl;
		std::cout << "a - attack " << std::endl << "f - fireball " << std::endl << "h - heal" << std::endl;
		std::cin >> game_action;
		
		// Lets make sure the user entered a valid command, if not prompt them again
		switch (game_action)
		{
			case 'a':
			case 'f':
			case 'h':
			move(user1_health, user2_health, user1_spells, user1_potions, user_max_health, game_action);
			break;
			
			default:
			goto TRY_AGAIN_1;
		}
		
		// If player 2 died...
		if (user2_health == 0)
		{
			std::cout << "Player one is the winner!" << std::endl;
			break;
		}
		
		/* Player 2's turn will begin here */
		TRY_AGAIN_2: // This is a label, try not to use them unless you know what you're doing!
		std::cout << "Enter a command for player 2" << std::endl;
		std::cout << "(Health: " << user2_health << "/" << user_max_health
			<< " - Fireballs: " << user2_spells << "/" << user_max_spells
			<< " - Healing Potions: " << user2_potions << "/" << user_max_potions << ")"  << std::endl;
		std::cout << "a - attack " << std::endl << "f - fireball " << std::endl << "h - heal" << std::endl;
		std::cin >> game_action;
		
		// Lets make sure the user entered a valid command, if not prompt them again
		switch (game_action)
		{
			case 'a':
			case 'f':
			case 'h':
			move(user2_health, user1_health, user2_spells, user2_potions, user_max_health, game_action);
			break;
			
			default:
			goto TRY_AGAIN_2;
		}

		// If player 1 died...
		if (user1_health == 0)
		{
			std::cout << "Player two is the winner!" << std::endl;
			break;
		}
	}
}

void move(int &current_health, int &opponent_health, int &current_spellCount, int &current_potionCount, int &max_health, char move)
{
	// A switch statement is an easier way to do if/else if statements when only comparing simple statements
	switch (move)
	{
		case 'a':
		attack(opponent_health);
		break;
		
		case 'f':
		spell(opponent_health, current_spellCount);
		break;
		
		case 'h':
		heal(current_health, max_health, current_potionCount);
		break;
	}
}

void attack(int &opponent_health)
{
	int damage = rand() % 21; // [0 - 20]
	
	if (damage)
	{
		std::cout << "Attack hits for " << damage << " points of damage!" << std::endl;

		opponent_health -= damage;
		if (opponent_health < 0)
			opponent_health = 0;
	}
	else
	{
		std::cout << "Miss!" << std::endl;
	}
}

void spell(int &opponent_health, int &current_count)
{
	if (current_count == 0)
	{
		std::cout << "You have used all of your fireballs!" << std::endl;
	}
	else
	{
		int damage = rand() % 21 + 10; // [10 - 30]
		current_count--;

		std::cout << "Fireball hits for " << damage << " points of damage!" << std::endl;

		opponent_health -= damage;
		if (opponent_health < 0)
			opponent_health = 0;
	}
}

void heal(int &current_health, int &max_health, int &current_count)
{	
	if (current_count == 0)
	{
		std::cout << "You have used all of your heal potions!" << std::endl;
	}
	else if (current_count == max_health)
	{
		std::cout << "You wasted a potion as your health can't go over " << max_health << "!" << std::endl;
		current_count--;
	}
	else
	{
		int heal = rand() % 21 + 20; // [20 - 40]
		current_count--;
		
		current_health += heal;
		if (current_health > max_health)
			current_health = max_health;
		
		std::cout << "You have healed yourself " << heal << " points!" << std::endl;
	}
}