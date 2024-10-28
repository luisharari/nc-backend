// parser.cpp
#include "parser.h"
#include <iostream>

Token create_token(std::string source)
{
	return Token();
}

std::vector<Token> parse_source(const char source[])
{
	size_t i = 0;
	std::string converted_source = std::string(source); // Create a string from our source pointer so we have more tools to parse through.

	std::vector<Token> tokens;

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

			Token word_token;
			word_token.source = word;

			if (strcmp(word.c_str(), "return") == 0)
			{
				word_token.type = Operation;
			}

			tokens.push_back(word_token);

			continue;
		}

		if (std::isdigit(character)) {
			std::string number;
			while (i < converted_source.size() && std::isdigit(converted_source[i])) {
				number += converted_source[i];
				i++;
			}
			std::cout << "number: " << number << std::endl;
			
			Token integer_token;
			integer_token.source = std::string(1, character);
			tokens.push_back(integer_token);
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

			Token string_token; 
			string_token.source = str; 
			string_token.type = String;
			tokens.push_back(string_token);
			continue;
		}

		if (std::ispunct(character)) {
			std::cout << "Symbol: " << character << std::endl;
			Token symbol_token; 
			symbol_token.source = std::string(1, character);
			symbol_token.type = Symbol;
			tokens.push_back(symbol_token);
			i++;
			continue;
		}

		i++;
	}

	return tokens;
}
