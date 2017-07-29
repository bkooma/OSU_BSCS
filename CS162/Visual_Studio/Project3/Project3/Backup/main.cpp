#include "Creature.hpp"
#include "Vampire.hpp"

#include <iostream>
#include <iomanip>
#include <vector>

int main() 
{
	const int numCreatures = 1;
	const int numSims = 5;
	std::string p1Round;
	std::string p2Round;
	int round = 1;
	
	std::vector<Creature*> set1 = { new Vampire() };
	std::vector<Creature*> set2 = { new Vampire() };

	for (int i = 0; i < numCreatures; i++) {
		for (int j = 0; j < numCreatures; j++) {
			Creature* p1 = set1[j];
			Creature* p2 = set2[i];

			while (!p1->is_dead() && !p2->is_dead()) {
				int damage = 0;
				int p1_attack = p1->attack();
				int p2_defense = p2->defense();

				std::cout << std::string(95, '-') << std::endl;
				std::cout << std::left << std::setw(10) << "Round #";
				std::cout << std::setw(8) << "Player1 " << std::setw(30) << p1->get_name();
				std::cout << std::setw(8) << "|  Player2 " << std::setw(30) << p2->get_name();
				std::cout << std::setw(15) << "Damage" << std::endl;
				std::cout << std::setw(10) << round;
				
				damage = p2->take_damage(p1_attack, p2_defense);
				
				p1Round = "Attack:  " + std::to_string(p1_attack);
				if (p1->get_special() != "") {
					p1Round = p1Round + "(" + p1->get_special() + ")";
				}
				
				p2Round = "|  Defense: " + std::to_string(p2_defense);
				if (p2->get_special() != "") {
					p2Round = p2Round + "(" + p2->get_special() + ")";
				}

				p2Round = p2Round + " + armor: " + std::to_string(p2->get_armor());

				std::cout << std::setw(38) << p1Round << std::setw(41) << p2Round;
				std::cout << std::setw(5) << "P2: -" << std::setw(10) << damage << std::endl;

				if (!p2->is_dead()) {
					int p2_attack = p2->attack();
					int p1_defense = p1->defense();

					damage = p1->take_damage(p2_attack, p1_defense);

					p1Round = "Defense: " + std::to_string(p1_defense);
					if (p1->get_special() != "") {
						p1Round = p1Round + "(" + p1->get_special() + ")";
					}

					p1Round = p1Round + " + armor: " + std::to_string(p1->get_armor());

					p2Round = "|  Attack:  " + std::to_string(p2_attack);
					if (p2->get_special() != "") {
						p2Round = p2Round + "(" + p2->get_special() + ")";
					}

					std::cout << std::setw(10) << "" << std::setw(38) << p1Round << std::setw(41) << p2Round;
					std::cout << std::setw(5) << "P1: -" << std::setw(10) << damage << std::endl;
				}

				std::cout << std::setw(10) << "" << std::setw(20) << "P1 Final Strength Pts: " << std::setw(15) << p1->get_strength();
				std::cout << std::setw(20) << "|  P2 Final Strength Pts: " << std::setw(15) << p2->get_strength() << std::endl << std::endl;

				round++;
			}
		}
	}

}