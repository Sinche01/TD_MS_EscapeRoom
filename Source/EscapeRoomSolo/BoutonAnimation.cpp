// Fill out your copyright notice in the Description page of Project Settings.

#include "EscapeRoomSolo.h"
#include "BoutonAnimation.h"


// Sets default values for this component's properties
UBoutonAnimation::UBoutonAnimation()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBoutonAnimation::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();
	// ...
	
}


// Called every frame
void UBoutonAnimation::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );


	if (!PressurePlate) {
		return;
	}
	//Recupère le triggerVolume et si le pawn héritant d'actor passe dans le triggerVolume OpenDoor
	if (PressurePlate->IsOverlappingActor(ActorThatOpen)) {

		Descendre();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}

	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > Delay) {

		Monte();
	}
	// ...
}

void UBoutonAnimation::Monte()
{
	CurentLocation = Owner->GetActorLocation();

	if (CurentLocation.Z < StartLocation) {
		CurentLocation.Z += speed;
		Owner->SetActorLocation(CurentLocation);
	}

	
}

void UBoutonAnimation::Descendre()
{

	CurentLocation = Owner->GetActorLocation();

	if (CurentLocation.Z > FinishLocation) {
		CurentLocation.Z -= speed;
		Owner->SetActorLocation(CurentLocation);
	}

	
	// ...

}