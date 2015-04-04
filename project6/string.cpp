#include "string.h"

int strLen(char *stdstr)
{
  char *str = stdstr;
  int length = 0;

  while(*str != '\0')
  {
    length++;
    str++;
  }
  return length;
}

void copyString(char *stddest, char *stdsrc)
{
  char *dest = stddest;
  char *src = stdsrc;

  while(*src != '\0')
  {
    *dest = *src;
    src++;
    dest++;
  }

  *dest = '\0';
}

void concatString(char *stddest, char *stdsrc)
{
  char *dest = stddest;
  char *src = stdsrc;

  int destLen = strLen(dest);

  for(int i=0; i<destLen; i++)
  {
    dest++;
  }

  while( *src != '\0' )
     {
      *dest = *src;
      src++;
      dest++;
     }

  *dest = '\0';
}

bool compareStrings(char *stdstr1, char *stdstr2)
{
  char *str1 = stdstr1;
  char *str2 = stdstr2;

  int diff = 0;
  bool cont = true;

  while( *str1 != '\0' && *str2 != '\0' && cont == true)
  {
    diff = *str1 - *str2;

    if( diff != 0 )
       {
        cont = false;
       }

    str1++;
    str2++;
  }
  return cont;
}