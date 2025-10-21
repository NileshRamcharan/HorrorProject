// Fill out your copyright notice in the Description page of Project Settings.


#include "HorrorAI.h"

#include "Kismet/GameplayStatics.h"

void AHorrorAI::BeginPlay()
{
	Super::BeginPlay();

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (PlayerPawn)
	{
		SetFocus(PlayerPawn);
	}
}

void AHorrorAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (PlayerPawn)
	{
		MoveToActor(PlayerPawn, 200.0f);
	}

}
