/* =========================================================================  */
/*  Raphael Montanari                                        nº USP: 5890010  */
/*  Dog and Gopher                                                            */
/* =========================================================================  */

#include <stdio.h>

int main()
{
	int n, i, fugiu;
	float topeirax, topeiray, dogx, dogy, distancia1, distancia2, saidax, saiday;
	float buraco[10000][2];
	while(scanf("%d", &n) != EOF)
	{
		fugiu = 0;
		scanf("%f%f%f%f", &topeirax, &topeiray, &dogx, &dogy);
		for (i = 0; i < n; i++)
			scanf("%f%f", &buraco[i][0], &buraco[i][1]);
		for (i = 0; i < n; i++)
		{
			distancia1 = (topeirax - buraco[i][0]) * (topeirax - buraco[i][0]) + (topeiray - buraco[i][1]) * (topeiray - buraco[i][1]);
			distancia2 = (dogx - buraco[i][0]) * (dogx - buraco[i][0]) + (dogy - buraco[i][1]) * (dogy - buraco[i][1]);
			if (4*distancia1 <= distancia2)
			{
				fugiu = 1;
				saidax = buraco[i][0];
				saiday = buraco[i][1];
				break;
			}
		}
		if (fugiu == 1)
				printf("The gopher can escape through the hole at (%.3f,%.3f).\n", saidax, saiday);
		else
				printf("The gopher cannot escape.\n");
	}
	return 0;
}
