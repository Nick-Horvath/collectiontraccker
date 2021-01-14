#include <iostream>
#include <string>
#include <fstream>

int main()
{
	std::string line;
	std::fstream infile;
	std::fstream outfile;
	int count = 0;
	infile.open("tbftext.txt");
	outfile.open("formattedtext.txt");
	std::string countHolder;
	char singleDigitTemp;
	char doubleDigit1;
	char doubleDigit2;

	if (infile.is_open())
	{
		std::cout << "open";
		while (!infile.eof())
		{
			if (count < 9)
			{
				std::getline(infile, line);
				line[33] = '0';
				countHolder = std::to_string(count + 1);
				singleDigitTemp = countHolder[0];
				line[34] = singleDigitTemp;
				outfile << line << "\n";
				outfile << "<br>" << "\n";
				line.clear();
			}
			else
			{
				std::getline(infile, line);
				countHolder = std::to_string(count + 1);
				doubleDigit1 = countHolder[0];
				doubleDigit2 = countHolder[1];
				line[33] = doubleDigit1;
				line[34] = doubleDigit2;
				outfile << line << "\n";
				outfile << "<br>" << "\n";
				line.clear();
			}
			count++;
		}
	}
}
