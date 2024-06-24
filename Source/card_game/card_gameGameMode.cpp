// Copyright Epic Games, Inc. All Rights Reserved.

#include "card_gameGameMode.h"
#include "card_gamePlayerController.h"
#include "card_gameCharacter.h"
#include "UObject/ConstructorHelpers.h"

Acard_gameGameMode::Acard_gameGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = Acard_gamePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}