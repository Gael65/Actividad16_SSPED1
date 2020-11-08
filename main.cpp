#include <iostream>
#include "laboratorio.h"

using namespace std;

int main() {
    Laboratorio l;
    string opc;

    while(true) {
        cout << "1) Agregar computadora" << endl;
        cout << "2) Mostrar" << endl;
        cout << "3) Respaldar" << endl;
        cout << "4) Recuperar" << endl;
        cout << "5) Insertar" << endl;
        cout << "6) Inicializar" << endl;
        cout << "7) Eliminar" << endl;
        cout << "8) Ordenar" << endl;
        cout << "9) Borrar ultimo" << endl;
        cout << "10) Buscar" << endl;
        cout << "11) Frente" << endl;
        cout << "12) Ultimo" << endl;
        cout << "0) Salir" << endl;

        getline(cin, opc);

        if(opc == "1") {
            Computadora c;
            cin >> c;

            l.agregarFinal(c);
        }
        else if(opc == "2") {
            l.mostrar();
        }
        else if(opc == "3") {
            l. respaldar();
        }
        else if(opc == "4") {
            l.recuperar();
        }
        else if(opc == "5") {
            Computadora c;
            cin >> c;

            size_t p;
            cout << "Dame la posicion: "; cin >> p; cin.ignore();

            if(p >= l.size()) {
                cout << "Posicion no valida..." << endl;
            }
            else {
                l.insertar(c, p);
            }
        }
        else if(opc == "6") {
            Computadora c;
            cin >> c;

            size_t n;
            cout << "n: "; cin >> n; cin.ignore();       

            l.inicializar(n, c);     
        }
        else if(opc == "7") {
            size_t p;
            cout << "Dame la posicion: "; cin >> p; cin.ignore();

            if(p >= l.size()) {
                cout << "Posicion no valida..." << endl;
            }
            else {
                l.eliminar(p);
            }
        }
        else if(opc == "8") {
            l.ordenar();
        }
        else if(opc == "9") {
            l.borrarUltimo();
        }
        else if(opc == "10") {
            Computadora c;
            cin >> c;

            Computadora *ptr = l.buscar(c);

            if(ptr == nullptr) {
                cout << "No encontrado..." << endl;
            }
            else {
                cout << *ptr << endl;
            }
        }
        else if(opc == "11") {
            l.frente();
        }
        else if(opc == "12") {
            l.ultimo();
            
        }
        else if(opc == "0") {
            break;
        }
    }
    return 0;
}