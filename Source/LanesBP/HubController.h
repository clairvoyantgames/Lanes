

#pragma once

#include "GameFramework/PlayerController.h"
#include "HubController.generated.h"

/**
 *
 */
UCLASS()
class AHubController : public APlayerController
{
	GENERATED_UCLASS_BODY()
  
protected:
  virtual void SetupInputComponent() OVERRIDE;
  
  void ToggleLane1();
  void ToggleLane2();
  void ToggleLane3();
  void ToggleLane4();
  void ToggleLane5();
  void ToggleLane6();
  void ToggleLane7();
  void ToggleLane(uint32 laneNumber, uint32 laneOffset);
};
