// Fill out your copyright notice in the Description page of Project Settings.

#include "EscapeRoomSolo.h"
#include "PushmouvementXTimer.h"


// Sets default values for this component's properties
UPushmouvementXTimer::UPushmouvementXTimer()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPushmouvementXTimer::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPushmouvementXTimer::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (Activateur->IsOverlappingActor(ActorThatOpen) && Owner->GetActorLocation().X == StartLocation) {

		Monteb = true;

	}

	if (Activateur->IsOverlappingActor(ActorThatOpen) && Owner->GetActorLocation().X == FinishLocation) {
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

void UPushmouvementXTimer::Avance()
{
	CurentLocation = Owner->GetActorLocation();

	if (CurentLocation.X > FinishLocation) {
		CurentLocation.X -= speed;
		Owner->SetActorLocation(CurentLocation);
	}

	if (CurentLocation.X == FinishLocation) {
		Monteb = false;
	}
}

void UPushmouvementXTimer ::Recule()
{

	CurentLocation = Owner->GetActorLocation();

	if (CurentLocation.X < StartLocation) {
		CurentLocation.X += speed;
		Owner->SetActorLocation(CurentLocation);
	}

	if (CurentLocation.X == StartLocation) {
		Descend = false;
	}
	// ...

}