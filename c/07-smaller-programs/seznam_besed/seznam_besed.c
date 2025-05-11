#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#define MAX_WORD_LEN 101  // do not that this includes terminating null as well
#define DO_NOT_DUPLICATE true
#define CHARS_ARR_LEN 224 // se NULL char

typedef struct Beseda {
    char* niz;

    // naslednja beseda z isto zacetno crko. ce ima naslednja beseda drugacno zacetno crko, bo to NULL
    struct Beseda* next;
    struct Beseda* prev;
} Beseda;

Beseda* init_beseda(char* niz)
{
    if (strlen(niz) == 0) {
        printf("Poskusas narediti prazno besedo!\n");
        return NULL;
    }

    Beseda* beseda = (Beseda*)malloc(sizeof(Beseda));
    beseda->niz = strdup(niz);
    beseda->next = NULL;
    beseda->prev = NULL;
    return beseda;
}

// sprosti pomnilnik, ki ga zavzame beseda, ter vrne naslednjo besedo z isto crko
Beseda* free_beseda(Beseda* beseda)
{
    Beseda* next = beseda->next;
    free(beseda->niz);
    free(beseda);
    return next;
}

// najde pravilno lokacijo za besedo
// vrne prejsnjo besedo besede ki ima vecjo ordinalno vrednost
// VRNE ZADNJO MANJSO BESEDO
Beseda* najdi_lokacijo(Beseda* zacetek, const Beseda* beseda)
{
    if (zacetek == NULL || beseda == NULL) {
        return NULL;
    }

    while (zacetek != NULL && strcasecmp(zacetek->niz, beseda->niz) < 0) {
        if (zacetek->next == NULL) {
            return zacetek;
        }
        zacetek = zacetek->next;
    }

    if (zacetek != NULL) {
        return zacetek->prev;
    }
    return zacetek;
};

typedef struct {
    Beseda* besede[CHARS_ARR_LEN];
} Besede;

Besede* init_besede()
{
    Besede* besede = malloc(sizeof(Besede));
    for (int i = 0; i < CHARS_ARR_LEN; i++) {
        besede->besede[i] = NULL;
    }
    return besede;
}

int get_word_idx(const Besede* besede, const char* word)
{
    if (besede == NULL) {
        printf("get_word_idx(): besede=NULL\n");
        return -1;
    }
    if (strlen(word) == 0) {
        printf("get_word_idx(): word je prazen: %s\n", word);
        return -1;
    }

    // eliminiramo lowercase crke
    if (word[0] < 'a') {
        return word[0];
    } else if (word[0] >= 'a' && word[0] <= 'z') {
        return word[0] - 32;
    }
    return word[0] - 26;
}

void dodaj_besedo(Besede* besede, Beseda* beseda)
{
    if (besede == NULL || beseda == NULL) {
        printf("dodaj_besedo() besede ALI beseda je NULL\n");
        return;
    }
    const int idx_prve_crke = get_word_idx(besede, beseda->niz);

    if (idx_prve_crke == -1) {
        printf("%s %s %s", besede, beseda, beseda->niz);
        return;
    }
    if (besede->besede[idx_prve_crke] == NULL) {
        besede->besede[idx_prve_crke] = beseda;
        return;
    }

    Beseda* zadnja_manjsa = najdi_lokacijo(besede->besede[idx_prve_crke], beseda);
    Beseda* prva_vecja = NULL;

    // nocemo duplicirat besede (ignorira upper in lower case)
    if (DO_NOT_DUPLICATE && zadnja_manjsa != NULL && strcasecmp(zadnja_manjsa->niz, beseda->niz) == 0) {
        return;
    }

    if (zadnja_manjsa == NULL) {
        prva_vecja = besede->besede[idx_prve_crke];
        besede->besede[idx_prve_crke] = beseda;
    } else {
        prva_vecja = zadnja_manjsa->next;
        zadnja_manjsa->next = beseda;
    }

    beseda->next = prva_vecja;
    beseda->prev = zadnja_manjsa;
    if (prva_vecja != NULL) {
        prva_vecja->prev = beseda;
    }
}

void izpis(const Beseda* beseda)
{
    int i = 1;
    while (beseda != NULL) {
        printf("%d. beseda: %s\n", i++, beseda->niz);
        beseda = beseda->next;
    }
}

int get_st_korakov(const Besede* besede, const char* word) {
    const int idx = get_word_idx(besede, word);

    if (idx == -1) {
        printf("Najden idx za besedo ne obstaja\n");
        return -1;
    }

    Beseda* zacetek = besede->besede[idx];
    int hops = 1;
    bool found = false;
    while (zacetek != NULL) {
        if (strcasecmp(zacetek->niz, word) == 0) {
            return hops;
        }
        zacetek = zacetek->next;
        hops++;
    }
    return -1;
}

void poisci(const Besede* besede, const char* word)
{
    if (besede == NULL || strlen(word) == 0) {
        printf("poisci(): besede NULL ali word prazen\n");
        return;
    }

    int st_korakov = get_st_korakov(besede, word);
    if (st_korakov != -1) {
        printf("Beseda %s najdena po %d. hopih.\n", word, st_korakov);
    } else {
        printf("Beseda \"%s\" ni bila najdena.\n", word);
    }
}

int strlen_fake(const char* niz) {
    int i = 0;
    while((*niz) != '\0') {
        if (isalnum(*niz)) {
            i++;
        }
        niz++;
    }
    return i;
}


void povprecnoIskanje(const Besede* besede) {
    int st_korakov = 0;
    int st_besed = 0;
    Beseda* curr_beseda;
    for (int i = 0; i<CHARS_ARR_LEN; i++) {
        curr_beseda = besede->besede[i];
        while (curr_beseda != NULL) {
            st_besed++;
            st_korakov += get_st_korakov(besede, curr_beseda->niz);
            curr_beseda = curr_beseda -> next;
        }
    }
    printf("Povprecno stevilo hopov na besedo je %.2f.\n", (float)st_korakov / st_besed);
}

int main(const int argc, char* args[])
{
    if (argc != 2) {
        printf("Datoteka ni definirana!\n");
        return -1;
    }
    FILE* file = fopen(args[1], "r");
    if (file == NULL) {
        printf("File coild not be opened!\n");
        return -1;
    }

    Besede* besede = init_besede();

    char curr_beseda[MAX_WORD_LEN] = { '\0' };
    while (feof(file) == false) {


        fscanf(file, "%99[a-zA-Z]%*[^a-zA-Z]", curr_beseda);
        if (curr_beseda[0] != '\0') {
            if (strlen_fake(curr_beseda)> 3) {
                dodaj_besedo(besede, init_beseda(curr_beseda));
            }
            for (int i = 0; i<MAX_WORD_LEN; i++) {
                curr_beseda[i] = '\0';
            }
        } else {
            printf("fscanf on empty!\n");
            return -1;
        }
    }

    izpis(besede->besede[65]);
    dodaj_besedo(besede, init_beseda("a0"));
    dodaj_besedo(besede, init_beseda("A0"));
    dodaj_besedo(besede, init_beseda("a10"));
    dodaj_besedo(besede, init_beseda("matej"));
    dodaj_besedo(besede, init_beseda("starc"));
    poisci(besede, "axxx");
    povprecnoIskanje(besede);

    return 0;
}
