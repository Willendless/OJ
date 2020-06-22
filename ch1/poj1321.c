#include <stdio.h>
#include <string.h>

int m[9][9];
int v[9];
int n;

int dfs(int, int);

int
main()
{
    int k, ch;
    while (scanf("%d %d", &n, &k) != EOF) {
        if (n == -1 && k == -1)
            break;

        getchar();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                m[i][j] = getchar();
            }
            getchar();
        }

        printf("%d\n", dfs(1, k));
    }

    return 0;
}

int
dfs(int line, int left)
{
    if (left == 0)
        return 1;

    if (n - line + 1 < left)
        return 0;
    
    int ret = dfs(line + 1, left);

    for (int i = 1; i <= n; i++) {
        if (m[line][i] == '#' && v[i] == 0) {
            v[i] = 1;
            ret += dfs(line + 1, left - 1);
            v[i] = 0;
        }
    }

    return ret;
}
