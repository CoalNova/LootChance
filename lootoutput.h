#pragma once

namespace LootCalc
{
	/// Prints the general help to the command line
	void PrintHelp();

	/// Prints the message that reps is too low to the command line
	void PrintTooLowReps();

	/// Prints the resulting drop rate
	void PrintResult(const double& chance, const unsigned long long& count, const unsigned long long& reps, const double& rate);
}
