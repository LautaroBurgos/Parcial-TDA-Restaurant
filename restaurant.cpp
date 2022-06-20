#include "restaurant.hpp"

Restaurant::Restaurant(unsigned int maxMesasPosibles){
	this->estadoRestaurant=Abierto;
	this->cantMesasActual=0;
	this->maxMesasPosibles=maxMesasPosibles;
	this->maxMesasHist=0;
	this->mesas = new Lista<Mesa*>();
}
EstadoRestaurant Restaurant::getEstado(){
	return (this->estadoRestaurant);
}
void Restaurant::setEstado(EstadoRestaurant estado){
	if(this->getEstado()==estado){
		if(estado==Abierto){
			throw "El restaurant ya se encontraba abierto.";
		}
		else{
			throw "El restaurant ya se encontraba cerrado.";
		}
	}
	this->estadoRestaurant=estado;
} 

int Restaurant::getCantMesasActual(){
	return (this->mesas->contarElementos());
}
int Restaurant::getMaxMesasPosibles(){
	return this->maxMesasPosibles;
}
void Restaurant::agregarMesa(){

	if(this->getEstado()==Abierto){
		if(this->getCantMesasActual()<this->getMaxMesasPosibles()){
			Mesa* nuevaMesa=new Mesa();
			this->mesas->add(nuevaMesa);
			this->maxMesasHist+=1;
		}
		else{
			throw "Ya se alcanzo el maximo de mesas posibles.";
		}
	}
	else{
		throw "El restaurant esta cerrado.";
	}
}
void Restaurant::eliminarMesa(){
	if(this->getEstado()==Abierto){
		if(this->getCantMesasActual()==0){
			throw "Ya se alcanzo el minimo de mesas posibles.";
		}
		this->mesas->remover(this->getCantMesasActual());
	}
	else{
		throw "El restaurant esta cerrado.";
	}
}
int Restaurant::getMaxMesasHist(){
	return this->maxMesasHist;
}

Mesa* Restaurant::getMesa(unsigned int posicion){
	return (this->mesas->get(posicion));
}
Restaurant::~Restaurant(){
	for(int i=1;i<this->mesas->contarElementos();i++){
		this->mesas->remover(i);
	}
	delete this->mesas;
}