/*
* Generates a vetor filled with random int numbers and saves in "data/randomvetor.in"
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <vector>
#include <chrono>

using namespace std;

//Fill a vector with random numbers in the range [lower, upper]
void randomFill(int  * &V, const int lower, const int upper, int sz, const unsigned int seed) 
{
	V = new int[sz];
    //use the default random engine and an uniform distribution
    default_random_engine eng(seed);
    uniform_int_distribution<int> distr(lower, upper);

    for (int i = 0; i < sz; ++i)
    {
        V[i] = distr(eng);
    }
}

int main(int argc, char * argv[])
{
	int vetorSize, limitInf, limitSup;
	unsigned int seed;
	cout << argc << endl;
	if (argc > 1)
	{
		stringstream( argv[1] ) >> vetorSize;
		stringstream( argv[2] ) >> limitInf;
		stringstream( argv[3] ) >> limitSup;
	}
	else
	{
		cout << "Digite o tamanho do vetor, o limite inferior e o superior: ";
		cin >> vetorSize >> limitInf >> limitSup;
	}
	
	ofstream outputFile; // Stream object to handle the output file.
	outputFile.open("data/randomvetor.in");
	int *vetor = nullptr;
	if (argc = 4)
	{
		stringstream(argv[4]) >> seed;
		randomFill(vetor, limitInf, limitSup, vetorSize, seed);
		//random_device r;
	}
	else
	{
		random_device r;
		randomFill(vetor, limitInf, limitSup, vetorSize, r());
	}
	for(int j; j<vetorSize; j++)
	{
		outputFile << vetor[j] << " ";
	}
	outputFile.close();
}