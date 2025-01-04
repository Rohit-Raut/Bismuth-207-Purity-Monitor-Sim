#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "QGSP_BERT.hh"
#include "include/DetectorConstruction.hh"
#include "include/PhysicsList.hh"
#include "include/PrimaryGeneratorAction.hh"

int main(int argc, char** argv)
{
    G4RunManager* runManager = new G4RunManager;
    runManager->SetUserInitialization(new DetectorConstruction);
    runManager->SetUserInitialization(new PhysicsList);

    runManager->SetUserAction(new PrimaryGeneratorAction);

    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialize();

    G4UIExecutive* ui = new G4UIExecutive(argc, argv);
    G4UImanager* UImanager = G4UImanager::GetUIpointer();
    UImanager->ApplyCommand("/control/execute vis.mac");
    ui->SessionStart();
    delete ui;
    delete visManager;
    delete runManager;
    return 0;
}