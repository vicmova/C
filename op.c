#include <stdio.h>
#include <string.h>

// exámen: 18:30h

/*
nombre del fichero: ventas.txt 

contenido del fichero: 

0 1111 0 Wul
1 2222 1 Luci
2 3333 0 Osw
0 4444 1 Kevin
1 0000 0 Roc
0 5555 1 Joe
2 1212 0 Tomeu
1 2323 1 Hugo
0 0101 1 Victor
2 1231 0 Tina
1 3213 0 Ian
*/

#define nmax 10

typedef struct vendas{

    char tlf[10];
    int contrato;
    char nom[10];

}venda;


void cargar (venda v[3][nmax], int num[], char nombrefichero[]);

void imprimir (venda v[3][nmax], int num[]);

int buscar (venda v[3][nmax], int num[], char tlf[], int *posi, int *posj);

int borrar (venda v[3][nmax], int num[], char nombreborrar[], int *posi, int *posj);

void introducir (venda v[3][nmax], venda k, int num[], int op);
    
void contratos (venda v[3][nmax], int num[], int cont[]);

void contacero (int cont[], int num[]);


void main(){

	venda v[3][nmax];
	venda k;

	char salida;
		
	FILE *f;
	
    	int n=1, operador, posi, posj, res, op, cont[nmax],x;
    
	int num[3]={0,0,0};
    
    char nombrefichero[nmax], tlf[nmax], nombreborrar[nmax];
    
    	printf("------------------------------------------------------------------------\n");
    	printf ("Indica el nombre del fichero que deseas cargar seguido de su extensión: \n");
    	printf("------------------------------------------------------------------------\n");
        
        scanf("%s", nombrefichero);
        
        cargar (v,num,nombrefichero);
    
    	printf("---------------------\n");
    	printf("--Opciones del menu--\n");
    	printf("---------------------\n");

    while (n!=0){

        printf("1. Imprime las ventas. \n");
        
        printf("2. Accede a la información mediante el número del teléfono. \n");
        
        printf("3. Da de baja a un contacto. \n");
        
        printf("4. Crea un contacto. \n");
        
        printf("5. Contrato o targeta. \n");
        
        printf("6. Sal del programa. \n");


        scanf("%d", &n);

        switch(n){

            case 1: imprimir (v, num);
			
			printf("\n");

			printf("Introduce una venta. \n");

			
            
            		break;
            
            case 2: printf("Buscar teléfono: \n");
                	
			scanf("%s", tlf);
                	
                	res = buscar (v, num, tlf, &posi, &posj);
                	
                	if (res==0){
                    	
                    		printf("El contacto no aparece en el fichero. \n");
                	
                	} else {
				
				/*for (x=0; x<3; x++){
        
        			operador=x;
		
        
        			if (x==0){
            
            			printf("	El usuario pertenece a: MOVIESPLAN: \n");
        
        			} else if (x==1){
            
            			printf("	El usuario pertenece a: VODASTONE: \n"); 
	
				} else {
            
            			printf("	El usuario pertenece a: ALMENA: \n");
        	
				}
	
				}*/
                    		
				printf("	Teléfono: %s. Tipo de contrato: %d. Nombre: %s. \n", v[posi][posj].tlf, v[posi][posj].contrato, v[posi][posj].nom);
                	
                	}
			
			printf("\n");
                
                	break;
            
            case 3: printf("Dar de baja por nombre: \n");
                	
                	scanf("%s", nombreborrar);
                
                	res=borrar (v, num, nombreborrar, &posi, &posj);
                	
                	if (res==0){
                    	
                    	printf("El contacto no pertenece a este fichero. \n");
                	
			} else {
                    
                    	printf("El contacto ha sido eliminado. \n");
                	
                	}
                	
			printf("\n");
		
                	break;
            
            case 4: printf("Operador, telefono, contrato, nombre: \n");
                
                	scanf("%d", &op);
                	
                	scanf("%s %d %s", k.tlf, &k.contrato, k.nom);
                	
                	introducir (v,k,num,op);

			printf("\n");
                
                	break;
                
            case 5: printf("Compañias con más de 3 contratos (1) que no son de targeta (0)\n");
                
                	contacero (cont, num);
                	
                	contratos(v,num,cont);

			printf("\n");

			break;
                	
            case 6: printf("¿Seguro? s/n \n");

			
				scanf("%c", &salida);


				if(salida=='s'){

					n=0;				

				}

			printf("\n");

			break;
            
            
        }
    }

}

