#ifndef RESEARCH_H
#define RESEARCH_H

class Research {
    public:
        void run();

    private:
    long long measureList(int vertices, double density, int instanceCount);
    long long measureMatrix(int vertices, double density, int instanceCount);
    
};

#endif