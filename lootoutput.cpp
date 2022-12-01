#include "lootoutput.h"
#include <iostream>

namespace LootCalc
{
	void PrintHelp()
	{
		std::cout << "LootCalc is a simple loot drop chance calculator for determining loot chance over multiple chests\n" <<
            "\tThis runs a simulation rather than a calculation to allow for edge cases to be simulated at low repetition rates.\n\n" <<
	#ifdef _win32
			"lootcalc.exe" << 
	#else
			"lootcalc" <<
	#endif
			" drop_chance chest_count repetitions\n\n" <<
			" drop_chance\t[float] - The chance, as a percentage(0.0% - 100.0%), that a drop will occur.\n" <<
			" chest_count\t[integer] -  The number of chests from which a drop will occur.\n" <<
			" repetitions\t[integer] -  The number of times this calculation will be performed.\n";
		PrintTooLowReps();
		std::cout << '\n' << std::endl;
	}

	void PrintTooLowReps()
	{
        std:: cout << "\nToo few repetitions may lead to anomolous results,\n" << 
            "\tresult homogenization will form at greater than ~1000 repetitions.\n";
	}

    void PrintResult(const double& chance, const unsigned long long& count, const unsigned long long& reps, const double& rate)
    {
        std::cout << "\nAt a chance of " << chance << "%, across " << count << " chests, over " << reps << 
            " times, the drop rate was " << rate * 100 << "%\n" << std::endl;
    }
}