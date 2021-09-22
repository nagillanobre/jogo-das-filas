// Nome: Nagilla Nobre da Silva

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>

#define TAM 10

typedef struct JogoDasFilas{
	char fila[TAM];
	int elem;
	int ini;
	int fim;
	int resul;
}JDF;

char aux;

void criar(JDF* fila){
	char letras[] = "ABCDEFGHIJ";
	int i, aux, num;
	srand(time(NULL));
	for (i = 0; i < TAM; i++){
		num = rand() % TAM;
		aux = letras[i];
		letras[i] = letras[num];
		letras[num] = aux;
	}
	
	for(i = 0; i < TAM; i++){
		fila->fila[i] = letras[i];
	}
}

void preencher(JDF* fila){
	int i;
	for (i=0; i<TAM; i++){
		fila->fila[i] = 45;
	}
}

void imprimir(JDF* fila){
	int i;
	for(i=0; i<TAM; i++){
		printf(" %c ", fila->fila[i]);
	}
	printf("\n");
}

int remover(JDF* fila){
	if(fila->elem == 0){
		printf(" N�o h� o que remover!\n");
	}else{
		aux = fila->fila[fila->ini];
		fila->fila[fila->ini] = 45;
		fila->ini++;
		fila->elem--;
		if(fila->ini == TAM){
			fila->ini = 0;
		}
	}
	return aux;
}

void adiciona(JDF* fila){
	if(fila->elem == TAM){
		printf(" Fila cheia! N�o pode adicionar!\n");
	}else{
		fila->fila[fila->fim] = aux;
		fila->fim++;
		fila->elem++;
		if(fila->fim == TAM){
			fila->fim = 0;
		}
	}
}

void ganhou(JDF* fila){
	char vet[] = "ABCDEFGHIJ";
	int i;
	for(i=0; i<TAM; i++){
		if(fila->fila[i] != vet[i]){
			break;
		}else{
			continue;
		}
	}
	if(i == TAM){
		fila->resul = 1;
	}else{
		fila->resul = 0;
	}
}

int main(){
	setlocale(LC_ALL, "");
	
	JDF* fila1 = malloc(sizeof(JDF));
	fila1->elem = TAM;
	fila1->ini = 0;
	fila1->fim = 0;
	criar(fila1);
	JDF* fila2 = malloc(sizeof(JDF));
	fila2->elem = 0;
	fila2->ini = 0;
	fila2->fim = 0;
	preencher(fila2);

	JDF* fila3 = malloc(sizeof(JDF));
	fila3->elem = 0;
	fila3->ini = 0;
	fila3->fim = 0;
	preencher(fila3);				
	
	printf(" Este � o Jogo das Filas!\n");
	printf(" A regra das filas �: o primeiro que entra � o primeiro que sai, de forma circular.\n Voc� s� poder� remover do come�o e adicionar no final da fila. Ent�o a l�gica � fazer\n movimentos com aten��o para n�o cometer erros e perder.\n");
	printf(" O objetivo � deixar todos as letras em ordem alfab�tica, nas filas A, B ou C.\n");
	printf(" No momento em que uma das tr�s for completada, o jogo acaba!\n\n");
	printf(" Op��es:\n Digite 1: para Fila A.\n Digite 2: para Fila B.\n Digite 3: para Fila C.\n\n");
	printf(" Esta � a fila A com as letras para organizar:\n Fila A: ");
	imprimir(fila1);
	printf(" Fila B: ");
	imprimir(fila2);
	printf(" Fila C: ");
	imprimir(fila3);
	printf("\n");
	
	int REM, ADD, i=0;
					
	do{
		REM=0; ADD=0;
		printf(" Digite de qual fila remover:\n ");
		scanf("%d", &REM);
		getchar();
		printf("\n Digite em qual fila adicionar:\n ");
		scanf("%d", &ADD);
		getchar();
		printf("\n");
		
		if(REM == 1 && ADD == 2){
			remover(fila1);
			adiciona(fila2);
			printf(" Fila A: ");
			imprimir(fila1);
			printf(" Fila B: ");
			imprimir(fila2);
			printf(" Fila C: ");
			imprimir(fila3);
			printf("\n");
		}else if(REM == 1 && ADD == 3){
			remover(fila1);
			adiciona(fila3);
			printf(" Fila A: ");
			imprimir(fila1);
			printf(" Fila B: ");
			imprimir(fila2);
			printf(" Fila C: ");
			imprimir(fila3);
			printf("\n");
		}else if(REM == 2 && ADD == 1){
			remover(fila2);
			adiciona(fila1);
			printf(" Fila A: ");
			imprimir(fila1);
			printf(" Fila B: ");
			imprimir(fila2);
			printf(" Fila C: ");
			imprimir(fila3);
			printf("\n");
		}else if(REM == 2 && ADD == 3){
			remover(fila2);
			adiciona(fila3);
			printf(" Fila A: ");
			imprimir(fila1);
			printf(" Fila B: ");
			imprimir(fila2);
			printf(" Fila C: ");
			imprimir(fila3);
			printf("\n");
		}else if(REM == 3 && ADD == 1){
			remover(fila3);
			adiciona(fila1);
			printf(" Fila A: ");
			imprimir(fila1);
			printf(" Fila B: ");
			imprimir(fila2);
			printf(" Fila C: ");
			imprimir(fila3);
			printf("\n");
		}else if(REM == 3 && ADD == 2){
			remover(fila3);
			adiciona(fila2);
			printf(" Fila A: ");
			imprimir(fila1);
			printf(" Fila B: ");
			imprimir(fila2);
			printf(" Fila C: ");
			imprimir(fila3);
			printf("\n");
		}else{
			printf(" ERRO: Op��o Iv�lida! Leia as instru��es novamente!\n\n");
		}
		ganhou(fila1);
		if((fila1->elem == TAM && fila1->resul == 1) || fila2->elem == TAM || fila3->elem == TAM){
			i = 1;
		}else{
			continue;
		}
	}while(i != 1);
	
	printf("\n GAME OVER!!!\n");
	
	ganhou(fila2);
	ganhou(fila3);
	
	if(fila1->resul == 1 || fila2->resul == 1 || fila3->resul == 1){
		printf(" PARAB�NS!!! VOC� GANHOU!!! :D\n\n");
	}else{
		printf(" Voc� Perdeu! :(\n Tente Outra Vez! ;)\n\n");
	}
	
	system("pause");
	return 0;
}
