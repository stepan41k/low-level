#ifndef LOGIC_H
#define LOGIC_H

typedef struct {
    long total;
    long used;
} RamStats;

RamStats get_stats();

#endif