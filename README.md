🧾 SISDOAR - Sistema de Gestão de Doações
O SISDOAR é um sistema simples, escrito em linguagem C, desenvolvido com o objetivo de auxiliar iniciativas locais e organizações sociais no gerenciamento de doações, voluntários e necessidades de forma organizada e eficiente (Trabalho de Grau B de Algoritmos e Programação II, da faculdade Uniftec)

🎯 Objetivo
Facilitar a gestão e o registro de informações relacionadas a:

Doações recebidas

Voluntários de ongs/orgs

Necessidades da comunidade

Estatísticas de atuação

📌 Funcionalidades Principais
O sistema oferece um menu principal com 4 opções:

1. Gerenciar Doações
Cadastrar Doação: Registro de nome do doador, categoria (comida, higiene ou roupas), item doado, quantidade e data.

Listar Doações: Mostra todas as doações registradas no sistema.

2. Gerenciar Voluntários
Cadastrar Voluntário: Permite cadastrar o nome, múltiplas funções (como Direção, Atendimento, etc.) e disponibilidade (diária, fins de semana, etc.).

Listar Voluntários: Exibe todos os voluntários com suas respectivas funções e disponibilidades.

3. Gerenciar Necessidades
Cadastrar Necessidade: Registra uma categoria em falta (comida, higiene ou roupas), item necessário, quantidade e nível de urgência (de 1 a 5).

Listar Necessidades: Mostra todas as demandas registradas.

4. Estatísticas Gerais
Apresenta relatórios automáticos com base nos dados cadastrados:

Total de doações e a porcentagem por categoria

Total de voluntários e distribuição por função e disponibilidade

Total de necessidades e categorias mais recorrentes

📁 Estrutura de Arquivos
Os dados são salvos em arquivos .txt separados:

ARQ_DOACOES.txt

ARQ_VOLUNTARIOS.txt

ARQ_NECESSIDADES.txt

Cada operação de cadastro grava os dados diretamente nesses arquivos, garantindo a persistência das informações entre execuções do sistema.

🧠 Organização do Código
O sistema é dividido em várias funções para modularidade e clareza:

Menus interativos: menuPrincipal(), menuDoacoes(), menuVoluntarios(), menuNecessidades()

Funções de cadastro e listagem: cadastrarDoacao(), listarVoluntarios(), etc.

Função de estatísticas: mostrarEstatisticas() analisa os dados dos arquivos e apresenta resumos com porcentagens.

Uso de structs: Definição das estruturas Doacao, Voluntario e Necessidade para representar os dados de forma organizada.

⚙️ Tecnologias Usadas
Linguagem: C

Entrada/Saída: stdio.h, conio.h

Manipulação de strings: string.h, ctype.h

Localização (acentuação): locale.h
