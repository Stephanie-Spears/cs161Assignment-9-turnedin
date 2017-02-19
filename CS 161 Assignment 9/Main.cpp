#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

#define Array_Size 100 

using namespace std;

void GetFileName(string& FileName)
{
	string FileType = ".txt";
	fstream InputFile;

	cout << "Enter the input file name: ";
	getline(cin, FileName);
	FileName.append(FileType);
	InputFile.open(FileName, fstream::in);


}


int main()
{

	string FileNamePath;
	fstream InputFile;
	int NumbersArray[Array_Size];
	int Num;
	int i = 0;

	GetFileName(FileNamePath);

	InputFile.open(FileNamePath, fstream::in);

	if (InputFile.fail())
	{
		cout << endl << "Input file name '" << FileNamePath << "' does not exist." << endl;
		InputFile.close();
		return 1;

	}
	else
	{
		cout << endl << "Input file name '" << FileNamePath << "' opened for reading." << endl;

	}
	cout << endl;

	while (InputFile >> Num)
	{
		NumbersArray[i] = Num;
		i++;
	}
	
	for (int i = 0; i < Array_Size; i++)
	{
		for (int j = 0; j < Array_Size; j++)
		{
			if (NumbersArray[i] < NumbersArray[j])
			{
				swap(NumbersArray[i], NumbersArray[j]);

			}
		}
	}
	
	cout << "Sorted Array: " << endl << endl;

	for (int i = 0; i < Array_Size; i++)
	{
		cout << NumbersArray[i] << endl;
	}

	InputFile.close();

	return 0;
}