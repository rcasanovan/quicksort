#include <stdio.h>
#include <stdlib.h>

#define RUN_UNIX
//#undef RUN_UNIX

#define TAM_ARREGLO 7

void clrscr()
{
    #ifdef RUN_UNIX
        system("clear");
    #else   
        system("cls");
    #endif
}

void pause()
{
    #ifdef RUN_UNIX
        system("read -p 'Presione una tecla para continuar' var");
    #else   
        system("pause");
    #endif
}

void quicksort(int arreglo[], int L, int R)
{
    int pivote, i, j, x;
    
    i = L;
    j = R;
    pivote  = arreglo[(L+R) / 2];
    
    do
    {
        while (arreglo[i] < pivote)
            i++;
            
        while (arreglo[j] > pivote)
            j--;
            
        if (i <= j)
        {
            /* swap de los valores*/
            x = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = x;
            i++;
            j--;
        }
        
    } while (i <= j);
    
    if (L<j)
        quicksort(arreglo, L, j);
        
    if (i<R)
        quicksort(arreglo, i, R);
}

void imprimirArreglo(int arreglo[])
{
    int i;
    
    printf("arreglo = [");
    
    for (i=0 ; i<TAM_ARREGLO ; i++)
    {
        if (i != TAM_ARREGLO-1)
           printf("%d, ", arreglo[i]);
        else
            printf("%d", arreglo[i]);
    }
    
    printf("]\n");
}

int main()
{
    int arreglo[TAM_ARREGLO];
    
    arreglo[0] = 6;
    arreglo[1] = 9;
    arreglo[2] = 7;
    arreglo[3] = 1;
    arreglo[4] = 3;
    arreglo[5] = 2;
    arreglo[6] = 5;
    
    clrscr(); 
    
    imprimirArreglo(arreglo);
    
    quicksort(arreglo, 0, TAM_ARREGLO-1);
    
    imprimirArreglo(arreglo);
    
    pause();
    
    return EXIT_SUCCESS;
}






