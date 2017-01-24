// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "OpenActor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOMSOLO_API UOpenActor : public UActorComponent
{
	GENERATED_BODY()

private:

	UPROPERTY(EditAnywhere)
		float OpenAngle;
	UPROPERTY(EditAnywhere)
		float StartAngle;
	UPROPERTY(EditAnywhere)
		ATriggerVolume *PressurePlate;//Set TriggerVolume Editable UE4
	UPROPERTY(EditAnywhere)
	AActor *ActorThatOpen = nullptr;//pawn h�rite de actor

	UPROPERTY(EditAnywhere)
		float Delay = 1.0f;

	UPROPERTY(EditAnywhere)
		float speed;

	FRotator CurentRotation;
	float LastDoorOpenTime;
	UPROPERTY(EditAnywhere)
	FRotator StartLoc;
	AActor *Owner;





public:
	// Sets default values for this component's properties
	UOpenActor();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//M�thode ouvrir porte
	void OpenDoor();

	//M�thode ferme porte
	void CloseDoor();


};
