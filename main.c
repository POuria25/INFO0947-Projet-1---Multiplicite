/**
 * main-multiplicite.c
 *
 * Ce fichier contient la fonction main() du programme de manipulation
 * de fichiers pnm.
 *
 * @authors: SALEHIKATOZI SeyedPouria S192865 
 * @groupe : 4
 * @date: 9/07/2021
 * @projet: INFO0947 Projet 1
 */

#include <stdio.h>
#include "multiplicite.h"

int main(void){

  const int N = 9;
  int T[9] = {10,10,10,10,10,10,10,10,10};
  int max;


  printf("%d ", multiplicite(T, N, &max));
  printf("[%d]\n", max);
  return 0;
}
