#ifndef FRIGE_H_EA8DLUSZ
#define FRIGE_H_EA8DLUSZ

#include <string>
#include <memory>

class Frige 
{
  public:
    Frige();
    virtual ~Frige();
    void cooldown(std::string degree); 
  private:
    class FrigeImpl;
    std::unique_ptr<FrigeImpl> _impl;
};

#endif /* end of include guard: FRIGE_H_EA8DLUSZ */
