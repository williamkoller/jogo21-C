/*
	
	projeto: Jogando 21 
	desenvolvedores: Jeferson Jacinto, Nilton, Vinicius e William Koller
	
*/

#include <time.h>
#include <ctype.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int pts1, pts2, pt1, pt2, partida, jogandoi; // sistema
int smc_player2, i2, sorteadas2, player2, player2_2, player2_2_bkp; // jogador 2
int smc_player1, i1, sorteadas1, player1, continua1, continua1_1; // jogador 1
char cartas1[100], carta1[2]; // jogador 1
char jogador2[40], cartas2[100], carta2[2], result2[80], continuar, outracarta; // jogador 2
int x;
char naipe[1];
int chooseNaipe;
int cartassorteadas[52];

int sorteio();



main()
{
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	system("title JOGANDO 21");
	system("color 22");

	pts1 = (0);
	pts2 = (0);
	partida = (0);
	jogandoi = (2);
	continuar = 'S';
	
	printf(" ---------------------------------------------------------------------- \n");
	printf(" |                          BLACK JACK                                 | \n");
	printf("----------------------------------------------------------------------\n");
	printf(" \n Bem vindo ao: BLACK JACK! \n\n\n ");
	
	printf("             ************* INSTRUCOES ********************* \n\n");
	printf(" 1 - O Ganhador é quem conseguir somar o numero de cartas em 21. \n");
	printf(" 2 - podera comprar a quantidade de cartas conforme seu jogo ateh que o numero  21 seja ultrapassado. \n");
	printf(" 3 - Voce pode tambem optar por nao comprar mais cartas mesmo que o numero nao tenha fechado em 21. \n\n");
	printf(" Esta pronto ? \n\n");
	printf(" Vamos la digite abaixo o nome do seu jogador: \n");
	
	
	// inicia o vetor de cartas sorteadas com o valor -1
	for(int k=0;k<52;k++){
		cartassorteadas[k] = -1;
	}

	printf("\n Nome do jogador 1 : Windows");
	printf("\n Nome do jogador 2 : ");
	fflush(stdin);
	gets(jogador2);

	do 
	{ // while controlador.

		system("cls");

		partida++; 	
		pt1 = (0);
		pt2 = (0);
		sorteadas2 = (2);
		sorteadas1 = (2);
		smc_player1 = (0);
		smc_player2 = (0);
		strcpy(cartas1, "");
		strcpy(cartas2, "");
		strcpy(carta1, "");
		strcpy(carta2, "");

		printf(" ------------------------------------------------------------------------------ \n");
		printf(" |  Rodada: %i  |  Placar: Windows %i x %i %s  |  21 contra o Windows  \n", partida, pts1, pts2, jogador2);
		printf(" ------------------------------------------------------------------------------ \n");

		if (jogandoi == 2) // inicio da jogada, jogador 2
		{
			/*
				Player two
			*/
			for (i2=1 ; i2<=2 ; i2++)
			{
				
				
				srand(time(NULL));
				player2 = sorteio(); //rand()%12;
				
				
				if (player2 >=1 && player2 <=13){
					player2		= player2;
					naipe [0]	= 'P';					
				}
				else if (player2 >=14 && player2 <=26){
					player2		= player2 - 13;
					naipe [0]	= 'C';			
				}
				else if (player2 >=27 && player2 <=39){
					player2		= player2 - 26;
					naipe [0]	= 'E';					
				}
				else if (player2 >=40 && player2 <=52){
					player2		= player2 - 39;
					naipe [0]	= 'O';					
				}
				
				
				
				smc_player2 = (smc_player2+player2); // soma cartas

				itoa(player2,carta2,10); // converte numero inteiro em string
				strcat(cartas2, "["); // concatena strings
				strcat(cartas2, carta2); // concatena strings
				strcat(cartas2, naipe);
				strcat(cartas2, "]"); // concatena strings
				

				if (i2 == 1)
				{
					printf("\n Dando as cartas! -  ");
					system("pause");
					printf("\n");
				}
			}

			
			printf("\n Foram dadas 2 cartas %s \n A soma das suas cartas corresponde a {%i}", cartas2, smc_player2);
			printf("\n Quer outra carta? (S/N) ");
				do {
					fflush(stdin);
					outracarta = toupper(getch());
				} while (outracarta!='s' && outracarta!='S' && outracarta!='n' && outracarta!='N');
			if (outracarta == 'S')
			{
				do {
					sorteadas2++;

				srand(time(NULL));
				player2_2 = sorteio(); //rand()%12;
				
				
				if (player2_2 >=1 && player2_2 <=13){
					player2_2		= player2_2;
					naipe [0]	= 'P';					
				}
				else if (player2_2 >=14 && player2_2 <=26){
					player2_2		= player2_2 - 13;
					naipe [0]	= 'C';			
				}
				else if (player2_2 >=27 && player2_2 <=39){
					player2_2		= player2_2 - 26;
					naipe [0]	= 'E';					
				}
				else if (player2_2 >=40 && player2_2 <=52){
					player2_2		= player2_2 - 39;
					naipe [0]	= 'O';					
				}

					player2_2_bkp = (player2_2);
					smc_player2 = (smc_player2+player2_2); // soma cartas aceitas alem das sorteados

					itoa(player2_2,carta2,11); // converte numero inteiro em string
					strcat(cartas2, "["); // concatena strings
					strcat(cartas2, carta2); // concatena strings
					strcat(cartas2, naipe);
					strcat(cartas2, "]"); // concatena strings

					if (smc_player2 > 21)
					{
						printf("\n \n Estourou, voce pegou a carta [%i%s] \n Voce obteve um total de {%i}", player2_2_bkp,naipe, smc_player2);
						printf("\n Suas cartas foram %s", cartas2);
						printf("\n Windows ganhou um ponto no placar! \n \n");
						outracarta = 'N';
						jogandoi = (2);
						pt1 = (1);
						pts1++;
					}
					else if (smc_player2 == 21)
					{
						printf("\n \n OPA que sorte! [21] \n");
						printf("\n Suas cartas foram %s", cartas2, naipe);
						printf("\n Voce ganhou um ponto no placar! \n \n");
						outracarta = 'N';
						jogandoi = (2);
						pt2 = (1);
						pts2++;
					}
					else
					{
						printf("\n \n Voce pegou a carta [%i%s]", player2_2_bkp, naipe);
						printf("\n Voce ja tem [%i] cartas, a soma corresponde a {%i}", sorteadas2, smc_player2);
						printf("\n Quer outra carta? (S/N) ");
						do {
							fflush(stdin);
							outracarta = toupper(getch());
						} while (outracarta!='s' && outracarta!='S' && outracarta!='n' && outracarta!='N');
					}
				} while (outracarta=='S');
			}
			if (smc_player2 < 21 && jogandoi == 2)
			{
				if (smc_player2 == 20)
				{
					strcpy(result2, "\n Otimo. voce tem grandes chances! \n");
				}
				else if (smc_player2 >= 18 && smc_player2 <= 19)
				{
					strcpy(result2, "\n Bom. tomara que o windows estoure! \n");
				}
				else if (smc_player2 >= 15 && smc_player2 <= 17)
				{
					strcpy(result2, "\n Eita. voce podia ter tentado mais uma! \n");
				}
				else if (smc_player2 >= 12 && smc_player2 <= 14)
				{
					strcpy(result2, "\n Aff. ta feio pro seu lado! \n");
				}
				else if (smc_player2 <= 13)
				{
					strcpy(result2, "\n SO POR UM MILAGRE VOCE LEVA A RODADA! \n");
				}

				printf("\n \n A soma de suas cartas corresponde a {%i} %s", smc_player2, result2);
				printf("\n Suas cartas foram %s \n \n", cartas2);
				
			}
			if (outracarta == 'N' && smc_player2 < 21)
			{
				jogandoi = (1);
			}

			system("pause");
			
		}
		if (jogandoi == 1) //inicio da jogada, jogador 1
		{
			/*
				Windows
			*/
			system("cls");

			printf(" ------------------------------------------------------------------------------ \n");
			printf(" |  Rodada: %i  |  Placar: Windows %i x %i %s  |  21 contra o Windows  \n", partida, pts1, pts2, jogador2);
			printf(" ------------------------------------------------------------------------------ \n");

			for (i1=1 ; i1<=2 ; i1++)
			{
				srand(time(NULL));
				player1 = sorteio(); //rand()%12;
				
				
				if (player1 >=1 && player1 <=13){
					player1	= player1;
					naipe [0]	= 'P';					
				}
				else if (player1>=14 && player1<=26){
					player1	= player1 - 13;
					naipe [0]	= 'C';			
				}
				else if (player1 >=27 && player1 <=39){
					player1		= player1 - 26;
					naipe [0]	= 'E';					
				}
				else if (player1 >=40 && player1 <=52){
					player1		= player1 - 39;
					naipe [0]	= 'O';					
				}

				smc_player1 = (smc_player1+player1); // soma cartas

				itoa(player1,carta1,10); // converte numero inteiro em string
				strcat(cartas1, "["); // concatena strings
				strcat(cartas1, carta1); // concatena strings
				strcat(cartas1, naipe);
				strcat(cartas1, "]"); // concatena strings

				if (i1 == 1)
				{
					printf("\n Windows jogando! \n");
					printf("\n Recebendo as cartas! -  ");
					system("pause");
					printf("\n");
					
				}
			}

			printf("\n Windows fala: Nao tenho nada a esconder! \n Vou mostrar minhas cartas e jogadas \n");
			printf("\n Peguei 2 cartas %s \n A soma das cartas corresponde a {%i} \n ", cartas1, smc_player1);
			system("pause");

			do 
			{
			
				continua1 = (1);
				if (smc_player1 <= 17)
				{
				sorteadas1++;

				srand(time(NULL));
				player1 = sorteio(); //rand()%12;
				
					
					if (player1 >=1 && player1 <=13){
						player1	= player1;
						naipe [0]	= 'P';					
					}
					else if (player1>=14 && player1<=26){
						player1	= player1 - 13;
						naipe [0]	= 'C';			
					}
					else if (player1 >=27 && player1 <=39){
						player1		= player1 - 26;
						naipe [0]	= 'E';					
					}
					else if (player1 >=40 && player1 <=52){
						player1		= player1 - 39;
						naipe [0]	= 'O';					
					}

					smc_player1 = (smc_player1+player1); // soma cartas

					itoa(player1,carta1,10); // converte numero inteiro em string
					strcat(cartas1, "["); // concatena strings
					strcat(cartas1, carta1); // concatena strings
					strcat(cartas1, naipe);
					strcat(cartas1, "]"); // concatena strings

					if (smc_player1 < 21)
					{
						printf("\n Estou com %i cartas, somando {%i} \n ", sorteadas1, smc_player1);
						system("pause");
					}
				}
				else if (smc_player1 >= 18 && smc_player1 <= 19)
				{
					srand(time(NULL));
					continua1_1 = sorteio(); //rand()%12;
				
				
				if (continua1_1  >=1 && continua1_1  <=13){
					continua1_1 	= continua1_1 ;
					naipe [0]		= 'P';					
				}
				else if (continua1_1 >=14 && continua1_1 <=26){
					continua1_1		= continua1_1  - 13;
					naipe [0]		= 'C';			
				}
				else if (continua1_1 >=27 && continua1_1 <=39){
					continua1_1		= continua1_1 - 26;
					naipe [0]		= 'E';					
				}
				else if (continua1_1 >=40 && continua1_1 <=52){
					continua1_1		= continua1_1 - 39;
					naipe [0]		= 'O';					
				}		 			
				 }

					if (continua1_1 == 1)
					{
						sorteadas1++;

						srand(time(NULL));
						player1 = sorteio(); //rand()%12;
					
				
						if (player1 >=1 && player1 <=13){
							player1		= player1;
							naipe [0]	= 'P';					
						}
						else if (player1>=14 && player1<=26){
							player1		= player1 - 13;
							naipe [0]	= 'C';			
						}
						else if (player1 >=27 && player1 <=39){
							player1		= player1 - 26;
							naipe [0]	= 'E';					
						}
						else if (player1 >=40 && player1 <=52){
							player1		= player1 - 39;
							naipe [0]	= 'O';					
						}

						smc_player1 = (smc_player1+player1); // soma cartas

						itoa(player1,carta1,10); // converte numero inteiro em string
						strcat(cartas1, "["); // concatena strings
						strcat(cartas1, carta1); // concatena strings
						strcat(cartas1, naipe);
						strcat(cartas1, "]"); // concatena strings
					}
					else
					{
						printf("\n Windows fala: Vou parar por Aqui! \n Vamos ver quem chegou mais perto do 21 \n ");
						continua1 = (1);
						system("pause");
					}
				
				if (smc_player1 == 20)
				{
					srand(time(NULL));
					continua1_1 = sorteio(); //rand()%12;
					
					
					if (continua1_1  >=1 && continua1_1  <=13){
						continua1_1 	= continua1_1 ;
						naipe [0]		= 'P';					
					}
					else if (continua1_1 >=14 && continua1_1 <=26){
						continua1_1 	= continua1_1  - 13;
						naipe [0]		= 'C';			
					}
					else if (continua1_1 >=27 && continua1_1 <=39){
						continua1_1		= continua1_1- 26;
						naipe [0]		= 'E';					
					}
					else if (continua1_1 >=40 && continua1_1 <=52){
						continua1_1		= continua1_1 - 39;
						naipe [0]		= 'O';					
					}		 			
				}

					if (continua1_1 == 1)
					{
						sorteadas1++;

						srand(time(NULL));
						player1 = sorteio(); //rand()%12;
				
				
						if (player1 >=1 && player1 <=13){
							player1		= player1;
							naipe [0]	= 'P';					
						}
						else if (player1>=14 && player1<=26){
							player1		= player1 - 13;
							naipe [0]	= 'C';			
						}
						else if (player1 >=27 && player1 <=39){
							player1		= player1 - 26;
							naipe [0]	= 'E';					
						}
						else if (player1 >=40 && player1 <=52){
							player1		= player1 - 39;
							naipe [0]	= 'O';					
						}

						

						smc_player1 = (smc_player1+player1); // soma cartas

						itoa(player1,carta1,10); // converte numero inteiro em string
						strcat(cartas1, "["); // concatena strings
						strcat(cartas1, carta1); // concatena strings
						strcat(cartas1, naipe);
						strcat(cartas1, "]"); // concatena strings
					}
					else 
					{
						printf("\n Windows fala: Vou parar por Aqui! \n Vamos ver quem chegou mais perto do 21 \n ");
						//continua1 = (0);
						jogandoi = (2);
						pt1 = (0);
						pts1++;
						system("pause");
					}
				
				if (smc_player1 == 21)
				{
					printf("\n Ganhei! HAHAHAHA fiz 21 \n Minhas cartas foram %s \n ", cartas1);
					continua1 = (0);
					jogandoi = (2);
					pt1 = (1);
					pts1++;
					system("pause");
				}
				else if (smc_player1 > 21)
				{
					printf("\n Ow nao! Estourei. \n Peguei as cartas %s \n Fiz um total de {%i}", cartas1, smc_player1);
					printf("\n \n %s, ganhou um ponto no placar! \n \n ", jogador2);
					continua1 = (0);
					jogandoi = (2);
					pt2 = (1);
					pts2++;
					system("pause");
				}
			} while (continua1==1);
		
			if (pt1 == 0 && pt2 == 0)
			{
				if (smc_player1 > smc_player2)
				{
					printf("\n HEHE, quase ganhou em. Mas eu sou Melhor.");
					printf("\n Windows venceu! por aproximacao do 21");
					printf("\n Soma do windows {%i} - Soma do(a) %s {%i} \n \n", smc_player1, jogador2, smc_player2);
					pts1++;
					jogandoi = (2);
					system("pause");
				}
				else if (smc_player2 > smc_player1)
				{
					printf("\n %s venceu! por aproximacao do 21", jogador2);
					printf("\n Soma do(a) %s {%i} - Soma do Windows {%i} \n \n", jogador2, smc_player2, smc_player1);
					pts2++;
					jogandoi = (2);
					system("pause");
				}
				else if (smc_player2 == smc_player1)
				{
					printf("\n OW nossa. houve empate ^^ \n Um ponto pra cada! \n ");
					pts1++;
					pts2++;
					jogandoi = (2);
					system("pause");
				}
			}
			system("cls");
			printf("\n \n Outra rodada? (S/N) ");
		
			do {
				fflush(stdin);
				continuar = toupper(getch());
			} while (continuar!='s' && continuar!='S' && continuar!='n' && continuar!='N');
		} 
	}while (continuar == 'S');
		printf("\n \n PLACAR FINAL | Windows: %i x %i %s", pts1, pts2, jogador2);
	
		if (pts1 > pts2)
		{
			printf("\n \n Windows fala: HAHAHA, Ja vai sair? esta tao divertido! kkkk \n Eu sou bom nisso! \n \n \n \n");
		}
		else if (pts2 > pts1)
		{
			printf("\n \n Windows fala: Tude bem. Vai ter revanche! \n E alias, meu negocio é pokker! \n \n \n \n");
		}
		else if (pts1 == pts2)
		{
			printf("\n \n Windows fala: empatou! \n Vamos jogar de novo, isso nao ficou bem decidido. \n \n \n \n");
		}
	
	
}

int sorteio(){

	int carta, naipe, x = 1;
	int i;
	
	do{
		carta = rand() % 52;
		carta++;				// 1-13 ->paus		14-26 ->copas		27-39 ->espadas			40-52 ->ouro
		
		for(i=0; i<52 && cartassorteadas[i] != -1; i++){
			if (cartassorteadas[i] == carta){
				x = 0;
			}
		}
		
		if (x == 1){
			cartassorteadas[i] = carta;
			return carta;
		}
	}while (x == 0);

}












