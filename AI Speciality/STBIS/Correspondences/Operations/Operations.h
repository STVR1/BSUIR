#pragma once
#include<iostream>
#include<vector>

class Correspondence
{

private:

	std::vector<int> X1;

	std::vector<int> Y1;

	std::vector<std::pair<int, int>> G1;

	std::vector<int> X2;

	std::vector<int> Y2;

	std::vector<std::pair<int, int>> G2;

	std::vector<int> UniverseX;

	std::vector<int> UniverseY;

	std::vector<std::pair<int, int>> UniverseG;

public:
	
	Correspondence(); 

	~Correspondence(); 

	void ShowCorrespodences(); 

	void Unit(); 

	void Crossing(); 

	void Diff12(); 

	void Diff21(); 

	void SymDiff(); 

	void Inversion1(); 

	void Inversion2(); 

	void Composition12(); 

	void Composition21(); 

	void Complement12(); 

	void Complement21(); 

	void Type1();

	void Type2();

	void Prototype1();

	void Prototype2();

	void Constriction1();

	void Constriction2();

	void Continuation1();

	void Continuation2();

};
