#include <stdio.h>

/* fill in binaryRep[] the binary representation of val, with size bits.
   space is inserted between the bits for better visual effects.
*/
void fillBinary(char binaryRep[],int val, int size){

  int i;
  for (i=0;i<size;i++) 
  {
      if (val & 1) {
          binaryRep[(size-1-i)*2] = '1'; 
          binaryRep[(size-i-1)*2+1] = ' ';}
      else 
         {binaryRep[(size-1-i)*2] = '0'; 
          binaryRep[(size-i-1)*2+1] = ' ';}
      
      val >>= 1; // shift right to test next bit

  }
  binaryRep[i*2] = '\0';


}

