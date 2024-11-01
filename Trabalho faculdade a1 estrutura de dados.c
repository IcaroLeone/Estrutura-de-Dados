#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do nó
typedef struct Node {
    int data; // Dado armazenado no nó
    struct Node* next; // Ponteiro para o próximo nó
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um novo nó no início da lista
void insert(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Elemento %d inserido com sucesso.\n", data);
}

// Função para exibir todos os elementos da lista
void display(Node* head) {
    Node* temp = head;
    printf("Elementos na lista: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Função para pesquisar um elemento na lista
Node* search(Node* head, int data) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            printf("Elemento %d encontrado na lista.\n", data);
            return temp;
        }
        temp = temp->next;
    }
    printf("Elemento %d não encontrado na lista.\n", data);
    return NULL;
}

// Função para alterar um elemento da lista
void update(Node* head, int oldData, int newData) {
    Node* nodeToUpdate = search(head, oldData);
    if (nodeToUpdate != NULL) {
        nodeToUpdate->data = newData;
        printf("Elemento %d alterado para %d.\n", oldData, newData);
    }
}

// Função para remover um elemento da lista
void delete(Node** head, int data) {
    Node* temp = *head;
    Node* prev = NULL;

    // Se o elemento a ser removido é o primeiro nó
    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        printf("Elemento %d removido com sucesso.\n", data);
        return;
    }

    // Busca pelo nó a ser removido, mantendo o nó anterior para ajustar o encadeamento
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // Se o elemento não foi encontrado
    if (temp == NULL) {
        printf("Elemento %d não encontrado na lista.\n", data);
        return;
    }

    // Desconecta o nó e libera a memória
    prev->next = temp->next;
    free(temp);
    printf("Elemento %d removido com sucesso.\n", data);
}

// Função principal
int main() {
    Node* head = NULL;
    int choice, data, newData;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir\n");
        printf("2. Exibir\n");
        printf("3. Consultar\n");
        printf("4. Alterar\n");
        printf("5. Remover\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &data);
                insert(&head, data);
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Digite o valor a ser consultado: ");
                scanf("%d", &data);
                search(head, data);
                break;
            case 4:
                printf("Digite o valor a ser alterado: ");
                scanf("%d", &data);
                printf("Digite o novo valor: ");
                scanf("%d", &newData);
                update(head, data, newData);
                break;
            case 5:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &data);
                delete(&head, data);
                break;
            case 6:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (choice != 6);

    return 0;
}
