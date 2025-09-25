#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta do Super Trunfo
typedef struct {
    char nome[50];
    char estado[30];
    char codigo[10];
    unsigned long int populacao;  // População da cidade
    float area;                    // Área da cidade em km²
    float pib;                     // PIB da cidade
    int pontos_turisticos;         // Número de pontos turísticos
    float densidade;               // Densidade populacional (população / área)
    float pib_per_capita;          // PIB per capita (PIB / população)
    float super_poder;             // Soma de todos os atributos para comparação
} Carta;

// Função para calcular densidade populacional
void calcular_densidade(Carta *c) {
    c->densidade = c->populacao / c->area;
}

// Função para calcular PIB per capita
void calcular_pib_per_capita(Carta *c) {
    c->pib_per_capita = c->pib / c->populacao;
}

// Função para calcular o Super Poder da carta
void calcular_super_poder(Carta *c) {
    // Quanto menor a densidade, maior o poder. Usamos o inverso da densidade
    float inverso_densidade = 1.0f / c->densidade;

    // Somamos todos os atributos relevantes
    c->super_poder = (float)c->populacao + c->area + c->pib 
                     + c->pontos_turisticos + c->pib_per_capita 
                     + inverso_densidade;
}

// Função para comparar os atributos das cartas
void comparar_cartas(Carta c1, Carta c2) {
    printf("\n===== Comparação de Cartas =====\n");

    // Para população, área, PIB, pontos turísticos e PIB per capita, maior vence
    printf("População: Carta %d venceu (%d)\n", (c1.populacao > c2.populacao) ? 1 : 2, (c1.populacao > c2.populacao) ? 1 : 0);
    printf("Área: Carta %d venceu (%d)\n", (c1.area > c2.area) ? 1 : 2, (c1.area > c2.area) ? 1 : 0);
    printf("PIB: Carta %d venceu (%d)\n", (c1.pib > c2.pib) ? 1 : 2, (c1.pib > c2.pib) ? 1 : 0);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", (c1.pontos_turisticos > c2.pontos_turisticos) ? 1 : 2, (c1.pontos_turisticos > c2.pontos_turisticos) ? 1 : 0);
    
    // Para densidade populacional, vence a menor
    printf("Densidade Populacional: Carta %d venceu (%d)\n", (c1.densidade < c2.densidade) ? 1 : 2, (c1.densidade < c2.densidade) ? 1 : 0);
    
    printf("PIB per Capita: Carta %d venceu (%d)\n", (c1.pib_per_capita > c2.pib_per_capita) ? 1 : 2, (c1.pib_per_capita > c2.pib_per_capita) ? 1 : 0);

    // Super Poder: maior vence
    printf("Super Poder: Carta %d venceu (%d)\n", (c1.super_poder > c2.super_poder) ? 1 : 2, (c1.super_poder > c2.super_poder) ? 1 : 0);
}

// Função para exibir os dados de uma carta
void exibir_carta(Carta c) {
    printf("\n--- Dados da Carta ---\n");
    printf("Nome: %s\n", c.nome);
    printf("Estado: %s\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("População: %lu\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontos_turisticos);
    printf("Densidade Populacional: %.2f\n", c.densidade);
    printf("PIB per Capita: %.2f\n", c.pib_per_capita);
    printf("Super Poder: %.2f\n", c.super_poder);
}

int main() {
    Carta carta1, carta2;

    // Leitura da Carta 1
    printf("Digite os dados da Carta 1:\n");
    printf("Nome: ");
    fgets(carta1.nome, sizeof(carta1.nome), stdin);
    carta1.nome[strcspn(carta1.nome, "\n")] = 0; // remover \n
    printf("Estado: ");
    fgets(carta1.estado, sizeof(carta1.estado), stdin);
    carta1.estado[strcspn(carta1.estado, "\n")] = 0;
    printf("Código: ");
    fgets(carta1.codigo, sizeof(carta1.codigo), stdin);
    carta1.codigo[strcspn(carta1.codigo, "\n")] = 0;
    printf("População: ");
    scanf("%lu", &carta1.populacao);
    printf("Área: ");
    scanf("%f", &carta1.area);
    printf("PIB: ");
    scanf("%f", &carta1.pib);
    printf("Pontos Turísticos: ");
    scanf("%d", &carta1.pontos_turisticos);
    getchar(); // limpar buffer

    // Leitura da Carta 2
    printf("\nDigite os dados da Carta 2:\n");
    printf("Nome: ");
    fgets(carta2.nome, sizeof(carta2.nome), stdin);
    carta2.nome[strcspn(carta2.nome, "\n")] = 0;
    printf("Estado: ");
    fgets(carta2.estado, sizeof(carta2.estado), stdin);
    carta2.estado[strcspn(carta2.estado, "\n")] = 0;
    printf("Código: ");
    fgets(carta2.codigo, sizeof(carta2.codigo), stdin);
    carta2.codigo[strcspn(carta2.codigo, "\n")] = 0;
    printf("População: ");
    scanf("%lu", &carta2.populacao);
    printf("Área: ");
    scanf("%f", &carta2.area);
    printf("PIB: ");
    scanf("%f", &carta2.pib);
    printf("Pontos Turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    // Cálculos das cartas
    calcular_densidade(&carta1);
    calcular_densidade(&carta2);
    calcular_pib_per_capita(&carta1);
    calcular_pib_per_capita(&carta2);
    calcular_super_poder(&carta1);
    calcular_super_poder(&carta2);

    // Exibir dados das cartas antes da comparação
    exibir_carta(carta1);
    exibir_carta(carta2);

    // Comparação das cartas
    comparar_cartas(carta1, carta2);

    return 0;
}
