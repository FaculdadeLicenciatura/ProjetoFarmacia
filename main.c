#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Estrutura para representar um produto
typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

// Estrutura para representar um funcionario
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
void RegistarProduto(FILE *arquivoProdutos);
void listarProdutos(FILE *arquivoProdutos);
void atualizarProduto(FILE *arquivoProdutos);
void venderProduto(FILE *arquivoProdutos);
void excluirProduto(FILE *arquivoProdutos);
void RegistarFuncionario(FILE *arquivoFuncionarios);
void listarFuncionarios(FILE *arquivoFuncionarios);
void excluirFuncionario(FILE *arquivoFuncionarios);
void RegistarReceita(FILE *arquivoReceitas);
void listarReceitas(FILE *arquivoReceitas);
void atualizarReceita(FILE *arquivoReceitas);
void excluirReceita(FILE *arquivoReceitas);

int main() {

    setlocale(LC_ALL, "en_US.UTF-8");

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

int Menu() {
    int opcao;
    system("clear");
    printf("\n+---------------------------------------+\n");
    printf("|          Menu Principal               |\n");
    printf("|---------------------------------------|\n");
    printf("| 1) Produtos                           |\n");
    printf("| 2) Funcionarios                       |\n");
    printf("| 3) Receitas                           |\n");
    printf("| 4) Stock                              |\n");
    printf("| 9) Sair                               |\n");
    printf("+---------------------------------------+\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    return opcao;
}


// Função para exibir o menu de produtos
void menuProdutos(FILE *arquivoProdutos) {
    int opcao;
    while (1) {
        system("clear");
        printf("\n+---------------------------------------+\n");
        printf("|          Menu de Produtos             |\n");
        printf("|---------------------------------------|\n");
        printf("| 1) Registar Produto                  |\n");
        printf("| 2) Listar Produtos                    |\n");
        printf("| 3) Atualizar Produto                  |\n");
        printf("| 4) Vender Produto                     |\n");
        printf("| 5) Excluir Produto                    |\n");
        printf("| 9) Voltar                             |\n");
        printf("+---------------------------------------+\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                RegistarProduto(arquivoProdutos);
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

// Função para exibir o menu de funcionarios
void menuFuncionarios(FILE *arquivoFuncionarios) {
    int opcao;
    while (1) {
        system("clear"); // Limpa a tela (apenas para sistemas Unix/Linux)
        printf("\n+---------------------------------------+\n");
        printf("|         Menu de Funcionarios           |\n");
        printf("|---------------------------------------|\n");
        printf("| 1) Registar Funcionario              |\n");
        printf("| 2) Listar Funcionarios                |\n");
        printf("| 3) Excluir Funcionario                |\n");
        printf("| 9) Voltar                             |\n");
        printf("+---------------------------------------+\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                RegistarFuncionario(arquivoFuncionarios);
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
        printf("\n+---------------------------------------+\n");
        printf("|           Menu de Receitas             |\n");
        printf("|---------------------------------------|\n");
        printf("| 1) Registar Receita                   |\n");
        printf("| 2) Listar Receitas                     |\n");
        printf("| 3) Atualizar Receita                   |\n");
        printf("| 4) Excluir Receita                     |\n");
        printf("| 9) Voltar                              |\n");
        printf("+---------------------------------------+\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                RegistarReceita(arquivoReceitas);
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

void listarStock(FILE *arquivoProdutos) {
    Produto produto;

    system("clear");
    printf("\n+---------------------------------------+\n");
    printf("|                Stock                  |\n");
    printf("|---------------------------------------|\n");
    rewind(arquivoProdutos);
    while (fscanf(arquivoProdutos, "%s %f %d\n", produto.nome, &produto.preco, &produto.quantidade) != EOF) {
        printf("| Nome: %-20s | Preco: %-8.2f | Quantidade: %d |\n", produto.nome, produto.preco, produto.quantidade);
    }
    printf("+---------------------------------------+\n");
    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();
}

// Função para Registar um novo produto
void RegistarProduto(FILE *arquivoProdutos) {
    Produto novoProduto;

    printf("\n+---------------------------------------+\n");
    printf("|          Registar Novo Produto        |\n");
    printf("|---------------------------------------|\n");
    printf("| Nome:                                 |\n");
    scanf("%s", novoProduto.nome);
    printf("| Preco:                                |\n");
    scanf("%f", &novoProduto.preco);
    printf("| Quantidade:                           |\n");
    scanf("%d", &novoProduto.quantidade);

    if (fprintf(arquivoProdutos, "%s %.2f %d\n", novoProduto.nome, novoProduto.preco, novoProduto.quantidade) < 0) {
        printf("Erro ao registrar o produto.\n");
    } else {
        printf("Produto registrado com sucesso!\n");
    }
    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();
}


// Função para listar os produtos cadastrados
void listarProdutos(FILE *arquivoProdutos) {
    Produto produto;

    system("clear"); // Limpa a tela (apenas para sistemas Unix/Linux)
    printf("\n+---------------------------------------+\n");
    printf("|        Listagem de Produtos            |\n");
    printf("|---------------------------------------|\n");
    rewind(arquivoProdutos);
    while (fscanf(arquivoProdutos, "%s %f %d\n", produto.nome, &produto.preco, &produto.quantidade) != EOF) {
        printf("| Nome: %-20s | Preco: %-8.2f | Quantidade: %d |\n", produto.nome, produto.preco, produto.quantidade);
    }
    printf("+---------------------------------------+\n");
    printf("\nPressione Enter para continuar...");
    getchar(); // Limpar o buffer do teclado
    getchar(); // Esperar pelo Enter
}


// Função para atualizar informações de um produto
void atualizarProduto(FILE *arquivoProdutos) {
    char nome[50];
    int quantidade;
    Produto produto;

    printf("\n+---------------------------------------+\n");
    printf("|           Atualizar Produto            |\n");
    printf("|---------------------------------------|\n");
    printf("| Nome do Produto a Atualizar:           |\n");
    scanf("%s", nome);

    rewind(arquivoProdutos);
    FILE *temp = fopen("temp.txt", "w");

    while (fscanf(arquivoProdutos, "%s %f %d\n", produto.nome, &produto.preco, &produto.quantidade) != EOF) {
        if (strcmp(produto.nome, nome) == 0) {
            printf("| Novo Preco:                            |\n");
            scanf("%f", &produto.preco);
            printf("| Nova Quantidade:                       |\n");
            scanf("%d", &quantidade);
            produto.quantidade = quantidade;
            fprintf(temp, "%s %.2f %d\n", produto.nome, produto.preco, produto.quantidade);
            printf("| Produto atualizado com sucesso!       |\n");
        } else {
            fprintf(temp, "%s %.2f %d\n", produto.nome, produto.preco, produto.quantidade);
        }
    }

    fclose(arquivoProdutos);
    fclose(temp);
    remove("produtos.txt");
    rename("temp.txt", "produtos.txt");
    printf("+---------------------------------------+\n");
    printf("\nPressione Enter para continuar...");
    getchar(); // Limpar o buffer do teclado
    getchar(); // Esperar pelo Enter
}


// Função para vender um produto
void venderProduto(FILE *arquivoProdutos) {
    char nome[50];
    int quantidadeVendida;
    int quantidadeAtual;
    FILE *temp;
    Produto produto;

    printf("\n+---------------------------------------+\n");
    printf("|           Venda de Produto             |\n");
    printf("|---------------------------------------|\n");
    printf("| Nome do Produto:                       |\n");
    scanf("%s", nome);

    rewind(arquivoProdutos);
    temp = fopen("temp.txt", "w");

    while (fscanf(arquivoProdutos, "%s %f %d\n", produto.nome, &produto.preco, &produto.quantidade) != EOF) {
        if (strcmp(produto.nome, nome) == 0) {
            printf("| Quantidade atual: %d                   |\n", produto.quantidade);
            printf("| Quantidade vendida:                    |\n");
            scanf("%d", &quantidadeVendida);
            quantidadeAtual = produto.quantidade - quantidadeVendida;
            fprintf(temp, "%s %.2f %d\n", produto.nome, produto.preco, quantidadeAtual);
            printf("| Venda realizada com sucesso!           |\n");
        } else {
            fprintf(temp, "%s %.2f %d\n", produto.nome, produto.preco, produto.quantidade);
        }
    }

    fclose(arquivoProdutos);
    fclose(temp);
    remove("produtos.txt");
    rename("temp.txt", "produtos.txt");
    printf("+---------------------------------------+\n");
    printf("\nPressione Enter para continuar...");
    getchar(); // Limpar o buffer do teclado
    getchar(); // Esperar pelo Enter
}


// Função para excluir um produto
void excluirProduto(FILE *arquivoProdutos) {
    char nome[50];
    Produto produto;
    int encontrado = 0;

    printf("\n+---------------------------------------+\n");
    printf("|           Excluir Produto              |\n");
    printf("|---------------------------------------|\n");
    printf("| Nome do Produto a Excluir:             |\n");
    scanf("%s", nome);

    rewind(arquivoProdutos);
    FILE *temp = fopen("temp.txt", "w");

    while (fscanf(arquivoProdutos, "%s %f %d\n", produto.nome, &produto.preco, &produto.quantidade) != EOF) {
        if (strcmp(produto.nome, nome) == 0) {
            encontrado = 1;
            printf("| Produto %s excluído com sucesso!      |\n", nome);
        } else {
            fprintf(temp, "%s %.2f %d\n", produto.nome, produto.preco, produto.quantidade);
        }
    }

    if (!encontrado) {
        printf("| Produto %s não encontrado.             |\n", nome);
    }

    fclose(arquivoProdutos);
    fclose(temp);
    remove("produtos.txt");
    rename("temp.txt", "produtos.txt");
    printf("+---------------------------------------+\n");
    printf("\nPressione Enter para continuar...");
    getchar(); // Limpar o buffer do teclado
    getchar(); // Esperar pelo Enter
}

// Função para Registar um novo funcionario
void RegistarFuncionario(FILE *arquivoFuncionarios) {
    Funcionario novoFuncionario;

    printf("\n+---------------------------------------+\n");
    printf("|     Registar Novo Funcionario         |\n");
    printf("|---------------------------------------|\n");
    printf("| Nome:                                   |\n");
    scanf("%s", novoFuncionario.nome);
    printf("| Idade:                                  |\n");
    scanf("%d", &novoFuncionario.idade);
    printf("| Função:                                 |\n");
    scanf("%s", novoFuncionario.funcao);

    if (fprintf(arquivoFuncionarios, "%s %d %s\n", novoFuncionario.nome, novoFuncionario.idade, novoFuncionario.funcao) < 0) {
        printf("| Erro ao registrar o funcionario.       |\n");
    } else {
        printf("| Funcionario registrado com sucesso!    |\n");
    }
    printf("+---------------------------------------+\n");
    printf("\nPressione Enter para continuar...");
    getchar(); // Limpar o buffer do teclado
    getchar(); // Esperar pelo Enter
}


// Função para listar os funcionarios cadastrados
void listarFuncionarios(FILE *arquivoFuncionarios) {
    Funcionario funcionario;

    printf("\n+---------------------------------------+\n");
    printf("|        Listagem de Funcionarios         |\n");
    printf("|---------------------------------------|\n");
    rewind(arquivoFuncionarios);
    while (fscanf(arquivoFuncionarios, "%s %d %s\n", funcionario.nome, &funcionario.idade, funcionario.funcao) != EOF) {
        printf("| Nome: %-20s | Idade: %-3d | Função: %-10s |\n", funcionario.nome, funcionario.idade, funcionario.funcao);
    }
    printf("+---------------------------------------+\n");
    printf("\nPressione Enter para continuar...");
    getchar(); // Limpar o buffer do teclado
    getchar(); // Esperar pelo Enter
}


// Função para excluir um funcionario
void excluirFuncionario(FILE *arquivoFuncionarios) {
    char nome[50];
    Funcionario funcionario;
    int encontrado = 0;

    printf("\n+---------------------------------------+\n");
    printf("|         Excluir Funcionario            |\n");
    printf("|---------------------------------------|\n");
    printf("| Nome do Funcionario a Excluir:          |\n");
    scanf("%s", nome);

    rewind(arquivoFuncionarios);
    FILE *temp = fopen("temp.txt", "w");

    while (fscanf(arquivoFuncionarios, "%s %d %s\n", funcionario.nome, &funcionario.idade, funcionario.funcao) != EOF) {
        if (strcmp(funcionario.nome, nome) == 0) {
            encontrado = 1;
            printf("| Funcionario %s excluído com sucesso!   |\n", nome);
        } else {
            fprintf(temp, "%s %d %s\n", funcionario.nome, funcionario.idade, funcionario.funcao);
        }
    }

    if (!encontrado) {
        printf("| Funcionario %s não encontrado.         |\n", nome);
    }

    fclose(arquivoFuncionarios);
    fclose(temp);
    remove("funcionarios.txt");
    rename("temp.txt", "funcionarios.txt");
    printf("+---------------------------------------+\n");
    printf("\nPressione Enter para continuar...");
    getchar(); // Limpar o buffer do teclado
    getchar(); // Esperar pelo Enter
}


// Função para Registar uma nova receita
void RegistarReceita(FILE *arquivoReceitas) {
    Receita novaReceita;

    printf("\n+---------------------------------------+\n");
    printf("|         Registar Nova Receita        |\n");
    printf("|---------------------------------------|\n");
    printf("| Nome:                                 |\n");
    scanf("%s", novaReceita.nome);
    printf("| Descrição:                            |\n");
    scanf("%s", novaReceita.descricao);

    if (fprintf(arquivoReceitas, "%s %s\n", novaReceita.nome, novaReceita.descricao) < 0) {
        printf("| Erro ao Registar a receita.          |\n");
    } else {
        printf("| Receita cadastrada com sucesso!       |\n");
    }
    printf("+---------------------------------------+\n");
    printf("\nPressione Enter para continuar...");
    getchar(); // Limpar o buffer do teclado
    getchar(); // Esperar pelo Enter
}


void listarReceitas(FILE *arquivoReceitas) {
    Receita receita;

    printf("\n+---------------------------------------+\n");
    printf("|            Listagem de Receitas        |\n");
    printf("|---------------------------------------|\n");
    rewind(arquivoReceitas);
    while (fscanf(arquivoReceitas, "%s %s\n", receita.nome, receita.descricao) != EOF) {
        printf("| Nome: %-20s │ Descrição: %-30s |\n", receita.nome, receita.descricao);
    }
    printf("+---------------------------------------+\n");
    printf("\nPressione Enter para continuar...");
    getchar(); // Limpar o buffer do teclado
    getchar(); // Esperar pelo Enter
}


void atualizarReceita(FILE *arquivoReceitas) {
    char nome[50];
    Receita receita;

    printf("\n+---------------------------------------+\n");
    printf("|          Atualizar Receita            |\n");
    printf("|---------------------------------------|\n");
    printf("| Nome da Receita a Atualizar:           |\n");
    scanf("%s", nome);

    rewind(arquivoReceitas);
    FILE *temp = fopen("temp.txt", "w");

    while (fscanf(arquivoReceitas, "%s %s\n", receita.nome, receita.descricao) != EOF) {
        if (strcmp(receita.nome, nome) == 0) {
            printf("| Nova Descrição:                       |\n");
            scanf("%s", receita.descricao);
            fprintf(temp, "%s %s\n", receita.nome, receita.descricao);
            printf("| Receita atualizada com sucesso!      |\n");
        } else {
            fprintf(temp, "%s %s\n", receita.nome, receita.descricao);
        }
    }

    fclose(arquivoReceitas);
    fclose(temp);
    remove("receitas.txt");
    rename("temp.txt", "receitas.txt");
    printf("+---------------------------------------+\n");
    printf("\nPressione Enter para continuar...");
    getchar(); // Limpar o buffer do teclado
    getchar(); // Esperar pelo Enter
}


void excluirReceita(FILE *arquivoReceitas) {
    char nome[50];
    Receita receita;
    int encontrado = 0;

    printf("\n+---------------------------------------+\n");
    printf("|          Excluir Receita              |\n");
    printf("|---------------------------------------|\n");
    printf("| Nome da Receita a Excluir:             |\n");
    scanf("%s", nome);

    rewind(arquivoReceitas);
    FILE *temp = fopen("temp.txt", "w");

    while (fscanf(arquivoReceitas, "%s %s\n", receita.nome, receita.descricao) != EOF) {
        if (strcmp(receita.nome, nome) == 0) {
            encontrado = 1;
            printf("| Receita %s excluída com sucesso!      |\n", nome);
        } else {
            fprintf(temp, "%s %s\n", receita.nome, receita.descricao);
        }
    }

    if (!encontrado) {
        printf("| Receita %s não encontrada.           |\n", nome);
    }

    fclose(arquivoReceitas);
    fclose(temp);
    remove("receitas.txt");
    rename("temp.txt", "receitas.txt");
    printf("+---------------------------------------+\n");
    printf("\nPressione Enter para continuar...");
    getchar(); // Limpar o buffer do teclado
    getchar(); // Esperar pelo Enter
}
