#ifndef __MOMENTUM_H__
#define __MOMENTUM_H__

#include <TObject.h>


class Momentum : public TObject {
    public:
     Momentum(); // default constructor
     Momentum(Int_t variable); // some other constructor
     virtual ~Momentum(); // destructor


    private:
     Int_t variable_;

     ClassDef(Momentum, 1); // your_class
};

#endif // __MOMENTUM_H__