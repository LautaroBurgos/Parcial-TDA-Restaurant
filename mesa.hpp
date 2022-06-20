#ifndef MESA_H_
#define MESA_H_

enum EstadoMesa{
	Vacia,
	Ocupada,
	Inhabilitada
};

class Mesa{
	private:
		EstadoMesa estadoMesa;
		unsigned int cantSillasActual;
		unsigned int maxCantSillasHist;
	public:
		/*
			PRE:
			POST: Crea una silla, con 4 sillas y estado Vacia.
		*/
		Mesa();
		/*
			PRE: El EstadoMesa recibido tiene que ser valido, Vacia, Ocupada o Inhabilitada.
			POST: Establece el estado de una mesa, pero en caso de que ya este en ese estado arroja una excepcion.
		*/
		void setEstado(EstadoMesa estado);
		/*
			PRE:
			POST: Devuelve el estado actual de una Mesa.
		*/
		EstadoMesa getEstado();
		/*
			PRE:
			POST: Devuelve el maximo historico de sillas que tuvo una mesa.
		*/
		int getMaxSillasHist();
		/*
			PRE:
			POST: Suma 1 a cantSillasActual y tambien suma 1 a cantSillasHist.
		*/
		void agregarSilla();
		/*
			PRE:
			POST: Devuelve la cantidad de sillas actual de una mesa.
		*/
		int getCantSillasActual();
		/*
			PRE:
			POST: Resta 1 a cantSillasActual.
		*/
		void eliminarSilla();
		/*
			PRE:
			POST: Destructor de la clase.
		*/
		virtual ~Mesa();
};

#endif