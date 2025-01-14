﻿#include "MSProjectileSubsystem.h"

#include "MSNiagaraActor.h"
#include "MSProjectileFragments.h"
#include "NiagaraComponent.h"


void UMSProjectileSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
		
	MassSubsystem = GetWorld()->GetSubsystem<UMassEntitySubsystem>();
	
}

void UMSProjectileSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
		
}

FSharedStruct UMSProjectileSubsystem::GetOrCreateSharedNiagaraFragmentForSystemType(UNiagaraSystem* NiagaraSystem)
{

	//we only want to key these based off of unique type sof niagara systems! Usually the entire thing would be hashed.
	uint32 ParamsHash = PointerHash(NiagaraSystem);

	FSharedNiagaraSystemFragment SharedStructToReturn;

	//try to see if we have seen this system type before...
	if(PreexistingSharedNiagaraActors.Contains(ParamsHash))
	{
		//if yes, just grab the one we made earlier!
		return MassSubsystem->GetOrCreateSharedFragment<FSharedNiagaraSystemFragment>(ParamsHash,SharedStructToReturn);
	}

	//if not, we need to spawn an entity+actor for it!
	AMSNiagaraActor* NewNiagaraActor = GetWorld()->SpawnActor<AMSNiagaraActor>();

	NewNiagaraActor->GetNiagaraComponent()->SetAsset(NiagaraSystem);
	
	SharedStructToReturn.NiagaraManagerActor = NewNiagaraActor;

	PreexistingSharedNiagaraActors.Add(ParamsHash,NewNiagaraActor);
	
	return MassSubsystem->GetOrCreateSharedFragment<FSharedNiagaraSystemFragment>(ParamsHash,SharedStructToReturn);
	
}

