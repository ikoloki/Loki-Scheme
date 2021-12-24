#include <fstream>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <regex>

#include "token.hpp"
#include "tokenizer.hpp"
	
void Tokenizer::load_file(const char *path) {
	std::ifstream file = std::ifstream(path);
	if (file.good() == false)
			throw std::invalid_argument("Could Not load/find file:" + std::string(path));		
	char c;
	while (true) {
		c = file.get();
		if (file.bad() || file.fail())
			break;
		file_contents+=c;
	}
	file.close();
}

void Tokenizer::register_token(std::regex pattern,Token_Type) {

}