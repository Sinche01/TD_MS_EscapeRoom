// Fill out your copyright notice in the Description page of Project Settings.

#include "EscapeRoomSolo.h"
#include "AscenseurScipt.h"


// Sets default values for this component's properties
UAscenseurScipt::UAscenseurScipt()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAscenseurScipt::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();


	// ...
	
}


// Called every frame
void UAscenseurScipt::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (!PressurePlate) {
		return;
	}
	//Recupère le triggerVolume et si le pawn héritant d'actor passe dans le triggerVolume OpenDoor
	if (PressurePlate->IsOverlappingActor(ActorThatOpen) && Owner->GetActorLocation().Z == StartLocation) {

		Monteb = true;
		
	}

	if (PressurePlate->IsOverlappingActor(ActorThatOpen) && Owner->GetActorLocation().Z == FinishLocation) {
		Descend =true;

	}

	if (Monteb ==true) {
		Monte();
	}

	if (Descend == true) {
		Descendre();
	}
	// ...
}

void UAscenseurScipt::Monte()
{
	CurentLocation = Owner->GetActorLocation();

	if (CurentLocation.Z < FinishLocation) {
	CurentLocation.Z += speed;
	Owner->SetActorLocation(CurentLocation);
	}

	if (CurentLocation.Z ==FinishLocation) {
		Monteb = false;
	}
}

void UAscenseurScipt::Descendre()
{
	
	CurentLocation = Owner->GetActorLocation();

	if (CurentLocation.Z > StartLocation) {
		CurentLocation.Z -= speed;
		Owner->SetActorLocation(CurentLocation);
	}

	if (CurentLocation.Z == StartLocation) {
		Descend = false;
	}
	// ...

}


