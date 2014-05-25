

#include "LanesBP.h"
#include "HubController.h"
#include "HubPawn.h"


AHubController::AHubController(const class FPostConstructInitializeProperties& PCIP)
: Super(PCIP)
{
  
}

void AHubController::SetupInputComponent() {
  Super::SetupInputComponent();
  
  check(InputComponent);
  
  if (InputComponent != NULL) {
    InputComponent->BindAction("Lane1", IE_Pressed, this, &AHubController::ToggleLane1);
    InputComponent->BindAction("Lane2", IE_Pressed, this, &AHubController::ToggleLane2);
    InputComponent->BindAction("Lane3", IE_Pressed, this, &AHubController::ToggleLane3);
    InputComponent->BindAction("Lane4", IE_Pressed, this, &AHubController::ToggleLane4);
    InputComponent->BindAction("Lane5", IE_Pressed, this, &AHubController::ToggleLane5);
    InputComponent->BindAction("Lane6", IE_Pressed, this, &AHubController::ToggleLane6);
    InputComponent->BindAction("Lane7", IE_Pressed, this, &AHubController::ToggleLane7);
  }
}

void AHubController::ToggleLane1() {
  ToggleLane(0, -3);
}

void AHubController::ToggleLane2() {
  ToggleLane(1, -2);
}

void AHubController::ToggleLane3() {
  ToggleLane(2, -1);
}

void AHubController::ToggleLane4() {
  ToggleLane(3, 0);
}

void AHubController::ToggleLane5() {
  ToggleLane(4, 1);
}

void AHubController::ToggleLane6() {
  ToggleLane(5, 2);
}

void AHubController::ToggleLane7() {
  ToggleLane(6, 3);
}

/*
 * ToggleLane(int laneNumber)
 * PRECONDITION:  Controller exists and is accepting input
 * POSTCONDITION: Lane is activated
 */
void AHubController::ToggleLane(uint32 laneNumber, uint32 laneOffset) {
  // Get the current controller's pawn
  AHubPawn *Pawn = (AHubPawn *)GetPawn();
  
  // Check lane status
  if (Pawn->LaneStatus[laneNumber]) {
    
  } else {
    Pawn->SpawnShot(laneNumber, laneOffset);
  }
}