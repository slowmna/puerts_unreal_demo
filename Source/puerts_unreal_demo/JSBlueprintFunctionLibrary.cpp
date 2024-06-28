// Fill out your copyright notice in the Description page of Project Settings.

#include "JSBlueprintFunctionLibrary.h"

void UTestOuter::DoSomething()
{
	for (int i = 0; i < 10; i++)
	{
		int RandKey = FMath::RandRange(0, 100);		
		if (!this->MyTestA.MyTestB.Contains(RandKey))
		{
			FTestB B;
			int JMax = FMath::RandRange(0, 5);
			for (int j = 0; j < JMax; j++)
			{
				B.MyDummy.Add(NewObject<UDummyObj>(GetTransientPackage()));
			}
			this->MyTestA.MyTestB.Add(RandKey, MoveTemp(B));
		}
	}
}

const FTestA& UTestOuter::ReturnConstRef()
{
	UE_LOG(LogTemp, Log, TEXT("[ReturnConstRef] PrintAddress! (%p) =========================================================="), &MyTestA)
	return MyTestA;
}

FString UJSBlueprintFunctionLibrary::GetName()
{
	return TEXT("小马哥");//返回中文
}

FString UJSBlueprintFunctionLibrary::Hello(FString To)
{
    FString Result = FString::Printf(TEXT("Hello %s"), *(To));
    UE_LOG(LogTemp, Warning, TEXT("%s"), *Result);
    return Result;
}

FString UJSBlueprintFunctionLibrary::Concat(FString First, FString Second)
{
	return First + Second;
}

void UJSBlueprintFunctionLibrary::Info(UClass* To)
{
	UE_LOG(LogTemp, Warning, TEXT("Info %s %p"), *(To->GetPathName()), To);
}

UTestOuter* UJSBlueprintFunctionLibrary::GetTestOuter()
{
	return NewObject<UTestOuter>(GetTransientPackage());
}

void UJSBlueprintFunctionLibrary::TouchTestA(const FTestA& A)
{
	UE_LOG(LogTemp, Log, TEXT("[TouchTestA] PrintAddress! (%p) =========================="), &A)
}
