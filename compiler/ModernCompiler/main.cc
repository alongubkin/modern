
#include <string>
#include <iostream>

#include "ASTGenerator.h"
#include "Node.h"

int main(int argc, char *argv[]) 
{
	ASTGenerator generator(argv[1]);
	generator.Initialize();
	
	std::cout << generator.Generate()->ToString();

	getchar();

}