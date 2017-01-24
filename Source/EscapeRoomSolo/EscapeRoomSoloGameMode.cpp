// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "EscapeRoomSolo.h"
#include "EscapeRoomSoloGameMode.h"
#include "EscapeRoomSoloHUD.h"
#include "EscapeRoomSoloCharacter.h"

AEscapeRoomSoloGameMode::AEscapeRoomSoloGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AEscapeRoomSoloHUD::StaticClass();
}
