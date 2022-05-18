#include<stdio.h>
#include<string.h>

#define nmax 100

/*

fi.txt
600080396 moraues_victor 0
101086396 agues_tor 1
201011396 es_ictr 0
401086396 ages_r 1

*/

typedef struct Venta{

	int tlf;
	//int tj = 0;
	char nom[40];
	int ct;


}V;

int main(){

	int i, j;
	int n=1;
	//V A[4][3];
	V A[10];
	
	FILE *f = fopen("fi.txt", "r");
	
		
		for(i=0;i<4;i++){
		
			//for(j=0;j<6;j++){
			
				//fscanf(f,"%d %s", &A[i][j].tlf, A[i][j].nom);
				fscanf(f,"%d %s %d", &A[i].tlf, A[i].nom, &A[i].ct);
			
			//}
		
		}
		
		printf("\n");
		
		for(i=0;i<4;i++){
		
			//for(j=0;j<6;j++){
			
				//fprintf(f,"%d %s", A[i][j].tlf, A[i][j].nom);
				printf("valor telf: %d, valor nom: %s, valor tipo de contrato: %d \n ", A[i].tlf, A[i].nom, A[i].ct);
			
			//}
		
		}


	fclose(f);
	
}



