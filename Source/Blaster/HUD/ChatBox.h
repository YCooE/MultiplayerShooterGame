// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
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

    UPROPERTY(meta = (BindWidget))
    class UTextBlock* ChatTextBlock;

private:
    UPROPERTY(EditAnywhere)
    TSubclassOf<class UChatBox> ChatBoxClass;

    UPROPERTY()
    class APlayerController* OwningPlayer;
};
