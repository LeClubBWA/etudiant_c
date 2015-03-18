#include <stdio.h>

#define NB_ETUD 2

struct etudiant_type
{
	char nom[20];
	char prenom[20];
	int age;
	int nb_note;
	char sexe; 
	float moyenne;
};

void saisie_etudiant(struct etudiant_type p_etud[NB_ETUD])
{
	int i;
	for(i=0;i<NB_ETUD;i++){
		printf("Saisir le nom de l etudiant %d \n",i+1);
		scanf("%s", &p_etud[i].nom);
		printf("Saisir le prenom de l etudiant %d \n",i+1);
		scanf("%s", &p_etud[i].prenom);
		printf("Saisir l age de %s \n",p_etud[i].nom);
		scanf("%d", &p_etud[i].age);
		fflush(stdin);
		printf("Saisir le sexe de %s (H ou F) \n",p_etud[i].nom);
		scanf("%c", &p_etud[i].sexe);
		p_etud[i].moyenne = 0;
		p_etud[i].nb_note = 0;
	}
}

void ajouter_note (float *moyenne , int *nb_note, float note)
{
	*moyenne = ((*moyenne) * (*nb_note) + note) / (*nb_note + 1);
	*nb_note ++;
	fflush(stdin);
}

void affich_etud (struct etudiant_type etudiant)	
{
	if(etudiant.sexe == 'H' || etudiant.sexe == 'h')
	{
		printf("M. %s %s \n",  etudiant.prenom , etudiant.nom);
	
	}else{
		printf("Mme. %s %s \n", etudiant.prenom , etudiant.nom);
	}
	printf("%d ans \n", etudiant.age);
	printf("%f \n", etudiant.moyenne);
}	

void main()
{
	char choix;
	printf("Etudiants d'une classe \n");
	struct etudiant_type etud[NB_ETUD];
	saisie_etudiant(etud);
	int i;
	int numero = 0;
	printf("Numero etudiant | Prenom | Nom \n");
	for(i=0;i<NB_ETUD;i++)
	{
		
		printf("%d | %s | %s \n", numero, etud[i].prenom, etud[i].nom);
		numero++;
	}
	
	do
	{
		int numero_etud = 0;
		float note = 0;
		printf("Saisir le numero de l etudiant dont vous voulez saisir une nouvelle note :\n");
		scanf("%d", &numero_etud);
		printf("Saisir la note a ajouter :\n");
		scanf("%f", &note);
		ajouter_note(&etud[numero_etud].moyenne, &etud[numero_etud].nb_note, note);
		printf("Rentrer une nouvelle note ? (O/N) :\n");
		scanf("%c", &choix);
	}
	while(choix == 'o' || choix == 'O');
	
	do
	{
		int numero_etud = 0;
		printf("Saisir le numero de l etudiant a afficher\n");
		scanf("%d", &numero_etud);
		affich_etud(etud[numero_etud]);
		fflush(stdin);
		printf("Afficher un nouvel etudiant ? (O/N) :\n\n");
		scanf("%c", &choix);
	}
	while(choix == 'o' || choix == 'O');
}
