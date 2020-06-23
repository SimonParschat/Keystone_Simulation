// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************

/// \file muonSDSimEventAction.cc
/// \brief Implementation of the muonSDSimEventAction class

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "muonSDSimEventAction.hh"
#include "muonSDSimRunAction.hh"
#include "muonSDSimAnalysis.hh"

#include "G4Event.hh"
#include "G4THitsMap.hh"
#include "G4SDManager.hh"
#include "G4RunManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

muonSDSimEventAction::muonSDSimEventAction()
: G4UserEventAction(),
    fEdep(0.),
    fMuonTime(0.),
    fGammaTime(0.),
    fGammaCount(0.),
    fCollID_scint(-1)
{} 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

muonSDSimEventAction::~muonSDSimEventAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void muonSDSimEventAction::BeginOfEventAction(const G4Event*)
{    
    fMuonTime    = 0.;
    fGammaTime   = 0.;
    fGammaCount  = 0.;
    edep   = 0.;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void muonSDSimEventAction::EndOfEventAction(const G4Event* evt)
{   
    // get analysis manager
    auto analysisManager = G4AnalysisManager::Instance();
    // G4cout << "Muon time " << fMuonTime << G4endl;

    if (fGammaCount > 0) {
        G4double deltaTime = ((fGammaTime/fGammaCount) - fMuonTime);
        if (deltaTime > 0){
            analysisManager->FillH1(0, deltaTime);
        }
    }

    // fill histograms
    // analysisManager->FillH1(0, fMuonTime);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
