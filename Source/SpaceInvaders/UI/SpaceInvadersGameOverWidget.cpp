#include "SpaceInvaders/UI/SpaceInvadersGameOverWidget.h"
#include "Kismet/GameplayStatics.h"

void USpaceInvadersGameOverWidget::SetScoreText(int32 Score)
{
	ScoreTextBlock->SetText(FText::FromString(FString::Printf(TEXT("Score: %d"), Score)));
}

void USpaceInvadersGameOverWidget::SetIsWin(bool IsWin)
{
	if (IsWin)
	{
		GameOverTextBlock->SetText(FText::FromString(FString::Printf(TEXT("GAME WON"))));
	}
	else
	{
		GameOverTextBlock->SetText(FText::FromString(FString::Printf(TEXT("GAME OVER"))));
	}
}

void USpaceInvadersGameOverWidget::OnContinue()
{
	UGameplayStatics::OpenLevel(this, TEXT("Level_SpaceInvadersInGame"));
}

void USpaceInvadersGameOverWidget::NativeConstruct()
{
	Super::NativeConstruct();

    UWorld* World = GetWorld();
    if (!ensureMsgf(World, TEXT("Could not bind continue action. World is not valid")))
    {
        return;
    }

    APlayerController* PlayerController = World->GetFirstPlayerController();
    if (!ensureMsgf(PlayerController, TEXT("Could not bind continue action. PlayerController is not valid")))
    {
        return;
    }

    PlayerController->InputComponent->BindAction("Continue", IE_Pressed, this, &USpaceInvadersGameOverWidget::OnContinue);
}