// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "EscapeRoomSolo.h"
#include "EscapeRoomSoloHUD.h"
#include "Engine/Canvas.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "Timer.h"

AEscapeRoomSoloHUD::AEscapeRoomSoloHUD()
{
	// Set the crosshair texture
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshiarTexObj(TEXT("/Game/FirstPerson/Textures/FirstPersonCrosshair"));
	CrosshairTex = CrosshiarTexObj.Object;
	
	
	
}


void AEscapeRoomSoloHUD::DrawHUD()
{
	Super::DrawHUD();
	FLinearColor TextColor = FColor::Red;
	// Draw very simple crosshair

	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition( (Center.X),
										   (Center.Y));

	// draw the crosshair
	FCanvasTileItem TileItem( CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem( TileItem );

	

	StartTimer = GetWorld()->GetTimeSeconds();
	
	time= FinishTimer - StartTimer;
	int32 FloToint = time;
	//Float en String
	FString FloToStr = FString::FromInt(FloToint);
	//FString FloToStr = FString::SanitizeFloat(time);
	//Draw Compteur
	
	
	if (time > 0) {
		DrawLine(32.0, 32.0, time+32, 32.0, FColor::Red, 10.0);
		
	}

	if (time <= 0) {
		
		DrawText("Vous avez perdu", TextColor, Center.X - 60, Center.Y - 30, NULL, 2.0f, false);

	}
}

