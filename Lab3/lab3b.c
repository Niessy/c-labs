#include <stdio.h>
#include <string.h>

void fillBinary(char[], int, int);

int main() {
 
 int r, g,b;
 int rgb_pack;
 int r_unpack, g_unpack,b_unpack;
 char outstr[70];
 /* declear variables if you need */


 printf("input R value (0~225): ");
 scanf("%d",&r);
 printf("input G value (0~225): ");
 scanf("%d",&g);
 printf("input B value (0~225): ");
 scanf("%d",&b);

 while(! (r==-1 && g== -1 && b == -1) )
 {			
  fillBinary(outstr,r,8);  /* we only need to see the lower 8 bits */
  printf("R: %d\tbinary rep  0 ... %s\n", r, outstr );
  fillBinary(outstr,g,8);
  printf("G: %d\tbinary rep  0 ... %s\n", g, outstr  );
  fillBinary(outstr,b,8);
  printf("B: %d\tbinary rep  0 ... %s\n", b, outstr  );

  /* now do the packing into rgb_pack */
  /* you code here  */

  rgb_pack = 0;
  rgb_pack = rgb_pack | r;
  rgb_pack = rgb_pack << 8;
  rgb_pack = rgb_pack | g;
  rgb_pack = rgb_pack << 8;
  rgb_pack = rgb_pack | b;


  fillBinary(outstr,rgb_pack,32);
  printf("Packed: value %d.      binary rep %s\n", rgb_pack, outstr );

  printf("Unpacking  ......\n");
 
  /* now do the unpacking from rgb-pack */
  /* you code here  */
  b_unpack = b & rgb_pack;
  rgb_pack = rgb_pack >> 8;
  g_unpack = g & rgb_pack;
  rgb_pack = rgb_pack >> 8;
  r_unpack = r & rgb_pack;

  /* display the unpacked r g and b */
  fillBinary(outstr,r_unpack,32);
  printf("R: %s (%d)\n", outstr,r_unpack );
  fillBinary(outstr,g_unpack,32);
  printf("G: %s (%d)\n", outstr,g_unpack  );
  fillBinary(outstr,b_unpack,32);
  printf("B: %s (%d)\n", outstr,b_unpack  );

  /* read again */
  printf("\ninput R value: ");
  scanf("%d",&r);
  printf("input G value: ");
  scanf("%d",&g);
  printf("input B value: ");
  scanf("%d",&b);

 }
 return 0;
}


