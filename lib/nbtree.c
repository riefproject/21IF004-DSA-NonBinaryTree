#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nbtree.h"

/*************************/
/* S P E S I F I K A S I */
/*************************/
void Create_tree(Isi_Tree X, int Jml_Node) {
    // Create Non Binary Tree sebanyak Jml_Node
    // Tujuan mengentrykan Non Binary Tree ke array Isi_Tree dengan pola Level Order
    // Jml Node adalah banyaknya elemen dalam Tree yang menjadi parameter input

    if (Jml_Node < 1 || Jml_Node > jml_maks) {
        printf("Jumlah node tidak valid\n");
        return;
    }
    for (int i = 0; i < jml_maks; i++) {
        X[i].info = '\0';
        X[i].ps_fs = nil;
        X[i].ps_nb = nil;
        X[i].ps_pr = nil;
    }

    // -1 karena array 0-based index
    Isi_Tree template = {
        // fs, nb, pr
        {'A', 2 - 1, 0 - 1,  0 - 1},
        {'B', 4 - 1, 3 - 1,  1 - 1},
        {'C', 6 - 1, 0 - 1,  1 - 1},
        {'D', 0 - 1, 5 - 1,  2 - 1},
        {'E', 9 - 1, 0 - 1,  2 - 1},
        {'F', 0 - 1, 7 - 1,  3 - 1},
        {'G', 0 - 1, 8 - 1,  3 - 1},
        {'H', 0 - 1, 0 - 1,  3 - 1},
        {'I', 0 - 1, 10 - 1, 5 - 1},
        {'J', 0 - 1, 0 - 1,  5 - 1}
    };

    memcpy(X, template, sizeof(nbtree) * Jml_Node);

}

bool IsEmpty(Isi_Tree P) {
    /* Mengirimkan true jika Isi_Tree KOSONG */
    return P[0].info == '\0' && P[0].ps_fs == nil && P[0].ps_pr == nil;
}

/***** Traversal *****/


void PreOrder(Isi_Tree P) {
    /* Traversal PreOrder */
    /* IS : P terdefinisi */
    /* FS : Semua simpul P sudah ditampilkan secara PreOrder : Parent,
    fs, nb */
    if (IsEmpty(P)) {
        printf("Tree is empty\n");
        return;
    }

    int cur = 0;
    printf("%c ", P[cur].info);
    bool flag = true;

    do {
        if (P[cur].ps_fs != nil && flag) {
            cur = P[cur].ps_fs;
            printf("%c ", P[cur].info);
        }
        else if (P[cur].ps_nb != nil) {
            cur = P[cur].ps_nb;
            printf("%c ", P[cur].info);
            flag = true;
        }
        else {
            cur = P[cur].ps_pr;
            flag = false;
        }
    } while (P[cur].ps_pr != nil);
    printf("\n");
}

void InOrder(Isi_Tree P) {
    /* Traversal InOrder */
    /* IS : P terdefinisi */
    /* FS : Semua simpul P sudah ditampilkan secara InOrder : fs, Parent,
    Sisa anak lain */
    int cur = 0;
    bool flag = true;
    while (cur != nil) {
        if (P[cur].ps_fs != nil && flag) {
            cur = P[cur].ps_fs;
        }
        else {
            if (flag) {
                printf("%c ", P[cur].info);
            }
            if (cur == P[P[cur].ps_pr].ps_fs) {
                printf("%c ", P[P[cur].ps_pr].info);

            }
            if (P[cur].ps_nb != nil) {
                cur = P[cur].ps_nb;
                flag = true;
            }
            else {
                cur = P[cur].ps_pr;
                flag = false;
            }
        }
    }
    printf("\n");
}

void PostOrder(Isi_Tree P) {
    /* Traversal PostOrder */
    /* IS : P terdefinisi */
    /* FS : Semua simpul P sudah ditampilkan secara PostOrder : fs, nb,
    Parent */
    int cur = 0;
    bool flag = true;
    while (cur != nil) {
        if (P[cur].ps_fs != nil && flag) {
            cur = P[cur].ps_fs;
        }
        else {
            printf("%c ", P[cur].info);
            if (P[cur].ps_nb != nil) {
                cur = P[cur].ps_nb;
                flag = true;
            }
            else {
                cur = P[cur].ps_pr;
                flag = false;
            }
        }
    }
    printf("\n");
}

void Level_order(Isi_Tree X, int Maks_node) {
    /* Traversal LevelOrder */
    /* IS : P terdefinisi */
    /* FS : Semua simpul P sudah ditampilkan secara Level Order */
    int depth = 0;
    bool flag = true;

    while (flag) {
        flag = false;
        for (int i = 0; X[i].info != '\0'; ++i) {
            int curDepth = Level(X, X[i].info);

            if (curDepth == depth) {
                printf("%c ", X[i].info);
                flag = true;
            }
        }
        depth++;
    }
    printf("\n");
}

void PrintTree(Isi_Tree P) {
    /* IS : P terdefinisi */
    /* FS : Semua simpul P sudah ditulis ke layar */
    printf("Seluruh Node pada Non Binary Tree:\n");
    for (int i = 0; P[i].info != '\0'; i++) {
        printf("\n---> Indeks ke-%d\n", i);
        printf("----------------------------------\n");
        printf("info array ke %d         : %c\n", i, P[i].info);
        printf("first son array ke %d    : %d\n", i, P[i].ps_fs);
        printf("next brother array ke %d : %d\n", i, P[i].ps_nb);
        printf("parent array ke %d       : %d\n", i, P[i].ps_pr);
        printf("----------------------------------\n");
    }

}

/***** Search *****/

bool Search(Isi_Tree P, infotype X) {
    /* Mengirimkan true jika ada node dari P yang bernilai X */
    for (int i = 0; P[i].info != '\0'; i++) {
        if (P[i].info == X) return true;
    }
    return false;
}

/***** Fungsi Lain *****/

int nbElmt(Isi_Tree P) {
    /* Mengirimkan banyak elemen (node) di pohon non biner P */
    int i = 0;
    while (P[i].info != '\0') {
        i++;
    }
    return i;
}

int nbDaun(Isi_Tree P) {
    /* Mengirimkan banyak daun (node) pohon non biner P */
    int cnt = 0;
    for (int i = 0; P[i].info != '\0'; ++i) {
        if (P[i].ps_fs == nil) cnt++;
    }
    return cnt;
}

int Level(Isi_Tree P, infotype X) {
    /* Mengirimkan level dari node X yang merupakan salah satu simpul */
    /* dr pohon P. Akar (P) levelnya adalah 0. Pohon tidak kosong */
    int idx = 0;
    while (P[idx].info != X) idx++;

    int depth = 0;
    while (P[idx].ps_pr != nil) {
        depth++;
        idx = P[idx].ps_pr;
    }
    return depth;
}

int Depth(Isi_Tree P) {
    /* Pohon Biner mungkin Kosong, mengirimkan 'depth' yaitu tinggi dari
    Pohon */
    /* Basis : Pohon Kosong, tingginya Nol */
    int idx = 0;
    while (P[idx].info != '\0') idx++;
    return Level(P, P[idx - 1].info);
}

infotype Max(infotype Data1, infotype Data2) {
    /* Mengirimkan Nilai terbesar dari dua data */
    if (Data1 >= Data2) return Data1;
    else return Data2;
}