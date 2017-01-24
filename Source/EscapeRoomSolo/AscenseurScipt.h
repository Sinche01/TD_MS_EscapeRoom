// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "AscenseurScipt.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOMSOLO_API UAscenseurScipt : public UActorComponent
{
	GENERATED_BODY()
private:

	UPROPERTY(EditAnywhere)
		float StartLocation;
	UPROPERTY(EditAnywhere)
		float FinishLocation;
	UPROPERTY(EditAnywhere)
		float speed;
	UPROPERTY(EditAnywhere)
		ATriggerVolume *PressurePlate;//Set TriggerVolume Editable UE4
	UPROPERTY(EditAnywhere)
	AActor *ActorThatOpen = nullptr;//pawn hérite de actor
	
	UPROPERTY(EditAnywhere)
		float Delay = 1.0f;

	float LastDoorOpenTime;
	FVector CurentLocation;
	AActor *Owner;
public:	
	// Sets default values for this component's properties
	UAscenseurScipt();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	//Méthode monte
	void Monte();

	//Méthode descendre
	void Descendre();
	UPROPERTY(EditAnywhere)
	bool Monteb = false;

	bool Descend = false;
};
