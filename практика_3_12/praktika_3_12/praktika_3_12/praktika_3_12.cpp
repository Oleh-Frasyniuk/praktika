#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cctype>

void split(const std::string& text, std::set<std::string>& words) {
    std::istringstream iss(text);
    std::string word;
    while (iss >> word) {
        //деліт розділові знаки з кінця і початку слова
        word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
        words.insert(word);
    }
}

void remove_words(const std::set<std::string>& words_to_remove, std::string& text) {
    std::istringstream iss(text);
    std::ostringstream oss;
    std::string word;

    while (iss >> word) {
        std::string stripped_word = word;
        //деліт розділові знаки з кінця і початку слова
        stripped_word.erase(std::remove_if(stripped_word.begin(), stripped_word.end(), ::ispunct), stripped_word.end());

        if (words_to_remove.find(stripped_word) == words_to_remove.end()) {
            oss << word << " ";
        }
    }

    text = oss.str();
    if (!text.empty()) {
        text.pop_back(); //деліт пробіл в кінці
    }
}

int main() {
    std::string first_text = "word1, word2, word3";
    std::string second_text = "Exmple that include word1, word2, but not word3.";

    std::set<std::string> words_to_remove;
    split(first_text, words_to_remove);

    remove_words(words_to_remove, second_text);

    std::cout << "Result: " << second_text << std::endl;

    return 0;
}