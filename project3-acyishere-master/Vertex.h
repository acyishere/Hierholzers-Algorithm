#include <vector> 
#include "Edge.h" 
using namespace std;

class Vertex {

public:

	Vertex(int id,int outDegree);
	~Vertex();
	int id;
	int outDegree;
	int inDegree;
	bool isEligible;
	int lastUsedId;

	vector<Edge*> edges;

};



