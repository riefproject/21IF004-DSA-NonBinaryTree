#include <stdio.h>
#include <stdlib.h>
#include "nbtree.h"

void showMenu() {
    printf("\n\n");
    printf("1. Traversal PreOrder\n");
    printf("2. Traversal InOrder\n");
    printf("3. Traversal PostOrder\n");
    printf("4. Traversal LevelOrder\n");
    printf("5. Print Tree\n");
    printf("6. Search node Tree\n");
    printf("7. Jumlah Daun/Leaf\n");
    printf("8. Mencari Level node Tree\n");
    printf("9. Kedalaman tree\n");
    printf("10. Membandingkan 2 node Tree\n");
    printf("11. Exit\n");
    printf("Pilih Menu: ");
}

void selectMenu(int choice, Isi_Tree tree, int jmlNode) {
    do {
        showMenu();
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
        case 1:
            PreOrder(tree);
            break;
        case 2:
            InOrder(tree);
            break;
        case 3:
            PostOrder(tree);
            break;
        case 4:
            Level_order(tree, jmlNode);
            break;
        case 5:
            PrintTree(tree);
            break;
        case 6: {
            char nodeToSearch;
            printf("Masukkan node yang dicari: ");
            scanf(" %c", &nodeToSearch);
            Search(tree, nodeToSearch) ? printf("Node %c ditemukan.\n", nodeToSearch) : printf("Node %c tidak ditemukan.\n", nodeToSearch);
            break;
        }
        case 7:
            printf("Jumlah daun: %d\n", nbDaun(tree));
            break;
        case 8: {
            char nodeToFindLevel;
            printf("Masukkan node untuk mencari level: ");
            scanf(" %c", &nodeToFindLevel);
            printf("Level dari node %c adalah: %d\n", nodeToFindLevel, Level(tree, nodeToFindLevel));
            break;
        }
        case 9:
            printf("Kedalaman tree: %d\n", Depth(tree));
            break;
        case 10: {
            infotype Data1, Data2;
            getchar();
            printf("Masukkan node 1: ");
            scanf("%c", &Data1);
            getchar();
            if (!Search(tree, Data1)) {
                printf("Node tak ditemukan!\n");
                break;
            }
            printf("Masukkan node 2: ");
            scanf("%c", &Data2);
            getchar();
            if (!Search(tree, Data2)) {
                printf("Node tak ditemukan!\n");
                break;
            }
            printf("Node dengan infotype terbesar: %c", Max(Data1, Data2));
            break;
        }
        case 11:
            printf("Keluar dari program...\n");
            break;
        default:
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (choice != 11);
}

int main() {
    Isi_Tree tree, duplikat_tree, tree2;
    int jmlNode = 10;

    int choice;
    Create_tree(tree, jmlNode);
    // printf("Jumlah elemen tree: %d\n", nbElmt(tree));
    selectMenu(choice, tree, jmlNode);

    return 0;
}