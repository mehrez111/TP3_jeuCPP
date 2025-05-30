// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Sphere_feu.h"

// Sets default values
ACPP_Sphere_feu::ACPP_Sphere_feu()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	smCube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
	check(smCube != nullptr);
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	UStaticMesh* mesh = MeshAsset.Object;
	smCube->SetStaticMesh(mesh);

	static ConstructorHelpers::FObjectFinder<UMaterialInterface>MaterialAsset(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Water_Lake.M_Water_Lake'"));
	UMaterialInterface* material = MaterialAsset.Object;
	smCube->SetMaterial(0, material);

	psParticles = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticuleEau"));
	check(psParticles != nullptr);
	static ConstructorHelpers::FObjectFinder<UParticleSystem>ParticlesAsset(TEXT("/Script/Engine.ParticleSystem'/Game/StarterContent/Particles/P_Steam_Lit.P_Steam_Lit'"));
	UParticleSystem* particles = ParticlesAsset.Object;
	psParticles->SetTemplate(particles);
	psParticles->SetupAttachment(CastChecked<UStaticMeshComponent>(smCube));

	
}

// Called when the game starts or when spawned
void ACPP_Sphere_feu::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_Sphere_feu::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

