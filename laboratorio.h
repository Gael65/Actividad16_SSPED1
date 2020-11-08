#ifndef LABORATORIO_H
#define LABORATORIO_H

#include <iostream>
#include <vector>

#include "computadora.h"

using namespace std;

class Laboratorio {
private:
    vector<Computadora> computadoras;
public:
    Laboratorio();
    void agregarFinal(const Computadora &c);
    void mostrar();
    void respaldar_tabla();
    void respaldar();
    void recuperar();

    void insertar(const Computadora &c, size_t p);
    size_t size();
    void inicializar(size_t n, const Computadora &c);
    void eliminar(size_t p);
    void ordenar();
    void borrarUltimo();
    Computadora* buscar(const Computadora &c);
    void frente();
    void ultimo();

    friend Laboratorio& operator<<(Laboratorio &l, const Computadora &c){
        l.agregarFinal(c);

        return l;
    }
};

#endif