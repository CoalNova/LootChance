#include "lootoutput.h"
#include "lootinput.h"
#include "lootproc.h"
#include <thread>


int main(int argc, char** argv)
{
	if (argc != 4)
	{
		LootCalc::PrintHelp();
		return 1;
	}

	// initialize variables
	unsigned long long 
		count = 0, 
		reps = 0;
	double chance = 0.0;

	// recognize inputs
	LootCalc::ParseInputs(argc, argv, chance, count, reps);

	// alert that low repitions may yield unexpected results
	if (reps < 1000) 
		LootCalc::PrintTooLowReps();

	// gather thread count of current system
	int threadCount = std::thread::hardware_concurrency();

	// create pools for returned data and threads
	double *ratePool = new double[threadCount];
	std::thread* threadPool = new std::thread[threadCount];

	// initialize threads, passing data as necessary
	for(unsigned int thread = 0; thread < threadCount; thread++)
		threadPool[thread] = std::thread(LootCalc::ProcDrops, chance, count, reps / threadCount, &ratePool[thread]);
	
	// create rate and calculate the remainder of what was processed by the threads
	double rate = 0.0; 
	LootCalc::ProcDrops(chance, count, reps % threadCount, &rate);

	// wait for threads to finish, then yoink the final values
	for(unsigned int thread = 0; thread < threadCount; thread++)
	{
		threadPool[thread].join();
		rate += ratePool[thread];
	}

	// free memory of no longer needed data
	delete[] ratePool;
	delete[] threadPool;

	// Average rate from reps and pass along to be printed 
	rate /= reps;
	LootCalc::PrintResult(chance, count, reps, rate);

	return 0;
}
