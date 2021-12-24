#include "token.hpp"

/* Token_Type Constructors */

Token_Type::Token_Type(Token_Variant variant, Literal_Type type) : variant{variant}, type{type} {}

Token_Type::Token_Type(Token_Variant variant) : variant{variant} {}
/* Token Constructors */

Token::Token(std::string lexeme, Token_Type type) : lexeme{lexeme}, type{type} {}

Token::Token(std::string lexeme) : lexeme{std::move(lexeme)}, type{Token_Variant::Undefined} {}

/* getters and setters */

std::string Token::get_lexeme() {
    return lexeme;
}

Token_Type Token::get_type() {
    return type;
}
