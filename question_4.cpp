#include <iostream>
#include <vector>
#include <stack>
#include <queue>

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

    void parc_prof_rec(Vertex* start){ // Implémentation du parcours en profondeur
    start->visited = true;
    std::cout<<"Sommet "<<start->value<<" puis ";
    for (Edge* arete : start->edges){ // On regard tous les sommets reliés au sommet de départ
        if (!arete->end->visited){ // Si un sommet relié à celui de départ n'a jamais été visité, on lance le parcours à partir de ce sommet 
            parc_prof_rec(arete->end);
        }
    }
    std::cout<<std::endl;
    }

    void parc_prof_it(Vertex* start){
        for (Vertex* v : vertices){
            v->visited = false;
        }
        std::stack<Vertex*> pile;
        pile.push(start);
        while (!pile.empty()){
            Vertex* somm_expl = pile.top();
            pile.pop();
            somm_expl->visited = true;
            std::cout<<"Sommet "<<somm_expl->value<<" puis "; 
            for (Edge* arete : somm_expl->edges){
                if (!arete->end->visited){
                    pile.push(arete->end);
                }
            }
        }
        std::cout<<std::endl;
    }

    void parc_large_it(Vertex* start){
        for (Vertex* v : vertices){
            v->visited = false;
        }
        std::queue<Vertex*> file;
        file.push(start);
        while (!file.empty()){
            Vertex* somme_expl = file.back();
            file.pop();
            somme_expl->visited=true;
            std::cout<<"Sommet "<<somm_expl->value<<" puis "; 
            for (Edge* arete : somm_expl->edges){
                if (!arete->end->visited){
                    file.push(arete->end);
                }
            }
        }
        std::cout<<std::endl;      
        };
};

int main(){ // on crée très basiquement un graphe
    Graph myGraph;
    Vertex* v1= myGraph.addVertex(1);
    Vertex* v2= myGraph.addVertex(2);
    Vertex* v3= myGraph.addVertex(3);
    Edge* edge23= myGraph.addEdge(v2,v3,8);
    Edge* edge12= myGraph.addEdge(v1,v2,5);
    Edge* edge31= myGraph.addEdge(v3,v1,3);
    std::cout<<"Représentation du graphe"<<std::endl;
    std::cout<<"les sommets sont"<<std::endl;
    for (Vertex* somm : myGraph.vertices){
        std::cout<<somm->value<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"les arêtes sont"<<std::endl;
    for (Edge* are : myGraph.edges){
        std::cout<<are->start->value<<" vers "<<are->end->value<<" de poids "<<are->weight<<std::endl;
    }
    std::cout<<"Parcours en profondeur récursif :"<<std::endl; // On intègre notre parcours en profondeur dans le main
    myGraph.parc_prof_rec(v1);
    std::cout<<"Parcours en profondeur itératif :"<<std::endl;
    myGraph.parc_prof_it(v1);
    std::cout<<"Parcours en largeur itératif :"<<std::endl;
    myGraph.parc_large_it(v1);
    return 0;
};
