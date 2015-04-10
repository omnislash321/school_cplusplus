//------------------------------------------------------------------------------
// Project Name: Movie Stats 
// Written By: Roberto Hong Xu Kuang
// Last Modified: 11/19/2014
//------------------------------------------------------------------------------


// ****************************************************************************
// GRADE FEEDBACK:
//   * missed 6 test casess (-3)
//
// FINAL GRADE: 97
// ****************************************************************************



// Movie Statistics project that will get an input and output file from the
// command line. Then, these two files will be opened and data will be read and
// written. The program first asks for a number of students, then a dynamically
// sized array will be created. After that, the program will need how many 
// movies each student has seen. Afterwards, it will show the mean, median, and
// mode. The array will also be sorted using the quick sort with a random pivot

#include <iostream> // This is for displaying errors in case no files found.
#include <fstream> // Used for files, input and output.
#include <stdlib.h> // The standard library. For random, and other things.

using namespace std;

//Function Prototypes.
void getData(fstream*, fstream*);
void processData(fstream*, int*, int);
void quickSort(int*, int, int);
int partition(int*, int, int);
void swap(int, int, int*);

//------------------------------------------------------------------------------
// main method - Has command line arguments. Will open the files, or exit
// gracefully if the files are not found.
int main(int argc, char* argv[])
{
	//If there are not enough command line arguments,
	if(argc < 3)
		//Then exit with error code 1.
		exit(1);
	else
	{
		//Two file streams, input and output.
		fstream inFile, outFile;

		//Open the input file.
		inFile.open(argv[1], ios::in);
		//If no input file, then display error and exit.
		if(!inFile)
		{
			cout << "InFile not found!";
			exit(1);
		}

		//Open output file.
		outFile.open(argv[2], ios::out);
		//If no output file, then display error and exit.
		if(!outFile)
		{
			cout << "OutFile not found!";			
			exit(1);
		}

		//If the two files are opened, then continue with program.
		if(inFile && outFile)
		{
			//Call the getData method to collect data.
			getData(&inFile, &outFile);
			//Close the two files.
			inFile.close();
			outFile.close();
		}	
	}	
}

//------------------------------------------------------------------------------
// void getData(fstream pointer inFile, fstream pointer outFile - This will 
// get the information from the inFile and properly show any error messages in
// the output file. 
void getData(fstream* inFile, fstream* outFile)
{

	//The size of the array.
	int numStudents;
	//Array to hold the movies.
	int * moviesSeen;

	//Get the size.
	*outFile << "How many students were surveyed?";
	*inFile >> numStudents;
	
	//If students are less than or equal to 1. 
	if(numStudents <= 1)
	{
		//Display error, then close the files and exit.
		*outFile << " Number of students surveyed must be greater than 1.";
		inFile->close();
		outFile->close();
		exit(1);
	}
	else //Otherwise, continue with the program.
	{
		//Create a new array from the heap with the size.
		moviesSeen = new int[numStudents];

		//Now, we get the data for every single student.
		*outFile << " Enter the number of movies each student saw.\n";
		
		//Loop to go through the entire array.
		for(int loop = 1; loop <= numStudents; loop++)
		{
			int temp = 0;
			*outFile << "Student " << loop << ": ";
			*inFile >> temp;

			//If the number is below 0,
			if(temp < 0)
			{
				//Display error, close files, and then exit.
				*outFile << "Number of movies must be 0 or greater.";
				inFile->close();
				outFile->close();
				exit(1);
			}
			else
				//Otherwise, put the input data into the array.
				moviesSeen[loop-1] = temp;
		} 
	}
	//Now, we process the data.
	processData(outFile, moviesSeen, numStudents);
}

//------------------------------------------------------------------------------
// void processData(fstream pointer outFile, int pointer moviesSeen, int size)
// This will sort the data and then find the mean, median, and mode. 
void processData(fstream* outFile, int* moviesSeen, int size)
{
	//Sort the array using quick sort.
	quickSort(moviesSeen, 0, size-1);

	//The median is different depending on whether or not it is even. 
	double median;
	if(size % 2 == 0)
		median = ( moviesSeen[size/2-1] + moviesSeen[size/2])/2;
	else
		median = moviesSeen[size/2];

	//Start the average with the first value
	double average = moviesSeen[0];	
	
	//This is for the mode.
	int number = moviesSeen[0]; // The current number.
	int mode = number;	//The mode number.
	int count = 1;  // Count of number.
	int countMode = 1;  // Count of mode.
		
	//Since the array is sorted, only one loop will be needed.
	for(int loop = 1; loop < size; loop++)
	{
		//Instead of having two loops, I incorporated the sum into this.
		average += moviesSeen[loop];
		//Since they're in order, all of the same numbers will be in a row.
		//So, if the next number is the same, increment the count.
		if(moviesSeen[loop] == number)
			count ++;
		else
		{
			//If it's not the same, then it is another number.
			//So we need to compare countMode to count, which is the count
			// for the number that's after.
			//And if count is greater than countMode, 
			if(count > countMode)
			{
				//Turn the value and count into the new mode.
				countMode = count;
				mode = number;
			}
			//And reset count and number to the new value.
			count = 1;
			number = moviesSeen[loop];
		}
	}
	//Divide the average by size to get the real average.
	average /= size;
	
	//Output.
	*outFile << "The average number of movies seen is: " << average << "\n";
	*outFile << "The median of the number of movies seen is: "<< median <<"\n";
	*outFile << "The mode of the number of movies seen is: " << mode << "\n";
	
	//Deleting the dynamic array.
	delete [] moviesSeen;
}

//------------------------------------------------------------------------------
// void quickSort(int pointer moviesSeen, int left, int right) - The quicksort
// algorithm that will recursively call itself.
void quickSort(int* moviesSeen, int left, int right)
{
	//Base case.
	if(left < right)
	{
		//Gets a partition from the partition method.
		int mid = partition(moviesSeen, left, right);
		//Recursive calls.
		quickSort(moviesSeen, left, mid-1);
		quickSort(moviesSeen, mid+1, right);
	}	
}

//------------------------------------------------------------------------------
// int partition(int pointer moviesSeen, int left, int right) - This is the 
// method that will use a random pivot point, and then sort everything.
int partition(int* moviesSeen, int left, int right)
{
	//Random pivot chosen using the random function.
	int pivot = rand() % (right - left + 1) + left; 
	int pivotValue = moviesSeen[pivot];
	
	//Swap the pivot to the very right, to move it out of the way.
	swap(pivot, right, moviesSeen);
	
	//Position of the smallest number that is greater than pivot value.
	int index = left;
	
	//Loop through left to right - 1.
	for(int loop = left; loop < right; loop++)
		//If the value is smaller than the pivot,
		if(moviesSeen[loop] < pivotValue)
		{
			//Swap the current index with the index of the smallest big number.
			swap(loop, index, moviesSeen);
			//Increment the wall. 
			index ++;
		}

	//At the very end, index will be the index of the smallest number greater
			//than the pivot Value. So, we swap it.
	swap(index, right, moviesSeen);
	//We must return this new index of the pivot so that we can recursively
	// quicksort the two sides.
	return index;
}

//------------------------------------------------------------------------------
// void swap(int a, int b, int pointer moviesSeen) - Simple swap method that 
// will swap the values of the two indexes inside the array.
void swap(int a, int b, int* moviesSeen)
{
	int temp = moviesSeen[a];
	moviesSeen[a] = moviesSeen[b];
	moviesSeen[b] = temp;
}
