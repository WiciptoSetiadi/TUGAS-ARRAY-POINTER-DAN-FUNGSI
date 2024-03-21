#include <stdio.h>
#include <stdlib.h>

void koboImaginaryChess(int i, int j, int size, int *chessBoard) {
    // Menginisialisasi papan catur dengan nilai 0 di setiap index
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            *(chessBoard + row * size + col) = 0;
        }
    }

    // Menandai posisi yang dapat dicapai oleh bidak kuda
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int k = 0; k < 8; k++) {
        int x = i + dx[k];
        int y = j + dy[k];

        if (x >= 0 && x < size && y >= 0 && y < size) {
            *(chessBoard + x * size + y) = 1;
        }
    }

    // Output array berukuran 8x8 sesuai soal
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            printf("%d ", *(chessBoard + row * size + col));
        }
        printf("\n");
    }
}

int main() {
    int i, j;
    scanf("%d %d", &i, &j);

    int size = 8;
    int *chessBoard = (int *)malloc(size * size * sizeof(int));

    if (chessBoard == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }

    koboImaginaryChess(i, j, size, chessBoard);

    free(chessBoard);
    return 0;
}
