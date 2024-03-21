#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi untuk menghitung jumlah langkah minimum pertukaran
int count_swaps(int n, int cards[]) {
    int swaps = 0;
    int i, j;

    for (i = 0; i < n; i++) {
        int min_index = i;
        for (j = i+1; j < n; j++) {
            if (cards[j] < cards[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            // Melakukan pertukaran posisi kartu
            int temp = cards[i];
            cards[i] = cards[min_index];
            cards[min_index] = temp;
            swaps++;

            // Mencetak susunan kartu setelah pertukaran
            printf("Pertukaran %d: ", swaps);
            for (int k = 0; k < n; k++) {
                if (cards[k] == 11) {
                    printf("J ");
                } else if (cards[k] == 12) {
                    printf("Q ");
                } else if (cards[k] == 13) {
                    printf("K ");
                } else {
                    printf("%d ", cards[k]);
                }
            }
            printf("\n");
        }
    }

    return swaps;
}

int main() {
    int n;
    scanf("%d", &n);

    // Mengalokasikan memori untuk array kartu
    int *cards = (int *)malloc(n * sizeof(int));

    // Membaca nilai kartu dari input
    char card[3];
    for (int i = 0; i < n; i++) {
        scanf("%s", card);
        if (strcmp(card, "J") == 0) {
            cards[i] = 11;
        } else if (strcmp(card, "Q") == 0) {
            cards[i] = 12;
        } else if (strcmp(card, "K") == 0) {
            cards[i] = 13;
        } else {
            cards[i] = atoi(card);
        }
    }

    // Mencetak susunan kartu sebelum pertukaran
    printf("Susunan kartu sebelum pertukaran: ");
    for (int i = 0; i < n; i++) {
        if (cards[i] == 11) {
            printf("J ");
        } else if (cards[i] == 12) {
            printf("Q ");
        } else if (cards[i] == 13) {
            printf("K ");
        } else {
            printf("%d ", cards[i]);
        }
    }
    printf("\n");

    // Menghitung jumlah langkah minimum pertukaran
    int minimum_swaps = count_swaps(n, cards);

    // Mencetak jumlah langkah minimum pertukaran
    printf("Jumlah langkah minimum pertukaran: %d\n", minimum_swaps);

    // Membebaskan memori yang dialokasikan untuk array kartu
    free(cards);

    return 0;
}
