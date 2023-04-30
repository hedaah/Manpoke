#include <iostream>
#include "TableauDynamique.h"



    /* données membres */
    /* =============== */
    /* (ne sont pas censées être connues par l'utilisateur,
        si on avait pu ne pas les faire figurer dans l'interface, on l'aurait fait)
    */

    /* fonctions membres */
    /* ================= */
    TableauDynamique::TableauDynamique()
    {
    	ad = new ElementTD[1];
    	capacite = 1;
    	taille_utilisee = 0;
    }
     // Constructeur par défaut
    /* Postcondition : le tableau a 1 emplacement alloué mais vide (taille utilisée nulle) */

    TableauDynamique::TableauDynamique(const TableauDynamique& t)
    {
    	capacite = t.capacite;
    	taille_utilisee = t.taille_utilisee;
    	ad = new ElementTD[capacite];
    	for (unsigned int i = 0; i< taille_utilisee ; i++) ad[i] = t.ad[i];
    }
     // Constructeur par copie
    /* Precondition : le tableau t est initialisé */
    /* Postcondition : les deux tableaux contiennent des séquences d'ElementTD identiques (copie de t) */

    TableauDynamique::~TableauDynamique ()
    {
    	delete[] ad;
    	capacite = 0;
    	taille_utilisee = 0;
    } // Destructeur
    /* Postcondition : la mémoire allouée dynamiquement est libérée. */
	
    void TableauDynamique::vider ()
	{
		delete[] ad;
		ad = new ElementTD[1];
		taille_utilisee = 0;
	}
    /* Postcondition : la mémoire allouée dynamiquement est libérée.
	                   le tableau a 1 emplacement alloué mais vide (taille utilisée nulle) */

    void TableauDynamique::ajouterElement (ElementTD e)
    {
    	if (taille_utilisee == capacite) {
    		ElementTD* temp = ad;
    		ad = new ElementTD[2*capacite];
    		capacite *= 2;
    		for (unsigned int i = 0; i < taille_utilisee; i++) ad[i] = temp[i];
    		delete[] temp;
    	}
    	ad[taille_utilisee] = e;
    	taille_utilisee++;
    }
    /* Postcondition : l'élément e est ajouté dans le premier emplacement inutilisé du tableau,
                       la taille est incrémentée de 1. Doublement de la capacité si nécessaire. */

    ElementTD TableauDynamique::valeurIemeElement (unsigned int indice) const
    {
    	return ad[indice];
    }
    /* Precondition : 0 <= indice < taille_utilisee */
    /* Resultat : retourne l'ElementTD à l'indice en paramètre */

    void TableauDynamique::modifierValeurIemeElement (ElementTD e, unsigned int indice)
    {
    	ad[indice] = e;
    }
    /* Precondition : 0 <= indice < taille_utilisee */
    /* Postcondition : l'ElementTD à l'indice en paramètre vaut e */

    void TableauDynamique::afficher () const
    {
    	for (unsigned int i=0; i<taille_utilisee; i++)
    	{
    		std::cout << ad[i] << " ";
    	}
    	std::cout << std::endl;
    }
    /* Postcondition : les éléments du tableau sont affichés sur la sortie standard (espacement entre les éléments)
                       en utilisant la procédure d'affichage de ElementTD */

    void TableauDynamique::supprimerElement (unsigned int indice)
    {
    	ElementTD* temp = ad;
    	bool estSupp = false;
    	ad = new ElementTD[capacite];
    	for (unsigned int i = 0; i<taille_utilisee ; i++)
    	{
    		if (estSupp == false)
    		{
    			if (i != indice)
    			{
    				ad[i] = temp[i];
    			}
    			else 
    			{
    				estSupp = true;
    			}
    		}
    		else
    		{
    			ad[i-1] = temp[i];
    		}
    		//std::cout << "La boucle d'indice " << i << " s'est terminée" << std::endl;
    		//afficher();
    	}
    	taille_utilisee -=1;
    	if (taille_utilisee < capacite/3)
    	{
    	        temp = ad;
    		ad = new ElementTD[(int)capacite/2];
    		for (unsigned int i =0; i< taille_utilisee;i++)
    		{
    			ad[i] = temp[i];
    		}
    		capacite = (int)capacite/2;
    		
    	}
    	delete[] temp;
    }
    /* Precondition : le tableau est non vide, et 0 <= indice < taille_utilisee */
    /* Postcondition : la taille utilisée du tableau est décrémentée de 1.
                       si taille_utilisee < capacite/3, alors on divise la capacité par 2. */

    void TableauDynamique::insererElement (ElementTD e, unsigned int indice)
    {
    	ElementTD* tmp = ad;
    	if (capacite == taille_utilisee)
    	{
    		ad = new ElementTD[2*capacite];
    		capacite *= 2;
    		for (unsigned int i = 0; i < taille_utilisee; i++) ad[i] = tmp[i];
    		delete[] tmp;
    	}
    	//bool estInsere = false;
    	taille_utilisee++;
    	for (unsigned int i = taille_utilisee; i> indice;i--)
    	{
    		ad[i] = tmp[i-1];
	    	//afficher();
    	}
    	ad[indice] = e;
    	//afficher();
    }
    
    /* Precondition : 0 <= indice < taille_utilisee */
    /* Postcondition : e est inséré à l'indice en paramètre et la taille utilisée est incrémentée de 1 */

    void TableauDynamique::trier ()
    {
    	ElementTD x;
    	unsigned int j;
    	for(unsigned int i=1;i<taille_utilisee;i++)
    	{ 
    	  x=ad[i];
    	  j=i;
    	  while(j>0 && ad[j-1]>x)
    	  { ad[j]=ad[j-1];
    	    j--;
    	    }
    	   ad[j] = x;
    	   
    	   }
    	    
    	    
    	
    }
    /* Postcondition : le tableau est trié dans l'ordre croissant des valeurs des éléments */

    int TableauDynamique::rechercherElement (ElementTD e) const
    {
    	return recherche(e,0,taille_utilisee-1);
    }
    
    int TableauDynamique::recherche (ElementTD e, int imin, int imax ) const
    { 
    int i;
    i=(imin+imax)/2;
    if(e=ad[i]) return i;
    if(imin==imax) return -1;
    if(e<i){ recherche(e,imin,i-1);}
    if(e>i){ recherche(e,i+1,imax);
    }}
      
    /* Precondition : le tableau est trié dans l'ordre croissant */
    /* Résultat : indice de l'emplacement qui contient un ElementTD égal à e,
                  -1 si le tableau ne contient pas d'élément égal à e */
