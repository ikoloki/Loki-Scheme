#include "include.hpp"
#include "tokenizer/token.hpp"
#include "tokenizer/tokenizer.hpp"

int main(int argc,char **argv) {

	std::cout << "hello world" << std::endl;

	Tokenizer scheme_tokenizer = Tokenizer();
	scheme_tokenizer.register_token(std::regex("([\(])"),Token_Type(Token_Variant::Open));
	scheme_tokenizer.load_file("tests/longer-test.scm");
		
	return 0;
}