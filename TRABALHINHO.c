#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	int qntE=0, qntJ=0, menu=0, i=1; //Equipes, Jogos, Menu, incremento
	int vt, em, dt, soma, pnt; //vitoria, empate, derrota, soma, pontuação
	
	
	while(qntE>10 || qntE<3){
		printf("Digite a quantidade de equipes(3 a 10): ");
		scanf("%d", &qntE);
	}  //verifica a validade do valor qntE

	
	while(qntJ>10 || qntJ<1){
		printf("Valor invalido!\n");
		printf("digite a quantidade de jogos disputados(1 a 10):");
		scanf("%d", &qntJ);
	}  //verifica a validade do valor qntJ
	
	
	while(menu<1 || menu>5){
		printf("== Menu ==\n1 - Registrar resultados do campeonato\n2 - Mostrar resumo do campeonato\n3 - Mostrar regulamento\n4 - Simular campanha de uma equipe\n5 - Encerrar sistema\nEscolha uma opção: ");
		scanf("%d", &menu);
	}
	
	switch(menu){
		case 1:
			for(; i<=qntE; i++){
				printf("\nEquipe %d\n", i);
				printf("Digite a quantidade de\nVitórias\nEmpate\nDerrota: \n");
				scanf("%d, %d, %d", &vt, &em,&dt);
				soma = vt + em + dt;

				while(qntJ!=soma){
					printf("\nValores Invalidos!\nDigite a quantidade de\nVitórias\nEmpate\nDerrota:\n");
					scanf("%d, %d, %d", &vt, &em,&dt);
					soma = vt + em + dt;
				}
				
				pnt = vt*3 + em + dt*0;
				
				printf("\n%d Jogos por equipe.\nEquipe %d: %d Vitórias, %d Empates, %d Derrotas. \nPontuação: %d pontos", qntJ, i, vt, em, dt, pnt);
				if(pnt>=15){
					printf("\nSituação: Excelente campanha!\n");
				}else if(pnt<=14 && pnt>=10){
					printf("\nSituação: Boa campanha!\n");
				}else if(pnt<=9 && pnt>=5){
					printf("\nSituação: Campanha regular!\n");
				}else{
					printf("\nSituação: Campanha ruim!\n");
				}
				
			}
		break;
			
		default:
			printf("AIAI");
			
	}
	
}
