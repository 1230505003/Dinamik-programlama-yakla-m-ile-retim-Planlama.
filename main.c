#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000 

int min(int a, int b) {
    return a < b ? a : b;
}
int main() {
	int i;
	int j;
	int k;
	
    int n, m;
    printf("Is sayisini girin: ");
    scanf("%d", &n);
    printf("Makine sayisini girin: ");
    scanf("%d", &m);

    int time[n][m];
    int cost[m][m];

    printf("Islem surelerini girin (n satir m sutun):\n");
    for ( i = 0; i < n; i++)
        for ( j = 0; j < m; j++)
            scanf("%d", &time[i][j]);

    printf("Gecis maliyetlerini girin (m satir m sutun):\n");
    for ( i = 0; i < m; i++)
        for ( j = 0; j < m; j++)
            scanf("%d", &cost[i][j]);

    int dp[n][m];

  
    for ( j = 0; j < m; j++) {
        dp[0][j] = time[0][j];
    }

    
    for ( i = 1; i < n; i++) {
        for ( j = 0; j < m; j++) { 
            dp[i][j] = INF;
            for ( k = 0; k < m; k++) { 
                int transition = (k == j) ? 0 : cost[k][j];
                dp[i][j] = min(dp[i][j], dp[i-1][k] + transition + time[i][j]);
            }
        }
    }

    int result = INF;
    for ( j = 0; j < m; j++) {
        result = min(result, dp[n-1][j]);
    }

    printf("Minimum toplam sure: %d\n", result);

    return 0;
}

