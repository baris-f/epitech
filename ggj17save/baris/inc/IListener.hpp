#ifndef ILISTENER_HPP_
# define ILISTENER_HPP_

class IListener {
public:
  virtual ~IListener(){}
  virtual void func() = 0;
};

#endif /* !ILISTENER_HPP_ */
