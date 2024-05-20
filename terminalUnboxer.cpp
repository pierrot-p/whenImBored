#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>  
#include <ctime>    

std::string getColor(const std::string& rarity) {
    if (rarity == "Rare") return "\033[34m";           // Navy Blue
    else if (rarity == "Mythical") return "\033[35m";  // Purple
    else if (rarity == "Legendary") return "\033[95m"; // Hot Pink
    else if (rarity == "Ancient") return "\033[31m";   // Red
    else if (rarity == "Exceedingly Rare") return "\033[33m"; // Gold
    else return "\033[0m";                             // Default color
}

std::string resetColor() {
    return "\033[0m";
}

int main() {
    std::vector<std::pair<std::string, double>> outcomes = {
        {"Rare", 79.92},
        {"Mythical", 15.98},
        {"Legendary", 3.2},
        {"Ancient", 0.64},
        {"Exceedingly Rare", 0.26},
    };

    std::vector<std::string> outcomes_list;
    std::vector<double> probabilities_list;
    
	double price = 2.35;
	double total_price = 0.0;
    double total_probability = 0.0;

    for (const auto& outcome : outcomes) {
        outcomes_list.push_back(outcome.first);
        probabilities_list.push_back(outcome.second);
        total_probability += outcome.second;
    }

    for (auto& probability : probabilities_list) {
        probability = (probability / total_probability) * 100.0;
    }

    std::cout << "Total probability: " << total_probability << "%" << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << "Possible outcomes:" << std::endl;
    std::cout << "-----------------" << std::endl;

    for (size_t i = 0; i < outcomes_list.size(); ++i) {
        std::cout << getColor(outcomes_list[i]) << outcomes_list[i] << std::endl;
        std::cout << "Chance: " << probabilities_list[i] << "%" << resetColor() << std::endl;
    }
    std::cout << "-----------------" << std::endl;

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    size_t userChoice;
    std::cout << "Enter the number of the outcome you want to see the chance of: ";
    std::cin >> userChoice;

	total_price = price * userChoice;

    for (size_t i = 0; i < userChoice; ++i) {
        double random_value = (std::rand() % 10000) / 100.0;
        double cumulative_probability = 0.0;

        for (size_t j = 0; j < probabilities_list.size(); ++j) {
            cumulative_probability += probabilities_list[j];
            if (random_value <= cumulative_probability) {
                std::cout << getColor(outcomes_list[j]) << "Outcome: " << outcomes_list[j] << resetColor() << std::endl;
                break;
            }
        }
    }

	std::cout << "You just spent $: " << total_price << std::endl;

    return 0;
}
