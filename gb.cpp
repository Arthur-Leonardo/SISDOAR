	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <locale.h>
	#include <ctype.h>
	#include <conio.h>
	
	#define MAX 100
	
	// Estruturas principais
	typedef struct {
	    int id;
	    char doador[50];
	    char cat;
	    char item[50];
	    int quantidade;
	    char data[11];
	} Doacao;
	
	typedef struct {
	    int id;
	    char nome[50];
	    char habilidades[100];
	    char disponibilidade[30];
	} Voluntario;
	
	typedef struct {
	    int id;
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
		char op;
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
		    printf("Habilidades: "); 
			gets(v.habilidades);
		    printf("Disponibilidade: "); 
			gets(v.disponibilidade);
		
		    fprintf(fp, "Nome: %s|Habilidade: %s|Disponibilidade: %s\n", v.nome, v.habilidades, v.disponibilidade);
		    fclose(fp);
		    printf("Voluntário cadastrado com sucesso!\n");
			do{
		    	printf("\nGostaria de cadastrar outro voluntário? S/N\n");
		    	op = toupper(getche());
		    if(op != 'S' && op != 'N'){
		    	printf("\nCaractere inválido, favor redigite.");
		    	printf("\nGostaria de cadastrar outro voluntário? S/N\n");
			}
			}while(op != 'S' && op != 'N');
		}while(op != 'N');
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
	    printf("\nItem necessário: "); 
		gets(n.item);
	    printf("Quantidade: "); 
		scanf("%d", &n.quantidade_necessaria);
		do{
		    printf("Urgência (1-5): "); 
			scanf("%d", &n.urgencia);
			if(n.urgencia < 1 || n.urgencia > 5){
				printf("\nValor inválido, favor redigitar (1 - 5)\n");
			}
		}while(n.urgencia < 1 || n.urgencia > 5);
	
	    fprintf(fp, "Item: %s|Quantidade: %d|Urgência: %d\n", n.item, n.quantidade_necessaria, n.urgencia);
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

