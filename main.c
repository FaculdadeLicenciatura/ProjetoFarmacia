#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar um produto
typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

// Estrutura para representar um funcionário
typedef struct {
    char nome[50];
    int idade;
    char funcao[50];
} Funcionario;

// Estrutura para representar uma receita
typedef struct {
    char nome[50];
    char descricao[100];
} Receita;

// Funções para o menu principal e submenus
int Menu();
void menuProdutos(FILE *arquivoProdutos);
void menuFuncionarios(FILE *arquivoFuncionarios);
void menuReceitas(FILE *arquivoReceitas);
void listarStock(FILE *arquivoProdutos);
void cadastrarProduto(FILE *arquivoProdutos);
void listarProdutos(FILE *arquivoProdutos);
void atualizarProduto(FILE *arquivoProdutos);
void venderProduto(FILE *arquivoProdutos);
void excluirProduto(FILE *arquivoProdutos);
void cadastrarFuncionario(FILE *arquivoFuncionarios);
void listarFuncionarios(FILE *arquivoFuncionarios);
void excluirFuncionario(FILE *arquivoFuncionarios);
void cadastrarReceita(FILE *arquivoReceitas);
void listarReceitas(FILE *arquivoReceitas);
void atualizarReceita(FILE *arquivoReceitas);
void excluirReceita(FILE *arquivoReceitas);

int main() {
    FILE *arquivoProdutos, *arquivoFuncionarios, *arquivoReceitas;
    arquivoProdutos = fopen("produtos.txt", "a+");
    arquivoFuncionarios = fopen("funcionarios.txt", "a+");
    arquivoReceitas = fopen("receitas.txt", "a+");
    if (arquivoProdutos == NULL || arquivoFuncionarios == NULL || arquivoReceitas == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return 1;
    }

    while (1) {
        switch (Menu()) {
            case 1:
                menuProdutos(arquivoProdutos);
                break;
            case 2:
                menuFuncionarios(arquivoFuncionarios);
                break;
            case 3:
                menuReceitas(arquivoReceitas);
                break;
            case 4:
                listarStock(arquivoProdutos);
                break;
            case 9:
                fclose(arquivoProdutos);
                fclose(arquivoFuncionarios);
                fclose(arquivoReceitas);
                return 0;
            default:
                printf("Opcao invalida.\n");
        }
    }
    return 0;
}

