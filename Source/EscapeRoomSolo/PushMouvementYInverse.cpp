// Fill out your copyright notice in the Description page of Project Settings.

#include "EscapeRoomSolo.h"
#include "PushMouvementYInverse.h"


// Sets default values for this component's properties
UPushMouvementYInverse::UPushMouvementYInverse()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPushMouvementYInverse::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();
	// ...
	
}


// Called every frame
void UPushMouvementYInverse::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );


	if (Activateur->IsOverlappingActor(ActorThatOpen) && Owner->GetActorLocation().Y == StartLocation) {

		Monteb = true;

	}

	if (Activateur->IsOverlappingActor(ActorThatOpen) && Owner->GetActorLocation().Y == FinishLocation) {
		Descend = true;

	}
	if (Monteb == true) {
		Avance();
	}

	if (Descend == true) {
		Recule();
	}
	// ...
}

void UPushMouvementYInverse::Avance()
{
	CurentLocation = Owner->GetActorLocation();

	if (CurentLocation.Y > FinishLocation) {
		CurentLocation.Y -= speed;
		Owner->SetActorLocation(CurentLocation);
	}

	if (CurentLocation.Y == FinishLocation) {
		Monteb = false;
	}
}

void UPushMouvementYInverse::Recule()
{

	CurentLocation = Owner->GetActorLocation();

	if (CurentLocation.Y < StartLocation) {
		CurentLocation.Y += speed;
		Owner->SetActorLocation(CurentLocation);
	}

	if (CurentLocation.Y == StartLocation) {
		Descend = false;
	}
	// ...

}