// Fill out your copyright notice in the Description page of Project Settings.

#include "EscapeRoomSolo.h"
#include "PushMouvementXInverse.h"


// Sets default values for this component's properties
UPushMouvementXInverse::UPushMouvementXInverse()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	Owner = GetOwner();
	// ...
}


// Called when the game starts
void UPushMouvementXInverse::BeginPlay()
{
	Super::BeginPlay();

	
	// ...
	
}


// Called every frame
void UPushMouvementXInverse::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if ( GetWorld()->GetTimeSeconds() - LastDoorOpenTime > Delay && Owner->GetActorLocation().X == StartLocation) {

		Monteb = true;
		
	}

	if (Activateur->IsOverlappingActor(ActorThatOpen) && Owner->GetActorLocation().X == FinishLocation ) {
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

void UPushMouvementXInverse::Avance()
{
	CurentLocation = Owner->GetActorLocation();
	
	if (CurentLocation.X > FinishLocation) {
		CurentLocation.X -= speed;
		Owner->SetActorLocation(CurentLocation);
	}

	if (CurentLocation.X == FinishLocation) {
		Monteb = false;
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
}

void UPushMouvementXInverse::Recule()
{

	CurentLocation = Owner->GetActorLocation();
	
	if (CurentLocation.X < StartLocation) {
		CurentLocation.X += speed;
		Owner->SetActorLocation(CurentLocation);
	}

	if (CurentLocation.X == StartLocation) {
		Descend = false;
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
	// ...

}