// Função para exibir o menu principal
int Menu() {
    int opcao;
    system("clear"); // Limpa a tela (apenas para sistemas Unix/Linux)
    printf("\n=========================================\n");
    printf("             Menu Principal\n");
    printf("=========================================\n");
    printf("1) Produtos\n");
    printf("2) Funcionarios\n");
    printf("3) Receitas\n");
    printf("4) Stock\n");
    printf("9) Sair\n");
    printf("-----------------------------------------\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

// Função para exibir o menu de produtos
void menuProdutos(FILE *arquivoProdutos) {
    int opcao;
    while (1) {
        system("clear"); // Limpa a tela (apenas para sistemas Unix/Linux)
        printf("\n=========================================\n");
        printf("             Menu de Produtos\n");
        printf("=========================================\n");
        printf("1) Cadastrar Produto\n");
        printf("2) Listar Produtos\n");
        printf("3) Atualizar Produto\n");
        printf("4) Vender Produto\n");
        printf("5) Excluir Produto\n");
        printf("9) Voltar\n");
        printf("-----------------------------------------\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto(arquivoProdutos);
                break;
            case 2:
                listarProdutos(arquivoProdutos);
                break;
            case 3:
                atualizarProduto(arquivoProdutos);
                break;
            case 4:
                venderProduto(arquivoProdutos);
                break;
            case 5:
                excluirProduto(arquivoProdutos);
                break;
            case 9:
                return;
            default:
                printf("Opcao invalida.\n");
        }
    }
}

// Função para exibir o menu de funcionários
void menuFuncionarios(FILE *arquivoFuncionarios) {
    int opcao;
    while (1) {
        system("clear"); // Limpa a tela (apenas para sistemas Unix/Linux)
        printf("\n=========================================\n");
        printf("           Menu de Funcionarios\n");
        printf("=========================================\n");
        printf("1) Cadastrar Funcionario\n");
        printf("2) Listar Funcionarios\n");
        printf("3) Excluir Funcionario\n");
        printf("9) Voltar\n");
        printf("-----------------------------------------\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarFuncionario(arquivoFuncionarios);
                break;
            case 2:
                listarFuncionarios(arquivoFuncionarios);
                break;
            case 3:
                excluirFuncionario(arquivoFuncionarios);
                break;
            case 9:
                return;
            default:
                printf("Opcao invalida.\n");
        }
    }
}

// Função para exibir o menu de receitas
void menuReceitas(FILE *arquivoReceitas) {
    int opcao;
    while (1) {
        system("clear"); // Limpa a tela (apenas para sistemas Unix/Linux)
        printf("\n=========================================\n");
        printf("             Menu de Receitas\n");
        printf("=========================================\n");
        printf("1) Cadastrar Receita\n");
        printf("2) Listar Receitas\n");
        printf("3) Atualizar Receita\n");
        printf("4) Excluir Receita\n");
        printf("9) Voltar\n");
        printf("-----------------------------------------\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarReceita(arquivoReceitas);
                break;
            case 2:
                listarReceitas(arquivoReceitas);
                break;
            case 3:
                atualizarReceita(arquivoReceitas);
                break;
            case 4:
                excluirReceita(arquivoReceitas);
                break;
            case 9:
                return;
            default:
                printf("Opcao invalida.\n");
        }
    }
}

// Função para listar o stock de produtos
void listarStock(FILE *arquivoProdutos) {
    Produto produto;

    system("clear"); // Limpa a tela (apenas para sistemas Unix/Linux)
    printf("\n=========================================\n");
    printf("                Stock\n");
    printf("=========================================\n");
    rewind(arquivoProdutos);
    while (fscanf(arquivoProdutos, "%s %f %d\n", produto.nome, &produto.preco, &produto.quantidade) != EOF) {
        printf("Nome: %-20s | Preco: %-8.2f | Quantidade: %d\n", produto.nome, produto.preco, produto.quantidade);
    }
    getchar(); // Limpar o buffer do teclado
    printf("\nPressione Enter para continuar...");
    getchar(); // Esperar pelo Enter
}

// Função para cadastrar um novo produto
void cadastrarProduto(FILE *arquivoProdutos) {
    Produto novoProduto;

    printf("\n=========================================\n");
    printf("          Cadastrar Novo Produto\n");
    printf("-----------------------------------------\n");
    printf("Nome: ");
    scanf("%s", novoProduto.nome);
    printf("Preco: ");
    scanf("%f", &novoProduto.preco);
    printf("Quantidade: ");
    scanf("%d", &novoProduto.quantidade);

    if (fprintf(arquivoProdutos, "%s %.2f %d\n", novoProduto.nome, novoProduto.preco, novoProduto.quantidade) < 0) {
        printf("Erro ao registrar o produto.\n");
    } else {
        printf("Produto registrado com sucesso!\n");
    }
    getchar(); // Limpar o buffer do teclado
    printf("\nPressione Enter para continuar...");
    getchar(); // Esperar pelo Enter
}

// Função para listar os produtos cadastrados
void listarProdutos(FILE *arquivoProdutos) {
    Produto produto;

    system("clear"); // Limpa a tela (apenas para sistemas Unix/Linux)
    printf("\n=========================================\n");
    printf("           Listagem de Produtos\n");
    printf("-----------------------------------------\n");
    rewind(arquivoProdutos);
    while (fscanf(arquivoProdutos, "%s %f %d\n", produto.nome, &produto.preco, &produto.quantidade) != EOF) {
        printf("Nome: %-20s | Preco: %-8.2f | Quantidade: %d\n", produto.nome, produto.preco, produto.quantidade);
    }
    getchar(); // Limpar o buffer do teclado
    printf("\nPressione Enter para continuar...");
    getchar(); // Esperar pelo Enter
}

// Função para atualizar informações de um produto
void atualizarProduto(FILE *arquivoProdutos) {
    char nome[50];
    int quantidade;
    Produto produto;

    printf("\n=========================================\n");
    printf("           Atualizar Produto\n");
    printf("-----------------------------------------\n");
    printf("Nome do Produto a Atualizar: ");
    scanf("%s", nome);

    rewind(arquivoProdutos);
    FILE *temp = fopen("temp.txt", "w");

    while (fscanf(arquivoProdutos, "%s %f %d\n", produto.nome, &produto.preco, &produto.quantidade) != EOF) {
        if (strcmp(produto.nome, nome) == 0) {
            printf("Novo Preco: ");
            scanf("%f", &produto.preco);
            printf("Nova Quantidade: ");
            scanf("%d", &quantidade);
            produto.quantidade = quantidade;
            fprintf(temp, "%s %.2f %d\n", produto.nome, produto.preco, produto.quantidade);
            printf("Produto atualizado com sucesso!\n");
        } else {
            fprintf(temp, "%s %.2f %d\n", produto.nome, produto.preco, produto.quantidade);
        }
    }

    fclose(arquivoProdutos);
    fclose(temp);
    remove("produtos.txt");
    rename("temp.txt", "produtos.txt");
    getchar(); // Limpar o buffer do teclado
    printf("\nPressione Enter para continuar...");
    getchar(); // Esperar pelo Enter
}

// Função para vender um produto
void venderProduto(FILE *arquivoProdutos) {
    char nome[50];
    int quantidadeVendida;
    int quantidadeAtual;
    FILE *temp;
    Produto produto;

    printf("\n=========================================\n");
    printf("           Venda de Produto\n");
    printf("-----------------------------------------\n");
    printf("Nome do Produto: ");
    scanf("%s", nome);

    rewind(arquivoProdutos);
    temp = fopen("temp.txt", "w");

    while (fscanf(arquivoProdutos, "%s %f %d\n", produto.nome, &produto.preco, &produto.quantidade) != EOF) {
        if (strcmp(produto.nome, nome) == 0) {
            printf("Quantidade atual: %d\n", produto.quantidade);
            printf("Quantidade vendida: ");
            scanf("%d", &quantidadeVendida);
            quantidadeAtual = produto.quantidade - quantidadeVendida;
            fprintf(temp, "%s %.2f %d\n", produto.nome, produto.preco, quantidadeAtual);
            printf("Venda realizada com sucesso!\n");
        } else {
            fprintf(temp, "%s %.2f %d\n", produto.nome, produto.preco, produto.quantidade);
        }
    }

    fclose(arquivoProdutos);
    fclose(temp);
    remove("produtos.txt");
    rename("temp.txt", "produtos.txt");
    getchar(); // Limpar o buffer do teclado
    printf("\nPressione Enter para continuar...");
    getchar(); // Esperar pelo Enter
}

// Função para excluir um produto
void excluirProduto(FILE *arquivoProdutos) {
    char nome[50];
    Produto produto;
    int encontrado = 0;

    printf("\n=========================================\n");
    printf("           Excluir Produto\n");
    printf("-----------------------------------------\n");
    printf("Nome do Produto a Excluir: ");
    scanf("%s", nome);

    rewind(arquivoProdutos);
    FILE *temp = fopen("temp.txt", "w");

    while (fscanf(arquivoProdutos, "%s %f %d\n", produto.nome, &produto.preco, &produto.quantidade) != EOF) {
        if (strcmp(produto.nome, nome) == 0) {
            encontrado = 1;
            printf("Produto %s excluído com sucesso!\n", nome);
        } else {
            fprintf(temp, "%s %.2f %d\n", produto.nome, produto.preco, produto.quantidade);
        }
    }

    if (!encontrado) {
        printf("Produto %s não encontrado.\n", nome);
    }

    fclose(arquivoProdutos);
    fclose(temp);
    remove("produtos.txt");
    rename("temp.txt", "produtos.txt");
    getchar(); // Limpar o buffer do teclado
    printf("\nPressione Enter para continuar...");
    getchar(); // Esperar pelo Enter
}

// Função para cadastrar um novo funcionário
void cadastrarFuncionario(FILE *arquivoFuncionarios) {
    Funcionario novoFuncionario;

    printf("\n=========================================\n");
    printf("         Cadastrar Novo Funcionario\n");
    printf("-----------------------------------------\n");
    printf("Nome: ");
    scanf("%s", novoFuncionario.nome);
    printf("Idade: ");
    scanf("%d", &novoFuncionario.idade);
    printf("Funcao: ");
    scanf("%s", novoFuncionario.funcao);

    if (fprintf(arquivoFuncionarios, "%s %d %s\n", novoFuncionario.nome, novoFuncionario.idade, novoFuncionario.funcao) < 0) {
        printf("Erro ao registrar o funcionario.\n");
    } else {
        printf("Funcionario registrado com sucesso!\n");
    }
    getchar(); // Limpar o buffer do teclado
    printf("\nPressione Enter para continuar...");
    getchar(); // Esperar pelo Enter
}

// Função para listar os funcionários cadastrados
void listarFuncionarios(FILE *arquivoFuncionarios) {
    Funcionario funcionario;

    system("clear"); // Limpa a tela (apenas para sistemas Unix/Linux)
    printf("\n=========================================\n");
    printf("          Listagem de Funcionarios\n");
    printf("-----------------------------------------\n");
    rewind(arquivoFuncionarios);
    while (fscanf(arquivoFuncionarios, "%s %d %s\n", funcionario.nome, &funcionario.idade, funcionario.funcao) != EOF) {
        printf("Nome: %-20s | Idade: %-3d | Funcao: %s\n", funcionario.nome, funcionario.idade, funcionario.funcao);
    }
    getchar(); // Limpar o buffer do teclado
    printf("\nPressione Enter para continuar...");
    getchar(); // Esperar pelo Enter
}

// Função para excluir um funcionário
void excluirFuncionario(FILE *arquivoFuncionarios) {
    char nome[50];
    Funcionario funcionario;
    int encontrado = 0;

    printf("\n=========================================\n");
    printf("           Excluir Funcionario\n");
    printf("-----------------------------------------\n");
    printf("Nome do Funcionario a Excluir: ");
    scanf("%s", nome);

    rewind(arquivoFuncionarios);
    FILE *temp = fopen("temp.txt", "w");

    while (fscanf(arquivoFuncionarios, "%s %d %s\n", funcionario.nome, &funcionario.idade, funcionario.funcao) != EOF) {
        if (strcmp(funcionario.nome, nome) == 0) {
            encontrado = 1;
            printf("Funcionario %s excluído com sucesso!\n", nome);
        } else {
            fprintf(temp, "%s %d %s\n", funcionario.nome, funcionario.idade, funcionario.funcao);
        }
    }

    if (!encontrado) {
        printf("Funcionario %s não encontrado.\n", nome);
    }

    fclose(arquivoFuncionarios);
    fclose(temp);
    remove("funcionarios.txt");
    rename("temp.txt", "funcionarios.txt");
    getchar(); // Limpar o buffer do teclado
    printf("\nPressione Enter para continuar...");
    getchar(); // Esperar pelo Enter
}

// Função para cadastrar uma nova receita
void cadastrarReceita(FILE *arquivoReceitas) {
    Receita novaReceita;

    printf("\n=========================================\n");
    printf("          Cadastrar Nova Receita\n");
    printf("-----------------------------------------\n");
    printf("Nome: ");
    scanf("%s", novaReceita.nome);
    printf("Descricao: ");
    scanf("%s", novaReceita.descricao);

    if (fprintf(arquivoReceitas, "%s %s\n", novaReceita.nome, novaReceita.descricao) < 0) {
        printf("Erro ao cadastrar a receita.\n");
    } else {
        printf("Receita cadastrada com sucesso!\n");
    }
    getchar(); // Limpar o buffer do teclado
    printf("\nPressione Enter para continuar...");
    getchar(); // Esperar pelo Enter
}

// Função para listar as receitas cadastradas
void listarReceitas(FILE *arquivoReceitas) {
    Receita receita;

    system("clear"); // Limpa a tela (apenas para sistemas Unix/Linux)
    printf("\n=========================================\n");
    printf("           Listagem de Receitas\n");
    printf("-----------------------------------------\n");
    rewind(arquivoReceitas);
    while (fscanf(arquivoReceitas, "%s %s\n", receita.nome, receita.descricao) != EOF) {
        printf("Nome: %-20s | Descricao: %s\n", receita.nome, receita.descricao);
    }
    getchar(); // Limpar o buffer do teclado
    printf("\nPressione Enter para continuar...");
    getchar(); // Esperar pelo Enter
}

// Função para atualizar informações de uma receita
void atualizarReceita(FILE *arquivoReceitas) {
    char nome[50];
    Receita receita;

    printf("\n=========================================\n");
    printf("           Atualizar Receita\n");
    printf("-----------------------------------------\n");
    printf("Nome da Receita a Atualizar: ");
    scanf("%s", nome);

    rewind(arquivoReceitas);
    FILE *temp = fopen("temp.txt", "w");

    while (fscanf(arquivoReceitas, "%s %s\n", receita.nome, receita.descricao) != EOF) {
        if (strcmp(receita.nome, nome) == 0) {
            printf("Nova Descricao: ");
            scanf("%s", receita.descricao);
            fprintf(temp, "%s %s\n", receita.nome, receita.descricao);
            printf("Receita atualizada com sucesso!\n");
        } else {
            fprintf(temp, "%s %s\n", receita.nome, receita.descricao);
        }
    }

    fclose(arquivoReceitas);
    fclose(temp);
    remove("receitas.txt");
    rename("temp.txt", "receitas.txt");
    getchar(); // Limpar o buffer do teclado
    printf("\nPressione Enter para continuar...");
    getchar(); // Esperar pelo Enter
}

// Função para excluir uma receita
void excluirReceita(FILE *arquivoReceitas) {
    char nome[50];
    Receita receita;
    int encontrado = 0;

    printf("\n=========================================\n");
    printf("           Excluir Receita\n");
    printf("-----------------------------------------\n");
    printf("Nome da Receita a Excluir: ");
    scanf("%s", nome);

    rewind(arquivoReceitas);
    FILE *temp = fopen("temp.txt", "w");

    while (fscanf(arquivoReceitas, "%s %s\n", receita.nome, receita.descricao) != EOF) {
        if (strcmp(receita.nome, nome) == 0) {
            encontrado = 1;
            printf("Receita %s excluída com sucesso!\n", nome);
        } else {
            fprintf(temp, "%s %s\n", receita.nome, receita.descricao);
        }
    }

    if (!encontrado) {
        printf("Receita %s não encontrada.\n", nome);
    }

    fclose(arquivoReceitas);
    fclose(temp);
    remove("receitas.txt");
    rename("temp.txt", "receitas.txt");
    getchar(); // Limpar o buffer do teclado
    printf("\nPressione Enter para continuar...");
    getchar(); // Esperar pelo Enter
}
