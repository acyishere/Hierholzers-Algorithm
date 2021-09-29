#include <iostream>
#include <fstream>
#include <list> 
#include <vector>
#include "Vertex.h" 
#define pb push_back

using namespace std;

int main(int argc, char const *argv[]) {

	FILE *readFrom,*writeTo;

 	readFrom = fopen (argv[1],"r");                                                                                                                                                                              
  	writeTo = fopen (argv[2],"w");  

 	list<int> eCircuit;

 	vector<Vertex*> allVertexes;

 	int roadCount = 0;
	int V; // total number of crossing points of roads (vertices).
	int vertexID;
	int outD; // the out degree of this vertex .
	int edgeVertexes; // represent the Vertex IDs to which there is an edge from this vertex.
	int startVID; // id of the starting vertex;

	fscanf (readFrom, "%d", &V);

	for(int i = 0;i< V;i++){
		Vertex *x = new Vertex(i,0);
		allVertexes.pb(x);
	}

	for(int i = 0;i<V;i++){

		fscanf (readFrom, "%d %d" , &vertexID, &outD);
		
		roadCount += outD;

		allVertexes[i] -> outDegree = outD;

		for(int j = 0;j<outD;j++) {

			fscanf (readFrom, "%d", &edgeVertexes);
			Edge *outE = new Edge(edgeVertexes);
			allVertexes[i] -> edges.pb(outE);
			allVertexes[edgeVertexes] -> inDegree++;

		}

		if(allVertexes[i] -> inDegree > allVertexes[i] -> outDegree){
			fprintf (writeTo,"no path");

		    for(int y = 0;y<allVertexes.size();y++){
		    	delete allVertexes[y];
		    }
			return 0;
		}

	}

	fscanf (readFrom, "%d", &startVID);

	for(int i = 0;i<V;i++) {
		if(allVertexes[i] -> outDegree != allVertexes[i] -> inDegree){
		    fprintf (writeTo,"no path");

		    for(int y = 0;y<allVertexes.size();y++){
		    	delete allVertexes[y];
		    }
			return 0;
		}
	}

	eCircuit.pb(startVID);

	int v = startVID; // id of the vertex we hold

 	auto i = eCircuit.begin();

 	

	while(eCircuit.size() <= roadCount) {

		 list<int> eachTour;

		while(allVertexes[v] -> lastUsedId < allVertexes[v] -> outDegree-1){ 

		 	eachTour.pb(v);

		 	int u = allVertexes[v] -> edges[allVertexes[v] -> lastUsedId+1] -> endID;

		 	allVertexes[v] -> lastUsedId++;
		 	if(allVertexes[v] -> lastUsedId == allVertexes[v] -> outDegree-1){
		 		allVertexes[v] -> isEligible = false;
		 	}
		 	v = u;
		 }
		 
		 eCircuit.insert(i,eachTour.begin(),eachTour.end());
		
		 for(i = eCircuit.begin();i != eCircuit.end();i++){
		 	if(allVertexes[*i] -> isEligible == true){
		 		break;
		 	}
		 }
		 if(i != eCircuit.end()){
		 	v = allVertexes[*i] -> id;
		 }

	}

		for(auto i : eCircuit) {
			fprintf (writeTo, "%d ", i);
		}

		for(int y = 0;y<allVertexes.size();y++){
		    delete allVertexes[y];
		}

	return 0;
}
