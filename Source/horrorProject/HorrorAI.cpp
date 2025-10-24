// Fill out your copyright notice in the Description page of Project Settings.


#include "HorrorAI.h"

#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void AHorrorAI::BeginPlay()
{
	Super::BeginPlay();

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

		UBlackboardComponent* MyBlackboard = GetBlackboardComponent();
		if (MyBlackboard && PlayerCharacter && MyCharacter)
		{
			MyBlackboard->SetValueAsVector("PlayerLocation", PlayerCharacter->GetActorLocation());
			MyBlackboard->SetValueAsVector("StartLocation", MyCharacter->GetActorLocation());

		}
	}
}
