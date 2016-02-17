//-----------------------------------------------------------------------------------------------
// This class is supposed to be used as a format guide for c++ code for the unreal engine.		  -
// The purpose is to streamline the readbility of the code and make sure other users and coders -
// can effectivly understand how to format their code.										                      -
// Name: Nicholas Mallonee																		                                  -
// Version: 4.10.2																				                                      -
// Created: 2.13.16																				                                      -
// Last Edit Date: 2.16.16																	                                    -
// Last Edit Programmer: Nicholas Mallonee													                          	-
//-----------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------
// Pragma's and Defines																			                                    -
//-----------------------------------------------------------------------------------------------
#pragma once
#define myVar 10.5

//-----------------------------------------------------------------------------------------------
// Libraries and Includes																		                                    -
//-----------------------------------------------------------------------------------------------
#include "GameFramework/Actor.h"
#include "MyBox.generated.h"

//-----------------------------------------------------------------------------------------------
// Enum : myEnum																			                                        	-
// Discrip: Holds Custom Data for this Sample project										                      	-
//-----------------------------------------------------------------------------------------------
UENUM()
enum class EMySampleEnum : unit8
{
	Red,
	Blue, 
	Green, 
	Yellow
};

//-----------------------------------------------------------------------------------------------
// UStruct : Sample Struct																	                                  	-
// Discrip: Holds Custom Data for this Sample project										                        -
//-----------------------------------------------------------------------------------------------
USTRUCT(BlueprintType)
struct FSampleStruct
{
	GENERATED_USTRUCT_BODY()

	// -- Struct information 
private:
	UPROPERTY()
	EMySampleEnum color;

	// -- Accessors and Mutators / Other Methods
public:
	/*
	* Returns the current state of this object.
	* @Return the enum state of this object.
	*/
	EOrbState getState()
	{
		return color;
	}

	/*
	* Allows outside access to set the state of the orb.
	* If the player catches the orb, the player will
	* set the orb state to caught.
	* @Param the state that orb should be set to.
	*/
	void setState(EMySampleEnum c)
	{
		color = c;
	}

	/*
	* Destroys the object and any custom datatypes.
	* @Return void method.
	*/
	void Destroy()
	{
	}

	// -- Base Constructor 
	FSampleStruct()
	{
		color = EMySampleEnum::Red;
	}
};

//-----------------------------------------------------------------------------------------------
// Clas Information																			                                      	-
//-----------------------------------------------------------------------------------------------
UCLASS()
class SampleProject_API ASampleClass : public AActor
{
	GENERATED_BODY()

	// -- Public Information -- Constructors and Engine Events -- // 
public:
	ASampleClass();

	ASampleClass(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
	
	// -- Private Information -- Sample Struct Container -- // 
private:
	FSampleStruct myInformation;
};
