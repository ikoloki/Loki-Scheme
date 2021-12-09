#include "include.hpp"
#include "compiler.hpp"

int main(int argc,char **argv) {
	std::cout << "hello world" << std::endl;
	
	Tokenizer scheme_tokenizer = Tokenizer();
	scheme_tokenizer.load_file("longer-test.scm");
	scheme_tokenizer.Tokenize();
	
	/* Compiler *Scheme_Compiler = new Compiler(); 
	Compiler *Scheme_Compiler.Tokenizer */
	return 0;
}
