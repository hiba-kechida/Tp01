#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int val;
    struct element *suivant;
} element;

// Créer une liste vide
element* creerListe() {
    return NULL;
}

// Charger une liste à partir d'un tableau
element* chargerListe(int Tab[], int taille, element* liste) {
    for (int i = taille - 1; i >= 0; i--) {
        element* nouveauNoeud = (element*)malloc(sizeof(element));
        if (nouveauNoeud == NULL) {
            printf("Erreur d'allocation de mémoire\n");
            exit(EXIT_FAILURE);
        }
        nouveauNoeud->val = Tab[i];
        nouveauNoeud->suivant = liste;
        liste = nouveauNoeud;
    }
    return liste;
}

// Afficher une liste
void afficherListe(element* L) {
    while (L != NULL) {
        printf("%d -> ", L->val);
        L = L->suivant;
    }
    printf("Null\n");
}

// Supprimer le dernier élément d'une liste
element* supprimerEnFin(element* L) {
    if (L == NULL) {
        return NULL;
    }
    if (L->suivant == NULL) {
        free(L);
        return NULL;
    }
    element* tmp = L;
    while (tmp->suivant->suivant != NULL) {
        tmp = tmp->suivant;
    }
    free(tmp->suivant);
    tmp->suivant = NULL;
    return L;
}

// Ajouter un élément en début de liste
element* ajouterEnDebut(element* L, int valeur) {
    element* nouveauNoeud = (element*)malloc(sizeof(element));
    if (nouveauNoeud == NULL) {
        printf("Erreur d'allocation de mémoire\n");
        exit(EXIT_FAILURE);
    }
    nouveauNoeud->val = valeur;
    nouveauNoeud->suivant = L;
    return nouveauNoeud;
}

// Vider une liste
void viderListe(element* L) {
    while (L != NULL) {
        element* tmp = L;
        L = L->suivant;
        free(tmp);
    }
    printf("La liste est vide\n");
}

int main() {
    int Tab[10] = {1, 3, 5, 7, 8, 10, 9, 11, 13, 20};
    element* liste = creerListe();
    liste = chargerListe(Tab, 10, liste);
    afficherListe(liste);

    liste = supprimerEnFin(liste);
    afficherListe(liste);

    liste = ajouterEnDebut(liste, 40);
    afficherListe(liste);

    viderListe(liste);
    return 0;
}
