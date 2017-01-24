// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"

#include "Timer.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOMSOLO_API UTimer : public UActorComponent
{
	GENERATED_BODY()

private :


UPROPERTY(EditAnywhere)
	AActor *ActorThatOpen = nullptr;
UPROPERTY(EditAnywhere)
	float Delay = 1.0f;

	float StartTimer;

	AActor *Owner;

UPROPERTY(EditAnywhere)
	UTextRenderComponent *text ;//pawn hérite de actor
UPROPERTY(EditAnywhere)
ATriggerVolume *PressurePlate;//Set TriggerVolume Editable UE4


public:	
	// Sets default values for this component's properties
	UTimer();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	bool Fin = false;
		
	
};
