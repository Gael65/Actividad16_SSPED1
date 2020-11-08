#include "laboratorio.h"
#include <fstream>
#include <algorithm>

Laboratorio::Laboratorio(){}

void Laboratorio::agregarFinal(const Computadora &c){
    computadoras.push_back(c);
}

void Laboratorio::respaldar_tabla() {
    ofstream archivo("computadoras_tabla.txt");
    if (archivo.is_open()) {
        archivo << left;
        archivo << setw(10) << "Marca";
        archivo << setw(10) << "S.O.";
        archivo << setw(5) << "RAM";
        archivo << setw(10) << "Procesador";
        archivo << endl;
        for(size_t i = 0; i < computadoras.size(); i++){
            Computadora &c = computadoras[i];
            archivo << c;
        }
    }
    archivo.close();
}

void Laboratorio::respaldar() {
    ofstream archivo("computadoras.txt");
    if (archivo.is_open()) {
        for (size_t i = 0; i < computadoras.size(); i++) {
            Computadora &c = computadoras[i];
            archivo << c.getMarca() << endl;
            archivo << c.getSO() << endl;
            archivo << c.getMemoriaRam() << endl;
            archivo << c.getProcesador() << endl;
        }
    }
    archivo.close();
}

void Laboratorio::recuperar() {
    ifstream archivo("computadoras.txt");
    if(archivo.is_open()) {
        string temp;
        int ram;
        Computadora c;

        while(true) {
            getline(archivo, temp);
            if (archivo.eof()) {
                break;
            }
            c.setMarca(temp);

            getline(archivo, temp);
            c.setSO(temp);

            getline(archivo, temp);
            ram = stoi(temp);
            c.setMemoriaRam(ram);

            getline(archivo, temp);
            c.setProcesador(temp);

            agregarFinal(c);
        }
    }
    archivo.close();
}

void Laboratorio::mostrar(){
    cout << left;
    cout << setw(10) << "Marca";
    cout << setw(10) << "S.O.";
    cout << setw(5) << "RAM";
    cout << setw(10) << "Procesador";
    cout << endl;
    for(size_t i = 0; i < computadoras.size(); i++){
        Computadora &c = computadoras[i];
        cout << c;
    }
}

void Laboratorio::insertar(const Computadora &c, size_t p) {
    computadoras.insert(computadoras.begin() + p, c);
}

size_t Laboratorio::size() {
    return computadoras.size();
}

void Laboratorio::inicializar(size_t n, const Computadora &c) {
    computadoras = vector<Computadora>(n, c);
}

void Laboratorio::eliminar(size_t p) {
    computadoras.erase(computadoras.begin() + p);
}

void Laboratorio::ordenar() {
    sort(computadoras.begin(), computadoras.end());
}

void Laboratorio::borrarUltimo() {
    computadoras.pop_back();
}

Computadora* Laboratorio::buscar(const Computadora &c) {
    //vector<Computadora>::iterator
    auto it = find(computadoras.begin(), computadoras.end(), c);

    if(it == computadoras.end()) {
        return nullptr;
    }
    else
    {
        return &(*it);
    }
}

void Laboratorio::frente() {
    if(computadoras.empty()) {
        cout << "Vector esta vacio" << endl;
    }
    else {
        cout << computadoras.front() << endl;
    }
}

void Laboratorio::ultimo() {
    if(computadoras.empty()) {
        cout << "Vector esta vacio" << endl;
    }
    else {
        cout << computadoras.back() << endl;
    }
}