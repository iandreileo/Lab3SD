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

int Eliminare(TLista  *aL, int e){
    int nr=0;
    TLista L = *aL;
    TLista aux;
    if(!L){
        return nr;
    }
    while(L->urm){
        if(L->urm->info == e){
            aux = L->urm;
            L->urm = aux -> urm;
            free(aux);
            nr++;
        } else {
            L=L->urm;
        }
    }
    if((*aL)->info == e){
        aux = *aL;
        *aL = aux -> urm;
        free(aux);
        nr++;
    }
    return nr;
}

TLista CitireOrdonata(size_t *lg){
    TLista L = NULL;
    TLista U;
    TLista aux;
    int x;
    char ch;
    for(*lg = 0; scanf("%d", &x)==1;){
        aux=AlocCelula(x);
        if(L=NULL){
            L=aux;
        } else {
            if(L->info >= x){
                aux->urm = L;
                L=aux;
            } else {
                U=L;
                while(U->urm && U->urm->info < x){
                    U = U->urm;
                }
                aux->urm = U->urm;
                U->urm = aux;
            }
        }
        (*lg)++;
    }
    while((ch==getchar())!= EOF && ch!='\n'){
    }
    return L;
}

//functia primeste adresa unei lista 
//construieste o noua lista
//din vechea lista in noua lista doar elementele impare
//intoarce lista si numarul de elemente

TLista Mutare(TLista* aL, int *nr){
 nr=0;
 TLista p, ant, r, ultim;
 r=NULL;
 for(ant=NULL, p=*aL; p!=NULL;){
     if(p->info % 2 == 0){
         ant=p;
         p=p->urm;
     } else {
        if(r==NULL){
            r=p;
        } else {
            ultim->urm=p;
        }
        ultim=p;
        if(ant==NULL){
            *aL=p->urm;
        } else {
            ant->urm=p->urm;
        }
        p=p->urm;
        nr++;
     }
 }
 if(r){
     ultim->urm=NULL;
 }
 return r;
}

TLista Reuniune(TLista a, TLista b, int *nr){
    TLista final=NULL;
    TLista ultim;
    TLista p=a, q=b, aux;
    nr=0;
    while(p && q){
        if(p->info > q->info){
            aux = AlocCelula(q->info);
            if(final == NULL){
                final = aux;
            } else {
                ultim->urm = aux;
            }
            ultim = aux;
            q=q->urm;
        } else {
            aux=AlocCelula(p->info);
            if(final == NULL){
                final = aux;
            } else {
                ultim->urm = aux;
            }
            ultim=aux;
            p=p->urm;
        }
    }

    while(p){
        aux = AlocCelula(p->info);
        if(final == NULL){
            final = aux;
        } else {
            ultim->urm=aux;
        }
        ultim = aux;
        p=p->urm;
    }
    while(q){
        aux = AlocCelula(q->info);
        if(final == NULL){
            final = aux;
        } else {
            ultim->urm = aux;
        }
        ultim = aux;
        q=q->urm;
    }
    if(final){
        ultim->urm = NULL;
    }
    return final;
}

//primim o lista
//primeste o lista cu elementele impare din lisat trecuta
TLista Copiere(TLista aL, int *nr){
    TLista p, aux, ultim, r=NULL;
    nr=0;
    for(p=aL;p!=NULL;p=p->urm){
        aux=AlocCelula(p->info);
        if(!aux)
            return r;
        if(r==NULL){
            r=aux;
        } else {
            ultim->urm = aux;
        }
        nr++;
        ultim=aux;
    }
    return r;

}

int main(){
    TLista x = NULL;     /* Lista prelucrata */
    int lx;           /* lungime lista */

    for (;;){
    /* citeste si afiseaza lista */
    printf("\nIntroduceti valori elemente terminate cu valoare nenumerica:\n");
    x = CitireL(&lx);
    AfisareL(x);
    if(!x) continue;
    int nr=0;
    TLista mutare = Mutare(&x,&nr);
    AfisareL(mutare);
    AfisareL(x);
    TLista reuniune = Reuniune(x,mutare,&nr);
    AfisareL(reuniune);

    TLista copie = Copiere(x,&nr);
    AfisareL(copie);
    DistrugeL(&x);
    DistrugeL(&mutare);
    DistrugeL(&reuniune);
    printf ("\n  Inca un test ? [d/n]");
    if (getchar() == 'n') break;
  }


    return 0;
}