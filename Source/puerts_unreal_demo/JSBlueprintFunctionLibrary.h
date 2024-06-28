// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "JSBlueprintFunctionLibrary.generated.h"


UCLASS()
class UDummyObj : public UObject
{
	GENERATED_BODY()

public:
	int num;
};


USTRUCT(BlueprintType)
struct FTestB
{
	GENERATED_USTRUCT_BODY()
public:

	FTestB() {}
	
	FTestB(const TArray<TObjectPtr<UDummyObj>>& InTasks): MyDummy(InTasks) {}
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced)
	TArray<TObjectPtr<UDummyObj>> MyDummy;
};


USTRUCT(BlueprintType)
struct FTestA
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<int, FTestB> MyTestB;
};

UCLASS()
class UTestOuter : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION()
	void DoSomething();
	
	UFUNCTION()
	const FTestA& ReturnConstRef();


	FTestA MyTestA;
};

/**
 * 
 */
UCLASS()
class PUERTS_UNREAL_DEMO_API UJSBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Test")
	static FString GetName();

	UFUNCTION(BlueprintCallable, Category = "Test")
	static FString Hello(FString To);

	UFUNCTION(BlueprintCallable, Category = "Test")
	static FString Concat(FString First, FString Second);

	UFUNCTION(BlueprintCallable, Category = "Test")
	static void Info(UClass* To);

	UFUNCTION()
	static UTestOuter* GetTestOuter();

	UFUNCTION()
	static void TouchTestA(const FTestA& A);
};
