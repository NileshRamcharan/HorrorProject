// Fill out your copyright notice in the Description page of Project Settings.


#include "HorrorAI.h"

#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void AHorrorAI::BeginPlay()
{
	Super::BeginPlay();

	/*AhorrorProjectCharacter* Player = Cast<AhorrorProjectCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

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
	}*/
}

void AHorrorAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (PlayerPawn)
	{
		if (LineOfSightTo(PlayerPawn))
		{
			SetFocus(PlayerPawn);
			MoveToActor(PlayerPawn, 200.0f);
		}
		else
		{
			ClearFocus(EAIFocusPriority::Gameplay);
			StopMovement();
		}
		
	}*/

}

void AHorrorAI::StartBehaviorTree(AhorrorProjectCharacter* Player)
{
	if (EnemyAIBehaviorTree)
	{
		MyCharacter = Cast<AhorrorProjectCharacter>(GetPawn());
		
		if (Player)
		{
			PlayerCharacter = Player;
		}
		
		RunBehaviorTree(EnemyAIBehaviorTree);
	}
}
