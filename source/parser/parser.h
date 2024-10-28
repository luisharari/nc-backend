#pragma once
#include <vector>
#include <string>

enum TokenTypes
{
	TypeDefinition, // int, bool, char, void
	Integer,		// 0-9
	Boolean,		// true or false 
	Symbol,			// + ! ( ) 
	String,			// Self explanatory 
	Operation,		// return
};

struct Token
{
	TokenTypes type;
	std::string source;
};

std::vector<Token> parse_source(const char source[]);