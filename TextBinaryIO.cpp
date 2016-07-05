//Sina Amini
//898211115

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream outf;
	ifstream inf;

	int num1, num2, num3, num4;
	int read1, read2, read3, read4;

	//Open text file "text.txt for writing
	outf.open("text.txt");

	cout << "Enter two integers: ";
	cin >> num1 >> num2;

	outf << num1 << " " << num2; 

	outf.close();

	//Open text file "text.txt" for reading
	inf.open("text.txt");

	inf >> read1 >> read2;

	cout << "The contents of the Text file: " 
		 << read1 << " " << read2 << endl;

	inf.close();

	//Open binary file "binary.bin" for writing
	outf.open("binary.bin", ios::binary);

	cout << "Enter two integers: ";
	cin >> num3 >> num4;

	outf.write((char *)&num3, sizeof(int));
	outf.write((char *)&num4, sizeof(int));

	outf.close();

	//open binary file "binary.bin" for reading
	inf.open("binary.bin", ios::binary);

	inf.read((char *)&read3, sizeof(num3));
	inf.read((char *)&read4, sizeof(num4));

	inf.close();

	cout << "The contents of the Binary file: " 
		 << read3 << " " << read4 << endl;

	return 0;
}

