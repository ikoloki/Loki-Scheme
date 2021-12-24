#ifndef _TOKEN_HPP_
#define _TOKEN_HPP_

#include <string>
#include <vector>
#include <variant>
#include <functional>
#include <regex>

namespace Literal_Alias {
	using integer = int;
	using floating_point = float;
	using string = std::string;
	using character = char;
	using boolean = bool;
	struct symbol :std::string{};
	// sorry for the inheritance couldnt think of a way to do this properly 
}

using Literal_Type = std::variant<
	Literal_Alias::integer,
	Literal_Alias::character,
	Literal_Alias::boolean,
	Literal_Alias::floating_point,
	Literal_Alias::string,
	Literal_Alias::symbol
	>;

enum class Token_Variant : int8_t {
		Undefined = -1,
		Open,
		Close,      
		Keyword,	
		Identifier, 
		Literal,    
		Whitespace,
};

struct Token_Type {
	Literal_Type type;
	Token_Variant variant;
	Token_Type(Token_Variant variant, Literal_Type type);
	Token_Type(Token_Variant variant);
};

class Token {
private:
	std::string lexeme;
	Token_Type type;
public:
	Token(std::string lexeme,Token_Type type);
	Token(std::string lexeme);
	Token() = default;

	std::string get_lexeme();
	Token_Type get_type();
};
#endif