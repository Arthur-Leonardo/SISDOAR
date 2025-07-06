	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <locale.h>
	#include <ctype.h>
	#include <conio.h>
	
	//Estruturas principais
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
	
	//Prototipos de funções
	void menuPrincipal();
	void menuDoacoes();
	void menuVoluntarios();
	void menuNecessidades();
	
	//Funções de doações
	void cadastrarDoacao();
	void listarDoacoes();
	
	//Funções de voluntários
	void cadastrarVoluntario();
	void listarVoluntarios();
	int defFuncao(int fcheck[]);
	void defDisponibilidade();
	
	//Funções de necessidades
	void cadastrarNecessidade();
	void listarNecessidades();
	
	//Função de estatística
	void mostrarEstatisticas();
	
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
	        printf("4. Estatísticas Gerais\n");
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
				case 4:
 			    mostrarEstatisticas();
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
			fp = fopen("ARQ_DOACOES.txt", "a");
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
		fp = fopen("ARQ_DOACOES.txt", "r");
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
			int fcheck[5] = {0};
		    FILE *fp;
			fp = fopen("ARQ_VOLUNTARIOS.txt", "a");
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
				int registrada = defFuncao(fcheck);
				do{
					printf("\nFunção registrada com sucesso, gostaria de registrar outra? (S/N)\n");
					op2 = toupper(getche());
					fflush(stdin);
					if(op2 != 'S' && op2 != 'N'){
				    	printf("\nCaractere inválido, favor redigite.");
				    	printf("\nGostaria de cadastrar outra doação? S/N\n");
					}
				}while(op2 != 'S' && op2 != 'N');
				if(op2 == 'S' && registrada){
					FILE *fp = fopen("ARQ_VOLUNTARIOS.txt", "a");
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
		fp = fopen("ARQ_VOLUNTARIOS.txt", "r");
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
		fp = fopen("ARQ_NECESSIDADES.txt", "a");
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
		fp = fopen("ARQ_NECESSIDADES.txt", "r");
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


	int defFuncao(int fcheck[]){
		FILE *fp;
		fp = fopen("ARQ_VOLUNTARIOS.txt", "a");
		if (!fp){
		printf("Erro ao abrir o arquivo de voluntários\n"); 
		return 0; 
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
			}while (v.funcao != 'D' && v.funcao != 'B' && v.funcao != 'G' && v.funcao != 'A' && v.funcao != 'C');
			int registrada = 0;
			switch(v.funcao){
				case 'D':
					if(fcheck[0] != 0){
						printf("\nEssa função já foi cadastrada!");
					}else{
						fprintf(fp, "Direção");
						fcheck[0] = 1;
						registrada = 1;
					}
					break;
				case 'B':
					if(fcheck[1] != 0){
					printf("\nEssa função já foi cadastrada!");
					}else{
					fprintf(fp, "Braçal");
					fcheck[1] = 1;
					registrada = 1;
					}
					break;
				case 'G':
					if(fcheck[2] != 0){
					printf("\nEssa função já foi cadastrada!");
					}else{
					fprintf(fp, "Gestão");
					fcheck[2] = 1;
					registrada = 1;
					}
					break;
				case 'A':
					if(fcheck[3] != 0){
					printf("\nEssa função já foi cadastrada!");
					}else{
					fprintf(fp, "Atendimento");
					fcheck[3] = 1;
					registrada = 1;
					}
					break;
				case 'C':
					if(fcheck[4] != 0){
					printf("\nEssa função já foi cadastrada!");
					}else{
					fprintf(fp, "Comunicação");
					fcheck[4] = 1;
					registrada = 1;
					}
					break;
				}
		fclose(fp);
		return registrada;
		}
	
	void defDisponibilidade(){
		FILE *fp;
		fp = fopen("ARQ_VOLUNTARIOS.txt", "a");
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
	
	void mostrarEstatisticas() {
    printf("\n==== ESTATÍSTICAS GERAIS ====\n");
    FILE *fp = fopen("ARQ_DOACOES.txt", "r");
    int totalDoacoes = 0, cat_doacoes[3] = {0};
    char linha[200];

    if (fp) {
        while (fgets(linha, sizeof(linha), fp)) {
            totalDoacoes++;
            if (strstr(linha, "Categoria: C")) {
			cat_doacoes[0]++;
			}
            else if (strstr(linha, "Categoria: H")) {
			cat_doacoes[1]++;
			}
            else if (strstr(linha, "Categoria: R")) {
			cat_doacoes[2]++;
			}
        }
        fclose(fp);
    }

    printf("\nDOAÇÕES:\n");
    printf("Total de Doações: %d\n", totalDoacoes);
    if (totalDoacoes > 0) {
        printf("Comida: %d (%.2f%%)\n", cat_doacoes[0], (cat_doacoes[0]*100.0)/totalDoacoes);
        printf("Higiene: %d (%.2f%%)\n", cat_doacoes[1], (cat_doacoes[1]*100.0)/totalDoacoes);
        printf("Roupas: %d (%.2f%%)\n", cat_doacoes[2], (cat_doacoes[2]*100.0)/totalDoacoes);
    }

    fp = fopen("ARQ_VOLUNTARIOS.txt", "r");
    int totalVol = 0, tot_disp[4] = {0}, total_func[5] = {0};
    if (fp) {
        while (fgets(linha, sizeof(linha), fp)) {
            totalVol++;
            if (strstr(linha, "Diariamente")) {
			tot_disp[0]++;
			}else if (strstr(linha, "Final de Semana")) {
			tot_disp[1]++;
			}else if (strstr(linha, "Dias Úteis")){
			tot_disp[2]++;
			}else if (strstr(linha, "Indefinido")) {
			tot_disp[3]++;
			}

            if (strstr(linha, "Direção")) {
			total_func[0]++;
			}
            if (strstr(linha, "Braçal")){
			total_func[1]++;
			}
            if (strstr(linha, "Gestão")) {
			total_func[2]++;
			}
            if (strstr(linha, "Atendimento")) {
			total_func[3]++;
			}
            if (strstr(linha, "Comunicação")) {
			total_func[4]++;
			}
        }
        fclose(fp);
    }

    printf("\nVOLUNTÁRIOS:\n");
    printf("Total de Voluntários: %d\n", totalVol);
    if (totalVol > 0) {
        printf("Funções:\n");
        printf(" - Direção: %d (%.2f%%)\n", total_func[0], (total_func[0]*100.0)/totalVol);
        printf(" - Braçal: %d (%.2f%%)\n", total_func[1], (total_func[1]*100.0)/totalVol);
        printf(" - Gestão: %d (%.2f%%)\n", total_func[2], (total_func[2]*100.0)/totalVol);
        printf(" - Atendimento: %d (%.2f%%)\n", total_func[3], (total_func[3]*100.0)/totalVol);
        printf(" - Comunicação: %d (%.2f%%)\n", total_func[4], (total_func[4]*100.0)/totalVol);

        printf("Disponibilidade:\n");
        printf(" - Diariamente: %d (%.2f%%)\n", tot_disp[0], (tot_disp[0]*100.0)/totalVol);
        printf(" - Final de Semana: %d (%.2f%%)\n", tot_disp[1], (tot_disp[1]*100.0)/totalVol);
        printf(" - Dias Úteis: %d (%.2f%%)\n", tot_disp[2], (tot_disp[2]*100.0)/totalVol);
        printf(" - Indefinido: %d (%.2f%%)\n", tot_disp[3], (tot_disp[3]*100.0)/totalVol);
    }

    fp = fopen("ARQ_NECESSIDADES.txt", "r");
    int totalNec = 0, cat_nec[3] = {0};
    if (fp) {
        while (fgets(linha, sizeof(linha), fp)) {
            totalNec++;
            if (strstr(linha, "Categoria: C")) {
			cat_nec[0]++;
			}
            else if (strstr(linha, "Categoria: H")) {
			cat_nec[1]++;
			}
            else if (strstr(linha, "Categoria: R")) {
			cat_nec[2]++;
			}
        }
        fclose(fp);
    }

    printf("\nNECESSIDADES:\n");
    printf("Total de Necessidades: %d\n", totalNec);
    if (totalNec > 0) {
        printf("Comida: %d (%.2f%%)\n", cat_nec[0], (cat_nec[0]*100.0)/totalNec);
        printf("Higiene: %d (%.2f%%)\n", cat_nec[1], (cat_nec[1]*100.0)/totalNec);
        printf("Roupas: %d (%.2f%%)\n", cat_nec[2], (cat_nec[2]*100.0)/totalNec);
    }

    printf("\nPressione ENTER para voltar ao menu...");
    getchar(); getchar();
}
