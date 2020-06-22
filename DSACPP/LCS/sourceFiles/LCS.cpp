#include "../headFiles/LCS.h"

int main()
{
	std::string s1{ "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA" };
	std::string s2{ "GTCGTTCGGAATGCCGTTGCTCTGTAAA" };
	printLCS(LCSIter(s1,s2), s1);
	std::system("pause");
}