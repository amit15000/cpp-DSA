class nStack{
    int *arr, *top , *next;
    int size, n , free;

    nStack(int _size,int _n){
        size = _size ;  //size of whole arr
        n = _n ; //number of the stacks

        arr = new int[size];
        next = new int[size];
        top = new int[n];

        //initialization

        for(int i = 0 ; i < size-1; i++) next[i] = i+1;
        next[n-1] = -1;

        for(int i=0;i<n;i++) top[i] = -1;

        free = 0;
    }

    void push(int _x, int _sn){

        if(free == -1){
            cout<<"Stack overflow "<<endl;
            return;
        }
        
        int index = free;
        free = next[index];

        arr[index] = _x;

        next[index] = top[_sn];

        top[_sn] = index;

    }

    int pop(int _sn){
        if(top[_sn] == -1){
            cout<<"Stack Underflow \n";
            return; 
        }

        int index = top[_sn];

        top[_sn] = next[index];
        next[index] = free;
        free = index;
        return arr[index];
    }

};
