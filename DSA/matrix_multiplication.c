#include <stdio.h>

#define N 100

void input_matrix(int mat[N][N], int m, int n);
void print_matrix(int mat[N][N], int m, int n);
void add_matrix(int A[N][N], int B[N][N], int C[N][N], int m, int n);
void multiply_matrix(
    int A[N][N], int B[N][N], int C[N][N], int am, int an, int bm, int bn);

void multiply_matrix_dnc(int A[N][N], int B[N][N], int C[N][N], int n);

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

  printf("\nMultiplying using DnC R = AxB ...\n\n");
  multiply_matrix_dnc(A, B, R, am);

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

void multiply_matrix_dnc(int A[N][N], int B[N][N], int C[N][N], int n) {
  if (n <= 2) {
    C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
    return;
  }

  int A11[N][N], A12[N][N], A21[N][N], A22[N][N];
  int B11[N][N], B12[N][N], B21[N][N], B22[N][N];
  int C11[N][N], C12[N][N], C21[N][N], C22[N][N];
  int C110[N][N], C111[N][N], C120[N][N], C121[N][N], C210[N][N], C211[N][N],
      C220[N][N], C221[N][N];

  multiply_matrix_dnc(A11, B11, C110, n / 2);
  multiply_matrix_dnc(A12, B21, C111, n / 2);
  add_matrix(C110, C111, C11, n / 2, n / 2);

  multiply_matrix_dnc(A11, B12, C120, n / 2);
  multiply_matrix_dnc(A12, B22, C121, n / 2);
  add_matrix(C120, C121, C12, n / 2, n / 2);

  multiply_matrix_dnc(A21, B11, C210, n / 2);
  multiply_matrix_dnc(A22, B21, C211, n / 2);
  add_matrix(C210, C211, C21, n / 2, n / 2);

  multiply_matrix_dnc(A21, B12, C220, n / 2);
  multiply_matrix_dnc(A22, B22, C221, n / 2);
  add_matrix(C220, C221, C22, n / 2, n / 2);

  return;
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

void add_matrix(int A[N][N], int B[N][N], int C[N][N], int m, int n) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
}
