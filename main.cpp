//
//  main.cpp
//  Barile_Final_Project
//
//  Created by Michael Barile on 3/29/18.
//  Copyright © 2018 Michael Barile. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void showScores(int correctAns, int numberOfRounds, string category);  // function prototype for showScores function which displays results when user exits program.  showScores defined after int main().

// This is a program that tests basic arithmetics skills.

int main()
{
    int userSelection;  // user selection number from main menu
    // All variables below are initialized to zero and are created to keep track of correct answers and total number of rounds played per category.  All rounds consist of 10 problems.  This info is used to calculate scores for display at end.
    int totalCorrectAnswersAdd = 0;  // total correct answers for all rounds of addition
    int totalCorrectAnswersSub = 0;  // sim for sub, mult, mix
    int totalCorrectAnswersMult = 0;
    int totalCorrectAnswersMix = 0;
    int numberOfRoundsAdd = 0;   // total number of rounds played for addition
    int numberOfRoundsSub = 0;     // sim for sub, mult, mix
    int numberOfRoundsMult = 0;
    int numberOfRoundsMix = 0;
    
    unsigned seed = time(0);
    int MIN_VALUE_ADD, MAX_VALUE_ADD;   // user-specified range of terms for addition and subtraction
    int MIN_VALUE_MULT, MAX_VALUE_MULT;  // user-specified range of terms for multiplication
    const int MIN_VALUE_MIX = 1 , MAX_VALUE_MIX = 3;  // used to generate problems of mixed type
    
    int term1, term2;  // terms to be added, subtracted or multiplied, randomly generated
    int mix; // randomly generated integer between 1 and 3 that determines which type of problem will be generated in mixed problem set //
    int answerRand; // correct answer to arithmetic problem
    int userAnswer; // user answer to arithmetic problem;
    
    srand(seed);
    
    cout << "This program tests basic arithmetic skills.\n";
    cout << "Make a selection from the following choices: "<<endl << endl;
    
    
    while(userSelection != 5)
    {
        cout << "\nPress 1 for addition." << endl;         //menu
        cout << "Press 2 for subtraction." << endl;
        cout << "Press 3 for multiplication." << endl;
        cout << "Press 4 for a mix." << endl;
        cout << "Press 5 to quit." << endl;
        
        cin >> userSelection;            //user selects problem set type
        
        if (userSelection == 1)
        {
            numberOfRoundsAdd++;     // adds 1 to number of addition rounds played
            // same process for subtraction, multiplication, mixed
            
            // user determines range of values
            cout << "You can specify the range of numbers that will be added.\n";
            cout << "Enter the smallest number first and then the largest, separated by a space: ";
            cin >> MIN_VALUE_ADD >> MAX_VALUE_ADD;
            
            if(MIN_VALUE_ADD > MAX_VALUE_ADD)  // switches if user enters in wrong order
            {
                int temp = MIN_VALUE_ADD;
                MIN_VALUE_ADD = MAX_VALUE_ADD;
                MAX_VALUE_ADD = temp;
            }
            
            for(int a = 1; a <= 10; ++a )    // 10 problems total
            {
                
                term1 = rand() % MAX_VALUE_ADD + MIN_VALUE_ADD;    // 2 terms randomly generated
                term2 = rand() % MAX_VALUE_ADD + MIN_VALUE_ADD;
                answerRand = term1 + term2;
                
                cout << term1 << " + " << term2 << " = ";
                cin >> userAnswer;
                
                if(userAnswer == answerRand)
                {                               // congragulates user if user answer correct
                    totalCorrectAnswersAdd++;
                    cout << "You are correct.  Good work!" << endl;
                }
                else
                {                               // correct answer given if user answer is wrong
                    cout << "The correct answer is " << answerRand << "."<< endl;
                }
                
            }
            
        }
        else if(userSelection == 2)
        {
            numberOfRoundsSub++;  // adds 1 to number of Subtraction rounds played
            
            cout << "You can specify the range of numbers that will be subtracted.\n";
            cout << "Enter the smallest number first and then the largest, separated by a space: ";
            cin >> MIN_VALUE_ADD >> MAX_VALUE_ADD;
            
            if(MIN_VALUE_ADD > MAX_VALUE_ADD)  // switches order if user enters incorrectly
            {
                int temp = MIN_VALUE_ADD;
                MIN_VALUE_ADD = MAX_VALUE_ADD;
                MAX_VALUE_ADD = temp;
            }
            
            for(int a = 1; a <= 10; ++a )  // 10 problems per round
            {
                
                term1 = rand() % MAX_VALUE_ADD + MIN_VALUE_ADD;
                term2 = rand() % MAX_VALUE_ADD + MIN_VALUE_ADD;
                answerRand = term1 - term2;
                
                cout << term1 << " - " << term2 << " = ";
                cin >> userAnswer;
                
                if(userAnswer == answerRand)
                {
                    totalCorrectAnswersSub++;
                    cout << "You are correct.  Good work!" << endl;
                }
                else
                {
                    cout << "The correct answer is " << answerRand << "."<< endl;
                }
                
            }
            
        }
        else if(userSelection == 3)    // same process as for addition and multiplication
        {
            numberOfRoundsMult++;
            
            cout << "You can specify the range of numbers that will be multiplied.\n";
            cout << "Enter the smallest number first and then the largest, separated by a space: ";
            cin >> MIN_VALUE_MULT >> MAX_VALUE_MULT;
            
            if(MIN_VALUE_MULT > MAX_VALUE_MULT)  // switches if user enters in wrong order
            {
                int temp = MIN_VALUE_MULT;
                MIN_VALUE_MULT = MAX_VALUE_MULT;
                MAX_VALUE_MULT = temp;
            }
            
            for(int a = 1; a <= 10; ++a )
            {
                
                term1 = rand() % MAX_VALUE_MULT + MIN_VALUE_MULT;
                term2 = rand() % MAX_VALUE_MULT + MIN_VALUE_MULT;
                answerRand = term1*term2;
                
                cout << term1 << " * " << term2 << " = ";
                cin >> userAnswer;
                
                if(userAnswer == answerRand)
                {
                    totalCorrectAnswersMult++;
                    cout << "You are correct.  Good work!" << endl;
                }
                else
                {
                    cout << "The correct answer is " << answerRand << "."<< endl;
                }
                
            }
            
        }
        else if(userSelection == 4)   // mixed problem sets of 10
        {
            numberOfRoundsMix++;
            
            cout << "You can specify the range of numbers that will be added/subtracted or multiplied.\n";
            cout << "Enter range of numbers to be added/subtracted, starting with smallest, and separated by a space: ";
            cin >> MIN_VALUE_ADD >> MAX_VALUE_ADD;
            cout << "Enter range of numbers to be multiplied, starting with smallest, and separated by a space: ";
            cin >> MIN_VALUE_MULT >> MAX_VALUE_MULT;
            
            if(MIN_VALUE_ADD > MAX_VALUE_ADD)  // switches if user enters in wrong order
            {
                int temp = MIN_VALUE_ADD;
                MIN_VALUE_ADD = MAX_VALUE_ADD;
                MAX_VALUE_ADD = temp;
            }
            
            if(MIN_VALUE_MULT > MAX_VALUE_MULT)  // switches if user enters in wrong order
            {
                int temp = MIN_VALUE_MULT;
                MIN_VALUE_MULT = MAX_VALUE_MULT;
                MAX_VALUE_MULT = temp;
            }
            
            for(int a = 1; a <= 10; ++a )
            {
                mix = rand() % MAX_VALUE_MIX + MIN_VALUE_MIX;  // generates a random int between 1 and 3, then uses switch statement to determine problem type
                
                switch(mix)
                {
                    case 1:                         // case 1 addition
                        
                        term1 = rand() % MAX_VALUE_ADD + MIN_VALUE_ADD;
                        term2 = rand() % MAX_VALUE_ADD + MIN_VALUE_ADD;
                        answerRand = term1 + term2;
                        
                        cout << term1 << " + " << term2 << " = ";
                        cin >> userAnswer;
                        break;
                        
                    case 2:                         // case 2 subtraction
                        
                        term1 = rand() % MAX_VALUE_ADD + MIN_VALUE_ADD;
                        term2 = rand() % MAX_VALUE_ADD + MIN_VALUE_ADD;
                        answerRand = term1 - term2;
                        
                        cout << term1 << " - " << term2 << " = ";
                        cin >> userAnswer;
                        break;
                        
                    case 3:                         // case 3 multiplication
                        
                        term1 = rand() % MAX_VALUE_MULT + MIN_VALUE_MULT;
                        term2 = rand() % MAX_VALUE_MULT + MIN_VALUE_MULT;
                        answerRand = term1*term2;
                        
                        cout << term1 << " * " << term2 << " = ";
                        cin >> userAnswer;
                        break;
                }
                
                if(userAnswer == answerRand)
                {
                    totalCorrectAnswersMix++;
                    cout << "You are correct.  Good work!" << endl;
                }
                else
                {
                    cout << "The correct answer is " << answerRand << "."<< endl;
                }
                
            }
        }
        else if (userSelection == 5)   // user quits
        {
            cout << "Sorry to see you go."<< endl << endl;
        }
        else                            // input validation, forces user to enter 1-5 on menu
        {
            cout << "\nInvalid Selection.  Please select a number from the menu." << endl;
        }
    }
    
    if(numberOfRoundsAdd > 0) //after user quits by selecting 5, displays scores with comments adjusted depending on performance by calling showScores function defined below
    {
        showScores(totalCorrectAnswersAdd, numberOfRoundsAdd, "Addition");
    }
    
    if(numberOfRoundsSub > 0)
    {
        showScores(totalCorrectAnswersSub, numberOfRoundsSub, "Subtraction");
    }
    
    if(numberOfRoundsMult > 0)
    {
        showScores(totalCorrectAnswersMult, numberOfRoundsMult, "Multiplication");
    }
    
    if(numberOfRoundsMix > 0)
    {
        showScores(totalCorrectAnswersMix, numberOfRoundsMix, "Mixed");
    }
    
    return 0;
}

// function for displaying final scores

void showScores(int correctAns, int numberOfRounds, string category)
{
    const int PROBLEMS_PER_ROUND = 10;   // all rounds have 10 problems, functions uses stored information from problem sets to calculate and print final scores
    if(100*correctAns/(numberOfRounds*PROBLEMS_PER_ROUND) > 90)
    {
        cout << "You got " <<100*correctAns/(numberOfRounds*PROBLEMS_PER_ROUND) << "% of the problems correct for " << category << " problem sets.  Great Work!" << endl << endl;
    }
    else if(100*correctAns/(numberOfRounds*PROBLEMS_PER_ROUND) > 80)
    {
        cout << "You got " <<100*correctAns/(numberOfRounds*PROBLEMS_PER_ROUND) << "% of the problems correct for " << category << " problem sets.  Good Work!" << endl << endl;
    }
    else
        cout << "You got " <<100*correctAns/(numberOfRounds*PROBLEMS_PER_ROUND) << "% of the problems correct for " << category << " problem sets.  Keep Practicing!" << endl << endl;
}
