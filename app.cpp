#include <iostream>
#include <iomanip>
#include <string>


using namespace std;


void AskForValues(int numCourses, string courses[], int unitsAttempted[], string grades[]);
int  UnitsPassed(int numCourses,string grades[]);
double TotalUnit(int numCourses, int unitsAttempted[]);
double  WeightedScore(int numCourses,int unitsAttempted[], string grades[]);

int main()
{
	cout << " Welcome to CGPA Calculator Application " << endl;

	
	// Declaring of variables
	string courses[20]; 
	int unitsAttempted[20];
	string grades[20];
	int numUnitsPassed;
	double weightedScoreValue;
	double totalUnits;
	double gradePoint;
	char answer;

	do{

	int numCourses;
	cout << "How many Courses are you did you offer? " ; 
	cin >> numCourses;


	courses[numCourses];
	unitsAttempted[numCourses];
	grades[numCourses];


	AskForValues(numCourses, courses, unitsAttempted, grades);
	numUnitsPassed = UnitsPassed(numCourses,grades);
	totalUnits = TotalUnit(numCourses,unitsAttempted);
	weightedScoreValue = WeightedScore(numCourses,unitsAttempted,grades);

	
	// Set the result to 2 decimal places
	cout.precision(2);
    cout.setf(ios::fixed);
	// To calculate the GP
	gradePoint =   (weightedScoreValue /  totalUnits ) ; 

	cout << endl  << "You attempted " << totalUnits << " units." << endl;
	cout << endl << "You passed  " << numUnitsPassed << " courses " << endl;
	cout << "Your Grade Point Average is  " << gradePoint << endl;
	
	
	// To Calculate again
		cout << endl << "Do you want to do calculate again? (Y = Yes  & N = No)" << endl;
		cin >> answer;
	}
	while(answer == 'y' || 'Y');
  
	system("PAUSE");
	return 0;
}

void AskForValues(int numCourses, string courses[], int unitsAttempted[], string grades[])
{
	for(int i = 0 ; i < numCourses; i++)
	{
		cout << "Enter the name of the course " << endl ;
		cin >> courses[i];
		cin.ignore();

		cout << "Enter the unit of the course " << endl ;
		cin >> unitsAttempted[i];
		cin.ignore();
		
		cout << "Enter the grade of the course - A , B, C, D, E, F " << endl ;
		cin >> grades[i];
		cin.ignore();
	}
	
}


int  UnitsPassed(int numCourses,string grades[])
{
	int count = 0;
	for(int i = 0; i< numCourses; i++)
	{
		if(grades[i] == "A" || grades[i] ==  "B" ||   grades[i] ==  "C"  || grades[i] ==  "D"  || grades[i] ==  "E"  )
		{
			count += 1;	
		}
		else if(grades[i] != "F" )
		{
		   cout << " Incorrect Grade was entered" << endl;
		}
	}
	return count;
}



double TotalUnit(int numCourses,int unitsAttempted[]){
	int totalUnits = 0;
	for(int i =0; i< numCourses; i++)
	{
		totalUnits += unitsAttempted[i];
	}
	return totalUnits;
}


double WeightedScore(int numCourses,int unitsAttempted[], string grades[])
{
	int totalScore = 0;
	for(int i =0; i< numCourses; i++)
	{
		if( grades[i] == "A" ){
		   totalScore += (5 * unitsAttempted[i]);
		}
		else if( grades[i] == "B" ){
			totalScore += (4 * unitsAttempted[i]);
		}
		else if( grades[i] == "C" ){
			totalScore += (3 * unitsAttempted[i]);
		}
		else if(grades[i] == "D"){
			totalScore += (2 * unitsAttempted[i]);
		}
		else if( grades[i] == "E"){
			totalScore += (1 * unitsAttempted[i]);
		}
		else if( grades[i] == "F"){
			totalScore += (0 * unitsAttempted[i]);
		}	
	}
	  return totalScore;
}
