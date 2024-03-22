/**
 * multiplicite.c
 *
 * Ce fichier contient la fonction main() du programme de manipulation
 * de fichiers pnm.
 *
 * @authors: SALEHIKATOZI SeyedPouria S192865 
 * @groupe : 4
 * @date: 9/07/2021
 */
#include <stdlib.h>
#include <assert.h>

#include "multiplicite.h"
/**
 * \fn int count_occ(int valeur1, int valeur2, int *max , int occ)
 * \brief Cette fonction compare le maximum avec les deux valeurs en cours
 *        d'observation et met à jour le compteur d'occurences du maximum
 *
 * \param valeur1 est un entier
 * \param valeur2 est un entier
 * \param max est un tableau (max != NULL)
 * \param occ est un entier qui contient le nombre de d'occurence de valeur maximale (occ >= 0)
 *
 * \return  occ le nombre d'occurences de la valeur maximale dans le tableau au moment de l'invocation de la fonction.
 */
static int count_occ(int valeur1, int valeur2, int *max , int occ){
      assert(max != NULL && occ >= 0);

  if(valeur1 == *max){
    occ++;
  }
  if(valeur2 == *max){
    occ++;
  }
  else if(valeur1 > *max && valeur2 > *max && valeur1 == valeur2){
    occ = 2;
  }
  else if(valeur1 > *max || valeur2 > *max){
    occ = 1;
  }

  return occ;
}

int multiplicite(int *T, const int N, int* max){
   assert(T != NULL && N > 0 && max != NULL);
/*
int i , int j ;
// i = ? et j = ?
*/
  unsigned int i = 0;
  unsigned int j = N-1;
  /*
  // i = 0  et j = n - 1
  */
  int occ = 0;
  *max = T[0];

  while(i < j){
    if(T[i] > T[j]){
      if(T[i] > *max){
        occ = 0;
        *max = T[i];
      }
      occ = count_occ(T[i],T[j], max, occ);
    }
    else if(T[i] == T[j]){
      if(T[i] == *max){
          occ = count_occ(T[i],T[j], max, occ);
      }
      if(T[i] > *max){
        occ = 0;
        *max = T[i];
        occ = count_occ(T[i],T[j], max, occ);
      }
    }
    else if(T[i] < T[j]){
      if(T[j] > *max){
        occ = 0;
        *max = T[j];
      }
      occ = count_occ(T[i],T[j], max, occ);
    }
    i++;
    j--;
  }//fin while

  if(i == j){
    if(T[i] > *max){
      occ = 0;
      *max = T[i];
      occ = 1;
    }
    else if(T[i] == *max){
      occ++;
    }
  }

  return occ;
}
