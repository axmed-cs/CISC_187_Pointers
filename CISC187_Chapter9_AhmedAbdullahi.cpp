/******************************************************************************

Ahmed Abdullahi

Chapter 9 Review programming assignment - Pointers

October 2023

*******************************************************************************/
#include <iostream>

using namespace std;

// Global constants
const int NUM_ROWS = 4;
const int NUM_COLS = 4;
const int SIZE = 16;

// Function Prototypes
void displayMatrix(int *);
void findMyInteger(int *);
void swapColumn(int *);
void exitFunction();

// main
int main()
{
    //1 Dimentional array and initialization
    int array[SIZE] = { 1,  3,  5,  7,
                        9, 11, 13, 15,
                       17, 19, 21, 23,
                       25, 27, 29, 31};
  
    // pointer variable that points to the array address
    int *intPtr = array;

    
    // while loop
    char option = 0;
  while (option != 4)
  {
    //Display menu
    cout <<  endl << endl << "********************************" << endl;
    cout << "Manipulate or view a 4x4 matrix" << endl;
    cout << "********************************" << endl;
    cout << "1.  Display matrix" << endl;
    cout << "2.  Find a integer" << endl;
    cout << "3.  Swap column 1 and 3" << endl;
    cout << "4.  Exit" << endl << endl;
    
    //input option
    cout << "Please choose a number from the options above or enter 4 to exit: ";
    cin >> option;
    cout << endl << endl;
    
    // switch case from user option
    switch(option)
    {
    case '1': 
        // case 1 will display the matrix
        displayMatrix(intPtr);
        
        break;
    
    case '2':    
            // case 2 will find integer from user input
        findMyInteger(intPtr);
           
        break;
           
    case '3':
        // case 3 will swap column 1 and 3
        swapColumn(intPtr);
            
        break;
       
    case '4' : 
        // case 4 will close program
        exitFunction();
       
        break;
       
    default:  
    
        // validation for menu option
        cout << "That is not a valid menu option." << endl;
        
        break;
    
    }//end switch
    
  }//end the while loop
 
    return 0;
}//end main



/***********************************
 name: displayMatrix
 called by: main
 passed: int *input
 returns: nothing
 calls: nobody
 The displayMatrix function will display 
 the 1 Dimentional matrix using 
 pointer Adresssing
 ***********************************/
void displayMatrix(int *input){
     cout << "Matrix:" << endl;
    for(int i = 0; i < NUM_ROWS; i++){
        for(int j = 0; j < NUM_COLS; j++){
            
          cout << *(input + (i*NUM_ROWS) + j) << " ";
    }
      cout << endl;
    }
}


/**********************************************
 name: findMyInteger
 called by: main
 passed: int *input
 returns: nothing
 calls: nobody
 The findMyInteger function will display 
 the coordinates(row and column) of the user input. 
 It treats the 1 Dimentional array as if it were 
 a 4x4 2-D array using a pointer as the parameter 
 to access the array.
 **********************************************/
void findMyInteger(int *input){
     cout << "Enter the integer you want me to locate: " << endl;
     int userInput = 0;
     int counter = 0;
     cin >> userInput;

      for (int i = 0; i < NUM_ROWS; i++){
          for(int j = 0; j < NUM_COLS; j++){
          if (*(input+(i*NUM_ROWS)+j) == userInput){
              cout << userInput << " found at row: "<< (i+1) << ", col: " << (j+1) << endl; 
              counter += 1;
              break;
          }
      }
      }
    if (counter < 1)
    cout << "Error, " << userInput << " not found..."<< endl;
}
          
          


/***********************************
 name: swapColumn
 called by: main
 passed: int *input
 returns: nothing
 calls: nobody
 The swapColumn function will swap 
 column 1 and column 3 of the matrix
 ***********************************/
void swapColumn(int *input){
     cout << "Swapping column 1 and column 3..." << endl;
    for(int i = 0; i < NUM_ROWS; i++){
     
            int temp = 0;
            temp = *(input+(i*NUM_ROWS));
            *(input+(i*NUM_ROWS)) = *(input+(i*NUM_ROWS)+2);
            *(input+(i*NUM_ROWS)+2) = temp;
    
    cout << endl;
    }
}
    



/***********************************
 name: exitFunction
 called by: main
 passed: nothing
 returns: nothing
 calls: nobody
 The exitFunction function will exit 
 and close the program
 ***********************************/
void exitFunction(){
    cout << "Thanks for playing." << endl;
     exit(0);
}









