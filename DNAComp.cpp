/***********************************************************************
* Program:
*    Assignment 01, Genetic Genealogy 
*    Brother Macbeth, CS165
* Author:
*    Filipe Ferreira
* Summary: 
*    This program prompts the user to imput a DNA, then
*    compares the DNA entered with the relatives entered
*    Estimated:  2.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>

using namespace std;

#define MAX_PEOPLE 50 //Max of people to be tested
#define DNA_SIZE 10 // the size of DNA ex: ADDDDADDDD

/************************************************
* The Fuction prompt for Info on DNA and Relatives
*************************************************/
void getDNA(string &DNA, int &numRelatives)
{
   cout << "Enter your DNA sequence: ";
   cin  >> DNA;
 
   cout << "Enter the number of potential relatives: ";
   cin  >> numRelatives;
   cout << endl;
}

/*********************************************************
* This Fuction is responsible for getting the Relatives Name
**********************************************************/
void getRelativeNames(string relativesNames[],
                      const int numRelatives)
{
   for (int i = 0; i < numRelatives; i++)
   {
      cout << "Please enter the name of relative #"
           << i + 1 << ": ";
      cin  >> relativesNames[i];
   }
   
   cout << endl;
}

/******************************************************
* This Fuction is prompt for the Relatives' DNA
******************************************************/
void getRelativesDNA(const int numRelatives,
                     const string relativesNames[],
                     string relativesDNA[])
{
   for (int i = 0; i < numRelatives; i++)
   {
      cout << "Please enter the DNA sequence for "
           << relativesNames[i] << ": ";
      cin  >> relativesDNA[i];
   }
   cout << endl;
}

/*******************************************************
* This Fuction Computes the DNA matches of the relatives
********************************************************/
void checkDNAmatches(const string &DNA, const int numRelatives,
                     const string relativesDNA[], int perMacth[])
{
   for (int i = 0; i < numRelatives; i++)
   {
      perMacth[i] = 0;
      
      for (int j = 0; j < DNA_SIZE; j++)
      {
         if (DNA[j] == relativesDNA[i][j])
         {
            perMacth[i] += 10;
            
         }
      }
   }
}

/****************************************************
* This Fuction Display our matched message
****************************************************/
void display(const string relativesNames[], const
             int numRelatives, const int perMacth[])
{
   for (int i = 0; i < numRelatives; i++)
   {
      cout << "Percent match for " << relativesNames[i]
           << ": " << perMacth[i] << "%\n";
   }
}


/************************************************
* This is our driven fuction
*************************************************/
int main()
{
   //All the variables to be analized
   string DNA;
   int numRelatives = 0;
   string relativesNames[MAX_PEOPLE];
   string relativesDNA [MAX_PEOPLE];
   int perMacth[MAX_PEOPLE];

   //All our the fuctions to be called
   getDNA(DNA, numRelatives);
   getRelativeNames(relativesNames, numRelatives);
   getRelativesDNA(numRelatives, relativesNames, relativesDNA);
   checkDNAmatches(DNA, numRelatives,relativesDNA, perMacth);
   display(relativesNames, numRelatives, perMacth);
   
   return 0;
}
