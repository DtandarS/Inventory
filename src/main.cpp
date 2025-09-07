#include <iostream>
#include <stdio.h>
#include <math.h>
#include "lib/headers.h"

bool boo = true;
int n, m, y;
int main(){

  while ( boo == true ){

      printf("your word is my command : ");
      scanf("%i", &n);

      if (n == 100){

        init();
        loadMedia();


      }

      if (n == 200){

        boo = false;
        return 0;

      };

  };

}
