// parser.cpp
#include "parser.h"
#include <iostream>

void parse_source(const char source[])
{
	size_t i = 0;
	std::string converted_source = std::string(source); // Create a string from our source pointer so we have more tools to parse through.

	while (i < converted_source.size())
	{
		char character = converted_source[i];

		// ignore whitespaces
		if (std::isspace(character))
		{
			i++;
			continue;
		}

		if(std::isalpha(character) || character == '_') {
			std::string word;
			while (i < converted_source.size() && (std::isalnum(converted_source[i]) || converted_source[i] == '_')) {
				word += source[i];
				i++;
			}
			std::cout << "word: " << word << std::endl;
			continue;
		}

		if (std::isdigit(character)) {
			std::string number;
			while (i < converted_source.size() && std::isdigit(converted_source[i])) {
				number += converted_source[i];
				i++;
			}
			std::cout << "number: " << number << std::endl;
			continue;
		}

		if (character == '\"') {
			std::string str;
			i++;  // Skip the opening quote
			while (i < converted_source.size() && converted_source[i] != '\"') {
				str += converted_source[i];
				i++;
			}
			i++;  // Skip the closing quote
			std::cout << "String: " << str << std::endl;
			continue;
		}

		if (std::ispunct(character)) {
			std::cout << "Symbol: " << character << std::endl;
			i++;
			continue;
		}

		i++;
	}
}
