

/*Complete the functions below*/
int find(int A[], int X)
{
    // add code here
    if (A[X] == X)
        return X;
    else
    {
        // return A[X]=find(A,A[X]); // to do path compression;
        return find(A, A[X]);
    }
}
void unionSet(int A[], int X, int Z)
{
    // add code here.
    int ult_par_X = find(A, X);
    int ult_par_Z = find(A, Z);
    // no union by rank or size, it says: "parent of Z will become the parent of X"
    // ult_par_Z=ult_parent_X; // wrong; it will change the local var value only;
    A[ult_par_X] = ult_par_Z;
    // for union by rank/size - (we would need the rank/size array entry or ultimate parent of X and Z); we would have made the larger rank/size parent as ult parent of the smaller one; if same we make anyone of them randomly;
}