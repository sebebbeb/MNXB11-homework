#include "Momentum.h"
ClassImp(Momentum)  // ROOT-specific macro to enable runtime type information

// Default constructor - initialize member variables to default values
Momentum::Momentum() : variable_(0), px(0), py(0), pz(0){
    // Constructor body, can be left empty for now
}

// Constructor with parameter
Momentum::Momentum(Int_t variable) : variable_(variable), px(0), py(0), pz(0) {
    // Constructor body, initialize variable_ with parameter
}

// Destructor
Momentum::~Momentum() {
    // Destructor body, can be left empty for now
}

Double_t Momentum::GetMomentumMagnitude() const {
    return std::sqrt(px * px + py * py + pz * pz);
}

