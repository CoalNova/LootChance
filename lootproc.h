#pragma once
#include <chrono>

namespace LootCalc 
{ 

    /// Process drop chances for number of chests for the provided number of repititons, pushes data to the supplied dunkbin pointer
    void ProcDrops(double chance, unsigned long long count, unsigned long long reps, double* dunkBin);

}