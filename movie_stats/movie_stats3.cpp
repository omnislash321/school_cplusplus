#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int mode(int*, int);
void quickSort(int*, int);
int partition(int*, int, int);
void swap(int, int, int*);
void showData(fstream*, fstream*);
double average(int*, int);
double median(int*, int);

int main(int argc, char* argv[])
{
	if(argc < 3)
		exit(1);
	else
	{
		fstream inFile, outFile;

		inFile.open(argv[1], ios::in);
		if(!inFile)
			cout << "InFile not found.";
		
		outFile.open(argv[2], ios::out);
		if(!outFile)
			cout << "OutFile not found.";
		
		if(inFile && outFile)
		{
			showData(&inFile, &outFile);
		}
	}
	
	return(0);
}

void showData(fstream *inFile, fstream *outFile) 
{
	
	int numStudents;
	int *students;

	*outFile << "How many students were surveyed? ";
	*inFile >> numStudents;

	if(numStudents < 2)
	{
		*outFile << "Number of students must be greater than 1.";
		inFile->close();
		outFile->close();
		exit(1);
	} 
	else 
	{
		students = new int[numStudents];
		*outFile << "Enter the number of movies each student saw. ";
		
		for(int i = 0; i < numStudents; i++) {
			
			int temp = 0;
			*outFile << "Student " << i << ": ";
			*inFile >> temp;
			
			if(temp < 0)
			{

				*outFile << "Number of movies must be 0 or grater.";
				inFile->close();
				outFile->close();
				exit(1);
			}
			else
				students[i] = temp;
		}
	}

	
	quickSort(students, numStudents);

	cout << average(students, numStudents) << endl;
	
	cout << mode(students, numStudents) << endl;	
	
	cout << median(students, numStudents) << endl;
		
	delete [] students;

}



int mode(int* students, int size)
{

	int number = students[0];
	int mode = number;
	int count = 1;
	int countM = 1;

	for(int i = 1; i < size; i++) {
		if(students[i] == number)
			countM++;
		else
		{
			if(countM > count)
			{
				count = countM;
				mode = number;
			}
		countM = 1;
		number = students[i];
		}
	}
	return mode;
}

double average(int* students, int size)
{

	double sum = 0;
	for(int i = 0; i < size; i++) {
		sum += students[i];
	}
	double average = sum/size;
	return average;
}

double median(int* students, int size)
{
	double sum = 0.;
	if(size%2 == 0)
	{
		size = size/2 -1;
		sum = students[size] + students[size+1];
		sum /= 2;
	}
	else
	{
		size = size/2;
		sum = students[size];
	}
	return sum;
}	

void quickSort(int* students, int size)
{
	int j, key;
	for(int i = 1; i < size; ++i) {
		key = students[i];
		j = i-1;
		while((j >= 0) && (students[j] > key)){
			students[j+1] = students[j];
			j -= 1;
		}
		students[j+1] = key;
	}
}

