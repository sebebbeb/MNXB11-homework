#include "Momentum.h"
#include <TFile.h>
#include <TTree.h>
#include <TRandom.h>

void write() {
    const Int_t nEvents = 1000;

    Momentum *particle = new Momentum();

    TFile *file = new TFile("tree_file.root", "RECREATE");

    TTree *tree = new TTree("tree", "A tree with Particle objects");

    tree->Branch("ParticleBranch", &particle);

    for (Int_t i = 0; i < nEvents; ++i) {
        particle->px = gRandom->Gaus(0, 0.02);
        particle->py = gRandom->Gaus(0, 0.02);
        particle->pz = gRandom->Gaus(0, 0.02);
        Double_t magnitude = particle->GetMomentumMagnitude();

        tree->Fill();
    }

    tree->Write();
    file->Close();

    delete particle;
    delete file;
}
