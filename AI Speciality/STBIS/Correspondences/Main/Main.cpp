#include"..\Operations\Operations.h"

int main()
{
	system("chcp 1251");

	Correspondence t=Correspondence();
	t.ShowCorrespodences();
	
	std::cout << "\nUnit\n";
	t.Unit();
	
	std::cout << "\nCrossing\n";
	t.Crossing();
	
	std::cout << "\nComplement12\n";
	t.Complement12();

	/*
	std::cout << "\nComplement21\n";
	t.Complement21();
	*/

	std::cout << "\nDiff12\n";
	t.Diff12();

	/*
	std::cout << "\nDiff21\n";
	t.Diff21();
	*/
	
	std::cout << "\nSymDiff\n";
	t.SymDiff();

	std::cout << "\nInversion1\n";
	t.Inversion1();

	/*
	std::cout << "\nInversion2\n";
	t.Inversion2();
	*/
	
	std::cout << "\nComposition12\n";
	t.Composition12();

	std::cout << "\nComposition21\n";
	t.Composition21();
	
	std::cout << "\nType1\n";
	t.Type1();

	/*
	std::cout << "\nType2\n";
	t.Type2();
	*/
	std::cout << "\nPrototype1\n";
	t.Prototype1();

	/*
	std::cout << "\nPrototype2\n";
	t.Prototype2();
	*/
	
	std::cout << "\nConstriction1\n";
	t.Constriction1();

	/**
	std::cout << "\nConstriction2\n";
	t.Constriction2();
	*/
	
	std::cout << "\nContinuation1\n";
	t.Continuation1();

	/*
	std::cout << "\nContinuation2\n";
	t.Continuation2();
	*/

	return 0;
}