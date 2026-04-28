#ifndef GRAPH_GENERATOR_H
#define GRAPH_GENERATOR_H

#include "GraphList.h"
#include "GraphMatrix.h"

class GraphGenerator {
    public:
    static void generateRandomGraph(
        GraphList& graphList,
        GraphMatrix& GraphMatrix,
        int vertices,
        double density,
        int seed
    );
};

#endif

