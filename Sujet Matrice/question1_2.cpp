#include <iostream>
#include <vector>

//Question 1 
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

    Vertex(int val) : value(val){} // Constructeur d'un sommet avec une liste d'arête vide

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
        Vertex* newVertex = new Vertex(val);
        vertices.push_back(newVertex);
        return newVertex;
    };
     
    Edge* addEdge(Vertex* start, Vertex* end, int weight){ // Ajout d'une arête au graphe 
        Edge* newEdge = new Edge(start, end, weight);
        start->addEdge(newEdge);
        edges.push_back(newEdge);
        return newEdge;
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
    return 0;
};



