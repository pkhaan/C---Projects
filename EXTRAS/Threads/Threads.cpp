// Threads.cpp : Defines the entry point for the console application.
//

#include <thread>
#include <math.h>
#include <random>
#include <iostream>

using namespace std;

std::default_random_engine generator;
std::uniform_real_distribution<double> distribution(0.0, 1.0);



void EstimatePI(double * result, long count)
{
	static int ID = 0; // this is the ID of the individual called funcion 
	ID++;              // Separate calls have their own unique ID. 
	int callID = ID;
	
	// Generate samples within a disk using dart throwing.
	// Evaluate the area of the disk as the count of valid samples
	// using a uniform distribution and hense PI as 

	*result = 0.0;
	for (long i = 0; i < count; i++)
	{
		//double xi  = rand() / (double)RAND_MAX;
		//double psi = rand() / (double)RAND_MAX;

		double xi = distribution(generator);
		double psi = distribution(generator);
		

		if (sqrt(xi*xi + psi*psi) <= 1.0)
			*result += 1.0;

		if (i % 10000 == 0) // every 10000 iterations...
			// print the current result
			printf("Call No %d - Progress: %3.3f, PI = %1.8f\n", callID, i / double(count), *result*4.0/double(i));

	}

	*result *= 4.0 / double(count);
}

int main(int argc, char* argv[])
{
	// srand/rand are not very accurate. Do not use for precise calculations
	srand(0);
	


	const long iterations = 100000000;
	const int numThreads = 4;
	
	double * PI = new double[numThreads];
	thread * threads = new thread[numThreads];

	// Spawn all threads.
	// They take some part of the load
	for (int i = 0; i < numThreads; i++)
	{
		// Each thread here takes up some some of the work load
		threads[i] = thread (EstimatePI, PI+i, iterations / numThreads );
	}

	
	// synchronize threads:
	//
	// This is a barrier, where the caller waits until all threads, 
	// whose "join" method is invoked, are terminated
	//
	for (int i = 0; i < numThreads; i++)
	{
		threads[i].join();
	}

	double finalPI = 0.0;
	for (int i = 0; i < numThreads; i++)
	{
		finalPI += PI[i] / numThreads;
	}

	cout << "\nFinished.\n\nPI = " << finalPI << endl;
	getchar();

	delete [] threads;
	delete[] PI;
	return 0;
}

