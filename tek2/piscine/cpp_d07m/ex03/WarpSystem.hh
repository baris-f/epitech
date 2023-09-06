#ifndef WARPSYSTEM_HH_
 #define WARPSYSTEM_HH_

namespace WarpSystem {
  class QuantumReactor {
  public :
    QuantumReactor();
    ~QuantumReactor();
  private :
    bool	_stability;
  public :
    bool	isStable();
    void	setStability(bool);
  };
  class Core {
  public :
    Core(QuantumReactor *);
    ~Core();
  private :
    QuantumReactor	*_coreReactor;
  public :
    QuantumReactor	*checkReactor();
  };
};

#endif /* WARPSYSTEM_HH_*/
