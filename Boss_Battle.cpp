#include <iostream>
#include <string>
#include <random>

int main() {
	std::random_device seed;
	std::mt19937 gen(seed());
	std::uniform_int_distribution<> oneTOoneH(1, 100);
	std::uniform_int_distribution<> thirddTOfived(30, 50);
	std::uniform_int_distribution<> goldAmount(6, 25);

	int selection;
	int gold_added;
	bool checkout = false;
	int price = 0;
	int decision;
	int gold2;
	int health = 0;
	int attack = 0;
	int speed = 0;
	int char_select;
	int menu_select;
	int fight_select;
	int round = 0;
	int boss_health_base = 50;
	int boss_health;
	int boss_attack;
	int gold = 3;
	int health_potion = 0;
	int bomb = 0;
	double random_num = 0;
	bool dead = false;
	bool fighting = false;
	double atkpercent = 0;
	std::string name;
	std::string char_str;
	std::string menu_str;
	std::string selection_str;
	std::string decision_str;
	std::string fight_select_str;

	std::cout << "~~~~~~~Boss Battles~~~~~~~" << std::endl;
	std::cout << "\nChose Your Character" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "TANK (1)\nHealth: 300 \nAttack: 250 \nSpeed: 10 \nAtack Chance: 40" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "GRUNT (2)\nHealth: 150 \nAttack: 100 \nSpeed: 50 \nAtack Chance: 60" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "SWIFTY (3)\nHealth: 50 \nAttack: 80 \nSpeed: 80 \nAtack Chance: 80" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "ENTER NUMBER OF CHARACTER: ";

	std::getline(std::cin, char_str);
	char_select = std::stoi(char_str);

	if (char_select > 0 && char_select <= 3) {
		if (char_select == 1) {
			name = "TANK";
			health = 300;
			attack = 250;
			speed = 10;
			atkpercent = 40;
		}
		if (char_select == 2) {
			name = "GRUNT";
			health = 150;
			attack = 100;
			speed = 50;
			atkpercent = 60;
		}
		if (char_select == 3) {
			name = "SWIFTY";
			health = 50;
			attack = 80;
			speed = 80;
			atkpercent = 80;
		}
	}
	else {
		std::cout << "~INVALID~INPUT!~~~GAME~ENDED~";
		return 0;
	}
	std::cout << "\nYOU CHOSE " << name << std::endl;

	//game logic
	while (dead == false) {
		round += 1;
		std::cout << "\n\n\n\n\nROUND: " << round << "\n---------" << std::endl;
		std::cout << "MENU\n";
		std::cout << "(GOLD: " << gold << ")" << std::endl;
		std::cout << "-----------------------" << std::endl;
		std::cout << "FIGHT (1)" << std::endl;
		std::cout << "SHOP (2)" << std::endl;
		std::cout << "END GAME (3)" << std::endl;
		std::cout << "-----------------------" << std::endl;
		std::cout << "Enter Selection Number: ";

		std::getline(std::cin, menu_str);
		menu_select = std::stoi(menu_str);

		if (menu_select > 0 && menu_select <= 3) {
			if (menu_select == 1) {
				fighting = true;
			}
			if (menu_select == 2) {

				checkout = true;
				while (checkout == true) {

					std::cout << "\n\n\nWelcome to the Shop! What would you like to purchase? " << std::endl;
					std::cout << "-------------------------------------" << std::endl;
					std::cout << "Your Gold: " << gold << std::endl;
					std::cout << "\nList: \n (1)Health Potion:	7 \n (2)Bomb:		15 \n (3)Strength potion:	40\n (4)Armor:		50\n (5)How to aim 101:	35\n (6)EXIT SHOP			(exiting shop will lead to battle) \n\n ENTER YOUR SELECTION: ";

					std::getline(std::cin, selection_str);
					selection = std::stoi(selection_str);

					if (selection > 7 && selection < 0) {
						std::cout << " Invalid selection" << std::endl;
					}
					else if (selection == 1) {
						price = 7;
						std::cout << "\nGold:" << gold << std::endl;
						std::cout << "You have selected the health potion:\n The price is " << price << " gold would you like to buy it? (1) yes (2) no" << std::endl;
						std::cout << " -------------------------------------" << std::endl;

						std::getline(std::cin, decision_str);
						decision = std::stoi(decision_str);

						if (decision == 1) {


							if (gold < price) {
								std::cout << "You can't afford this right now" << std::endl;
								std::cout << " -------------------------------------" << std::endl;
							}
							else {
								health_potion++;
								gold2 = gold;
								gold = gold2 - price;
								std::cout << " Thanks for the purchase you now have " << gold << " gold!" << std::endl;
								std::cout << " -------------------------------------" << std::endl;
							}
							decision = 0;
						}

					}

					else if (selection == 2) {
						price = 15;
						//15 gold
						std::cout << "\nGold:" << gold << std::endl;
						std::cout << "You have selected the bomb:\n The price is " << price << " gold would you like to buy it? (1) yes (2) no" << std::endl;
						std::cout << " -------------------------------------" << std::endl;

						std::getline(std::cin, decision_str);
						decision = std::stoi(decision_str);
						if (decision == 1) {


							if (gold < price) {
								std::cout << "You can't afford this right now" << std::endl;
								std::cout << " -------------------------------------" << std::endl;
							}
							else {

								bomb++;
								gold2 = gold;
								gold = gold2 - price;
								std::cout << " Thanks for the purchase you now have " << gold << " gold!" << std::endl;
								std::cout << " -------------------------------------" << std::endl;
							}
							decision = 0;
						}

					}

					else if (selection == 3) {
						price = 40;
						std::cout << "\nGold:" << gold << std::endl;
						std::cout << "You have selected the Strength potion:\n The price is " << price << " gold would you like to buy it? (1) yes (2) no" << std::endl;
						std::cout << " -------------------------------------" << std::endl;

						std::getline(std::cin, decision_str);
						decision = std::stoi(decision_str);
						if (decision == 1) {


							if (gold < price) {
								std::cout << "You can't afford this right now" << std::endl;
								std::cout << " -------------------------------------" << std::endl;
							}
							else {
								attack += 35;
								gold2 = gold;
								gold = gold2 - price;
								std::cout << " Thanks for the purchase you now have " << gold << " gold!" << std::endl;
								std::cout << " -------------------------------------" << std::endl;
							}
							decision = 0;
						}


						//40
					}

					else if (selection == 4) {
						price = 50;
						std::cout << "\nGold:" << gold << std::endl;
						std::cout << "You have selected the armor:\n the price is " << price << " gold would you like to buy it? (1) yes (2) no" << std::endl;
						std::cout << " -------------------------------------" << std::endl;

						std::getline(std::cin, decision_str);
						decision = std::stoi(decision_str);
						if (decision == 1) {



							if (gold < price) {
								std::cout << "You can't afford this right now" << std::endl;
								std::cout << " -------------------------------------" << std::endl;
							}
							else {
								health = health * 2;
								gold2 = gold;
								gold = gold2 - price;
								std::cout << " Thanks for the purchase you now have " << gold << " gold!" << std::endl;
								std::cout << " -------------------------------------" << std::endl;
							}
							decision = 0;
						}

						//50
					}

					else if (selection == 5) {
						price = 35;
						//35
						std::cout << "\nGold:" << gold << std::endl;
						std::cout << "You have selected the book on how to aim 101:\n The price is " << price << " gold would you like to buy it? (1) yes (2) no" << std::endl;
						std::cout << " -------------------------------------" << std::endl;
						std::getline(std::cin, decision_str);
						decision = std::stoi(decision_str);
						if (decision == 1) {

							if (gold < price) {
								std::cout << "You can't afford this right now" << std::endl;
								std::cout << " -------------------------------------" << std::endl;

							}
							else {
								atkpercent += 10;
								gold2 = gold;
								gold = gold2 - price;
								std::cout << " Thanks for the purchase you now have " << gold << " gold!" << std::endl;
								std::cout << " -------------------------------------" << std::endl;

							}
							decision = 0;
						}

					}

					if (selection == 6) {
						checkout = false;
						selection = 0;
					}

					std::cout << " -------------------------------------" << std::endl;
				}

				fighting = true;
			}
			if (menu_select == 3) {

			}
		}
		else {
			std::cout << "~INVALID~INPUT!~~~GAME~ENDED~" << std::endl;
			return 0;
		}

		boss_health = boss_health_base + (1 + (round / 3));
		boss_attack = thirddTOfived(gen) * (1 + (round / 2));

		while (fighting == true) {
			while (boss_health > 0 && health > 0) {
				std::cout << "\n\nBoss Information:\n	Health: " << boss_health << "\n	Attack: " << boss_attack << std::endl;
				std::cout << "--------------------" << std::endl;
				std::cout << "Your Stats: \n	Health: " << health << "\n	Attack: " << attack << "\n	Speed: " << speed << "\n	Attack Chance: " << atkpercent << std::endl;
				std::cout << "--------------------" << std::endl;
				std::cout << "Options:" << std::endl;
				std::cout << "	(1) FIGHT \n	(2) FLEE \n	(3) HEALTH POTION: " << health_potion << "\n	(4) BOMB: " << bomb << std::endl;
				std::cout << "--------------------" << std::endl;
				std::cout << "Input what you want to do: ";

				std::getline(std::cin, fight_select_str);
				fight_select = std::stoi(fight_select_str);


				while (fight_select > 0) {
					if (fight_select > 0 && fight_select < 5) {
						if (fight_select == 1) {
							random_num = oneTOoneH(gen);
							std::cout << "YOU ATTACKED" << std::endl;
							if (atkpercent <= random_num) {

								std::cout << "You Hit your ATTACK!" << std::endl;
								std::cout << "-" << attack << " towards BOSS" << std::endl;
								boss_health -= attack;
							}
							else {
								std::cout << "You missed your ATTACK" << std::endl;
								std::cout << "-" << boss_attack << " towards YOU" << std::endl;
								health -= boss_attack;
							}
							fight_select = 0;
						}
						if (fight_select == 2) {
							random_num = oneTOoneH(gen);
							if (speed >= random_num) {
								std::cout << "\nYour FLEE was successful!" << std::endl;
								std::cout << "You got tired from running. -1 SPEED" << std::endl;
								speed -= 1;
								boss_health = 0;
								fight_select = 0;
								fighting = false;

							}
							else {
								std::cout << "\nYour FLEE failed. You now must attack\n~~~~~~~~~~~~" << std::endl;
								fight_select = 1;
							}
						}
						if (fight_select == 3 && health_potion > 0) {
							health_potion--;
							health += 15;
							std::cout << "Health potion healed 15" << std::endl;
							fight_select = 0;
						}
						else if (fight_select == 3 && health_potion <= 0) {
							std::cout << "You dont have enough of that item" << std::endl;
						}
						if (fight_select == 4 && bomb > 0) {
							bomb--;
							std::cout << "BOMB blew up the BOSS for -40" << std::endl;
							boss_health -= 100;
							fight_select = 0;
						}
						else if (fight_select == 3 && health_potion <= 0) {
							std::cout << "You dont have enough of that item" << std::endl;
						}
					}
				}
			}
			if (boss_health <= 0) {
				gold_added = goldAmount(gen);
				std::cout << "\nYou defeted the BOSS. On to round " << round + 1 << std::endl;
				std::cout << gold_added << " GOLD added to inventory" << std::endl;
				gold += gold_added;
			}

			if (health <= 0) {
				std::cout << "You have died, you have survived " << round - 1 << " rounds" << std::endl;
				std::cout << " GAME OVER" << std::endl;
				return 0;
			}
			fighting = false;

		}

	}

	return 1000;
}


// Reapeating mesages
// Money system
// Classes
// Shop
// Fighing mecanics
// Monsters
// invintory
