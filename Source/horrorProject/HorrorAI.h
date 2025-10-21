// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "HorrorAI.generated.h"

/**
 * 
 */
UCLASS()
class HORRORPROJECT_API AHorrorAI : public AAIController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
