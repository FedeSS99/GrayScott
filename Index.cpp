inline int GetIndex(int j, int i, int N){
    return j + i*N;
}

inline void GetPeriodicIndex(int *index, int N){
    (*index) = (*index)%N;
}