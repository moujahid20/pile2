#include <stdio.h>
#include <stdlib.h>
#define maxelem 100 //nbr max des elements
typedef struct elem
{
    int tabint[maxelem];
    int sommet;//sommet de la pile
}tpile;

///fonction pour creer un pile
tpile *creer_tpile()
{
    //allouer l'espace memoire
    tpile *mapile=(tpile*)malloc(sizeof(tpile));
    if(!mapile)//tester si l'allocation passe bien
    {
        printf("\n erreur!");
        exit(-1);

    }
    mapile->sommet=-1;//initialser le sommet
    return mapile;
}

///fonction pour tester si la pile est vide
int estvide_tpile(tpile pile)
{
    return ((int)pile.sommet==-1);
}

///fonction pour tester si la pile est saturee
int estpleine_tpile(tpile pile)
{
    return ((int)pile.sommet==(maxelem-1));
}

///depiler la pile
int depiler(tpile *mapile,int *val)
{
    if(!mapile)//tester si l'allocation passe bien
    {
        printf("\n erreur!");
        return((int)-1);
    }
    //tester si la pile n'est pas vide
    if(!estvide_tpile(*mapile))
    {
        //la valeur depile et dicrementation de la pile
        *val=mapile->tabint[mapile->sommet--];
        return((int)1);
    }
    return((int)0);

}

///empiler la pile
int empiler(tpile *mapile,int element)
{
    if(!mapile)//tester si l'allocation passe bien
    {
        printf("\n erreur!");
        return((int)-1);
    }
    //tester si la pile n'est pas saturee
    if(!estpleine_tpile(*mapile))
    {

        mapile->sommet++;//incrementation de la pile
        mapile->tabint[mapile->sommet]=element;//empiler l'element
        return((int)1);
    }
    return((int)0);

}

///fonction pour afficher les element de la pile
int afficher_tpile(tpile *pile)
{
    //creer une 2eme pile
    tpile *pile2=creer_tpile();
    int val;//la valeur depile
    if(!pile)
    {
        printf("\n erreur!");
        return((int)-1);
    }
    //tester si la pile est vide
    if(estvide_tpile(*pile))
    {
        printf("\n pile est vide ");
        return((int)0);
    }
    //boucle pour depiler la pile principale
    while(depiler(pile,&val))
    {
        //afficher l'element dipile
        printf("\t\t %d",val);
        //empiler l'element dans la 2eme pile
        if(empiler(pile2,val));
    }
    //boucle pour depiler la 2eme pile
    while(depiler(pile2,&val))
    {
        //empiler l'element dans la pile principale
        if(empiler(pile,val));
    }
    return((int)1);

}

void main()
{
    tpile *pile=NULL;
    int x;
    pile=creer_tpile();
    if(empiler(pile,1));
    if(empiler(pile,2));
    if(empiler(pile,3));
    if(empiler(pile,4));
    if(empiler(pile,5));

    if(afficher_tpile(pile));
    if(empiler(pile,9));
    if(afficher_tpile(pile));
}

