// Fill out your copyright notice in the Description page of Project Settings.

#include "EscapeRoomSolo.h"
#include "OpenActor.h"


// Sets default values for this component's properties
// Sets default values for this component's properties
UOpenActor::UOpenActor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	

	// ...
}


// Called when the game starts
void UOpenActor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	Owner = GetOwner();
	

}


// Called every frame
void UOpenActor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (!PressurePlate) {
		return;
	}
	//Recupère le triggerVolume et si le pawn héritant d'actor passe dans le triggerVolume OpenDoor
	if (PressurePlate->IsOverlappingActor(ActorThatOpen)) {

		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}

	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > Delay) {

		CloseDoor();
	}


}

void UOpenActor::OpenDoor()
{


	Owner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));

}

void UOpenActor::CloseDoor()
{



	Owner->SetActorRotation(FRotator(0.0f, StartAngle, 0.0f));

}


