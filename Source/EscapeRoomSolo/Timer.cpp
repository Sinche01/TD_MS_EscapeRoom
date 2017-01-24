// Fill out your copyright notice in the Description page of Project Settings.

#include "EscapeRoomSolo.h"
#include "Timer.h"


// Sets default values for this component's properties
UTimer::UTimer()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTimer::BeginPlay()
{
	
	Super::BeginPlay();
	Owner = GetOwner();
	// ...
	//text->SetText("ojoj");
	//UE_LOG(LogTemp, Warning, TEXT("Start timer"));
	
	//UE_LOG(LogTemp, Warning, TEXT("Temps: %f ",StartTimer));
}


// Called every frame
void UTimer::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	
	// ...
}

