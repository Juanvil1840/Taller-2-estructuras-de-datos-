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
Polinomio<S> Polinomio<S>::operator*( const Polinomio< S >& der ) const //Agregado por Lina Perez
{
  Polinomio<S> resultado;

  // TODO #2

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
