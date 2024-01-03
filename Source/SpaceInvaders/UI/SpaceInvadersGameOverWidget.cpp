#include "SpaceInvaders/UI/SpaceInvadersGameOverWidget.h"

void USpaceInvadersGameOverWidget::SetScoreText(int32 Score)
{
		ScoreTextBlock->SetText(FText::FromString(FString::Printf(TEXT("Score: %d"), Score)));
}
