#include "../headFiles/LCS.h"

int main()
{
	/*std::string s1{ "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA" };
	std::string s2{ "GTCGTTCGGAATGCCGTTGCTCTGTAAA" };*/
	std::string s1{ "abcd" };
	std::string s2{ "ac" };
	std::cout << LCCS(s1, s2).first << std::endl;
	std::cout << LCCS(s1, s2).second << std::endl;

	//printLCS(LCSIter(s1,s2), s1);
	std::system("pause");
}