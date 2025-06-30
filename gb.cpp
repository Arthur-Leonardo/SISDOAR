	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <locale.h>
	
	#define MAX 100
	
	// Estruturas principais
	typedef struct {
	    int id;
	    char doador[50];
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
	
	// Prototipos de fun��es
	void menuPrincipal();
	void menuDoacoes();
	void menuVoluntarios();
	void menuNecessidades();
	
	// Fun��es de doa��es
	void cadastrarDoacao();
	void listarDoacoes();
	
	// Fun��es de volunt�rios
	void cadastrarVoluntario();
	void listarVoluntarios();
	
	// Fun��es de necessidades
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
	        printf("\n===== SISDOAR - Sistema de Gest�o de Doa��es =====\n");
	        printf("1. Gerenciar Doa��es\n");
	        printf("2. Gerenciar Volunt�rios\n");
	        printf("3. Gerenciar Necessidades\n");
	        printf("0. Sair\n");
	        printf("Escolha uma op��o: ");
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
	            default: printf("Op��o inv�lida!\n");
	        }
	    } while (opcao != 0);
	}
	
	void menuDoacoes() {
	    int opcao;
	    do {
	        printf("\n--- Menu Doa��es ---\n");
	        printf("1. Cadastrar Doa��o\n");
	        printf("2. Listar Doa��es\n");
	        printf("0. Voltar\n");
	        printf("Escolha uma op��o: ");
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
	            default: printf("Op��o inv�lida!\n");
	        }
	    } while(opcao != 0);
	}
	
	void menuVoluntarios() {
	    int opcao;
	    do {
	        printf("\n--- Menu Volunt�rios ---\n");
	        printf("1. Cadastrar Volunt�rio\n");
	        printf("2. Listar Volunt�rios\n");
	        printf("0. Voltar\n");
	        printf("Escolha uma op��o: ");
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
	            default: printf("Op��o inv�lida!\n");
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
	        printf("Escolha uma op��o: ");
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
	            default: printf("Op��o inv�lida!\n");
	        }
	    } while(opcao != 0);
	}
	
	void cadastrarDoacao() {
	    FILE *fp;
		fp = fopen("ARQ_DOACOES", "a");
	    if (!fp) { 
			printf("Erro ao abrir arquivo de doa��es!\n"); return;
			}
	
	    Doacao d;
	    fflush(stdin);
	    printf("\nNome do doador: ");
		gets(d.doador);
	    printf("Item doado: "); 
		gets(d.item);
	    printf("Quantidade: "); 
		scanf("%d", &d.quantidade);
		fflush(stdin);
	    printf("Data (dd/mm/aaaa): "); 
		gets(d.data);
	
	    fprintf(fp, "%s|%s|%d|%s\n", d.doador, d.item, d.quantidade, d.data);
	    fclose(fp);
	    printf("Doa��o registrada com sucesso!\n");
	    getchar();
	}
	
	void listarDoacoes() {
	    FILE *fp;
		fp = fopen("ARQ_DOACOES", "r");
	    if (!fp) { 
		printf("Nenhuma doa��o encontrada.\n"); 
		return; 
		}
		
		//chat gpt ajudou
	    char linha[200];
	    printf("\nLista de Doa��es:\n");
	    while (fgets(linha, sizeof(linha), fp)) {
	        printf("%s", linha);
	    }
	    getchar();
	    fclose(fp);
	}
	
	void cadastrarVoluntario() {
	    FILE *fp;
		fp = fopen("ARQ_VOLUNTARIOS", "a");
	    if (!fp) { 
		printf("Erro ao abrir arquivo de volunt�rios!\n"); 
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
	
	    fprintf(fp, "%s|%s|%s\n", v.nome, v.habilidades, v.disponibilidade);
	    fclose(fp);
	    printf("Volunt�rio cadastrado com sucesso!\n");
	}
	
	void listarVoluntarios() {
	    FILE *fp;
		fp = fopen("ARQ_VOLUNTARIOS", "r");
	    if (!fp) { 
		printf("Nenhum volunt�rio encontrado.\n"); 
		return; 
		}
	
	    char linha[200];
	    printf("\nLista de Volunt�rios:\n");
	    while (fgets(linha, sizeof(linha), fp)) {
	        printf("%s", linha);
	    }
	    fclose(fp);
	}
	
	void cadastrarNecessidade() {
	    FILE *fp;
		fp = fopen("ARQ_NECESSIDADES", "a");
	    if (!fp) { 
		printf("Erro ao abrir arquivo de necessidades!\n"); 
		return; 
		}
	
	    Necessidade n;
	    fflush(stdin);
	    printf("\nItem necess�rio: "); 
		gets(n.item);
	    printf("Quantidade: "); 
		scanf("%d", &n.quantidade_necessaria);
		do{
		    printf("Urg�ncia (1-5): "); 
			scanf("%d", &n.urgencia);
			if(n.urgencia < 1 || n.urgencia > 5){
				printf("\nValor inv�lido, favor redigitar (1 - 5)\n");
			}
		}while(n.urgencia < 1 || n.urgencia > 5);
	
	    fprintf(fp, "Item: %s|Quantidade: %d|Urg�ncia: %d\n", n.item, n.quantidade_necessaria, n.urgencia);
	    fclose(fp);
	    printf("Necessidade cadastrada com sucesso!\n");
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

