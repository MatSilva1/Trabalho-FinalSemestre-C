#include <stdio.h>
#include <stdlib.h>

#define limparTela system("clear")  // No Windows mude para "cls"

typedef struct {
    int codigo;
    char idproduto[100];
    char descricao[100];
    double valor;
} Produto_t;

typedef struct {
    int codigo;
    int codigoProduto[100];
    double valorTotal;
    char descricao[100];
} Pedido_t;

int main() {
    const int quantidadeMaximaProdutos = 100;  // Quantidade máxima de tipos de produto

    int posicaoProduto = 0;                   // Posição de inserção de novos produtos
    int posicaoProdutoPedido = 0;             // Posição de inserção no vetor de códigos do pedido
    int codigoProduto = 0;                    // Código para cadastrar o pedido

    Produto_t produtos[quantidadeMaximaProdutos];  // Vetor com os tipos de produto

    Pedido_t pedido;                        // Pedido

    char opcao = ' ';                       // Opção do menu principal

    do {
        limparTela;
        printf("MENU \n");
        printf("[ 1 ] - Cadastrar produto \n");
        printf("[ 2 ] - Ver produtos disponiveis \n");
        printf("[ 3 ] - Realizar pedido \n");
        printf("[ 0 ] - Finalizar compra e sair do programa \n");
        printf("> ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':   // Cadastrar produto
                limparTela;
                printf("NOVO PRODUTO: \n");
                printf("Descrição: ");
                scanf(" %[^\n]s", produtos[posicaoProduto].descricao);
                printf("Valor: R$ ");
                scanf(" %lf", &produtos[posicaoProduto].valor);

                produtos[posicaoProduto].codigo = posicaoProduto + 1;     // Código sequencial a partir de 1
                posicaoProduto += 1;
                break;

            case '2':
                limparTela;
                int voltar;
                printf ("Produtos em estoque: \n");
                printf ("ID: %i  Descricao:  Valor: ", codigoProduto);
                printf ("Digite [0] para voltar ao menu principal: \n");
                scanf ("%d", &voltar);
                if (voltar > 0){
                    printf("Digite um numero valido \n\n");
                    
                }
                else{
                    
                    break;
                }

            case '3':   // Fazer pedido
                limparTela;
                if (posicaoProduto == 0) {
                    printf("Não ha produtos cadastrados no momento \n");

                    if (getchar() == '\n') {
                        getchar();
                    }

                    break;
                }

                printf("NOVO PEDIDO \n");

                // Fica pedindo o código do produto para adicionar no pedido
                do {
                    printf("Código do produto [ 1 - %i / [0] - Fim ]: ", posicaoProduto);
                    scanf(" %i", &codigoProduto);

                    if (codigoProduto > 0 && codigoProduto <= posicaoProduto) {
                        
                        pedido.codigoProduto[posicaoProdutoPedido] = codigoProduto;
                        pedido.valorTotal += produtos[codigoProduto - 1].valor;
                        posicaoProdutoPedido += 1;
                        
                    }
                } while (codigoProduto != 0 && posicaoProdutoPedido < 100);
                
                pedido.codigo = 1;
                break;
        }
    } while (opcao != '0');

    limparTela;
    printf("--------------------------------------------- \n");
    printf("PEDIDO \n");
    printf("Código: %i \n", posicaoProdutoPedido);
    printf("Produtos: %s \n", pedido.descricao);
    printf("Valor: R$ %.2f \n", pedido.valorTotal);
    printf("--------------------------------------------- \n");

    return 0;
}

