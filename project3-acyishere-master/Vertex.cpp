   using namespace std;                                                        
   #include "Vertex.h"                                                         
                                                                              
  Vertex::Vertex(int id,int outDegree){   

     this -> id = id;                                                        
     this -> outDegree = outDegree;
     this -> isEligible = true;
     this -> inDegree = 0;
     this -> lastUsedId = -1;

  }                                                                           
  Vertex::~Vertex(){                                                          
      for(int i = 0;i<this -> edges.size();i++){
      		delete this -> edges[i];
      }                                                                        
  }                                                                           
             