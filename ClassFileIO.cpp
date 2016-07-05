//Sina Amini
//898211115

#include <iostream>
#include <fstream>
using namespace std;

class BinaryText
{
private: 

public:
	int num;
	double dub;
};

int main()
{
	ofstream outf;
	ifstream inf;	
	BinaryText Tex1, Tex2, Bin1, Bin2;
	
	//Open text file "textClass.txt for writing
	outf.open("textClass.txt");

	//take an integer and double from user
	cout << "Enter an integer and double: ";
	cin >> Tex1.num >> Tex1.dub;
	outf << Tex1.num << " " << Tex1.dub; 

	//close the text file "textClass.txt"
	outf.close();

	//Open text file "textClass.txt" for reading
	inf.open("textClass.txt");

	//read an integer and double from user
	inf >> Tex2.num >> Tex2.dub;

	cout << "The contents of the Text file: " 
		 << Tex2.num << " " << Tex2.dub << endl;
		 
	//close the text file "texClass.txt"
	inf.close();

	//Open binary file "binaryClass.bin" for writing
	outf.open("binaryClass.bin", ios::binary);

	//take an integer and double from user
	cout << "Enter an integer and double: ";
	cin >> Bin1.num >> Bin1.dub;
	
	//write both integer and double into binary file
	outf.write((char *)&Bin1, sizeof(Bin1));

	//close the binary file "binaryClass.bin"
	outf.close();

	//open binary file "binaryClass.bin" for reading
	inf.open("binaryClass.bin", ios::binary);

	//reads both integer and double from binary file
	inf.read((char *)&Bin2, sizeof(Bin1));

	//close the binary file "binaryClass.bin"
	inf.close();

	cout << "The contents of the Binary file: " 
		 << Bin2.num << " " << Bin2.dub << endl;


	BinaryText *BinOut, *BinIn;
	BinaryText binSeek;
	int n;

	cout << "Enter how many object to create: ";
	cin >> n;

	//creates a dynamic array of object BinOut
	BinOut = new BinaryText[n];

	//creates a dynamic array of object BinIn
	BinIn = new BinaryText[n];
	
	//open binary file "fiveObj.bin" for writing
	outf.open("fiveObj.bin", ios::binary);

	//takes values to store in binary file
	for(int i=0; i<n; i++)
	{
		cout << "\nEnter 2 values for object " << i+1 << ": ";
		cin >> BinIn[i].num >> BinIn[i].dub;
	}

	//writes 2 values into "fiveObj.bin"
	for(int j=0; j<n; j++)
	{
		outf.write((char *)&BinIn[j], sizeof(BinaryText));
	}

	//close binary file "fiveObj.bin"
	outf.close();

	//open binary file "fiveObj.bin" for reading
	inf.open("fiveObj.bin", ios::binary);

	//reads integers from binary file
	for(int k=0; k<n; k++)
	{
		inf.read((char *)&BinOut[k], sizeof(BinIn[k]));
	}
	
	//outputs the values stored within the binary file
	cout << "The contents of the Binary file:\n";
	for(int p=0; p<n; p++)
	{
		cout << BinOut[p].num << " " << BinOut[p].dub << "\n";
	}

	//seeks the 3rd value within the binary file "fiveObj.bin"
	inf.seekg(2* sizeof(BinaryText));

	//reads the 3rd value from the binary file "fiveObj.bin"
	inf.read((char *)&binSeek, sizeof(BinaryText));

	cout << "The content within the third object is: "
		 << binSeek.num << " " << binSeek.dub << endl;

	//close the binary file "fiveObj.bin"
	inf.close();

	system("pause");
	return 0;
}