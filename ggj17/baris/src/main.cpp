//
// main.cpp for  in /home/fus/taff/ggj17/sfml/src
//
// Made by Gaspard Thirion
// Login   <thirio_b@epitech.net>
//
// Started on  Sat Jan 14 20:43:04 2017 Gaspard Thirion
// Last update Sun Jan 22 13:40:50 2017 Duval Lucas
//

#include <thread>

#include "Data.hpp"
Data *data;
#include "init.hpp"
#include "thread.hpp"

int	main()
{
  data = new Data;
  initData();
  initTexture();
  initSound();
  initUnitAndButton();
  all(data);
  /*
    std::thread	renderThread(render, data);
    std::thread   updateThread(update, data);
    updateThread.join();
    renderThread.join();
  */
  return (0);
}
