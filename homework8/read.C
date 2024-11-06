#include "Momentum.h"
#include <TFile.h>
#include <TTree.h>
#include <TH2D.h>
#include <TCanvas.h>


void read() {
    TFile *file = TFile::Open("tree_file.root");
    if (!file || file->IsZombie()){
        std::cerr << "Error: Could not open tree_file.root" << std::endl;
        return;
    }

    TTree *tree = (TTree*)file->Get("tree");
    if (!tree){
        std::cerr << "Error: Could not find TTree 'tree'" << std::endl;
        file->Close();
        return;
    }

    Momentum *particle = new Momentum();
    tree->SetBranchAddress("ParticleBranch", &particle);

    TH2D *h_px_py = new TH2D("h_px_py", "px vs py;px;py", 100, -0.05, 0.05, 100, -0.05, 0.05);

    Long64_t N = tree->GetEntries();
    for (Long64_t i = 0; i < N; ++i) {
        tree->GetEntry(i);

        h_px_py->Fill(particle->px, particle->py);
    }

    TCanvas *c1 = new TCanvas("c1", "Momentum Plots", 1200, 600);
    c1->Divide(2, 1);  

    c1->cd(1); 
    tree->Draw("px:py", "", "COLZ");  

    c1->cd(2);  
    tree->Draw("px*py:pz", "sqrt(px*px + py*py + pz*pz) > 0.01", "COLZ"); 


    delete particle;
    file->Close();

}