#include "token.hpp"

Token_Type::Token_Type(Kind kind,Atom_Type atom) {
	this->kind = kind;
	this->atom = Atom_Type();
}

Token_Type::Token_Type(Kind kind) {
	this->kind = kind;
}

Token_Type::Token_Type() {
	this->kind = Kind::Undefined;
	this->atom = Lisp_Atom::symbol();
}

/* Token */

Token::Token(std::string literal,Token_Type type) {
	this->literal = literal;
	this->type = Token_Type(type);
};

Token::Token() {
	literal = "";
	this->type = Token_Type(type);
}

std::string Token::get_literal() {
	return literal;
};