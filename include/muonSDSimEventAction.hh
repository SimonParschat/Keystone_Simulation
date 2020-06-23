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

/// \file muonSDSimEventAction.hh
/// \brief Definition of the muonSDSimEventAction class

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef muonSDSimEventAction_h
#define muonSDSimEventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"

class muonSDSimRunAction;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

/// Event action class

class muonSDSimEventAction : public G4UserEventAction
{
  	public:
		muonSDSimEventAction();
		virtual ~muonSDSimEventAction();

		virtual void BeginOfEventAction(const G4Event* event);
		virtual void EndOfEventAction(const G4Event* event);

		void AddEdep(G4double eDep) {
			fEdep += eDep;
		}
		
		void MuonTime(G4double time) {
			if (muonCount < 1) fMuonTime = time;
			muonCount += 1;
		}
		
		void GammaTime(G4double time) {
			fGammaTime += time;
			fGammaCount += 1;
		}

  	private:
   	 	// muonSDSimRunAction* fRunAction;
    	G4double     fEdep;
		G4double     muonCount = 0;
		G4double     fMuonTime;
		G4double     fGammaTime;
		G4double     fGammaCount;
		G4double 	 edep;
		G4int fCollID_scint;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
