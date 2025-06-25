#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>  

typedef struct {
    char nome[100];
    double preco;
} ItemMenu;

void exibir_menu_console(int n_itens, ItemMenu *menu);

int main() {
    FILE *f_menu;
    int n_itens;

    f_menu = fopen("menu.txt", "r");
    if (f_menu == NULL) {
        perror("ERRO: Nao foi possivel abrir o arquivo 'menu.txt'");
        return 1;
    }

    if (fscanf(f_menu, "%d", &n_itens) != 1 || n_itens <= 0) {
        fprintf(stderr, "ERRO: Formato invalido ou quantidade de itens nula em menu.txt\n");
        fclose(f_menu);
        return 1;
    }

    ItemMenu *menu = (ItemMenu *)malloc(n_itens * sizeof(ItemMenu));
    if (menu == NULL) {
        fprintf(stderr, "ERRO: Falha ao alocar memoria para o menu.\n");
        fclose(f_menu);
        return 1;
    }

    for (int i = 0; i < n_itens; i++) {
        if (fscanf(f_menu, "%99s %lf", menu[i].nome, &menu[i].preco) != 2) {
             fprintf(stderr, "ERRO: Falha ao ler o item %d do menu.\n", i + 1);
             free(menu);
             fclose(f_menu);
             return 1;
        }
    }
    fclose(f_menu); 

    int *quantidades_pedidas = (int *)calloc(n_itens, sizeof(int));
    if (quantidades_pedidas == NULL) {
        fprintf(stderr, "ERRO: Falha ao alocar memoria para o pedido.\n");
        free(menu);
        return 1;
    }

    int codigo_item;
    do {
        exibir_menu_console(n_itens, menu);
        printf("\nDigite o codigo do item (ou 0 para finalizar o pedido): ");
        scanf("%d", &codigo_item);

        if (codigo_item > 0 && codigo_item <= n_itens) {
            int quantidade;
            printf("Digite a quantidade: ");
            scanf("%d", &quantidade);

            if (quantidade > 0) {
                quantidades_pedidas[codigo_item - 1] += quantidade;
                printf(">> %d unidade(s) de %s adicionada(s) ao pedido.\n\n", quantidade, menu[codigo_item - 1].nome);
            } else {
                printf(">> Quantidade invalida.\n\n");
            }
        } else if (codigo_item != 0) {
            printf(">> Codigo de item invalido. Tente novamente.\n\n");
        }

    } while (codigo_item != 0);

    printf("\nFinalizando pedido e gerando boleto...\n");

    FILE *f_boleto = fopen("boleto.txt", "w");
    if (f_boleto == NULL) {
        perror("ERRO: Nao foi possivel criar o arquivo 'boleto.txt'");
        free(menu);
        free(quantidades_pedidas);
        return 1;
    }

    fprintf(f_boleto, "========================================\n");
    fprintf(f_boleto, "         LANCHONETE DO USUARIO\n");
    fprintf(f_boleto, "========================================\n\n");
    fprintf(f_boleto, "%-4s %-20s %-8s %-10s\n", "QTD", "ITEM", "V. UN", "SUBTOTAL");
    fprintf(f_boleto, "----------------------------------------\n");

    double total_pedido = 0.0;
    for (int i = 0; i < n_itens; i++) {
        if (quantidades_pedidas[i] > 0) {
            double subtotal = menu[i].preco * quantidades_pedidas[i];
            fprintf(f_boleto, "%-4d %-20s R$%-7.2f R$%-9.2f\n",
                    quantidades_pedidas[i],
                    menu[i].nome,
                    menu[i].preco,
                    subtotal);
            total_pedido += subtotal;
        }
    }

    fprintf(f_boleto, "----------------------------------------\n");
    fprintf(f_boleto, "TOTAL DO PEDIDO: R$%.2f\n\n", total_pedido);
    fprintf(f_boleto, "Obrigado e volte sempre!\n");
    
    fclose(f_boleto);
    printf("Boleto gerado com sucesso em 'boleto.txt'!\n");

    free(menu);
    free(quantidades_pedidas);

    return 0;
}


void exibir_menu_console(int n_itens, ItemMenu *menu) {
    printf("==================== MENU ====================\n");
    for (int i = 0; i < n_itens; i++) {
        printf("  %2d - %-20s .... R$ %.2f\n", i + 1, menu[i].nome, menu[i].preco);
    }
    printf("============================================\n");
}