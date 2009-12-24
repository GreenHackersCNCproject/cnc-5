#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//#include <math.h>

char *base2dec(char *str, int base)
{
  char *ret = malloc(sizeof(int)*20);
  char *tmp = malloc(sizeof(int));
  int dec = 0;
  int digit = 0;
  int r = 0;
  int digit_weight = 1;

  for (r = strlen(str)-1; r >= 0; r--) {
    strncpy(tmp, &str[r], 1);
    digit = atoi(tmp);

    if ( digit == 1 ) {
      dec += digit_weight;
    }
    digit_weight *= base;
  }
  sprintf(ret, "%i", dec);
  return ret;
}

char *dec2base(int num, int base)
{
  char *bin = malloc(sizeof(int)*20);
  char *tmp = malloc(sizeof(int)*20);
  int r = 0;
  while ( num > 0 ) {
    if ( (num%base) != 0 ) {
      r = 1;
    } else {
      r = 0;
    }
    sprintf(tmp, "%i%s", r, bin);
    strcpy(bin, tmp);
    memset(tmp, 0, sizeof(int)*20);
    num=num/base;
  }
  return bin;
}

char *bin2dec(char *str)
{
  return base2dec(str, 2);
}

char *dec2bin(int num)
{
  return dec2base(num, 2);
}
