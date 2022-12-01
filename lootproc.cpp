#include "lootproc.h"
#include <thread>

namespace LootCalc 
{
    void ProcDrops( double chance,  unsigned long long count, unsigned long long reps, double* dunkBin)
    {
        double rate = 0;
        
        static unsigned long long x=std::time(nullptr), y=362436069, z=521288629;
        for(unsigned long long rep = 0; rep < reps; rep++)
            for(unsigned long long chest = 0; chest < count; chest++ )
            {
                unsigned long long t;
                    x ^= x << 16;
                    x ^= x >> 5;
                    x ^= x << 1;

                t = x;
                x = y;
                y = z;
                z = t ^ x ^ y;

                bool found = ((z % 100000) * 0.001 < chance);
                if (found)
                {
                    rate += 1;
                    break;
                }
            }

        *dunkBin = rate;
    }
    
}