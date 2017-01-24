// Fill out your copyright notice in the Description page of Project Settings.

#include "EscapeRoomSolo.h"
#include "PushMouvementY.h"


// Sets default values for this component's properties
UPushMouvementY::UPushMouvementY()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPushMouvementY::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();
	// ...
	
}


// Called every frame
void UPushMouvementY::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
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

void UPushMouvementY::Avance()
{
	CurentLocation = Owner->GetActorLocation();

	if (CurentLocation.Y < FinishLocation) {
		CurentLocation.Y += speed;
		Owner->SetActorLocation(CurentLocation);
	}

	if (CurentLocation.Y == FinishLocation) {
		Monteb = false;
	}
}

void UPushMouvementY::Recule()
{

	CurentLocation = Owner->GetActorLocation();

	if (CurentLocation.Y > StartLocation) {
		CurentLocation.Y -= speed;
		Owner->SetActorLocation(CurentLocation);
	}

	if (CurentLocation.Y == StartLocation) {
		Descend = false;
	}
	// ...

}

void UPushMouvementY::Start() {

	CurentLocation = Owner->GetActorLocation();

	if (CurentLocation.Y == StartLocation) {
		Monteb = true;
	}

	if (CurentLocation.Y == FinishLocation) {
		Descend = true;
	}

}