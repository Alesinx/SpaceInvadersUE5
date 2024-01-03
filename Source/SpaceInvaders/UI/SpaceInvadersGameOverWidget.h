// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpaceInvaders/UI/SpaceInvadersWidget.h"
#include "SpaceInvadersGameOverWidget.generated.h"

/**
 * 
 */
UCLASS()
class SPACEINVADERS_API USpaceInvadersGameOverWidget : public USpaceInvadersWidget
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    void SetScoreText(int32 Score);

protected:
    UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
    UTextBlock* ScoreTextBlock;
};
