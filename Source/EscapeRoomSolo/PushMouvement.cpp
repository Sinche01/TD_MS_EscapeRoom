// Fill out your copyright notice in the Description page of Project Settings.

#include "EscapeRoomSolo.h"
#include "PushMouvement.h"


// Sets default values for this component's properties
UPushMouvement::UPushMouvement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPushMouvement::BeginPlay()
{
	
	Super::BeginPlay();
	Owner = GetOwner();
	// ...
	
	
}


// Called every frame
void UPushMouvement::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
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

void UPushMouvement::Avance()
{
	CurentLocation = Owner->GetActorLocation();

	if (CurentLocation.X < FinishLocation) {
		CurentLocation.X += speed;
		Owner->SetActorLocation(CurentLocation);
	}

	if (CurentLocation.X == FinishLocation) {
		Monteb = false;
	}
}

void UPushMouvement::Recule()
{

	CurentLocation = Owner->GetActorLocation();

	if (CurentLocation.X > StartLocation) {
		CurentLocation.X -= speed;
		Owner->SetActorLocation(CurentLocation);
	}

	if (CurentLocation.X == StartLocation) {
		Descend = false;
	}
	// ...

}

void UPushMouvement::Start() {

	CurentLocation = Owner->GetActorLocation();

	if (CurentLocation.X == StartLocation) {
		Monteb = true;
	}

	if (CurentLocation.X == FinishLocation) {
		Descend = true;
	}

}

void UPushMouvement::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("Action", IE_Pressed, this, &UPushMouvement::Start);
	
}