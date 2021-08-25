#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <iostream>
using namespace std;

/*
Name: Alvin Tran
Section 2 (B)
Final
Date: 04/19/2021
Description: A program that generates a user inputed amount of patients, which are then randomly assigned conditions. Afterward, the program parses the patient list and determines how many people have certain illnesses,
and reports back to the user that information.

*/
class person{ //Generic information about any person. Build in case non patients are added into systems, or may identifying different set of diseases
	private:
		string firstName;
		string lastName;
		int age;
		int weight;
		bool sex;
		
	public:
		void assignDesc(string fn, string ln, int a, int w, bool s){
			firstName = fn;
			lastName = ln;
			age = a;
			weight = w;
			sex = s;
		}
	
};

class patient: public person{ //Patients called in.
	private:
		//Symptoms
		bool fever;
		bool cough;
		bool sob; //shortness of breath
		bool runny; //runny nose
		bool headache;
		bool sneezing;
		bool fatigue;
	public:
		patient(){
			//Each symptom is generated with a 50/50 of being present or not.
			//One can utilize the age, weight, sex, from the derived class person to generate non 50/50 odds.
			//if the above suggestion is follow, it is also advised to generate age in a controlled randomness and not complete randomness (appripiate age %'s)
			//0 is absent, 1 is present
			fever = (rand() % 2) == 1;
			cough = (rand() % 2) == 1;
			sob = (rand() % 2) == 1; //shortness of breath
			runny = (rand() % 2) == 1;
			headache = (rand() % 2) == 1;
			sneezing = (rand() % 2) == 1;
			fatigue = (rand() % 2) == 1;
		}
		void assignSymptoms(bool feverIn, bool coughIn, bool sobIn, bool runnyIn, bool headacheIn, bool sneezingIn, bool fatigueIn){
			fever = feverIn;
			cough = coughIn;
			sob = sobIn;
			runny = runnyIn;
			headache = headacheIn;
			sneezing = sneezingIn;
			fatigue = fatigueIn;
		}
		int diseaseCheck(){
			int covidRisk = 0; // COIVD-19 = 0
			int coldRisk = 0; // Cold = 1
			int fluRisk = 0; // Flu = 2
			//All other illnesses are -1
			
			//Weights
			int commonRisk = 5;
			int rareRisk = 2; 
			int noRisk = -50; //NO cases are assumed to not be that disease
			
			//Minimum amount of risk needed to classify patient under disease
			//Also represents commonality of said disease from symptoms
			int covidMin = 14;
			int coldMin = 10; 
			int fluMin = 12;
			//Using predetermined weights, we assign values to each symptom and generate a "Risk" factor.
			//Any additional multipliers can be added (ie x symptom is rare but more common that other rares)
			//Any additions or subtractors may be prescent if a certain risk factor is VERY common and odd to leave out.
			//Covid Risk
			covidRisk += (fever)?commonRisk:0;
			covidRisk += (cough)?commonRisk:0;
			covidRisk += (sob)?commonRisk:-3; // A patient w/o shortness of breath is much less liekly to have COVID-19
			covidRisk += (runny)?rareRisk:0;
			covidRisk += (headache)?rareRisk:0;
			covidRisk += (sneezing)?noRisk:0;
			covidRisk += (fatigue)?rareRisk:0;
			
			//Cold Risk
			coldRisk += (fever)?rareRisk:0;
			coldRisk += (cough)?rareRisk:0;
			coldRisk += (sob)?noRisk:0;
			coldRisk += (runny)?commonRisk:0;
			coldRisk += (headache)?rareRisk:0;
			coldRisk += (sneezing)?commonRisk:0;
			coldRisk += (fatigue)?rareRisk:0;
			
			//Flu Risk
			fluRisk += (fever)?commonRisk:0;
			fluRisk += (cough)?commonRisk:0;
			fluRisk += (sob)?noRisk:0;
			fluRisk += (runny)?rareRisk:0;
			fluRisk += (headache)?commonRisk:0;
			fluRisk += (sneezing)?noRisk:0;
			fluRisk += (fatigue)?commonRisk:0;
			
			
			//Risk determines if the patient has a disease, and must be above a certain threshold
			//Covid takes prescedence due to the danger. Cold and flue can be reoganized as perceieved danger.
			//If nothing is found to be dangerous, we assume other illness
			if (covidRisk >= covidMin){
				return 0;
			}else if(coldRisk >= coldMin){
				return 1;
			}else if(fluRisk >= fluMin){
				return 2;
			}else{
				return -1;
			}
		}
};

int main(){
	srand(time(NULL));
	
	int patientNumber = 0;
	int covidCases = 0;
	int coldCases = 0;
	int fluCases = 0;
	int otherCases = 0;
	//intial output for user to know
	cout << "Welcome to the Computer Simulated Epidemiology (CSE)" << endl;
	cout << "Here is our current set of diseases we are investigating and their symptoms" << endl << endl;
	
	cout << "Guide:    * Common      + Sometimes/Rarely     - None" << endl;
	cout << "=======================================================" << endl;
	cout << "Symptoms            | COVID-19 |    Cold   |   Flu    |" << endl;
	cout << "=======================================================" << endl;
	cout << "Fever               |     *    |      +    |     *    |" << endl;
	cout << "Cough               |     *    |      +    |     *    |" << endl;
	cout << "Shortness of Breath |     *    |      -    |     -    |" << endl;
	cout << "Runny Nose          |     +    |      *    |     +    |" << endl;
	cout << "Headaches           |     +    |      +    |     *    |" << endl;
	cout << "Sneezing            |     -    |      *    |     -    |" << endl;
	cout << "Fatigue             |     +    |      +    |     *    |" << endl;
	cout << "=======================================================" << endl << endl;
	
	cout << "Input number of patients to check" << endl;
	cin >> patientNumber;
	patient *patientList[patientNumber];
	
	
	for (int i = 0; i < patientNumber; i++){
		patientList[i] = new patient(); // Generates patients for amount of space user specified
		//In here, one can check or ask for user input for the names, age, etc of each patient.
		//Although, better to import some form of excel sheet or txt document.
		
		//after generating said patient, we check for disease
		switch(patientList[i]->diseaseCheck()){
			case 0:
				covidCases++;
				break;
			case 1:
				coldCases++;
				break;
			case 2:
				fluCases++;
				break;
			default:
				otherCases++;
		}
	}
	//Sample Size descriptions
	cout << endl << "=======================================================" << endl;
	cout << "we have found..." <<endl;
	cout << covidCases << " patients with symptoms of COVID-19" << endl;
	cout << coldCases << " patients with symptoms of Cold" << endl;
	cout << fluCases << " patients with symptoms of Flu" << endl;
	cout << otherCases << " patients may have another illness" << endl;
	cout << "=======================================================" << endl << endl;
	cout << "Percentages of each illness:" << endl;
	cout << "COVID-19: [" << covidCases*100/patientNumber << "%]"; 
	for(int i = 0; i < covidCases*100/patientNumber; i++)
		cout << "+";
	cout << endl;
	cout << "Cold    : [" << coldCases*100/patientNumber << "%]"; 
	for(int i = 0; i < coldCases*100/patientNumber; i++)
		cout << "+";
	cout << endl;
	cout << "Flu     : [" << fluCases*100/patientNumber << "%]"; 
	for(int i = 0; i < fluCases*100/patientNumber; i++)
		cout << "+";
	cout << endl;
	cout << "Other   : [" << otherCases*100/patientNumber << "%]"; 
	for(int i = 0; i < otherCases*100/patientNumber; i++)
		cout << "+";
	cout << endl;
	
	
	
}
