#include <iostream>
#include <fstream>
#include <ctime>
#include "stdlib.h"
#include "string.h"
#include "machine.h"

using namespace std;

// read in data file
bool readFile(symbol *initial);

// menu screen
int menu();

// executes user selected option
void execute(int option, symbol *initial, reel *machine, bool& cont);

// populate a new slot machine
void option1(symbol *initial, reel *machine);

//print the machine configuration
void option2(reel *machine);

//pick a reel and stop number
void option3(reel *machine);

//spin the reels
void option4(reel *machine);

//exit program
void option5(bool& cont);

int main()
{
  bool read = false;
  bool cont = true;
  int option = 0;

  symbol *initial = new symbol[6];
  reel * machine = new reel[3];

  // seed random number generator
  srand(time(NULL));

  // read file
  read = readFile(initial);

  // program will only run if it read a file correctly
  if(read == true)
  {
    // prepoulate reel
    option1(initial,machine);

    // while loop will run until quit is chosen
    while (cont == true)
    {

      // while loop will run until valid option is chosen
      while( option < 1 || option > 5 )
      {
        option = menu();
      }

      // executes user chosen option
      execute(option,initial,machine,cont);

      cout << endl;

      // resets option picked so user can pick again
      option = 0;
    }
  }

  delete [] initial;
  delete [] machine;
  return 0;
}

// read in data file
bool readFile(symbol *initial)
{
  ifstream fin;

  symbol *initManip = initial;

  int length = 0;
  int tempbounus = 0;

  char *temp = new char[20];
  char *inputFile = NULL;

  cout << "Enter file name: ";
  cin >> temp;

  length = strLen(temp);
  inputFile = new char[length+1];

  copyString(inputFile, temp);

  fin.clear();
  fin.open(inputFile);

  if(fin.good())
  {
    fin >> temp >> tempbounus;

    while(fin.good())
    {
      (*initManip).setname(temp);
      (*initManip).setbonus(tempbounus);
      (*initManip).setvalidBonus();

      initManip++;

      fin >> temp >> tempbounus;
    }

    delete[] temp;
    temp = NULL;

    fin.close();
    cout << "Read File" << endl << endl;
    return true;
  }

  else
  {
    cout << "ERROR: file not found";
    return false;
  }
}

// menu screen
int menu()
{
  int option;

  cout << "Enter the number of the action you'd like to take:" << endl;

  cout << "(1) Populate a new slot machine" << endl;

  cout << "(2) Print the machine configuration" << endl;

  cout << "(3) Pick a reel and stop number" << endl;

  cout << "(4) Spin the reels" << endl;

  cout << "(5) Exit program" << endl << endl;

  cout << "Option: ";

  cin >> option;

  return option;

}

// executes user selected option
void execute(int option, symbol *initial, reel *machine, bool& cont)
{
  reel *machineManip= machine;

  // check option selection
  switch(option)
  {
    // option 1: populate a new slot machine
    case 1:
      // deallocates memory from previous config
      delete [] machine;
      // allocates memory for new config
      machine = new reel[3];
      option1(initial, machine);
    break;

    // option 2: print the machine configuration
    case 2:
      option2(machine);
    break;

    // option 3: pick a reel and stop number
    case 3:
      option3(machine);
    break;

    // option 4: spin the reels
    case 4:
      option4(machine);
    break;

    // option 5: exit program
    case 5:
      option5(cont);
  }
}

// populate a new slot machine
void option1(symbol *initial, reel *machine)
{
  symbol *initManip = initial;
  reel *machineManip = machine;

  for(int i=0; i<3; i++)
  {
    // populate the slot machine
    (*machineManip).setreel(initManip);
    machineManip++;
  }
}

//print the machine configuration
void option2(reel *machine)
{
  reel *machineManip = machine;

  for(int i =0; i<3; i++)
  {
    (*machineManip).printreel();
    cout << endl;
    machineManip++;
  }

}

//pick a reel and stop number
void option3(reel *machine)
{
  reel *machineManip = machine;
  symbol *symbolCol = NULL;

  int i = 0;
  int j = 0;

  while( i < 1 || i > 3)
  {
    cout << "Enter in a reel number (1-3): ";
    cin >> i;
  }

  while( j < 1 || j > 10)
  {
    cout << "Enter in a stop number (1-10): ";
    cin >> j;
  }
  i--;
  j--;

  for(int a=0; a<i; a++)
  {
    machineManip++;
  }

  symbolCol = (*machineManip).getsymbols();

  for(int b=0; b<j; b++)
  {
    symbolCol++;
  }

  (*symbolCol).printsymbol();
}

void option4(reel *machine)
{
  int bonusVal = 0;
  int total = 0;

  reel *machineManip = machine;
  for(int i=0; i<3; i++)
  {
    bonusVal = (*machineManip).spinreel();
    machineManip++;
    total = total + bonusVal;
  }
  cout << "Total Bonus Value: " << total << endl;
}

//exit program
void option5(bool& cont)
{
  cont = false;
}