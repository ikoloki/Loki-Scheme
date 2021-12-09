#include <fstream>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <string>
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
}
/* checking functions because C++ doesnt have pattern matching */
Token Tokenizer::tokenize_open_paren(char c) {
	return Token("(",Token_Type(Kind::Open));
}

Token Tokenizer::tokenize_close_paren(char c) {
	return Token(")",Token_Type(Kind::Close));
}

Token Tokenizer::tokenize_dot(char c) {
	return Token(".",Token_Type(Kind::Dot));
}

Token Tokenizer::tokenize_single_quote(char c) {
	return Token("\'",Token_Type(Kind::Quote));
}

Token Tokenizer::tokenize_double_quote(char c) {
	return Token("\"",Token_Type(Kind::Double_Quote));
}
/* State Machine */

Token Tokenizer::tokenize_single(std::string line) {
	char c;
	Token found = Token();
	for (int i = 0; input_handler >> c; i++) {			
		switch (c) {
		case '(':
			found = tokenize_open_paren(c);
			break;	
		case ')':
			found = tokenize_close_paren(c);
			break;
		case '.':
			found = tokenize_dot(c);
			break;
		case '\'':
			found = tokenize_single_quote(c);
			break;
		case '\"':
			found = tokenize_double_quote(c);
			break;
		case ' ' || "\t":
			found = Token(" ",Kind::Whitespace);
			break;
		}
		return found;
	}
}

std::string Tokenizer::filter_comment (std::string line) {
	int i = 0;
	int len = line.length();
	for (; i < len; i++) {
		if (line[i] == ';') {
			return line.substr(0,i);
		}
	}
	return line;
}

Token Tokenizer::tokenize_atom(std::string line) {
	char c;
	for (int i = 0; input_handler >> c; i++) {
		
	}
}

std::vector<Token> Tokenizer::Tokenize() {
	tokens = std::vector<Token>();	
	std::string line;
	char c;
 
	input_handler.str(file_contents);
	
	while (std::getline(input_handler,line)){
		line = filter_comment(line);
		std::cout << line << std::endl;		
	}
}