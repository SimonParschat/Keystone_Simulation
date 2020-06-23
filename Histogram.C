{
  gROOT->Reset();
  
  // Draw histos filled by Geant4 simulation 
  TFile f("/Users/Simon/Desktop/KeystoneBlock/Keystone/keystoneSIm/newBuild/muonSDSim_output.root");  
  TCanvas* c1 = new TCanvas("c1", "Muon Decay Signal Time Difference");

  TH1D* hist1 = (TH1D*)f.Get("deltaTime");
  hist1->SetYTitle ("Counts");
  hist1->SetXTitle ("Pulse Time Difference (\mu s)");
  hist1->GetYaxis()->SetTitleOffset(1.4);
  hist1->Draw("HIST SAME E");
}  