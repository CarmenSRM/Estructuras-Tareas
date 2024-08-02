#include <iostream>
#include <string>

using namespace std;

class Elemento {
public:
    int num1;
    int num2;
    int num3;
    string cadena;
    Elemento *siguiente;
    //Mi contructor. 
    Elemento(int c1, int c2, int c3, const string& cad) {
        num1 = c1;
        num2 = c2;
        num3 = c3;
        cadena = cad;
        siguiente = nullptr;
    }
};

class Lista {
private:
    Elemento *primero;

public:
    Lista() : primero(nullptr) {} //Mi constructor. 
    // Agregar al inicio
    void addAtStart(Elemento* nuevo_elemento) {
        nuevo_elemento->siguiente = primero;
        primero = nuevo_elemento;
    }
    // Agregar al final
    void add(Elemento* nuevo_elemento) {
        if (primero == nullptr) {
            primero = nuevo_elemento;
        } else {
            Elemento* actual = primero;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo_elemento;
        }
    }
    //Imprimir
    void print() {
        Elemento* actual = primero;
        while (actual != nullptr) {
            cout << "num1: " << actual->num1
                 << ", num2: " << actual->num2
                 << ", num3: " << actual->num3
                 << ", cadena: " << actual->cadena << endl;
            actual = actual->siguiente;
        }
    }
    //Buscar
    Elemento* search(int valor) {
        Elemento* actual = primero;
        while (actual != nullptr) {
            if (actual->num1 == valor) {
                return actual;
            }
            actual = actual->siguiente;
        }
        return nullptr;
    }
    // Eliminar al inicio
    void deleteAtStart() {
        //Caso 0: No existen elementos en la lista
        if (primero == nullptr) {
            cout << "La lista está vacía." << endl;
            return;
        }
        //Caso 1: Se añade elemento
        Elemento* temp = primero;
        primero = primero->siguiente;
        delete temp;
        cout << "Elemento eliminado del inicio." << endl;
    }
    //Eliminar en general
    void eliminar(int valor) {
        //Caso 0: No existen elementos en la lista
        if (primero == nullptr) {
            cout << "La lista está vacía." << endl;
            return;
        }
        // Caso 1: Eliminar el único elemento
        if (primero->siguiente == nullptr) {
           deletUnique();
        }
        // Caso 2: Eliminar el primer elemento.
        if (primero->num1 == valor) {
            deleteAtStart();
        }
        //Busqueda para eliminar. 
        Elemento* actual = primero;
        while (actual->siguiente != nullptr && actual->siguiente->num1 != valor) {
            actual = actual->siguiente;
        }
        // Caso 3: Eliminar un elemento en el medio o al final
        if (actual->siguiente != nullptr) {
            Elemento* temp = actual->siguiente;
            actual->siguiente = actual->siguiente->siguiente;
            delete temp;
            cout << "Elemento con num1 = " << valor << " eliminado." << endl;
        } else {
            cout << "Elemento con num1 = " << valor << " no encontrado." << endl;
        }
    }
    // Eliminar elemento unico. 
    void deletUnique() {
        delete primero;
        primero = nullptr;
        cout << "Elemento eliminado del final." << endl;
        return;
    }
    //Eliminar al final 
    void deleteAtEnd() {
        if (primero == nullptr) {
            cout << "La lista está vacía." << endl;
            return;
        }
        // Caso 1: Eliminar el único elemento
        if (primero->siguiente == nullptr) {
           deletUnique();
        }
        // Caso 2: Eliminar el último elemento
        Elemento* actual = primero;
        while (actual->siguiente->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        delete actual->siguiente;
        actual->siguiente = nullptr;
        cout << "Elemento eliminado del final." << endl;
    }
};

int main() {
    Lista lista;
    // Crear algunos elementos
    Elemento* e1 = new Elemento(1, 2, 3, "uno");
    Elemento* e2 = new Elemento(4, 5, 6, "dos");
    Elemento* e3 = new Elemento(7, 8, 9, "tres");

    // Agregar al final
    lista.add(e1);
    lista.add(e2);
    lista.add(e3);

    // Imprimir
    cout << "Lista después de agregar al final:" << endl;
    lista.print();

    // Agregar al inicio
    Elemento* e4 = new Elemento(10, 11, 12, "cuatro");
    lista.addAtStart(e4);

    // Imprimir 
    cout << "\nLista después de agregar al inicio:" << endl;
    lista.print();

    // Eliminar al final
    lista.deleteAtEnd();

    // Imprimir
    cout << "\nLista después de eliminar al final:" << endl;
    lista.print();

    // Eliminar al inicio
    lista.deleteAtStart();

    // Imprimir
    cout << "\nLista después de eliminar al inicio:" << endl;
    lista.print();

    // Liberar memoria
    delete e1;
    delete e2;
    delete e3;
    delete e4;

    return 0;
}