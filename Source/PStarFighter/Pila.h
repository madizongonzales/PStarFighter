// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <iostream> 
using namespace std;

template<class T>

class Pila
{
private:
	T* Datos;

	//vector<T> datos; 

	int Cima;
	const int numeroElementos;

public:
	Pila(int _numeroElementos) : numeroElementos(_numeroElementos) {
		Datos = new T[numeroElementos];
		Cima = -1;
	}
	~Pila() { delete[] Datos; }

	// funcion Push 
	void Insertar(T c);

	// funcion Pop 
	T Sacar();
	bool Vacia();
	bool Llena();

	int getCima() { return Cima; }
};

template<class T>
void Pila<T>::Insertar(T elementoInsertar) {
	if (!Llena()) {
		Cima++;
		Datos[Cima] = elementoInsertar;

		cout << "Se ha insertado satisfactoriamente" << endl;
	}
	else {
		cout << "No se pudo ingresar el elemento en la pila" << endl;
	}
}

template<class T>
T Pila<T>::Sacar() {
	if (!Vacia()) {
		T elementoSacar = Datos[Cima];
		Cima--;
		return elementoSacar;
	}
	else {
		cout << "No se pudo sacar el elemento de la pila" << endl;
	}
}

template<class T>
bool Pila<T>::Vacia() {
	if (Cima < 0) {
		return true;
	}
	else
		return false;
}

template<class T>
bool Pila<T>::Llena() {
	if (Cima < numeroElementos - 1) {
		return false;
	}
	else {
		return true;
	}

}
