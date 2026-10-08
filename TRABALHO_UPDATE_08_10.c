#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	int qntE=0, qntJ=0, menu=0, i, voltar=1; //Equipes, Jogos, Menu, incremento, voltar p/menu
	int vt, em, dt, soma, pnt; //vitoria, empate, derrota, soma, pontuação
	int qntVT=0, qntEM=0, qntDT=0; float qntPNT=0;//Contadores vt, em, dt, pnt
	int qexc=0, qboa=0, qreg=0, qruim=0;//Contadores situacao: excelente, boa, regular, ruim
	
	while(qntE>10 || qntE<3){
		printf("Digite a quantidade de equipes(3 a 10): ");
		scanf("%d", &qntE);
	}  //verifica a validade do valor qntE
	
	while(qntJ>10 || qntJ<1){
		printf("\nDigite a quantidade de jogos disputados(1 a 10):");
		scanf("%d", &qntJ);
	}  //verifica a validade do valor qntJ
	
	system("cls");//system("cls"); limpa o terminal
	
	do{
		system("cls");
		voltar=1; i=1; //reseta o as variaveis/contadores
		
		printf("== Menu ==\n1 - Registrar resultados do campeonato\n2 - Mostrar resumo do campeonato\n3 - Mostrar regulamento\n4 - Simular campanha de uma equipe\n5 - Encerrar sistema\nEscolha uma opção: ");
		scanf("%d", &menu);
		
		switch(menu){
		case 1://pedir qnts de vitorias, empates, derrotas por equipe, calcular e mostrar situação
			system("cls");
			qexc=0; qboa=0; qreg=0; qruim=0;//zera acumuladores
			qntVT=0; qntEM=0; qntDT=0; qntPNT=0;
			
			for(i=1; i<=qntE; i++){
				printf("Equipe %d\n", i);
				printf("Digite a quantidade de\nVitórias, Empates, Derrotas: ");
				scanf("%d, %d, %d", &vt, &em, &dt);
				soma = vt + em + dt;

				while(qntJ!=soma){
					printf("\nValores Invalidos!\nDigite a quantidade de\nVitórias, Empates, Derrotas: ");
					scanf("%d, %d, %d", &vt, &em, &dt);
					soma = vt + em + dt;
				}
				
				qntVT+=vt; qntEM+=em; qntDT+=dt;//acumula qnt no contadores
				
				
				pnt = vt*3 + em + dt*0;//calcula pontuacao individual
				
				qntPNT+=pnt;//calcula/acumula pontos totais de todas equipes
				
				printf("\n%d Jogos por equipe.\nEquipe %d: %d Vitórias, %d Empates, %d Derrotas. \nPontuação: %d pontos", qntJ, i, vt, em, dt, pnt);
				if(pnt>=15){
					printf("\nSituação: Excelente campanha!\n\n");qexc++;
				}else if(pnt<=14 && pnt>=10){
					printf("\nSituação: Boa campanha!\n\n");qboa++;
				}else if(pnt<=9 && pnt>=5){
					printf("\nSituação: Campanha regular!\n\n");qreg++;
				}else{
					printf("\nSituação: Campanha ruim!\n\n");qruim++;
				}//mostra desempenho da equipe
				
				
			}	printf("Digite 0 para voltar ao menu: ");//para voltar o menu
				scanf("%d", &voltar);break;
		
		case 2://mostra resumo do camp
			system("cls");
			printf("==Resultado do Campeonato==\n");
			printf("\n\nQuantidade de equipes = %d, Quantidade de jogos por equipe = %d ", qntE, qntJ);
			printf("\n\nTotal, %d = Vitórias, %d = Empates, %d = Derrotas", qntVT, qntEM, qntDT);
			printf("\n\nSoma dos pontos = %.2f, Média do pontos = %.2f", qntPNT, (qntPNT/qntE));
			printf("\n\nSituações: Excelente = %d, Boa = %d, Regular = %d, Ruim = %d", qexc, qboa, qreg, qruim);
			printf("\n\nPontuadores Maior: Equipe %d com %d, Menor: Equipe %d com %d");
			printf("\n\nQuantidade de Pontuadores Empatados\n\tMaiores: %d Equipes com %d pontos\n\tMenores: %d Equipes com %d pontos\n\n");
			printf("Digite 0 para voltar ao menu: ");
			scanf("%d", &voltar);
			break;
			
		case 3:// mostra regulamento do camp
			system("cls");
			printf("==Regulamentos==\n\n");
			printf("Pontuações\nVitória = 3 pontos\nEmpate = 1 ponto\nDerrota = 0 pontos\n\n");
			printf("Situação\n15 ou + pontos = Excelente campanha\nDe 10 a 14 pontos = Boa campanha\nDe 5 a 9 pontos = Campanha regular\n5 ou - pontos = Campanha ruim\n\n");
			printf("Limites\nDe 3 a 10 equipes no Campeonato\nDe 1 a 10 jogos no Campeonato\n\n");
			printf("Digite 0 para voltar ao menu: ");
			scanf("%d", &voltar);
			break;
			
		case 4:
			break;
			
		case 5://encerra o sistema
			menu=5;
			system("cls");
			printf("Sistema encerrado com sucesso.\nObrigado por utilizar o sistema.");
			break;
		
				
		default:
			printf("Opção Inválida!");
		}
		
	}while(menu!=5);
		
}
