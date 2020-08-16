#include <iostream>
#include "Sequence.h"

using namespace std;

void basicTest();

int main(int argc, char const *argv[])
{
	basicTest();
	return 0;
}

void basicTest()
{
	Sequence sq1;
	double numbers[] = {1.1, 2.2, 3.3};
	int n = 3;

	sq1.insert(3.14);
	sq1.insert(numbers, n);

	int pies = sq1.find(3.14);
	int sqSize = sq1.size();
	double sqSum = sq1.sum();
	double sqMean = sq1.mean();
	double sqMedian = sq1.median();
	double sqStddev = sq1.stddev();

	Sequence sq2(sq1);
	Sequence sq3 = sq2.concatenate(sq1);

	cout << "end basic test" << endl;
}