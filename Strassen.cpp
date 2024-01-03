#include <stdio.h>
#include <stdlib.h>
void init(int **&a, int m, int n)
{
    a = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        a[i] = (int *)calloc(n, sizeof(int));
    }
}
void del(int **a, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        free(a[i]);
    }
    free(a);
}
void read(int **a, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", a[i] + j);
        }
    }
}
void write(int **a, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
void add(int **a, int **b, int **c, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}
void sub(int **a, int **b, int **c, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}
void cpy(int **a, int **b, int x0, int y0, int x1, int y1)
{
    for (int i = 0; i < x1 - x0; i++)
    {
        for (int j = 0; j < y1 - y0; j++)
        {
            b[i][j] = a[i + x0][j + y0];
        }
    }
}
void mul(int **a, int **b, int **c, int m, int n, int k)
{
    if (m == 1 && n == 1 && k == 1)
    {
        **c = **a * **b;
        return;
    }
    int **a11, **a12, **a21, **a22, **b11, **b12, **b21, **b22;
    init(a11, (m + 1) / 2, (n + 1) / 2);
    init(a12, (m + 1) / 2, (n + 1) / 2);
    init(a21, (m + 1) / 2, (n + 1) / 2);
    init(a22, (m + 1) / 2, (n + 1) / 2);
    init(b11, (n + 1) / 2, (k + 1) / 2);
    init(b21, (n + 1) / 2, (k + 1) / 2);
    init(b12, (n + 1) / 2, (k + 1) / 2);
    init(b22, (n + 1) / 2, (k + 1) / 2);
    cpy(a, a11, 0, 0, (m + 1) / 2, (n + 1) / 2);
    cpy(a, a12, 0, (n + 1) / 2, (m + 1) / 2, n);
    cpy(a, a21, (m + 1) / 2, 0, m, (n + 1) / 2);
    cpy(a, a22, (m + 1) / 2, (n + 1) / 2, m, n);
    cpy(b, b11, 0, 0, (n + 1) / 2, (k + 1) / 2);
    cpy(b, b12, 0, (k + 1) / 2, (n + 1) / 2, k);
    cpy(b, b21, (n + 1) / 2, 0, n, (k + 1) / 2);
    cpy(b, b22, (n + 1) / 2, (k + 1) / 2, n, k);
    int **m1, **m2, **m3, **m4, **m5, **m6, **m7, **tmp1, **tmp2;
    init(m1, (m + 1) / 2, (k + 1) / 2);
    init(m2, (m + 1) / 2, (k + 1) / 2);
    init(m3, (m + 1) / 2, (k + 1) / 2);
    init(m4, (m + 1) / 2, (k + 1) / 2);
    init(m5, (m + 1) / 2, (k + 1) / 2);
    init(m6, (m + 1) / 2, (k + 1) / 2);
    init(m7, (m + 1) / 2, (k + 1) / 2);
    init(tmp1, (m + 1) / 2, (n + 1) / 2);
    init(tmp2, (n + 1) / 2, (k + 1) / 2);
    add(a11, a22, tmp1, (m + 1) / 2, (n + 1) / 2);
    add(b11, b22, tmp2, (n + 1) / 2, (k + 1) / 2);
    mul(tmp1, tmp2, m1, (m + 1) / 2, (n + 1) / 2, (k + 1) / 2);
    add(a21, a22, tmp1, (m + 1) / 2, (n + 1) / 2);
    mul(tmp1, b11, m2, (m + 1) / 2, (n + 1) / 2, (k + 1) / 2);
    sub(b12, b22, tmp2, (n + 1) / 2, (k + 1) / 2);
    mul(a11, tmp2, m3, (m + 1) / 2, (n + 1) / 2, (k + 1) / 2);
    sub(b21, b11, tmp2, (n + 1) / 2, (k + 1) / 2);
    mul(a22, tmp2, m4, (m + 1) / 2, (n + 1) / 2, (k + 1) / 2);
    add(a11, a12, tmp1, (m + 1) / 2, (n + 1) / 2);
    mul(tmp1, b22, m5, (m + 1) / 2, (n + 1) / 2, (k + 1) / 2);
    sub(a21, a11, tmp1, (m + 1) / 2, (n + 1) / 2);
    add(b11, b12, tmp2, (n + 1) / 2, (k + 1) / 2);
    mul(tmp1, tmp2, m6, (m + 1) / 2, (n + 1) / 2, (k + 1) / 2);
    sub(a12, a22, tmp1, (m + 1) / 2, (n + 1) / 2);
    add(b21, b22, tmp2, (n + 1) / 2, (k + 1) / 2);
    mul(tmp1, tmp2, m7, (m + 1) / 2, (n + 1) / 2, (k + 1) / 2);
    del(a11, (m + 1) / 2, (n + 1) / 2);
    del(a12, (m + 1) / 2, (n + 1) / 2);
    del(a21, (m + 1) / 2, (n + 1) / 2);
    del(a22, (m + 1) / 2, (n + 1) / 2);
    del(b11, (n + 1) / 2, (k + 1) / 2);
    del(b21, (n + 1) / 2, (k + 1) / 2);
    del(b12, (n + 1) / 2, (k + 1) / 2);
    del(b22, (n + 1) / 2, (k + 1) / 2);
    del(tmp1, (m + 1) / 2, (n + 1) / 2);
    del(tmp2, (n + 1) / 2, (k + 1) / 2);
    int **c11, **c12, **c21, **c22;
    init(c11, (m + 1) / 2, (k + 1) / 2);
    init(c12, (m + 1) / 2, (k + 1) / 2);
    init(c21, (m + 1) / 2, (k + 1) / 2);
    init(c22, (m + 1) / 2, (k + 1) / 2);
    add(m1, m4, c11, (m + 1) / 2, (k + 1) / 2), sub(c11, m5, c11, (m + 1) / 2, (k + 1) / 2), add(c11, m7, c11, (m + 1) / 2, (k + 1) / 2);
    add(m3, m5, c12, (m + 1) / 2, (k + 1) / 2);
    add(m2, m4, c21, (m + 1) / 2, (k + 1) / 2);
    sub(m1, m2, c22, (m + 1) / 2, (k + 1) / 2), add(c22, m3, c22, (m + 1) / 2, (k + 1) / 2), add(c22, m6, c22, (m + 1) / 2, (k + 1) / 2);
    for (int i = 0; i < (m + 1) / 2; i++)
    {
        for (int j = 0; j < (k + 1) / 2; j++)
        {
            c[i][j] = c11[i][j];
        }
        for (int j = (k + 1) / 2; j < k; j++)
        {
            c[i][j] = c12[i][j - (k + 1) / 2];
        }
    }
    for (int i = (m + 1) / 2; i < m; i++)
    {
        for (int j = 0; j < (k + 1) / 2; j++)
        {
            c[i][j] = c21[i - (m + 1) / 2][j];
        }
        for (int j = (k + 1) / 2; j < k; j++)
        {
            c[i][j] = c22[i - (m + 1) / 2][j - (k + 1) / 2];
        }
    }
    del(m1, (m + 1) / 2, (k + 1) / 2);
    del(m2, (m + 1) / 2, (k + 1) / 2);
    del(m3, (m + 1) / 2, (k + 1) / 2);
    del(m4, (m + 1) / 2, (k + 1) / 2);
    del(m5, (m + 1) / 2, (k + 1) / 2);
    del(m6, (m + 1) / 2, (k + 1) / 2);
    del(m7, (m + 1) / 2, (k + 1) / 2);
    del(c11, (m + 1) / 2, (k + 1) / 2);
    del(c12, (m + 1) / 2, (k + 1) / 2);
    del(c21, (m + 1) / 2, (k + 1) / 2);
    del(c22, (m + 1) / 2, (k + 1) / 2);
}
int main()
{
    int m, n, k;
    scanf("%d%d%d", &m, &n, &k);
    int **a, **b, **c;
    init(a, m, n), init(b, n, k), init(c, m, k);
    read(a, m, n), read(b, n, k);
    mul(a, b, c, m, n, k);
    write(c, m, k);
}