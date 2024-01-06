#include "SpaceInvaders/UI/SpaceInvadersGameOverWidget.h"

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
