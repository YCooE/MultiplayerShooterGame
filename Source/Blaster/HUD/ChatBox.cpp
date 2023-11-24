// Fill out your copyright notice in the Description page of Project Settings.


#include "ChatBox.h"
#include "Components/ScrollBox.h"
#include "Components/EditableText.h"
#include "Components/TextBlock.h"
#include "Blaster/HUD/ChatTextBlock.h"

void UChatBox::SetChatText(const FString& Text, const FString& PlayerName)
{
    const FString Chat = PlayerName + " : " + Text;

    if (ChatBoxClass)
    {
        OwningPlayer = OwningPlayer == nullptr ? GetOwningPlayer() : OwningPlayer;
        if (OwningPlayer)
        {
            UChatTextBlock* ChatBoxWidget = CreateWidget<UChatTextBlock>(OwningPlayer, ChatBoxClass);
            if (InputScrollBox && ChatBoxWidget && ChatBoxWidget->ChatTextBlock)
            {
                ChatBoxWidget->ChatTextBlock->SetText(FText::FromString(Chat));
                ChatBoxWidget->ChatTextBlock->SetAutoWrapText(true);
                InputScrollBox->AddChild(ChatBoxWidget->ChatTextBlock); // This will add the TextBlock from WBP_ChatBox to the ScrollBox from top to bottom
                InputScrollBox->ScrollToEnd();
                InputScrollBox->bAnimateWheelScrolling = true;
            }
        }
    }
}