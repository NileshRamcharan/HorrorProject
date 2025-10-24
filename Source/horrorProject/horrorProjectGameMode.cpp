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

	UE_LOG(LogTemp, Display, TEXT("beginplay gamemode"));

	AhorrorProjectCharacter* Player = Cast<AhorrorProjectCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	TArray<AActor*> HorrorAIActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AHorrorAI::StaticClass(), HorrorAIActors);

	for (int32 LoopIndex = 0; LoopIndex < HorrorAIActors.Num(); LoopIndex++)
	{
		AActor* HorrorAIActor = HorrorAIActors[LoopIndex];
		AHorrorAI* HorrorAI = Cast<AHorrorAI>(HorrorAIActor);
	
		if (HorrorAI)
		{
			HorrorAI->StartBehaviorTree(Player);
			UE_LOG(LogTemp, Display, TEXT("%s starting behaviour tree"), *HorrorAI->GetActorNameOrLabel());
		}
	}

}
