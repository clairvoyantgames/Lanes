

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
  double ShotWidth;
  
  UPROPERTY()
  UClass *Shot;
  
  bool *LaneStatus;

  UFUNCTION(BlueprintCallable, Category="Shot")
  void SpawnShot(uint32 laneNumber, uint32 laneOffset);
	
};
