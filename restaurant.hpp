#ifndef RESTAURANT_H_
#define RESTAURANT_H_
#include "mesa.hpp"
#include "lista.hpp"

enum EstadoRestaurant{
	Cerrado,
	Abierto
};

class Restaurant{
	private:
		Lista<Mesa*>* mesas;
		EstadoRestaurant estadoRestaurant;
		unsigned int maxMesasPosibles;
		unsigned int maxMesasHist;
		unsigned int cantMesasActual;
	public:
		/*
			PRE:
			POST: Crea un Restaurant,inicialmente su estado es Abierto y con 0 mesa.
		*/
		Restaurant(unsigned int maxMesasPosibles);
		/*
			PRE:
			POST: Devuelve el estado actual del Restaurant.
		*/
		EstadoRestaurant getEstado();
		/*
			PRE: El EstadoRestaurant recibido debe ser valido.
			POST:Establece el estado del Restaurant, pero si ya se encuentra en ese estado, arroja una excepcion.
		*/
		void setEstado(EstadoRestaurant estado);
		/*
			PRE:
			POST: Devuelve la cantidad de mesas actual del restaurant.
		*/
		int getCantMesasActual();
		/*
			PRE:
			POST: Devuelve la cantidad maxima posible de mesas, establecida por el usuario en el constructor de la clase.
		*/
		int getMaxMesasPosibles();
		/*
			PRE:
			POST: Agrega una mesa al final de la lista de mesas, pero si ya se alcanzo el maximo posible  de mesas arroja una
			excepcion.
		*/		
		void agregarMesa();
		/*
			PRE:
			POST: Elimina la ultima mesa de la lista de mesas, como minimo puede haber 0 mesas.
		*/
		void eliminarMesa();
		/*
			PRE:
			POST: Devuelve el maximo historico de mesas que tuvo el Restaurant.
		*/		
		int getMaxMesasHist();
		/*
			PRE:la posicion recibida debe estar entre 1 y la cantidad de mesas actual.
			POST: Devuelve el puntero a la mesa que esta en la posicion seleccionada.
		*/		
		Mesa* getMesa(unsigned int posicion);
		/*
			PRE:
			POST: Destructor de la clase.
		*/	
		virtual~Restaurant();
};
#endif