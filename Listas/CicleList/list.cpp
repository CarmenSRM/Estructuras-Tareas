#include <iostream>
using namespace std;

// Clase nodo
class Node {
public:
    int value; // Valor del nodo
    Node* next; // Puntero al siguiente nodo
    Node(int val) : value(val), next(nullptr) {}
};

// Clase lista
class LinkedList {
private:
    Node* head; // Puntero al primer nodo

public:
    LinkedList() : head(nullptr) {}
    // Agregar un nodo al final de la lista
    void addNode(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Imprimir la lista
    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->value << " ";
            temp = temp->next;
            if (temp == head) break; // Evita impresión infinita en caso de ciclo
        }
        cout << endl;
    }

    // Crear un ciclo en la lista
    void createCycle() {
        if (!head || !head->next) return;
        Node* temp = head;
        Node* cycleStart = head->next->next; // Apunta al nodo que es el inicio del ciclo

        while (temp->next) {
            temp = temp->next;
        }
        temp->next = cycleStart; // Crea el ciclo
    }

    // Detectar y eliminar el ciclo.
    void detectAndRemoveCycle() {
        if (!head) return;
        Node* slow = head;
        Node* fast = head;

        // Detectar el ciclo
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }

        // Si no hay ciclo
        if (slow != fast) return;

        // Encontrar el inicio del ciclo
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // Encontrar el nodo final del ciclo
        Node* startOfCycle = slow;
        while (fast->next != startOfCycle) {
            fast = fast->next;
        }
        fast->next = nullptr; // Rompe el ciclo
    }

    // Liberar la memoria de la lista
    void freeMemory() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);
    list.addNode(6);
    list.addNode(7);
    list.createCycle();
    list.detectAndRemoveCycle();
    list.printList();
    list.freeMemory();
    return 0;
}