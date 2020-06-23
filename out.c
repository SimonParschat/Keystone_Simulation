#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TProfile.h"
#include "TRandom.h"
#include "TTree.h"

{
TCanvas *c1 = new TCanvas;
TFile* file = TFile::Open("/Users/Simon/Desktop/muonSDSim/build/muonSDSim_output.root");
EDepScint1->SetLineColor(2);
EDepScint2->SetLineColor(3);
EDepScint3->SetLineColor(4);
EDepHC->SetLineColor(2);
EDepScint1->SetFillColor(2);
EDepScint2->SetFillColor(3);
EDepScint3->SetFillColor(4);
EDepHC->SetFillColor(5);
EDepScint1->SetXTitle("Energy Deposited (MeV)");
EDepScint1->SetYTitle("# of Entries");
EDepScint1->SetLabelSize(0.018,"XY");
EDepScint2->SetLabelSize(0.018,"XY");
EDepScint3->SetLabelSize(0.018,"XY");
EDepHC->SetLabelSize(0.018,"XY");


EDepScint1->Draw("E HIST SAMES");
gPad->Update();

TPaveStats *tps1 = (TPaveStats*) EDepScint1->FindObject("stats");
tps1->SetName("Hist1 Stats");
double X1 = tps1->GetX1NDC();
double Y1 = tps1->GetY1NDC();
double X2 = tps1->GetX2NDC();
double Y2 = tps1->GetY2NDC();

EDepScint2->Draw("E HIST SAMES");
gPad->Update();

TPaveStats *tps2 = (TPaveStats*) EDepScint2->FindObject("stats");
tps2->SetTextColor(kBlack);
tps2->SetLineColor(kBlack);
tps2->SetX1NDC(X1);
tps2->SetX2NDC(X2);
tps2->SetY1NDC(Y1-(Y2-Y1));
tps2->SetY2NDC(Y1);

EDepScint3->Draw("E HIST SAMES");
gPad->Update();

TPaveStats *tps3 = (TPaveStats*) EDepScint3->FindObject("stats");
tps3->SetTextColor(kBlack);
tps3->SetLineColor(kBlack);
tps3->SetX1NDC(X1);
tps3->SetX2NDC(X2);
tps3->SetY1NDC(Y1-(Y2-Y1)-(Y2-Y1));
tps3->SetY2NDC(Y1-(Y2-Y1));

EDepHC->Draw("E HIST SAMES");
gPad->Update();

TPaveStats *tps4 = (TPaveStats*) EDepHC->FindObject("stats");
tps4->SetTextColor(kBlack);
tps4->SetLineColor(kBlack);
tps4->SetX1NDC(X1);
tps4->SetX2NDC(X2);
tps4->SetY1NDC(Y1-(Y2-Y1)-(Y2-Y1)-(Y2-Y1));
tps4->SetY2NDC(Y1-(Y2-Y1)-(Y2-Y1));

c1->SetTitle("Energy Deposited Histogram");
tps1->Draw("same");
tps2->Draw("same");
tps3->Draw("same");
tps4->Draw("same");
}