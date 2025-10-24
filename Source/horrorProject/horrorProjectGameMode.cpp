// Copyright Epic Games, Inc. All Rights Reserved.

#include "horrorProjectGameMode.h"

#include "Kismet/GameplayStatics.h"
#include "horrorProjectCharacter.h"
#include "HorrorAI.h"

AhorrorProjectGameMode::AhorrorProjectGameMode()
{
	// stub
}

void AhorrorProjectGameMode::BeginPlay()
{
	Super::BeginPlay();

	AhorrorProjectCharacter* Player = Cast<AhorrorProjectCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	TArray<AActor*> HorrorAIActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AHorrorAI::StaticClass(), HorrorAIActors);
}
