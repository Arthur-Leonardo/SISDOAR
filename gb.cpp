	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <locale.h>
	#include <ctype.h>
	#include <conio.h>
	
	#define MAX 100
	
	// Estruturas principais
	typedef struct {
	    char doador[50];
	    char cat;
	    char item[50];
	    int quantidade;
	    char data[11];
	} Doacao;
	
	typedef struct {
	    char nome[50];
	    char funcao;
	    char disponibilidade;
	} Voluntario;
	
	typedef struct {
	    char categoria;
	    char item[50];
	    int quantidade_necessaria;
	    int urgencia;
	} Necessidade;
	
	// Prototipos de funções
	void menuPrincipal();
	void menuDoacoes();
	void menuVoluntarios();
	void menuNecessidades();
	
	// Funções de doações
	void cadastrarDoacao();
	void listarDoacoes();
	
	// Funções de voluntários
	void cadastrarVoluntario();
	void listarVoluntarios();
	void defFuncao();
	void defDisponibilidade();
	
	// Funções de necessidades
	void cadastrarNecessidade();
	void listarNecessidades();
	
	int main() {
		setlocale(LC_ALL,"Portuguese_Brazil");
	    menuPrincipal();
	    return 0;
	}
	
	void menuPrincipal() {
	    int opcao;
	    do {
	    	system("cls");
	        printf("\n===== SISDOAR - Sistema de Gestão de Doações =====\n");
	        printf("1. Gerenciar Doações\n");
	        printf("2. Gerenciar Voluntários\n");
	        printf("3. Gerenciar Necessidades\n");
	        printf("0. Sair\n");
	        printf("Escolha uma opção: ");
	        scanf("%d", &opcao);
	
	        switch (opcao) {
	            case 1: 
				menuDoacoes(); 
					break;
	            case 2: 
				menuVoluntarios(); 
					break;
	            case 3: 
				menuNecessidades(); 
					break;
	            case 0: 
				printf("Saindo do sistema...\n"); 
					break;
	            default: printf("Opção inválida!\n");
	        }
	    } while (opcao != 0);
	}
	
	void menuDoacoes() {
	    int opcao;
	    do {
	        printf("\n--- Menu Doações ---\n");
	        printf("1. Cadastrar Doação\n");
	        printf("2. Listar Doações\n");
	        printf("0. Voltar\n");
	        printf("Escolha uma opção: ");
	        scanf("%d", &opcao);
	
	        switch(opcao) {
	            case 1: 
				cadastrarDoacao(); 
					break;
	            case 2: 
				listarDoacoes(); 
					break;
	            case 0: 
					break;
	            default: printf("Opção inválida!\n");
	        }
	    } while(opcao != 0);
	}
	
	void menuVoluntarios() {
	    int opcao;
	    do {
	        printf("\n--- Menu Voluntários ---\n");
	        printf("1. Cadastrar Voluntário\n");
	        printf("2. Listar Voluntários\n");
	        printf("0. Voltar\n");
	        printf("Escolha uma opção: ");
	        scanf("%d", &opcao);
	
	        switch(opcao) {
	            case 1: 
				cadastrarVoluntario(); 
					break;
	            case 2: 
				listarVoluntarios();
					break;
	            case 0: 
					break;
	            default: printf("Opção inválida!\n");
	        }
	    } while(opcao != 0);
	}
	
	void menuNecessidades() {
	    int opcao;
	    do {
	        printf("\n--- Menu Necessidades ---\n");
	        printf("1. Cadastrar Necessidade\n");
	        printf("2. Listar Necessidades\n");
	        printf("0. Voltar\n");
	        printf("Escolha uma opção: ");
	        scanf("%d", &opcao);
	
	        switch(opcao) {
	            case 1: 
				cadastrarNecessidade(); 
					break;
	            case 2: 
				listarNecessidades(); 
					break;
	            case 0: 
					break;
	            default: printf("Opção inválida!\n");
	        }
	    } while(opcao != 0);
	}
	
	void cadastrarDoacao() {
		char op;
		do{
		    FILE *fp;
			fp = fopen("ARQ_DOACOES", "a");
		    if (!fp) { 
			printf("Erro ao abrir arquivo de doações!\n"); return;
			}
			Doacao d;
		    fflush(stdin);
		    printf("\nNome do doador: ");
			gets(d.doador);
			printf("\nCategoria do objeto: ");
			printf("\n(C - Comida | H - Higiene | R - Roupas )\n");
			do{
			d.cat = toupper(getche());
			if(d.cat != 'C' && d.cat != 'H' && d.cat != 'R'){
				printf("\nCategoria inválida, favor redigite.");
				printf("\n(C - Comida | H - Higiene | R - Roupas )\n");
			}
			}while (d.cat != 'C' && d.cat != 'H' && d.cat != 'R');
			
		    printf("\nItem doado: "); 
			gets(d.item);
		    printf("Quantidade: "); 
			scanf("%d", &d.quantidade);
			fflush(stdin);
		    printf("Data (dd/mm/aaaa): "); 
			gets(d.data);
		    fprintf(fp, "Nome: %s|Categoria: %c|Item: %s|Qtd: %d|Data: %s\n", d.doador, d.cat, d.item, d.quantidade, d.data);
		    fclose(fp);
		    printf("Doação registrada com sucesso!\n");
		    do{
		    	printf("\nGostaria de cadastrar outra doação? S/N\n");
		    	op = toupper(getche());
		    if(op != 'S' && op != 'N'){
		    	printf("\nCaractere inválido, favor redigite.");
		    	printf("\nGostaria de cadastrar outra doação? S/N\n");
			}
			}while(op != 'S' && op != 'N');
		}while(op != 'N');
	    system("cls");
	}
	
	void listarDoacoes() {
	    FILE *fp;
		fp = fopen("ARQ_DOACOES", "r");
	    if (!fp) { 
		printf("Nenhuma doação encontrada.\n"); 
		return; 
		}
		
		//chat gpt ajudou
	    char linha[200];
	    printf("\nLista de Doações:\n");
	    while (fgets(linha, sizeof(linha), fp)) {
	        printf("%s", linha);
	    }
	    getchar();
	    fclose(fp);
	}
	
	void cadastrarVoluntario() {
		char op, op2;
		do{
		    FILE *fp;
			fp = fopen("ARQ_VOLUNTARIOS", "a");
		    if (!fp) { 
			printf("Erro ao abrir arquivo de voluntários!\n"); 
			return; 
			}
		
		    Voluntario v;
		    fflush(stdin);
		    printf("\nNome: "); 
			gets(v.nome);
			fflush(stdin);
			fprintf(fp, "Nome: %s|Função: ", v.nome);
			fclose(fp);
			do{
				defFuncao();
				do{
					printf("\nFunção registrada com sucesso, gostaria de registrar outra? (S/N)\n");
					op2 = toupper(getche());
					fflush(stdin);
					if(op2 != 'S' && op2 != 'N'){
				    	printf("\nCaractere inválido, favor redigite.");
				    	printf("\nGostaria de cadastrar outra doação? S/N\n");
					}
				}while(op2 != 'S' && op2 != 'N');
				if(op2 == 'S'){
					fp = fopen("ARQ_VOLUNTARIOS", "a");
					fprintf(fp, "/");
					fclose(fp);
				}
			}while(op2 != 'N');
			defDisponibilidade();
		    printf("\nVoluntário cadastrado com sucesso!\n");
			do{
		    	printf("\nGostaria de cadastrar outro voluntário? S/N\n");
		    	op = toupper(getche());
		    if(op != 'S' && op != 'N'){
		    	printf("\nCaractere inválido, favor redigite.");
		    	printf("\nGostaria de cadastrar outro voluntário? S/N\n");
			}
			}while(op != 'S' && op != 'N');
		}while(op != 'N');
		system("cls");
	}
	
	void listarVoluntarios() {
	    FILE *fp;
		fp = fopen("ARQ_VOLUNTARIOS", "r");
	    if (!fp) { 
		printf("Nenhum voluntário encontrado.\n"); 
		return; 
		}
	
	    char linha[200];
	    printf("\nLista de Voluntários:\n");
	    while (fgets(linha, sizeof(linha), fp)) {
	        printf("%s", linha);
	    }
	    fclose(fp);
	}
	
	void cadastrarNecessidade() {
		char op;
		do{
	    FILE *fp;
		fp = fopen("ARQ_NECESSIDADES", "a");
	    if (!fp) { 
		printf("Erro ao abrir arquivo de necessidades!\n"); 
		return; 
		}
	
	    Necessidade n;
	    fflush(stdin);
	    printf("\nCategoria em falta: "); 
	    printf("\n(C - Comida | H - Higiene | R - Roupas )\n");
			do{
			n.categoria = toupper(getche());
			if(n.categoria != 'C' && n.categoria != 'H' && n.categoria != 'R'){
				printf("\nCategoria inválida, favor redigite.");
				printf("\n(C - Comida | H - Higiene | R - Roupas )\n");
			}
			}while (n.categoria != 'C' && n.categoria != 'H' && n.categoria != 'R');
		escCategoria(fp);
		fflush(stdin);
		printf("\nItem: ");
		gets(n.item);
	    printf("\nQuantidade: "); 
		scanf("%d", &n.quantidade_necessaria);
		do{
		    printf("Urgência (1-5): "); 
			scanf("%d", &n.urgencia);
			if(n.urgencia < 1 || n.urgencia > 5){
				printf("\nValor inválido, favor redigitar (1 - 5)\n");
			}
		}while(n.urgencia < 1 || n.urgencia > 5);
	
	    fprintf(fp, "Categoria: %c|Item: %s|Quantidade: %d|Urgência: %d\n", n.categoria, n.item, n.quantidade_necessaria, n.urgencia);
	    fclose(fp);
	    printf("Necessidade cadastrada com sucesso!\n");
		do{
		    printf("\nGostaria de cadastrar outra necessidade? S/N\n");
		    op = toupper(getche());
		    if(op != 'S' && op != 'N'){
		    	printf("\nCaractere inválido, favor redigite.");
		    	printf("\nGostaria de cadastrar outra necessidade? S/N\n");
			}
			}while(op != 'S' && op != 'N');
		}while(op != 'N');
		system("cls");
	}
	
	void listarNecessidades() {
	    FILE *fp;
		fp = fopen("ARQ_NECESSIDADES", "r");
	    if (!fp){
		printf("Nenhuma necessidade encontrada.\n"); 
		return; 
		}
	
	    char linha[200];
	    printf("\nLista de Necessidades:\n");
	    while (fgets(linha, sizeof(linha), fp)) {
	        printf("%s", linha);
	    }
	    fclose(fp);
	}


	void defFuncao(){
		FILE *fp;
		fp = fopen("ARQ_VOLUNTARIOS", "a");
		if (!fp){
		printf("Erro ao abrir o arquivo de voluntários\n"); 
		return; 
		}
		Voluntario v;
		printf("\nFunção: "); 
		printf("\nD - Direção | B - Trabalho braçal | G - Gestão de Doações | A - Atendimento | C - Comunicação\n");
			do{
				v.funcao = toupper(getche());
				fflush(stdin);
				if(v.funcao != 'D' && v.funcao != 'B' && v.funcao != 'G' && v.funcao != 'A' && v.funcao != 'C'){
					printf("\nCategoria inválida, favor redigite.");
					printf("\n\nD - Direção | B - Trabalho braçal | G - Gestão de Doações | A - Atendimento | C - Comunicação\n");
					}
				switch(v.funcao){
					case 'D':
						fprintf(fp, "Direção");
						break;
					case 'B':
						fprintf(fp, "Braçal");
						break;
					case 'G':
						fprintf(fp, "Gestão");
						break;
					case 'A':
						fprintf(fp, "Atendimento");
						break;
					case 'C':
						fprintf(fp, "Comunicação");
						break;
					}
				}while (v.funcao != 'D' && v.funcao != 'B' && v.funcao != 'G' && v.funcao != 'A' && v.funcao != 'C');
			fclose(fp);
		}
	
	void defDisponibilidade(){
		FILE *fp;
		fp = fopen("ARQ_VOLUNTARIOS", "a");
		if (!fp){
		printf("Erro ao abrir o arquivo de voluntários\n"); 
		return; 
		}
		Voluntario v;
		fprintf(fp, "|Disponibilidade: ");
		printf("\nDisponibilidade: "); 
		printf("\nD - Diariamente | F - Final de Semana | U - Dias úteis | I - Indefinido\n");
			do{
				v.disponibilidade = toupper(getche());
				fflush(stdin);
				if(v.disponibilidade != 'D' && v.disponibilidade != 'F' && v.disponibilidade != 'U' && v.disponibilidade != 'I'){
					printf("\nCaracter inválido, favor redigite.");
					printf("\nD - Diariamente | F - Final de Semana | U - Dias úteis | I - Indefinido\n");
					}
				switch(v.disponibilidade){
					case 'D':
						fprintf(fp, "Diariamente");
						break;
					case 'F':
						fprintf(fp, "Final de Semana");
						break;
					case 'U':
						fprintf(fp, "Dias Úteis");
						break;
					case 'I':
						fprintf(fp, "Indefinido");
					}
				}while (v.disponibilidade != 'D' && v.disponibilidade != 'F' && v.disponibilidade != 'U' && v.disponibilidade != 'I');
				fprintf(fp, "\n");
			fclose(fp);
	}
	
	void escCategorias(arq){
		FILE *fp;
		fp = fopen(arq, "a");
		if (!fp){
		printf("Erro ao abrir o arquivo de voluntários\n"); 
		return; 
		}
		
	}
