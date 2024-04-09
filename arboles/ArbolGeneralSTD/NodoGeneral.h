#ifndef NODOGENERAL_H   
#define NODOGENERAL_H
#include <List>

template <class T>
class NodoGeneral {
 protected:
  int id; 
  T dato;
  std::list<NodoGeneral<T>*> desc;

 public:
  NodoGeneral();
  ~NodoGeneral();
  int getId();
  void setId(int nuevoId); 
  T& getDato();
  void setDato(T& val);
  void limpiarLista();
  void adicionarDesc(T& nval);
  void eliminarDesc(T& val);
};

#endif