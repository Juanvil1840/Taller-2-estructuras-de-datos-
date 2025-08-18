#ifndef __POLINOMIO__HXX__
#define __POLINOMIO__HXX__


// -------------------------------------------------------------------------
template < class S > 
Polinomio<S>::
Polinomio( )
{
}

// -------------------------------------------------------------------------
template < class S > 
Polinomio<S>::
~Polinomio( )
{
}

// -------------------------------------------------------------------------
template < class S > 
void Polinomio<S>::FijarCoeficiente( unsigned int grado, const S& coeficiente )
{
  if( grado >= this->size( ) )
    this->resize( grado + 1, S( 0 ) );
  ( *this )[ grado ] = coeficiente;
}

// -------------------------------------------------------------------------
template < class S > 
Polinomio<S> Polinomio<S>::operator+( const Polinomio< S >& der ) const //Agregado por Lina Perez
{
  Polinomio<S> resultado;
  //Agregado por Juan Mendoza
  // TODO #1
  // Encuentra el mayor grado entre los dos polinomios 
  unsigned int maxGradoIzq = this->size();
  unsigned int maxGradoDer = der.size();
  unsigned int maxGrado = std::max(maxGradoIzq, maxGradoDer);

  // Ajusta el tamaño del polinomio resultado con ceros
  resultado.resize(maxGrado, S(0));

  // Suma coeficientes grado a grado
  for (unsigned int i = 0; i < maxGrado; ++i) {
    S coefIzq, coefDer;

    // Obtener coeficiente del polinomio izquierdo
    if (i < maxGradoIzq)
    coefIzq = (*this)[i];
    else
    coefIzq = S(0);

    // Obtener coeficiente del polinomio derecho
    if (i < maxGradoDer)
    coefDer = der[i];
    else
    coefDer = S(0);

    // Guardar la suma en el resultado
    resultado[i] = coefIzq + coefDer;
    }

  return resultado;
}

// -------------------------------------------------------------------------
template < class S > 
Polinomio<S> Polinomio<S>::operator*( const Polinomio< S >& der ) const
{
  //Agregado por Lina Perez
  Polinomio<S> resultado;

  // TODO #2
  // Encuentra el mayor grado entre los dos polinomios
  // Este sera el numero de multiplicaciones que toca hacer por cada termino en el polinomio 
  unsigned int maxGradoIzq = this->size();
  unsigned int maxGradoDer = der.size();
  unsigned int maxGrado = std::max(maxGradoIzq, maxGradoDer);

  // Ajusta el tamaño del polinomio con el grado menor
  Polinomio<S> auxizq = *this;
  Polinomio<S> auxder = der;
  if( maxGrado > this->size( ) ){
    auxizq.resize( maxGrado, S( 0 ) );
  } else {
    auxder.resize( maxGrado, S( 0 ) );
  }

  std::vector<Polinomio<S> > multiplicacionesPorTermino;

  //Primer ciclo recorre el polinomio de la izquierda
  for(int i = 0; i < maxGrado; i++){

    Polinomio <S> multiplicacion;

    //Segundo ciclo recorre el polinomio de la derecha 
    for(int j = 0; j < maxGrado; j++){ 
      
      if((i + j) >= multiplicacion.size() ){
        multiplicacion.resize( (i + j) + 1 , S( 0 ) );
      }

      multiplicacion[i+j] = (auxizq[i]) * (auxder[j]);
      
    }

    multiplicacionesPorTermino.push_back(multiplicacion);
  }

  // Establecer el grado del resultado
  unsigned int gradoResultado = 0;
  
  // Recorre multiplicacionesPorTermino
  // multiplicacionesPorTermino.size() es igual a maxGrado porque fue planeado para que asi fuera
  for(int i = 0; i < maxGrado; i ++){
      
    //Encuentra el grado mas grande para todas las multiplicaciones
    if(multiplicacionesPorTermino[i].size() > gradoResultado){
      gradoResultado = multiplicacionesPorTermino[i].size();     
    }
  }

  resultado.resize(gradoResultado, S(0) );

  // Sumar el resultado de cada una de las multiplicaciones termino por termino
  // Recorre multiplicacionesPorTermino
  for(int i = 0; i < maxGrado; i ++) {
    resultado = resultado + multiplicacionesPorTermino[i];
  }

  return resultado;
}

// -------------------------------------------------------------------------
template < class S > 
S Polinomio<S>::operator()( const S& x ) const
{
  S resultado = S( 0 );

  // TODO #3

  return resultado;
}

#endif // __POLINOMIO__HXX__

// eof - Polinomio.hxx
