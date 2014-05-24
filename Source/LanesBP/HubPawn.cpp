

#include "LanesBP.h"
#include "HubPawn.h"
#include "ConstructorHelpers.h"


AHubPawn::AHubPawn(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
  static ConstructorHelpers::FObjectFinder<UBlueprint> ShotOb(TEXT("Blueprint'/Game/Blueprints/Shot.Shot'"));
  if (ShotOb.Object != NULL)
  {
    Shot = (UClass*)ShotOb.Object->GeneratedClass;
  }
}

/*
 * SpawnShot()
 * PRECONDITION:  Player Hub exists and is being controlled by some entity.
 * POSTCONDITION: A new projectile is spawned with the current Hub as the owner.
 */
void AHubPawn::SpawnShot() {
  
  if (!Shot) return;
  
  // Get the current hub pawn
  FTransform currentTransform = GetTransform();
  
  // Get the vector of the pawn
  FVector pawnVector = currentTransform.GetTranslation();
  
  // Generate new vector based on rules
  FVector shotVector = FVector(pawnVector.X, pawnVector.Y + (DistanceMultiplier * ShotWidth), pawnVector.Z);
  
  FTransform shotTransform = FTransform(shotVector);
  
  // Spawn the projectile with the new vector
  GetWorld()->SpawnActor(Shot);
}


