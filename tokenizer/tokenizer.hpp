#ifndef _TOKENIZER_HPP_
#define _TOKENIZER_HPP_

#include <vector>
#include <regex>
#include "token.hpp"

class Tokenizer {

private:	
	std::vector<Token> tokens;
	std::string file_contents;
		
public:
	void load_file(const char *path);
	void register_token(std::regex pattern,Token_Type type);
	std::vector<Token> Tokenize();
};



#endif