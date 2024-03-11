// vr: mêmes commentaires que pour le fichier précédent question1_2.cpp
// tu aurais pu mettre le parcours dans le fichier précédent`1  À4E5D
#include <iostream>
#include <vector>

// Question 3

class Vertex;

class Edge {
public:
    Vertex* start; // Sommet de départ de l'arête
    Vertex* end;   // Sommet de fin de l'arête
    int weight;    // Poids associé à l'arête 

    Edge(Vertex* s, Vertex* e, int w) : start(s), end(e), weight(w) {} // Constructeur 
};

class Vertex {
    public :
    int value; // Indice du sommet 
    std::vector<Edge*> edges; // Liste des arêtes auquel le sommet est relié

    // vr: l'idée n'est pas de rajouter un attribut à la classe mais de faire un tableau et de le passer en argument
    bool visited ; // Booléen True si le sommet a été visité par le parcours en profondeur, False sinon 

    Vertex(int val, bool vis) : value(val), visited(vis){} // Constructeur d'un sommet avec une liste d'arête vide

    void addEdge(Edge* edge){edges.push_back(edge);} // Méthode pour ajouter des arêtes au sommet
};

class Graph{
    public : 
    std::vector<Vertex*> vertices; // Liste des sommets du graphe
    std::vector<Edge*> edges; // Liste des arêtes du graphe 

    ~Graph(){ // Destructeur du graphe
        for (Vertex* v : vertices){
            delete v;
        }
        for (Edge* e : edges){
            delete e;
        }
    };

    Vertex* addVertex(int val){ // Ajout d'un sommet au graphe 
        Vertex* newVertex = new Vertex(val, false); // Initialisation du booléen de visite à false 
        vertices.push_back(newVertex);
        return newVertex;
    };
     
    Edge* addEdge(Vertex* start, Vertex* end, int weight){ // Ajout d'une arête au graphe 
        Edge* newEdge = new Edge(start, end, weight);
        start->addEdge(newEdge);
        edges.push_back(newEdge);
        return newEdge;
    }

    // vr: non ici l'idée serait de faire une méthode parc_prof sur les Vertex 
    void parc_prof(Vertex* start){ // Implémentation du parcours en profondeur
        start->visited = true;
        // vr: le code qui suit est un code de Vertex pas de Graph !
        std::cout<<"Sommet "<<start->value<<" puis ";
        for (Edge* arete : start->edges){ // On regard tous les sommets reliés au sommet de départ
            if (!arete->end->visited){ // Si un sommet relié à celui de départ n'a jamais été visité, on lance le parcours à partir de ce sommet 
                parc_prof(arete->end);
            }
        }
        std::cout<<std::endl;
    }
};

int main(){ // on crée très basiquement un graphe
    Graph myGraph;
    Vertex* v1= myGraph.addVertex(1);
    Vertex* v2= myGraph.addVertex(2);
    Vertex* v3= myGraph.addVertex(3);
    Edge* edge23= myGraph.addEdge(v2,v3,8);
    Edge* edge12= myGraph.addEdge(v1,v2,5);
    Edge* edge31= myGraph.addEdge(v3,v1,3);
    std::cout<<"Représentation du graphe"<<std::endl; // Représentation du graphe, pas très esthétique mais pratique 
    std::cout<<"les sommets sont"<<std::endl;
    for (Vertex* somm : myGraph.vertices){
        std::cout<<somm->value<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"les arêtes sont"<<std::endl;
    for (Edge* are : myGraph.edges){
        std::cout<<are->start->value<<" vers "<<are->end->value<<" de poids "<<are->weight<<std::endl;
    }
    std::cout<<"Parcours en profondeur :"<<std::endl; // On intègre notre parcours en profondeur dans le main
    myGraph.parc_prof(v1);
    return 0;
};


