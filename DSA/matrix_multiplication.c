#include <stdio.h>

#define N 100

void input_matrix(int mat[N][N], int m, int n);
void print_matrix(int mat[N][N], int m, int n);
void multiply_matrix(
    int A[N][N], int B[N][N], int C[N][N], int am, int an, int bm, int bn);

int main() {
  int am = 0, an = 0, bm = 0, bn = 0;

  printf("Enter dimensions of the first matrix: ");
  scanf("%d %d", &am, &an);

  printf("Enter dimensions of the second matrix: ");
  scanf("%d %d", &bm, &bn);

  if (an != bm) {
    printf("Matrix multiplication not possible. Dimensions incompatible\n");
    return 1;
  }

  int A[N][N], B[N][N], R[N][N];

  printf("Input Matrix A: \n");
  input_matrix(A, am, an);

  printf("Input Matrix B: \n");
  input_matrix(B, bm, bn);

  printf("\nMatrix A (%dx%d):\n", am, an);
  print_matrix(A, am, an);

  printf("\nMatrix B (%dx%d):\n", bm, bn);
  print_matrix(B, bm, bn);

  printf("\nMultiplying R = AxB ...\n\n");
  multiply_matrix(A, B, R, am, an, bm, bn);

  printf("\nResult of multiplication:\n");
  print_matrix(R, am, bn);
}

void multiply_matrix(
    int A[N][N], int B[N][N], int C[N][N], int am, int an, int bm, int bn) {
  if (an != bm) return;

  for (int i = 0; i < am; i++) {
    for (int j = 0; j < bn; j++) {
      C[i][j] = 0;
      for (int k = 0; k < an; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

void input_matrix(int mat[N][N], int m, int n) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("(%d, %d): ", i + 1, j + 1);
      scanf("%d", &mat[i][j]);
    }
  }
}

void print_matrix(int mat[N][N], int m, int n) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
}
