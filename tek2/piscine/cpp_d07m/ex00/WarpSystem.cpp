//
// WarpSystem.cpp for wap in /home/baris_f/rendu/tek2/cpp_d07m/ex00
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Tue Jan 10 09:52:54 2017 baris_f
// Last update Tue Jan 10 10:44:28 2017 baris_f
//

#include "WarpSystem.hh"

namespace WarpSystem {

  QuantumReactor::QuantumReactor()
  {
    _stability = true;
  }

  QuantumReactor::~QuantumReactor()
  {

  }

  bool	QuantumReactor::isStable()
  {
    return (_stability);
  }

  void	QuantumReactor::setStability(bool state)
  {
    _stability = state;
  }

  Core::Core(QuantumReactor *newreactor)
  {
    _coreReactor = newreactor;
  }

  Core::~Core()
  {
  }

  QuantumReactor	*Core::checkReactor()
  {
    return (_coreReactor);
  }
}
