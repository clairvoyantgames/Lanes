

#pragma once

#include "GameFramework/Pawn.h"
#include "HubPawn.generated.h"

/**
 * Class to control the player hub
 */
UCLASS()
class AHubPawn : public APawn
{
	GENERATED_UCLASS_BODY()
  
  UPROPERTY()
  double DistanceMultiplier;
  
  UPROPERTY()
  double ShotWidth;
  
  UPROPERTY()
  UClass *Shot;

protected:
  UFUNCTION(BlueprintCallable, Category="Shot")
  void SpawnShot();
	
};
