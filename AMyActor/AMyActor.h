// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AMyActor.generated.h"

UCLASS()
class HELLO_API AAMyActor : public AActor
{
	GENERATED_BODY()

	FVector2D currentLoc;
	FVector2D movingLoc;
	int evCnt;
	int coin;
	float travelDist;
	
public:	
	// Sets default values for this actor's properties
	AAMyActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;



	// 구현해야 할 과제
	float distance(FVector2D, FVector2D);

	void move();

	float step();

	int createEvent();



};
