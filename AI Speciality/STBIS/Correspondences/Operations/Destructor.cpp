#include"Operations.h"

Correspondence::~Correspondence()
{
	X1.erase(X1.begin(), X1.end());
	X2.erase(X2.begin(), X2.end());

	Y1.erase(Y1.begin(), Y1.end());
	Y2.erase(Y2.begin(), Y2.end());

	G1.erase(G1.begin(), G1.end());
	G2.erase(G2.begin(), G2.end());

	UniverseX.erase(UniverseX.begin(), UniverseX.end());
	UniverseY.erase(UniverseY.begin(), UniverseY.end());
	UniverseG.erase(UniverseG.begin(), UniverseG.end());

}
