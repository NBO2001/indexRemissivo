#ifndef ANALITYCALDATA_H
#define ANALITYCALDATA_H

typedef struct analyticalData{
    unsigned int tam;
    unsigned int factorCharge;
    unsigned int reHashingRealizade;
    unsigned int totalElements;
    unsigned int biggerLinkedList;
    double averageListSize;
    double avarageComparator;
    unsigned int totalCmp;
    unsigned int seachTotal;
    unsigned int positionsNoEmpty;
    unsigned int exceededFactorCharge;
    unsigned int totalListsRemoved;
}analyticalData;

#endif