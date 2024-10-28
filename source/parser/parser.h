#pragma once
#include <vector>
#include <string>

struct Token
{
	// TODO; type
	std::string source;
};

void parse_source(const char source[]);