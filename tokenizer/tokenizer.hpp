#include <vector>
#include <sstream>
#include "token.hpp"

#ifndef _TOKENIZER_HPP_
#define _TOKENIZER_HPP_

class Tokenizer {

private:
	std::vector<Token> tokens;
	std::string file_contents;
	std::istringstream input_handler;

	std::string filter_comment(std::string line);
	std::string filter_whitespace(std::string line);
	
	Token tokenize_single(std::string line);
	Token tokenize_whitespace(char c);
	Token tokenize_single_quote(char c);
	Token tokenize_double_quote(char c);
	Token tokenize_open_paren(char c);
	Token tokenize_close_paren(char c);
	Token tokenize_dot(char c);
	Token tokenize_atom(std::string line);
public:
	void load_file(const char *path);
	std::vector<Token> Tokenize();
};

#endif