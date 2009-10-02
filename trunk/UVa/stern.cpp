/*  ========================================================================  */
/*  Raphael Montanari                                        n° USP: 5890010  */
/*                      The Stern-Brocot Number System       Accepted    C++  */
/*  ========================================================================  */

#include <stdio.h>

int main() {
    long int m, n;
    long int Num_Esq, Den_Esq, Num_Dir, Den_Dir;
    long int Num, Den;
    scanf("%d %d", &m, &n);
    while ((m != 1) || (n != 1)) {
         if ((float)m/n < 1) {
              Num_Esq = 0;
              Den_Esq = 1;
              Num_Dir = 1;
              Den_Dir = 1;
              printf("L");
         }
         else {
              Num_Esq = 1;
              Den_Esq = 1;
              Num_Dir = 1;
              Den_Dir = 0;
              printf("R");
         }
         Num = Num_Esq + Num_Dir;
         Den = Den_Esq + Den_Dir;
         while ((Num != m) || (Den != n)) {
              if ((float)m/n < (float)Num/Den) {
                   Num_Dir = Num;
                   Den_Dir = Den;
                   printf("L");
              }
              else {
                   Num_Esq = Num;
                   Den_Esq = Den;
                   printf("R");
              }
              Num = Num_Esq + Num_Dir;
              Den = Den_Esq + Den_Dir;
         }
         printf("\n");
         scanf("%d %d", &m, &n);
    }
}
