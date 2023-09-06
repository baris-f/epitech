#ifndef KREOGCOM_H_
# define KREOGCOM_H_

#include <iostream>

class KreogCom
{
 public:
  KreogCom(int x, int y, int serial);
  ~KreogCom();

 public:
  void addCom(int x, int y, int serial);
  KreogCom *getCom();
  void removeCom();

 public:
  void ping() const;
  void locateSquad() const;
  void locateSquad2();

 private:
  KreogCom	*_next;
  int		_serial;
  int	_x;
  int	_y;
  //const	int	m_serial;
};

#endif /* !KREOGCOM_H_ */
