// Fill out your copyright notice in the Description page of Project Settings.


#include "AMyActor.h"



// Sets default values
AAMyActor::AAMyActor()
	: currentLoc(0, 0)
	, movingLoc(0, 0)
	, evCnt(0)
	, coin(0)
	, travelDist(0)
{	

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

}

// Called when the game starts or when spawned
void AAMyActor::BeginPlay()
{
	Super::BeginPlay();

	move();

	
}

// Called every frame
void AAMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AAMyActor::distance(FVector2D first, FVector2D second)
{

	int dx = first.X - second.X;
	int dy = first.Y - second.Y;

	float FtoSDistance = sqrt(dx * dx + dy * dy);


	return FtoSDistance;

}

void AAMyActor::move()
{
	float cLX = currentLoc.X;
	float cLY = currentLoc.Y;

	UE_LOG(LogTemp, Log, TEXT("Current Location ( %f, %f ), Start moving."), cLX, cLY);

	for (int i = 0; i < 10; ++i) 
	{
		step();
	}

	FVector2D diff = currentLoc - movingLoc;
	

	travelDist = travelDist + diff.Size();

	// 이동이 끝난 지점을 현재 위치 값으로
	currentLoc = movingLoc;

	UE_LOG(LogTemp, Log, TEXT("Event Count : %d"), evCnt);
	

}

float AAMyActor::step()
{
	
	// X-axis move
	int xRand = FMath::RandRange(-1, 1);
	int mLX = movingLoc.X = movingLoc.X + xRand;

	// Y-axis move
	int yRand = FMath::RandRange(-1, 1);
	int mLY = movingLoc.Y = movingLoc.Y + yRand;


	float Distance = sqrt(xRand * xRand + yRand * yRand);

	// 이동 완료 시 좌표 값 출력
	UE_LOG(LogTemp, Log, TEXT("Current Location : (%d, %d)"), mLX, mLY);

	// 스탭 마다 이벤트 확인
	createEvent();

	return Distance;

}

int AAMyActor::createEvent()
{

	int evRand = FMath::RandRange(0, 3);


	if (evRand == 0 || evRand == 1)
	{
		int amountCoin = evRand == 0 ? 1 : 5;
		coin += amountCoin;

		UE_LOG(LogTemp, Log, TEXT("You have obtained %d coin(s). Total: %d coin(s)"), amountCoin, coin);

		evCnt++;
	}


	return evCnt;

}

