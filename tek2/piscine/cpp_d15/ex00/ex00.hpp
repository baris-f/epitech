#ifndef _EX00_HPP_
# define _EX00_HPP_

template<typename Type>
void	swap(Type & operande1, Type & operande2)
{
  Type tmp = operande1;
  operande1 = operande2;
  operande2 = tmp;
}

template<typename Type>
Type min(Type & operande1, Type & operande2)
{
  if (operande1 < operande2)
    return (operande1);
  else
    return (operande2);
}

template<typename Type>
Type	max(Type & operande1, Type & operande2)
{
  if (operande1 > operande2)
    return (operande1);
  else
    return (operande2);
}

template<typename T>
T	add(T a, T b)
{
  return (a + b);
}

#endif /* !_EX00_HPP_ */
