#include <iostream>
#include "machine.h"
#include "stdlib.h"
#include "string.h"

using namespace std;

symbol::symbol()
{
  name = NULL;
  bonus = 0;
  validBonus = 0;
}

symbol::symbol(const symbol &srcSymbol)
{
  int size = 0;
  size = strLen(srcSymbol.name);

  name = new char[size+1];
  copyString(name,srcSymbol.name);
  bonus = srcSymbol.bonus;
  validBonus = srcSymbol.validBonus;
}

symbol::~symbol()
{
  delete[] name;
  name = NULL;
  bonus = 0;
  validBonus = 0;
}

void symbol::setname(char *string)
{
  int length = 0;
  length = strLen(string);

  name = new char[length+1];
  copyString(name,string);
}

char* symbol::getname()
{
  return name;
}

void symbol::setbonus(int number)
{
  bonus = number;
}

int symbol::getbonus()
{
  return bonus;
}

void symbol::setvalidBonus()
{
  if(bonus > 0)
  {
    validBonus = 1;
  }

  else
  {
    validBonus = 0;
  }
}

bool symbol::getvalidBonus()
{
  return validBonus;
}

void symbol::printsymbol()const
{
  cout << name << ' ';
  cout << bonus << ' ';
  cout << validBonus << ' ';
}

void symbol::copysymbol(symbol stdsymbol)
{
  int length = 0;
  char *srcname = stdsymbol.getname();

  length = strLen(srcname);

  name = new char[length+1];
  copyString(name,srcname);

  bonus = stdsymbol.getbonus();
  validBonus = stdsymbol.getvalidBonus();
}

reel::reel()
{
  symbols = new symbol[10];
  payline = 0;
}

reel::reel(const reel &srcReel)
{
  symbol *srcSymbols = srcReel.symbols;

  symbols = new symbol[10];
  symbol *symbolsManip = symbols;

  for(int i=0; i<10; i++)
  {
    (*symbolsManip).copysymbol((*srcSymbols));
    symbolsManip++;
    srcSymbols++;
  }
  symbols = srcReel.symbols;
  payline = srcReel.payline;

}

reel::~reel()
{
  delete [] symbols;
  symbols = NULL;
  payline = 0;
}

void reel::setreel(symbol *initial)
{
  int randomN;
  int n = 0;

  symbol *initManip = initial;
  symbol *symbolsManip = symbols;

  for(int i=0; i<10; i++)
      {
        randomN = rand() %6;

        //points the pointer to the random number location
        while(n < randomN)
        {
          initManip++;
          n++;
        }
        //copy values from symbol to machine
        (*symbolsManip).copysymbol((*initManip));

        //reset initManip pointer
        initManip = initial;

        //resest counter
        n = 0;

        //increment symbols pointer
        symbolsManip++;
      }
}

symbol* reel::getsymbols()
{
 return symbols;
}

int reel::spinreel()
{
  symbol *symbolsManip = symbols;

  int randomj;
  int total = 0;

  // get random stop
  randomj = rand() % 10;
  payline = randomj;
  for(int j = 0; j<randomj; j++)
  {
    symbolsManip++;
  }
  (*symbolsManip).printsymbol();

  return (*symbolsManip).getbonus();
}

void reel::printreel()const
{
  symbol *symbolsManip = symbols;

  for(int i=0; i<10; i++)
  {
    (*symbolsManip).printsymbol();
    cout << endl;
    symbolsManip++;
  }
}