#include <string>
#include <vector>
#include <variant>
#include <functional>

#ifndef _TOKEN_HPP_
#define _TOKEN_HPP_

namespace Lisp_Atom {
	using integer = int32_t;
	using floating_point = float;
	using string = std::string;
	using character = char;
	using boolean = bool;
	struct symbol :std::string{}; 
	// sorry for the inheritance couldnt think of a way to do this properly 
}

using Atom_Type = std::variant<
		Lisp_Atom::integer,
		Lisp_Atom::boolean,
		Lisp_Atom::character,
		Lisp_Atom::floating_point,
		Lisp_Atom::string,
		Lisp_Atom::symbol
		>;

enum class Kind {
	Open,
	Close,
	Dot,
	Quote,
	Atom,
	Double_Quote,
	Hash,
	Whitespace,
	Undefined
};

class Token_Type {
private:

public:
	Kind kind;
	Atom_Type atom;
	Token_Type(Kind,Atom_Type);
	Token_Type(Kind);
	Token_Type();
};

class Token {
private:
	std::string literal;
	Token_Type type;

	public:
	Token(std::string literal,Token_Type type);
	Token();
	std::string get_literal();
	Token_Type get_type();
};

#endif