// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blaster/HUD/ChatTextBlock.h"
#include "ChatBox.generated.h"

/**
 * 
 */
UCLASS()
class BLASTER_API UChatBox : public UUserWidget
{
	GENERATED_BODY()
	
public:
    void SetChatText(const FString& Text, const FString& PlayerName);

    UPROPERTY(meta = (BindWidget))
    class UScrollBox* InputScrollBox;

    UPROPERTY(meta = (BindWidget))
    class UEditableText* InputTextBox;

    UPROPERTY(EditAnywhere)
    TSubclassOf<class UChatTextBlock> ChatBoxClass;

private:
    

    UPROPERTY()
    class APlayerController* OwningPlayer;
};
