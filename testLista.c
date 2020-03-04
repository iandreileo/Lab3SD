/*--- testLista.c ---*/
#include <ctype.h>
#include <stdio.h>
#include "tlista.h"

TLista CitireL(int *lg)     /* construieste lista cu elemente citite */
{ TLista L = NULL, u, aux;
  int x;
  char ch;
  for(*lg = 0; scanf("%i", &x) == 1; )
  {
    aux = AlocCelula(x);           /* incearca inserarea valorii citite */
    if(!aux) return L;              /* alocare esuata => sfarsit citire */
    if(L == NULL) L = aux;
    else u->urm = aux;
    u = aux;
    (*lg)++;
  }

  while((ch=getchar()) != EOF && ch != '\n');
  return L;                     /* intoarce lista rezultat */
}

int primPar(TLista lista){
    int index=0;
    for(;lista;lista=lista->urm){
        if(lista->info % 2 == 0){
            return index;
        }
        index++;
    }
    return -1;
}

void index2(TLista L, int *prim, int *ultim){
    *prim = -1;
    *ultim = -1;
    int index = 0;
    int test_prim=0;
    int test_ultim=0;

    for(;L;L=L->urm){
        if(test_prim==0){
            if(L->info % 2 == 0){
                *prim=index;
                *ultim=*prim;
                test_prim=1;

            }
        } else if(test_prim!=0 && test_ultim==0){
            if(L->info % 2 == 0){
                *ultim=index;
                test_ultim=1;
            }

        }
        index++;
    }
}

int Cardinal(TLista L){
    int cardinal=0;
    for(;L;L=L->urm){
        cardinal++;
    }
    return cardinal;
}

void functieAfisare(TLista L){
    printf("\n");
    for(;L->urm;L=L->urm){
        if(L){
            printf("%d ", L->info);
        }
        if(L->urm){
            printf("%d\n", L->urm->info);
        }
    }
}

void printareJumatati(TLista L){
    int cardinal = Cardinal(L);
    TLista lista1=L;
    TLista lista2=L;
    // printf("\n%d\n", cardinal);
    int contor=0;
    int jumateCardinal;
    if(cardinal%2 == 0){
        jumateCardinal = cardinal/2;
    } else {
        jumateCardinal = cardinal/2+1;
    }
    
    for(;lista2;lista2=lista2->urm){
        if(contor == jumateCardinal){
            break;
        } else {
            contor++;
        }
    }
    if(cardinal%2==0){
        for(int i=0; i < jumateCardinal; i++){
            printf("%d %d\n", lista1->info, lista2->info);
            if(lista1->urm && lista2->urm){
                lista1 = lista1->urm;
                lista2 = lista2->urm;
            }
        }
    } else {
        for(int i=0; i < jumateCardinal-1; i++){
            printf("%d %d\n", lista1->info, lista2->info);
            if(lista1->urm && lista2->urm){
                lista1 = lista1->urm;
                lista2 = lista2->urm;
            }
        }
    }

}

// int insDupaRef(TLista L, int ref, int x){
//     TLista aux,p;
//     for(p=L; p!=NULL; p=p->urm){
//         if(p->info == ref)
//             break;
//     }
//     if(p== NULL){
//         return 0;
//     }
//     aux=AlocCelula(x);
//     if(!aux){
//         return 0;
//     }
//     aux->urm=p->urm;
//     return 1;
// }


int subsecventa(TLista L, int *start){
    int index=0;
    int lungime_max=0;
    int lungime_curr=0;
    int index_subs=-1;
    for(;L->urm;L=L->urm){
        if(L->info < L->urm->info){
            if(lungime_curr==0){
                index_subs=index;
                lungime_curr++;
                lungime_max=lungime_curr;
            } else {
                lungime_curr++;
                lungime_max=lungime_curr;
            }
        } else if(!(L->info < L->urm->info)){
            lungime_curr=0;
        }
        index++;
    }
    *start=index_subs;
    if(lungime_max!=0){
        lungime_max++;
    }

    return lungime_max;
}

void Dublare(TLista L){
    int index=0;
    for(;L;L=L->urm){
        if(L->info % 2 != 0){
            TLista aux,p;
             int ref=L->info, x=L->info;
             int index_p=0;
             p=L;
            for(; p!=NULL; p=p->urm){
                if(index_p==index)
                    break;
                index_p++;
            }
            aux=AlocCelula(x);
            aux->urm=p->urm;
        }
        index++;
    }
}


int main ()
{ TLista x = NULL;     /* Lista prelucrata */
  int lx;           /* lungime lista */

  for (;;)
  {
    /* citeste si afiseaza lista */
    printf("\nIntroduceti valori elemente terminate cu valoare nenumerica:\n");
    x = CitireL(&lx);
    AfisareL(x);
    if(!x) continue;

    /* apeluri functii implementate */
    // printf("\n %d \n", primPar(x));
    // int prim=-1;
    // int ultim=-1;
    // index2(x,&prim,&ultim);
    // printf("\n %d %d\n", prim, ultim);
    // functieAfisare(x);
    // printf("\n");
    // printareJumatati(x);
    // int start;
    // subsecventa(x, &start);
    // printf("\n%d %d\n", subsecventa(x,&start), start);
    Dublare(x);
    printf("\n");
    AfisareL(x);

    DistrugeL(&x);
    printf ("\n  Inca un test ? [d/n]");
    if (getchar() == 'n') break;
  }
}
