#include "mesa.hpp"

Mesa::Mesa(){
	this->cantSillasActual=4;
	this->estadoMesa=Vacia;
	this->maxCantSillasHist=4;
}
void Mesa::setEstado(EstadoMesa estado){
	this->estadoMesa=estado;
}
EstadoMesa Mesa::getEstado(){
	return (this->estadoMesa);
}
int Mesa::getMaxSillasHist(){
	return (this->maxCantSillasHist);
}
void Mesa::agregarSilla(){
	this->cantSillasActual +=1;
	this->maxCantSillasHist+=1;
}
int Mesa::getCantSillasActual(){
	return (this->cantSillasActual);
}
void Mesa::eliminarSilla(){
	this->cantSillasActual -=1;
}
Mesa::~Mesa(){

}