void cargar (venda v[3][nmax], int num[], char nombrefichero[]){
    
    int operador;
    
    FILE *f=fopen(nombrefichero, "r");

    
    while (fscanf(f,"%d", &operador) > 0){
        
        fscanf(f,"%s %d %s", v[operador][num[operador]].tlf, &v[operador][num[operador]].contrato, v[operador][num[operador]].nom);
            
            num[operador]++;
    }

    fclose(f);
}

void imprimir (venda v[3][nmax], int num[]){
  
    int i, j, operador;

    for (i=0; i<3; i++){
        
        operador=i;
        
        if (i==0){
            
            	printf("MOVIESPLAN: \n");
		
		printf("\n");
        
        } else if (i==1){
            
            	printf("VODASTONE: \n");
      		
		printf("\n");  
	
	} else {
            
            	printf("ALMENA: \n");
		
		printf("\n");
        }

        for (j=0; j<num[i]; j++){
            
            printf("	%s %d %s", v[i][j].tlf, v[i][j].contrato, v[i][j].nom);
            
            printf("\n");
        }
    }
}

int buscar (venda v[3][nmax], int num[], char tlf[], int *posi, int *posj){
    
    int i, j, x, operador, esta=0, res;

	
    for (i=0; i<3; i++){
        
        for (j=0; j<num[i]; j++){
            
            if (strcmp(tlf, v[i][j].tlf) == 0){
                
                *posi=i;
                
                *posj=j;
                
                esta=1;

            }
        }
    }
    
    if (esta==0){
        
        res=0;
        
        return res;
    
	} else {
        
        res=1;
        
        return res;
    }
    
}


int borrar (venda v[3][nmax], int num[], char nombreborrar[], int *posi, int *posj){
    int i,j, trobat=0, res;
    
    for (i=0;i<3;i++){
        
        for (j=0; j<num[i]; j++){
            
            if (strcmp(nombreborrar, v[i][j].nom) == 0){
                
                *posi=i;
                
                *posj=j;
                
                trobat=1;
            }
        }
    }
    
    if (trobat==0){
        
        res=0;
        
        return res;
    } else {
        
        for (i=*posi; i<3; i++){
            
            for (j=*posj; j<num[i]; j++){
                
                v[i][j]=v[i+1][j+1];
            }
        }
        
        num[i]=num[i]-1;
        
        res=1;
        
        return res;
    }
}

void introducir (venda v[3][nmax], venda k, int num[], int op){
    
    	v[op][num[op]]= k;
    
	num[op]++;
}

void contratos (venda v[3][nmax], int num[], int cont[]){
    int i, j, x;
    
    for (i=0; i<3;i++){

        for (j=0;j<num[i];j++){
            
		if (v[i][j].contrato==1){
                
		x=i;
                
		cont[x]++;
            }
        }
    }
            i=0;
            
            while (i<3){
                
                x=i;
                
                if (cont[x]>3){
                    
                    if (x==0){
                        
                        
			printf("Moviesplan \n");
                    } else if (x==1){
                        
                        printf("Vodastone \n");
                    } else {
                        
                        printf("Almena \n");
                    }
                }
                
                i++;
            }
                    
}

void contacero (int cont[], int num[]){
    
    int i, x;
    
    for (x=0; x<num[i]; x++){
        
        cont[x]=0;
    }
}
