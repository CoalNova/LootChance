#include "lootinput.h"
#include <string>

namespace LootCalc 
{
    void ParseInputs(int argc, char** argv, double& chance, unsigned long long& count, unsigned long long& reps)
    {
        chance = std::stod(argv[1]);
        count = std::stoull(argv[2]);
        reps = std::stoull(argv[3]);
    }
}