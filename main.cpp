#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> words;
    std::string input;

    std::cout << "Enter words (type 'exit' to finish):" << std::endl;

    while (true) {
        std::getline(std::cin, input);
        if (input == "exit") {
            break;
        }
        words.push_back(input);
    }

    std::cout << "You put in:" << std::endl << std::endl;
    for (const auto& word : words) {
        std::cout << word << std::endl << std::endl;
    }

    return 0;
}