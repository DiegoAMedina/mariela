//Names: Noe Lomeli, Diego Molina, David Jia, Alexis Munoz
//Date: 10-31-15
//Description: Speech Signal Analysis

//Which values for each data file match most closely?
//The data files that match the most, at first is the standard deviation with only 2.7% difference.
//The next data file that matches the most is the mean with 5.4% difference.
//Which values for each data file are most different?
//The data files that differ the most are the zero crossings with 49.4% difference and the average //magnitude with 18.4% difference.
//Are there other statistical measures that you could suggest?
//Another statistical measure to add would be the frequency
//Can you determine if these sound recordings are from the same person? Explain.
//It is not the same person due to the pitch not changing enough. The file comparison would be //much greater in difference if someone was kidnapped. Zero crossings would have a more //dramatic difference.


#include <iostream> // input output
#include <fstream> // files
#include <cstdlib> // exit()
#include <cmath>
#include <iomanip>
using namespace std;

double mean(double ary[], int n);
//Precondition:Array must be of type int, with the size/number of positions of the array going to 
//             be used, passed in as the second parameter of type int.
//Postcondition:Returns the mean of the the array type double

double stdDev(double var);
//Precondition:Take in variance of, type double.
//Postcondition:returns the standard deviation, type double.

double variance(double ary[], double mean, int num);
//Precondition:Takes in array of type double, also takes in mean of type double
//             and the size of array of type int.
//Postcondition:Returns the variance of the array of type double.

double avgPower(double ary[],int n);
//Precondition:Takes in array of type double with the size of the array of type int.
//Postcondition:Returns the average power of the array of type double.

double avgMagnitude(double ary[],int n);
//Precondition:Takes in array of type double with size of the array of type int.
//Postcondition:Returns the average magnitude of the array of type double.

int zeroCrossing(double ary[],int n);
//Precondition:Takes in array of type double with size of the array of type int.
//Postcondition:Returns the amount of zero crossing of type int.

double difference(double a, double b);
//Precondition:Takes in two parameters of type double.
//Postcondition:Returns the percentage difference between them,of type double.


//**********************************************************************************
int main()
{
    ifstream finA;
	ifstream finB;
	ofstream fout;
	
	const int SIZE = 1000;
	
	int index = 0;
	int zeroCrossingA;
	int zeroCrossingB;
	
	double valA;
	double valB;
    double meanA;
    double meanB;
    double stdDevA;
    double stdDevB;
    double varA;
    double varB;
    double meanDiff;
    double stdDevDiff;
    double varDiff;
    double zeroCrossDiff;
    double avgMagA;
    double avgMagB;
    double magDiff;
    double avgPowA;
    double avgPowB;
    double powDiff;
    
    double ary2A[SIZE];
    double ary2B[SIZE];


	finA.open("two_a.txt");
	finB.open("two_b.txt");
	fout.open("comparison.txt");

	if( finA.fail() || finB.fail() || fout.fail() )
	{
		cout << "Error opening filestream" << endl;
		exit(1);
	}

    while(finA >> ary2A[index] )
    {
        index++;
    }
    
    index = 0;
    
    while(finB >> ary2B[index] )
    {
        index++;
    }
      
    meanA = mean(ary2A,SIZE);
    meanB = mean(ary2B,SIZE);
    
    stdDevA = stdDev(meanA);
    stdDevB = stdDev(meanB);
    
    varA = variance(ary2A,meanA,SIZE);
    varB = variance(ary2B,meanB,SIZE);
    
    zeroCrossingA = zeroCrossing(ary2A,SIZE);
    zeroCrossingB = zeroCrossing(ary2B,SIZE);
    
    avgPowA = avgPower(ary2A,SIZE);
    avgPowB = avgPower(ary2B,SIZE);
    
    avgMagA = avgMagnitude(ary2A,SIZE);
    avgMagB = avgMagnitude(ary2B,SIZE);
    
    meanDiff = difference(meanA,meanB);
    stdDevDiff = difference(stdDevA,stdDevB);
    varDiff = difference(varA,varB);
    zeroCrossDiff = difference(zeroCrossingA,zeroCrossingB);
    powDiff = difference(avgPowA,avgPowB);
    magDiff = difference(avgMagA,avgMagB);

    fout << "Team members: Noe Lomeli, Diego Medina, David Jia, Alexis Munoz" << endl << endl;
    fout << setw(30) << "two_a.txt" << setw(20) << "two_b.txt" << setw(20) << "% difference"<< endl << endl;
    fout << "Mean:" << setw(25) << meanA << setw(20) << meanB << setw(15) << meanDiff<<  endl;
    fout << "Standard Deviation:" << setw(10) << stdDevA << setw(20) << stdDevB << setw(16) << stdDevDiff<< endl;
    fout << "Variance:" << setw(19) << varA << setw(20) << varB << setw(17) << varDiff << endl;
    fout << "Average Power:" << setw(14) << avgPowA << setw(19) << avgPowB << setw(17) << powDiff << endl;
    fout << "Average Magnitude:" << setw(10) << avgMagA << setw(20) << avgMagB << setw(17) << magDiff << endl;
    fout << "Zero Crossings:" << setw(8) << zeroCrossingA << setw(19) << zeroCrossingB << setw(23) << zeroCrossDiff << endl;

	finA.close();
	finB.close();
    fout.close();

	return 0;
}
//**********************************************************************************

double mean(double ary[], int n)
{
	double mean;
	double sum = 0.0;

	for(int ix = 0; ix < n; ix++)
	{
    	sum += ary[ix];
	}

	mean = sum / n;

	return mean;
}

double stdDev( double var)
{
	double result;
    
	result = sqrt(var);

	return result;
}

double variance(double ary[], double mean, int num)
{
    double difference;
	double variance = 0;

    for (int ix(0); ix < num; ix++)
	{
		difference = pow(ary[ix]- mean, 2);
        variance += difference;
    }

    variance = variance / num;	

    return variance;
}

int zeroCrossing(double ary[],int n)
{
    int zeroCross = 0;

    for(int ix = 0; ix < n - 1; ix++)
    {
        if( (ary[ix] < 0) && (ary[ix + 1] > 0) )
        {
            zeroCross++;
        }
        
        else if( (ary[ix] > 0) && (ary[ix + 1] < 0) )
        {
            zeroCross++;
        }
    }
    
    return zeroCross;
}

double difference(double a, double b)
{
    double diff;
    
    diff = ( fabs(a - b) / ( (a + b) / 2.0 )    ) * 100;
    
    return diff;
}

double avgPower(double ary[],int n)
{
    double avgPow;
    double sum = 0.0;
    
    for(int ix = 0; ix < n; ix++)
    {
        sum += pow(ary[ix],2);
    }
    
    avgPow = sum / n;

    return avgPow;

}

double avgMagnitude(double ary[],int n)
{
    double avgMag;
    double sum = 0.0;
    
    for(int ix = 0; ix < n; ix++)
    {
        sum += fabs( ary[ix] );
    }
    
    avgMag = sum / n;
        
    return avgMag;

}




