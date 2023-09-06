#ifndef FIND_H_
# define FIND_H_

#include <iostream>
#include <algorithm>
#include <vector>

template<class InputIt> typename InputIt::iterator
do_find(InputIt& ref, int bite){
  return (std::find( ref.begin(), ref.end(), bite));
}

#endif /* !FIND_H_ */
