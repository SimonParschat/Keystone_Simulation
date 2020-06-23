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

/// \file muonSDSimSteppingAction.cc
/// \brief Implementation of the muonSDSimSteppingAction class

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "muonSDSimSteppingAction.hh"
#include "muonSDSimEventAction.hh"
#include "muonSDSimDetectorConstruction.hh"
#include "muonSDSimAnalysis.hh"

#include "G4Step.hh"
#include "G4Event.hh"
#include "G4StepPoint.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "math.h"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

muonSDSimSteppingAction::muonSDSimSteppingAction(muonSDSimEventAction* eventAction)
: G4UserSteppingAction(),
    fEventAction(eventAction),
    fScoringVolume(0)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

muonSDSimSteppingAction::~muonSDSimSteppingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void muonSDSimSteppingAction::UserSteppingAction(const G4Step* step)
{
    G4double edep = step->GetTotalEnergyDeposit();
    if (edep <= 0.) return;

    G4StepPoint* prePoint  = step->GetPreStepPoint();
    G4StepPoint* postPoint = step->GetPostStepPoint();

    const muonSDSimDetectorConstruction* detectorConstruction
            = static_cast<const muonSDSimDetectorConstruction*>
                (G4RunManager::GetRunManager()->GetUserDetectorConstruction());

    if (!fScoringVolume)
    { 
        fScoringVolume = detectorConstruction->GetScoringVolume();
    }

    // get volume of the current step
    G4LogicalVolume* volume 
        = step->GetPreStepPoint()->GetTouchableHandle()
            ->GetVolume()->GetLogicalVolume();

        
    // check if we are in scoring volume
    if (volume == fScoringVolume)
    {
        G4double t1 = prePoint->GetGlobalTime();
        G4double t2 = postPoint->GetGlobalTime();
 
        if (t1 >= 0){
            fEventAction->MuonTime(t1);
            
            if (postPoint->GetStepStatus() == fGeomBoundary) {
                fEventAction->GammaTime(t2);
            }
        }
    };
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
