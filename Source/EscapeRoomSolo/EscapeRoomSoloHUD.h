// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once 

#include "GameFramework/HUD.h"
#include "EscapeRoomSoloHUD.generated.h"


UCLASS()
class AEscapeRoomSoloHUD : public AHUD
{
	GENERATED_BODY()

public:
	AEscapeRoomSoloHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;
	float StartTimer;
	float time;
	// Called every frame
	
private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;
	float FinishTimer = 300.0f;
	UPROPERTY(EditAnywhere)
		ATriggerVolume *PressurePlate;
	
};

